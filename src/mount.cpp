/*
 **  Copyright (C) 2001-2003 Daniel Sundberg & Anatoly Demchishin
 **
 **  This program is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 2 of the License, or
 **  (at your option) any later version.
 **
 **  This program is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with this program; if not, write to the Free Software
 **  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 **
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "mount.h"

//JagsConfig *cfg;
Mount::Mount(JagsConfig *icfg)
{
  cfg = icfg;
  mounts = g_list_alloc();
}

/*
 * This function will mount a new share and also check for errors
 *
 * returns:
 *  2 on already mounted
 *  1 on success
 * -1 on error, most likely bad password
 */
gint Mount::addMount(gchar *iserver, gchar *ishare, gchar *iworkgroup, 
		     gchar *irmb, gchar *iusername, gchar *ipassword)
{
  gchar *server, *share, *ptr, *cmd, *path, *mnt;
  GList *glist = mounts;
  gchar *sharemod;
  gint i;
  gchar *file = NULL;
  gchar *buffer = NULL;
  
  /* Prepare the strings */
  server = g_strdup(g_strchomp(iserver)); 
  g_strup(server);   // Only uppercase letters in the server-name
  share  = g_strchomp(ishare);

  ptr    = g_strdup(cfg->get_mount_dir());
  ptr    = g_strchomp (ptr);
  path   = getenv("HOME");
  sharemod = g_strdup(share);
  g_strdelimit(sharemod, NULL, '_');

  if (iworkgroup == NULL) iworkgroup=g_strdup("");
  if (irmb == NULL) irmb = g_strdup("");

  //--------------check if the share was already mounted------------------
  //--------------memory check------------------------------------
  mnt = g_strdup_printf("%s/%s/%s", cfg->get_mount_dir(), server, share);
  /* If we already mounted the share we return 2 */
  if (glist) {
    while (glist->next) {
      if (strcmp((gchar *)glist->next->data, mnt) == 0) {
	if (cfg->get_show_debug()) g_print("Share already mounted\n");
	return 2;
      }
      glist = glist->next;
    }
  }
  //---------------kernel mount check--------------------------------
  cmd = g_strdup_printf("sh %s/.jags/plugins/%s/ls_mnts.sh | "
			"grep \"//%s/%s\" > %s/.jags/mnterrors",path, 
			cfg->get_plugin(), server, sharemod, path);
  if (cfg->get_show_debug()) g_print("Kernel check: share already mounted...");
  system(cmd);
  file = g_strdup_printf("%s/.jags/mnterrors", path);
  ifstream onf(file);
  i = 0;
  while (onf.good()) {
    buffer = g_new(gchar,100);
    onf.getline(buffer, 100, '\n');
    i++;
  }
  if (cfg->get_show_debug()) g_print("%d time(s)\n", i-1);
  if (i>1) {
    if (cfg->get_show_debug()) g_print("%d time(s). Terminating task\n", i);
    onf.close();
    return 2;
  }
  //---------------------------------------------------------------

  /* If we didn't get password and username strings */
  if ((iusername == NULL) && (ipassword == NULL)) {
    iusername = g_strdup("");
    ipassword = g_strdup("");
    cmd = g_strdup_printf("sh %s/.jags/plugins/%s/mount_share.sh "
			  "\"%s\" \"%s\" \"%s/%s\" \"%s\" \"%s\"", path, 
			  cfg->get_plugin(), server, share, ptr, server, 
			  iworkgroup, irmb);
  } else {
    cmd    = g_strdup_printf("sh %s/.jags/plugins/%s/mount_share_with_remote.sh "
			     "\"%s\" \"%s\" \"%s/%s\" \"%s\" \"%s\" \"%s\" \"%s\"", 
			     path, cfg->get_plugin(), server, share, ptr, server, 
			     iworkgroup, irmb, iusername, ipassword);
  }  

  if (cfg->get_show_debug()) g_print("%s\n", cmd);
  /* Mount the share */
  system(cmd);
  //  g_print("sharemod = %s\n", sharemod);
  /* Check if the share was mounted */
  cmd = g_strdup_printf("sh %s/.jags/plugins/%s/ls_mnts.sh | grep "
			"\"//%s/%s\" > %s/.jags/mnterrors",path, cfg->get_plugin(), 
			server, sharemod, path);
  if (cfg->get_show_debug()) g_print("%s\n", cmd);
  system(cmd);
  file = g_strdup_printf("%s/.jags/mnterrors", path);
  ifstream onf2(file);
  i = 0;
  while (onf2.good()) {
    buffer = g_new(gchar,100);
    onf2.getline(buffer, 100, '\n');
    i++;
  }
  if (cfg->get_show_debug()) 
    g_print("quantity of successfull mounts detected: %d\n", i-1);
  if (i<2) {
    if (cfg->get_show_debug()) g_print("Det blev fel!\n");
    /* Here we found errors */
    onf2.close();
    cmd = g_strdup_printf("rm %s", file);
    system(cmd);
    return ERROR;
  } else {
    if (cfg->get_show_debug()) g_print("Everyting's ok\n");
    /* No errors found...add mounted dir to list of mounted shares */
    onf2.close();
    mounts = g_list_append(mounts, (gpointer)mnt);
    return OK;
  }
  /* Hmm shouldn't get to this */
  return 0;
}

gint Mount::addMountWithPath(gchar *iservershare, gchar *imountpath)
{
  gchar *path, *cmd, *server, *share, **mountpaths, *mountpath, *mountpath2;

  path = getenv("HOME");
  server = (g_strsplit(iservershare, "/", 3))[2];
  share =  (g_strsplit(iservershare, "/", 3))[3];
  g_strreverse(imountpath);
  mountpaths = g_strsplit(imountpath, "/", 25);
  g_strreverse(imountpath);
  mountpath = g_strjoinv("/", &mountpaths[1]);
  g_strreverse(mountpath);
  mountpath2 = g_strconcat("/", mountpath, NULL);

  if (cfg->get_show_debug()) g_print("%s\n", mountpath2);

  cmd = g_strdup_printf("sh %s/.jags/plugins/%s/mount_share.sh "
			"\"%s\" \"%s\" \"%s\"", path, cfg->get_plugin(), 
			server, share, mountpath2);
  /* Mount the share */
  g_print("%s\n", cmd);

  system(cmd);
  /* Check if the share was mounted */
  gchar *serversharemod = g_strdup(iservershare);
  //  g_print("%s\n", iservershare);
  g_strdelimit(serversharemod, NULL, '_');
  cmd = g_strdup_printf("sh %s/.jags/plugins/%s/ls_mnts.sh | "
			"grep \"%s\" > %s/.jags/mnterrors",path, cfg->get_plugin(), 
			serversharemod, path);
  if (cfg->get_show_debug()) g_print("%s\n", cmd);
  system(cmd);
  gchar *file = g_strdup_printf("%s/.jags/mnterrors", path);
  ifstream onf(file);
  gint i = 0;
  while (onf.good()) {
    gchar *buffer = g_new(gchar,100);
    onf.getline(buffer, 100, '\n');
    i++;
  }
  if (cfg->get_show_debug()) g_print("%d\n", i);
  if (i<2) {
    if (cfg->get_show_debug()) 
      g_print("An error occured while mounting the share...\n");
    /* Here we found errors */
    onf.close();
    cmd = g_strdup_printf("rm %s", file);
    system(cmd);
    return ERROR;
  } else {
    if (cfg->get_show_debug()) g_print("Everyting's ok\n");
    /* No errors found...add mounted dir to list of mounted shares */
    /* If we alreade mounted the share we return 2 */
    GList *glist = mounts;
    if (glist) {
      while (glist->next) {
	if (strcmp((gchar *)glist->next->data, imountpath) == 0) {
	  return 2;
	}
	glist = glist->next;
      }
    }
    mounts = g_list_append(mounts, (gpointer)imountpath);
    return OK;
  }
  /* Hmm shouldn't get to this */
  return 0;
}

gint Mount::rmMount(gchar *mnt)
{
  gchar *cmd = NULL, *path = NULL;

  gchar **str;
  gint j, i = 0, cntr = 0;
  gchar *deldir = NULL;

  str = g_strsplit(mnt,"/",20);
  while (str[i] != 0)
    i++;
  i -= 2;
  
  if (i<0) {
    g_print("Error while parsing directory to erase\n");
  } else {
    for (j=0;j<=i;j++)
      cntr+=strlen(str[j]);
    cntr+=i;
    deldir=g_strndup(mnt,cntr);
  }
  
  path = getenv("HOME");
  cmd = g_strdup_printf("sh %s/.jags/plugins/%s/umount.sh \"%s\" \"%s\"", 
			path, cfg->get_plugin(), mnt,deldir);
  /* Print some dbug nfo */
  if (cfg->get_show_debug()) g_print("Unmounting with syscall: %s\n", cmd);
  system(cmd);

  g_strfreev(str);
  g_free(deldir);  

  /* assume it was ssuccessful and remove from list of mounts */
  mounts = g_list_remove(mounts, (gpointer)mnt);

  return OK;
}


gchar *Mount::getLastError(void)
{
  return "error";
}

Mount::~Mount()
{
  g_list_free(mounts);
}

