/*
 **  Copyright (C) 2000-2003 Daniel Sundberg & Anatoly Demchishin
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

#include <iostream>
#include <fstream>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "cconfig.h"
#include "jagsconfig.h"
#include "jagsprefsdialog.h"
#include "gtk_common.h"
#include "../config.h"

/* This class holds all config... Pretty self-explaining...isn't it? :) */
JagsConfig::JagsConfig()
{
  gchar *filename = NULL;
  cfile = NULL;

  filename = g_strdup_printf("%s/%s", getenv("HOME"), JAGS_CONFIG_FILE_NAME);
  ifstream fin(filename);

  /* If the config file doesn't exist, then copy the sample conf and run prefs dialog */
  if (!fin) {
    g_print("Copying sample config to your home-dir\n");
    system("mkdir ~/.jags");
    gchar *command = g_strdup_printf("cp -R %s/share/jags/* ~/.jags", JAGS_PREFIX);
    system(command);
    system("mv ~/.jags/jags.conf.sample ~/.jags/jags.conf");
    g_print("Config files successflly copied to your home-dir....\n");
    g_print("Please setup the program by choosing \"settings/Preferences\""
	    " in the menu!\n\n");
    /* TODO: Someone can make this work */
    //    popup_dialog(320, "Message", "Config files successflly copied to your home-dir....\nPlease setup the program by choosing \"settings/Preferences\" in the menu!\n", "Ok");
  } else {
    fin.close();
  }
  
  //  cfile = new CConfig(filename);
  /* Read config-values */
  reload();

  g_free(filename);
}

JagsConfig::~JagsConfig()
{
  g_list_free(conf.mnts);
  delete cfile;
}

gchar *JagsConfig::get_mount_dir(void) {
  return conf.mount_dir;
}

gchar *JagsConfig::get_workgroup(void) {
  return conf.workgroup;
}

gchar *JagsConfig::get_wins(void) {
  return conf.wins;
}

gchar *JagsConfig::get_plugin(void) {
  return conf.plugin;
}

gchar *JagsConfig::get_browser(void) {
  return conf.browser;
}

gchar *JagsConfig::get_sound_params(void) {
  return conf.sound_params;
}

gboolean JagsConfig::get_hide_ipc_shares(void) {
  return conf.hide_ipc_shares;
}

gboolean JagsConfig::get_sound_enabled(void) {
  return conf.sound_enabled;
}

gboolean JagsConfig::get_show_debug(void) {
  return conf.show_debug;
}

gboolean JagsConfig::get_show_tooltips(void) {
  return conf.show_tooltips;
}

gchar *JagsConfig::get_username(void) {
  return conf.username;
}

gchar *JagsConfig::get_password(void) {
  return conf.password;
}

void JagsConfig::set_searchfor(gchar *s) {
  conf.searchfor = g_strdup_printf("%s", s);
}
 
gchar *JagsConfig::get_searchfor(void) {
  return conf.searchfor;
}

gint JagsConfig::searchisset(void) {
  return conf.isset;
}

void JagsConfig::setsearchfor(gint i) {
  conf.isset = i;
}

gint JagsConfig::get_nMnts(void) {
  return conf.nMnts;
}

gint JagsConfig::get_nBmarks(void) {
  return conf.nBmarks;
}


/* manipulate the glist to add and delete things */
void JagsConfig::addMnt(gchar *mnt, gchar *mntpath)
{
  gchar *setString = NULL;

  g_list_append(conf.mnts, (gpointer)mnt);
  g_list_append(conf.mnts, (gpointer)mntpath);  
  cfile->writeConfigKey("NumberOfMounts", g_strdup_printf("%d", ++conf.nMnts));
  setString = g_strdup_printf("Mount%d", conf.nMnts);
  cfile->writeConfigKey(setString, mnt);
  g_free(setString);
  setString = g_strdup_printf("MountPath%d", conf.nMnts);
  cfile->writeConfigKey(setString, mntpath);
  g_free(setString);
}

void JagsConfig::addBmark(gchar *server, gchar *workgroup)
{
  gchar *setString = NULL;

  g_list_append(conf.bmarks, (gpointer)server);
  g_list_append(conf.bmarks, (gpointer)workgroup);  
  cfile->writeConfigKey("NumberOfBookmarks", g_strdup_printf("%d", ++conf.nBmarks));
  setString = g_strdup_printf("BookmarkServer%d", conf.nBmarks);
  cfile->writeConfigKey(setString, server);
  g_free(setString);
  setString = g_strdup_printf("BookmarkWG%d", conf.nBmarks);
  cfile->writeConfigKey(setString, workgroup);
  g_free(setString);
}

void JagsConfig::delMnt(gchar *mnt)
{
  /* Remove all shares from config-file */
  gchar *rmKeyString, *setString;
  GList *glist = NULL;

  for (int i = 1; i <= conf.nMnts; i++) {
    rmKeyString = g_strdup_printf("Mount%d", i);
    cfile->rmConfigKey(rmKeyString);
    g_free(rmKeyString);
    rmKeyString = g_strdup_printf("MountPath%d", i);
    cfile->rmConfigKey(rmKeyString);
    g_free(rmKeyString);
  }
  cfile->writeConfigKey("NumberOfMounts", g_strdup_printf("%d", --conf.nMnts));

  /* Delete this share from local config-list */
  glist = conf.mnts;


  while (glist->next) {
    if (!g_strcasecmp((gchar *)glist->next->data, mnt)) {
      glist->next = glist->next->next->next;
      break;
    }
    glist = glist->next->next;
  }

  /* Write back the shares we want to keep into config-file */
  glist = g_list_copy(conf.mnts);

  for (int i = 1; i <= conf.nMnts; i++) {
    setString = g_strdup_printf("Mount%d", i);
    cfile->writeConfigKey(setString, (gchar *)glist->next->data);
    glist = glist->next;
    setString = g_strdup_printf("MountPath%d", i);
    cfile->writeConfigKey(setString, (gchar *)glist->next->data);
    if (glist->next) glist = glist->next;
  }
}

void JagsConfig::delBmark(gchar *server)
{
  /* Remove all shares from config-file */
  gchar *rmKeyString, *setString;
  GList *glist = NULL;

  for (int i = 1; i <= conf.nBmarks; i++) {
    rmKeyString = g_strdup_printf("BookmarkServer%d", i);
    cfile->rmConfigKey(rmKeyString);
    g_free(rmKeyString);
    rmKeyString = g_strdup_printf("BookmarkWG%d", i);
    cfile->rmConfigKey(rmKeyString);
    g_free(rmKeyString);
  }
  cfile->writeConfigKey("NumberOfBookmarks", g_strdup_printf("%d", --conf.nBmarks));

  /* Delete this bookmark from local config-list */
  glist = conf.bmarks;
  while (glist->next) {
    if (!g_strcasecmp((gchar *)glist->next->data, server)) {
      glist->next = glist->next->next->next;
      break;
    }
    glist = glist->next->next;
  }

  /* Write back the shares we want to keep into config-file */
  glist = g_list_copy(conf.bmarks);
  
  for (int i = 1; i <= conf.nBmarks; i++) {
    setString = g_strdup_printf("BookmarkServer%d", i);
    cfile->writeConfigKey(setString, (gchar *)glist->next->data);
    glist = glist->next;
    setString = g_strdup_printf("BookmarkWG%d", i);
    cfile->writeConfigKey(setString, (gchar *)glist->next->data);
    if (glist->next) glist = glist->next;
  }
}


GList *JagsConfig::get_mnts(void)
{
  return conf.mnts;
}

GList *JagsConfig::get_bmarks(void)
{
  return conf.bmarks;
}

void JagsConfig::reload()
{
  gchar *buffer = NULL;
  gchar *getString = NULL;
  gchar *filename = g_strdup_printf("%s/%s", getenv("HOME"), JAGS_CONFIG_FILE_NAME);

  if (cfile != NULL) delete cfile;
  cfile = new CConfig(filename);

  conf.mount_dir = g_strdup(cfile->getConfigKey("MountDir"));
  conf.workgroup = g_strdup(cfile->getConfigKey("Workgroup"));
  conf.wins = g_strdup(cfile->getConfigKey("WINS"));
  conf.sound_params = g_strdup(cfile->getConfigKey("SoundParams"));
  conf.browser   = g_strdup(cfile->getConfigKey("Browser"));
  conf.plugin    = g_strdup(cfile->getConfigKey("Plugin"));

  buffer         = g_strdup(cfile->getConfigKey("SoundEnabled"));
  if (g_strcasecmp(buffer, "1") == 0) {
    conf.sound_enabled = TRUE;  
  } else {
    conf.sound_enabled = FALSE;  
  }
  if (buffer) g_free(buffer);

  buffer = g_strdup(cfile->getConfigKey("HideIPCShares"));
  if (g_strcasecmp(buffer, "1") == 0) {
    conf.hide_ipc_shares = TRUE;  
  } else {
    conf.hide_ipc_shares = FALSE;  
  }
  if (buffer) g_free(buffer);

  buffer = g_strdup(cfile->getConfigKey("ShowDebugInfo"));
  if (g_strcasecmp(buffer, "1") == 0) {
    conf.show_debug = TRUE;
  } else {
    conf.show_debug = FALSE;  
  }
  if (buffer) g_free(buffer);
  buffer = g_strdup(cfile->getConfigKey("ShowTooltips"));
  if (g_strcasecmp(buffer, "1") == 0) {
    conf.show_tooltips = TRUE;
  } else {
    conf.show_tooltips = FALSE;  
  }
  if (buffer) g_free(buffer);
  conf.username   = g_strdup(cfile->getConfigKey("UserName"));
  conf.password   = g_strdup(cfile->getConfigKey("Password"));
  conf.isset = 0;
  
  conf.mnts = g_list_alloc();

  /* Read the shares which is to be mounted here */
  conf.nMnts = atoi(cfile->getConfigKey("NumberOfMounts"));
  //  g_print("%d\n", conf.nMnts);
  if (conf.nMnts > 0) {
    for (gint i = 1; i <= conf.nMnts; i ++) {
      getString = g_strdup_printf("Mount%d", i);
      conf.mnts = g_list_append(conf.mnts, 
				(gpointer)g_strdup(cfile->getConfigKey(getString)));
      g_free(getString);
      getString = g_strdup_printf("MountPath%d", i);
      conf.mnts = g_list_append(conf.mnts, 
				(gpointer)g_strdup(cfile->getConfigKey(getString)));
      g_free(getString);
    }
  }

  conf.bmarks = g_list_alloc();

  /* Read the bookmark data */
  conf.nBmarks = atoi(cfile->getConfigKey("NumberOfBookmarks"));
  if (conf.nBmarks > 0) {
    for (gint i = 1; i <= conf.nBmarks; i++) {
      getString = g_strdup_printf("BookmarkServer%d", i);
      conf.bmarks = g_list_append(conf.bmarks, 
				  (gpointer)g_strdup(cfile->getConfigKey(getString)));
      g_free(getString);
      getString = g_strdup_printf("BookmarkWG%d", i);
      conf.bmarks = g_list_append(conf.bmarks, 
				  (gpointer)g_strdup(cfile->getConfigKey(getString)));
      g_free(getString);
    }
  }
  g_free(filename);
}


/*
main() {
  JagsConfig *c;
  c = new JagsConfig();
  cout << c->get_mount_dir()       << '\n';
  cout << c->get_workgroup()       << '\n';
  cout << c->get_plugin()          << '\n';
  cout << c->get_hide_ipc_shares() << '\n';
  return 0;
}
*/
