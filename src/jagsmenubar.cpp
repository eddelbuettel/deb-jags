/*
 **  Copyright (C) 2000-2003 Daniel Sundberg, mike@penbex.com.tw and 
 **                          Anatoly Demchishin
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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gtk_common.h"
#include "jagsmenubar.h"
#include "jagsprefsdialog.h"
#include "jagsabout.h"
#include "jagsmountwith.h"
#include "jagssearchdialog.h"
#include "jagsmntswindow.h"
#include "data.h"

GtkWidget *bookmarks_item;
GtkWidget *bookmarks_menu;
GtkWidget *popup_menu;
GtkWidget *browse_item;
GtkWidget *mount_and_browse_item;
GtkWidget *mount_item;
GtkWidget *mount_with_item;
GtkWidget *mount_with_command_item;
GtkWidget *browse_item2;
GtkWidget *mount_and_browse_item2;
GtkWidget *mount_item2;
GtkWidget *mount_with_item2;

gchar *server_name = NULL;
gchar *share_name = NULL;
gchar *workgroup_name = NULL;
gchar *localmasterbrowser_name = NULL;
gchar *remotelocalmasterbrowser_name = NULL;
gint mount_error;
gint bm_updated = TRUE;

gchar *clean(gchar *s);
Mount *mmnt = NULL;
JagsMntsWindow *mb_mnts_window = NULL;
JagsConfig *menubar_conf = NULL;
JagsMenuBar *jagsmb = NULL;

GtkWidget *bmark_server;
GtkWidget *bmark_workgroup;

MainWindow *menubar_mainw;

/* Extra callbacks for the bookmarks dialog  */
static gint edit_bookmarks_close(GtkWidget *, gpointer data);
static gint edit_bookmarks_up(GtkWidget *, gpointer data);
static gint edit_bookmarks_down(GtkWidget *, gpointer data);
static gint edit_bookmarks_remove(GtkWidget *, gpointer data);
static gint edit_bookmarks_selection_made(GtkCList *clist, gint row, gint column, GdkEventButton *event, gpointer user_data);
gint bookmarks_selected_row = -1;

JagsMenuBar::JagsMenuBar(GtkWidget *vbox, GtkWidget *itree, JagsConfig *iconf, 
			 Mount *imount, MainWindow *mainw)
{
  GList *glist = NULL;

  conf = iconf;
  menubar_conf = iconf;
  mmnt = imount;
  mb_mnts_window = new JagsMntsWindow(mmnt, conf);
  jagsmb = this;
  main_tree = itree;
  menubar_mainw = mainw;

  /* Setup the menubar handlebox */
  handlebox = gtk_handle_box_new ();
  gtk_widget_show (handlebox);
  gtk_box_pack_start (GTK_BOX (vbox), handlebox, FALSE, FALSE, 0);

  /* Init the menubar */
  menubar = gtk_menu_bar_new();
  gtk_widget_show (menubar);
  gtk_container_add (GTK_CONTAINER (handlebox), menubar);

  /* Setup the filemenu */
  menuitem = gtk_menu_item_new_with_label("File");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);
 
  mount_and_browse_item = 
    gtk_menu_item_new_with_label_with_pixmap("Mount & browse...", "browse.xpm");
  gtk_widget_show (mount_and_browse_item);
  gtk_container_add (GTK_CONTAINER (menu), mount_and_browse_item);
  gtk_signal_connect (GTK_OBJECT(mount_and_browse_item), "activate", 
		      GTK_SIGNAL_FUNC (mount_and_browse), jagsmb);

  browse_item = gtk_menu_item_new_with_label_with_pixmap("Browse...", "browse.xpm");
  gtk_widget_show (browse_item);
  gtk_container_add (GTK_CONTAINER (menu), browse_item);
  gtk_signal_connect(GTK_OBJECT(browse_item), "activate", 
		     GTK_SIGNAL_FUNC(browse), jagsmb);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);
   
  mount_item = gtk_menu_item_new_with_label_with_pixmap("Mount", "mount.xpm");
  gtk_widget_show (mount_item);
  gtk_container_add (GTK_CONTAINER (menu), mount_item);
  gtk_signal_connect (GTK_OBJECT(mount_item), "activate", 
		      GTK_SIGNAL_FUNC (mount), jagsmb);
 
  mount_with_item = 
    gtk_menu_item_new_with_label_with_pixmap("Mount with pass...", "pass.xpm");
  gtk_widget_show (mount_with_item);
  gtk_container_add (GTK_CONTAINER (menu), mount_with_item);
  gtk_signal_connect (GTK_OBJECT(mount_with_item), "activate", 
		      GTK_SIGNAL_FUNC (mount_with), jagsmb);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Exit", "exit.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC (gtk_main_quit), NULL);

  menuitem = gtk_menu_item_new_with_label("Settings");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);

  menuitem = 
    gtk_menu_item_new_with_label_with_pixmap("Preferences...", "settings.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC (preferences), conf);

  /* Search menu */
  menuitem = gtk_menu_item_new_with_label("Search");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);

  menuitem = 
    gtk_menu_item_new_with_label_with_pixmap("Search computer...", "search.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC (my_search), jagsmb);

  /* Shares menu */
  menuitem = gtk_menu_item_new_with_label("Shares");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);

  menuitem = 
    gtk_menu_item_new_with_label_with_pixmap("Unmount all...", "unmount.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(umount), jagsmb);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);

  menuitem = 
    gtk_menu_item_new_with_label_with_pixmap("Mounted shares...", "browse.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(mnts_window), jagsmb);

  /* Bookmarks-menu */
  bookmarks_item = gtk_menu_item_new_with_label("Bookmarks");
  gtk_widget_show(bookmarks_item);
  gtk_container_add(GTK_CONTAINER(menubar), bookmarks_item);
  gtk_signal_connect(GTK_OBJECT(bookmarks_item), "activate", 
		     GTK_SIGNAL_FUNC(bookmark_menu), jagsmb);

  bookmarks_menu = gtk_menu_new();
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(bookmarks_item), bookmarks_menu);

  menuitem = 
    gtk_menu_item_new_with_label_with_pixmap("Bookmark server", "new_item.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(bookmark_add), jagsmb);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Add bookmark manually", 
						      "new_item.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(bookmarks_add_edit), jagsmb);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Edit bookmarks...", 
						      "settings.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(bookmark_edit), jagsmb);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);

  /* Add the bookmarks */
  if (iconf->get_show_debug()) g_print("Loading bookmarks...\n");
  if (iconf->get_nBmarks() > 0) {
    glist = g_list_copy(iconf->get_bmarks());
    while (glist->next->next) {
      if (iconf->get_show_debug()) 
	g_print("%s (server) %s (workgroup)\n", 
		(gchar *)glist->next->data, 
		(gchar *)glist->next->next->data);
      menuitem = 
	gtk_menu_item_new_with_label_with_pixmap((gchar *)glist->next->data, 
						 "i-bookmark.xpm");
      gtk_widget_show(menuitem);
      gtk_container_add(GTK_CONTAINER(bookmarks_menu), menuitem);
      gtk_signal_connect(GTK_OBJECT(menuitem), "activate", 
			 GTK_SIGNAL_FUNC(bookmark_selected), jagsmb);
      if (glist->next->next->next) 
	glist = glist->next->next;
      else 
	break;
    }
  } else {
    if (iconf->get_show_debug()) g_print("No bookmarks to load\n");
  }
  /* Help menu */
  menuitem = gtk_menu_item_new_with_label("Help");
  //gtk_menu_item_right_justify(GTK_MENU_ITEM(menuitem));
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("About...", "about.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC (about), jagsmb);

  /* Setup the popup menu */
  popup_menu = gtk_menu_new();

  mount_and_browse_item2 = 
    gtk_menu_item_new_with_label_with_pixmap("Mount & browse...", "browse.xpm");
  gtk_widget_show (mount_and_browse_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), mount_and_browse_item2);
  gtk_signal_connect (GTK_OBJECT(mount_and_browse_item2), "activate", 
		      GTK_SIGNAL_FUNC (mount_and_browse), jagsmb);

  browse_item2 = gtk_menu_item_new_with_label_with_pixmap("Browse...", "browse.xpm");
  gtk_widget_show (browse_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), browse_item2);
  gtk_signal_connect (GTK_OBJECT(browse_item2), "activate", 
		      GTK_SIGNAL_FUNC (browse), jagsmb);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (popup_menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);
   
  mount_item2 = gtk_menu_item_new_with_label_with_pixmap("Mount", "mount.xpm");
  gtk_widget_show (mount_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), mount_item2);
  gtk_signal_connect (GTK_OBJECT(mount_item2), "activate", 
		      GTK_SIGNAL_FUNC (mount), jagsmb);
 
  mount_with_item2 = 
    gtk_menu_item_new_with_label_with_pixmap("Mount with pass", "pass.xpm");
  gtk_widget_show (mount_with_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), mount_with_item2);
  gtk_signal_connect (GTK_OBJECT(mount_with_item2), "activate", 
		      GTK_SIGNAL_FUNC (mount_with), jagsmb);
}

JagsMenuBar::~JagsMenuBar()
{
  delete mb_mnts_window;
}


GtkWidget *JagsMenuBar::get_popupmenu(void)
{
  return popup_menu;
}

void JagsMenuBar::set_server_name(gchar *name)
{
  server_name = g_strdup_printf("%s", name);
}

void JagsMenuBar::set_share_name(gchar *name)
{
  share_name = g_strdup_printf("%s", name);
}

void JagsMenuBar::set_workgroup_name(gchar *name)
{
  workgroup_name = g_strdup_printf("%s", name);
}

void JagsMenuBar::set_localmasterbrowser_name(gchar *name)
{
  localmasterbrowser_name = g_strdup_printf("%s", name);
}

void JagsMenuBar::set_remotelocalmasterbrowser_name(gchar *name)
{
  remotelocalmasterbrowser_name = g_strdup_printf("%s", name);
}

gchar *JagsMenuBar::get_server_name(void)
{
  return server_name;
}

gchar *JagsMenuBar::get_share_name(void)
{
  return share_name;
}

gchar *JagsMenuBar::get_workgroup_name(void)
{
  return workgroup_name;
}

gchar *JagsMenuBar::get_localmasterbrowser_name(void)
{
  return localmasterbrowser_name;
}

gchar *JagsMenuBar::get_remotelocalmasterbrowser_name(void)
{
  return remotelocalmasterbrowser_name;
}


/* Grey or ungrey the menuitems, Actually vi reset the menuitems here if TRUE  */
void JagsMenuBar::toggle_menu_items(gboolean view)
{
  gboolean value = view;

  gtk_widget_set_sensitive(GTK_WIDGET(browse_item), !value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_and_browse_item), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_item), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_with_item), value);
  gtk_widget_set_sensitive(GTK_WIDGET(browse_item2), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_and_browse_item2), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_item2), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_with_item2), value);
}

void JagsMenuBar::toggle_browse(gboolean value) {
  gtk_widget_set_sensitive(GTK_WIDGET(browse_item), value);
  gtk_widget_set_sensitive(GTK_WIDGET(browse_item2), value);
}

void  JagsMenuBar::toggle_mount_and_browse(gboolean value) {
  gtk_widget_set_sensitive(GTK_WIDGET(mount_and_browse_item), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_and_browse_item2), value);  
}

void  JagsMenuBar::toggle_mount(gboolean value) {
  gtk_widget_set_sensitive(GTK_WIDGET(mount_item), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_item2), value);
}

void  JagsMenuBar::toggle_mount_with(gboolean value) {
  gtk_widget_set_sensitive(GTK_WIDGET(mount_with_item), value);
  gtk_widget_set_sensitive(GTK_WIDGET(mount_with_item2), value);
}

void JagsMenuBar::toggle_greyall(void)
{
  toggle_browse(FALSE);
  toggle_mount_and_browse(FALSE);
  toggle_mount(FALSE);
  toggle_mount_with(FALSE);

}

void JagsMenuBar::toggle_on_share_select(void)
{
  gchar *mnt, *server, *share,*sharemod,*path;
  GList *glist = mmnt->mounts;
  gint flag = 0;

  path   = getenv("HOME");
  server = g_strdup(g_strchomp(server_name)); 
  g_strup(server);         // Only uppercase letters in the server-name
  share  = g_strchomp(share_name);
  sharemod = g_strdup(share);
  g_strdelimit(sharemod, NULL, '_');

  //--------------check if the share was already mounted------------------
  //--------------memory check------------------------------------
  mnt = g_strdup_printf("%s/%s/%s", conf->get_mount_dir(), server, share);
  if (glist) { 
    while (glist->next) {
      if (strcmp((gchar *)glist->next->data, mnt) == 0)	{
      	flag=1;
	break;
      }
      glist = glist->next;
    }
  }
  g_free(mnt);
  
  if (!flag)
    toggle_unshade();
  else
    toggle_on_mount();
}

void JagsMenuBar::toggle_on_mount(void)
{
  toggle_browse(TRUE);
  toggle_mount_and_browse(FALSE);
  toggle_mount(FALSE);
  toggle_mount_with(FALSE);
}

void JagsMenuBar::toggle_unshade(void)
{
  toggle_browse(FALSE);
  toggle_mount_and_browse(TRUE);
  toggle_mount(TRUE);
  toggle_mount_with(TRUE);
}


void JagsMenuBar::mount_and_browse_ex(GtkMenuItem *item, JagsMenuBar *jmb)
{
  mount(item, jmb);
  if (!mount_error) browse(item, jmb);
}

/*--------------------- Callbacks ------------------------------------------------*/
gint mount_and_browse(GtkMenuItem *item, JagsMenuBar *jmb)
{
  mount(item, jmb);
  if (!mount_error) browse(item, jmb);
  
  return TRUE;
}

gint browse(GtkMenuItem *item, JagsMenuBar *jmb)
{
  gchar *server = g_strdup(g_strchomp(server_name));
  
  g_strup(server);
  gchar *command = g_strdup_printf("%s \"%s/%s/%s\" &", menubar_conf->get_browser(), 
				   menubar_conf->get_mount_dir(), server, 
				   share_name);
  if (menubar_conf->get_show_debug()) g_print("%s\n", command);
  system(command);

  return TRUE;
}

gint mount(GtkMenuItem *item, JagsMenuBar *jmb)
{
  gint result;
  gchar *cmd = NULL, *server = NULL, *mntpath = NULL, *mnt = NULL;
  
  /* Here I use the mount-class */
  if (g_strcasecmp(workgroup_name ,menubar_conf->get_workgroup())) {
    if (menubar_conf->get_show_debug()) 
      g_print("Remote nmb resolution mount launched\n");
    result = mmnt->addMount(server_name, share_name, g_strdup(workgroup_name), 
			    remotelocalmasterbrowser_name);
  } else {
    if (menubar_conf->get_show_debug()) 
      g_print("Local nmb resolution mount launched\n");
    result = mmnt->addMount(server_name, share_name);
  }

  if (menubar_conf->get_show_debug()) g_print("result == %d\n", result);
  if (result == OK) {
    mount_error = 0;
    if (menubar_conf->get_sound_enabled()) {
      cmd = g_strdup_printf("ogg123 %s %s/.jags/sounds/share2.ogg &", 
			    menubar_conf->get_sound_params(), g_get_home_dir());
      system(cmd);
      g_free(cmd);
    }

    jmb->toggle_on_mount();

    /* Call jagsmntswindow.addMnt() here */
    server = g_strdup(server_name);
    g_strup(server);
    mntpath = g_strdup_printf("%s/%s/%s", menubar_conf->get_mount_dir(), 
			      server, share_name);
    mnt = g_strdup_printf("//%s/%s", server, share_name);
    mb_mnts_window->addMount(mnt, mntpath);
    
    return TRUE;
  } else if (result == ERROR) {
    /* Popup mount_with here */
    if (menubar_conf->get_sound_enabled()) {
      cmd = g_strdup_printf("ogg123 %s %s/.jags/sounds/password2.ogg &", 
			    menubar_conf->get_sound_params(), g_get_home_dir());
      system(cmd);
      g_free(cmd);
    }
    mount_error = 1;
    JagsMountWith *mw = new JagsMountWith(menubar_conf, server_name, share_name, 
					  jmb, mmnt, mb_mnts_window);
    gint i = mw->get_result();
    if (i) {
      g_print("debug: %d\n",i);
    } else {
      g_print("debug %d\n",i);
    }
    
    return TRUE;
  } else {
    mount_error = 0;
    popup_dialog(140, "Error:", "Share probably already mounted...", "Ok");
    jmb->toggle_on_mount();

    return TRUE;
  }
  
  return TRUE;
}

gchar *clean(gchar *s)
{
  int i = strlen(s);
  char *outstr = new char[i];
  int j = 0;
  for (j = 0; j<i; j++) {
    if ( s[j] != ' ' ) {
      outstr[j]=s[j];
    } else {
      break;
    }
  } 
  outstr[j]='\0';
  return outstr;
}

gint mount_with(GtkMenuItem *item, JagsMenuBar *jmb)
{
  JagsMountWith *mw = new JagsMountWith(menubar_conf, server_name, share_name, 
					jmb, mmnt, mb_mnts_window);
  if (mw) g_print("MountWith dialog memory allocation OK\n");
  jmb->toggle_on_mount();

  return TRUE;
}


gint preferences(GtkMenuItem *item, JagsConfig *conf)
{
  gchar *cmd = NULL;

  if (conf->get_sound_enabled()) {
    cmd = g_strdup_printf("ogg123 %s %s/.jags/sounds/settings2.ogg &", 
			  conf->get_sound_params(), g_get_home_dir());
    system(cmd);
    g_free(cmd);
  }

  JagsPrefsDialog *d = new JagsPrefsDialog(conf);
  if (d) g_print("Prefs dialog memory allocation OK\n");

  return TRUE;
}

gint about(GtkMenuItem *item, JagsMenuBar *jmb)
{
  JagsAbout *a = new JagsAbout();
  if (a) g_print("About memory allocation OK\n");

  return TRUE;
}

gint my_search(GtkMenuItem *item, JagsMenuBar *jmb)
{
  JagsSearchDialog *d = new JagsSearchDialog(mmnt, jmb);
  if (d) g_print("Search dialog memory allocation OK\n");

  return TRUE;
}

gint umount(GtkMenuItem *item, JagsMenuBar *jmb)
{
  GList *glist = NULL;
  gchar *cmd = NULL;

  glist = g_list_copy(mmnt->mounts);

  if (glist->next)
    cmd = g_strdup_printf("ogg123 %s %s/.jags/sounds/unmall2.ogg &", 
			  jmb->conf->get_sound_params(), g_get_home_dir());
  else
    cmd = g_strdup_printf("ogg123 %s %s/.jags/sounds/nothing2.ogg &", 
			  jmb->conf->get_sound_params(), g_get_home_dir());

  if (jmb->conf->get_sound_enabled()) system(cmd);

  while (glist->next) {
    mmnt->rmMount((gchar *)glist->next->data);
    glist = glist->next;
  }
  g_list_free(glist);
  mb_mnts_window->clear_list();

  g_free(cmd);
  return TRUE;
}

gint mnts_window(GtkMenuItem *item, JagsMenuBar *jmb)
{
  //  JagsMntsWindow *m = new JagsMntsWindow(mmnt, jmb->conf);
  mb_mnts_window->show();

  return TRUE;
}

//-------------BOOKMARK SECTION-------------------------------------------------
gint bookmark_menu(GtkMenuItem *item, JagsMenuBar *jmb)
{
  return TRUE;
}

gint bookmark_add(GtkMenuItem *item, JagsMenuBar *jmb)
{
  GtkWidget *menuitem;
  gchar *file = NULL;

  /* If we have selected a server, add it to bookmarks */
  if (server_name) {
    g_print("Add bookmark\n");
    file = g_strdup_printf("%s/.jags/bookmarks", getenv("HOME"));
    ofstream outf(file, ios::app);
    if (outf.good()) { 
      outf << server_name << '\n';
      outf.close();
      menuitem = 
	gtk_menu_item_new_with_label_with_pixmap(server_name, "i-bookmark.xpm");
      gtk_widget_show(menuitem);
      gtk_signal_connect(GTK_OBJECT(menuitem), "activate", 
			 GTK_SIGNAL_FUNC(bookmark_selected), jmb);
      gtk_menu_append(GTK_MENU(bookmarks_menu), menuitem);
    }
  } else {
    g_print("Add bookmark: invalid item selected\n");
  }

  return TRUE;
}

gint bookmarks_add_edit(GtkMenuItem *item, JagsMenuBar *jmb)
{
  GtkWidget *dialog;
  GtkWidget *button, *button1 = NULL, *button2 = NULL, *label = NULL, 
    *hbox = NULL, *table = NULL;
  GSList *group;

  g_print("Manual bookmark editing dialog...\n");
  dialog = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW(dialog), "Manual bookmark editing...");
  gtk_widget_set_usize(dialog, 400, 200);

  /* Server name */
  hbox = gtk_hbox_new(TRUE, 3);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show(hbox);
  
  label = gtk_label_new("Server NetBIOS name:");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 0);
  gtk_widget_show(label);

  bmark_server = gtk_entry_new();
  gtk_entry_set_editable(GTK_ENTRY(bmark_server), TRUE);
  gtk_entry_set_text(GTK_ENTRY(bmark_server), "NAME");
  gtk_box_pack_start(GTK_BOX(hbox), bmark_server, TRUE, TRUE, 0);
  gtk_widget_show(bmark_server);

  table=gtk_table_new(3, 2, TRUE);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), table, TRUE, FALSE, 0);
  gtk_widget_show(table);
  /* Server name */
  label = gtk_label_new("Server workgroup:");
  gtk_table_attach_defaults(GTK_TABLE(table), label, 0,1, 0,1);
  gtk_widget_show(label);

  /* local */
  button1 = gtk_radio_button_new_with_label (NULL, "local workgroup");
  gtk_table_attach_defaults(GTK_TABLE(table), button1, 0,1, 1,2);
  gtk_signal_connect(GTK_OBJECT(button1), "toggled", GTK_SIGNAL_FUNC(bookmarks_radio_local_toggle), NULL);
  gtk_widget_show(button1);

  /* remote */
  group = gtk_radio_button_group (GTK_RADIO_BUTTON (button1));
  button2 = gtk_radio_button_new_with_label(group, "remote workgroup");
  gtk_table_attach_defaults(GTK_TABLE(table), button2, 0,1, 2,3);
  gtk_widget_show(button2);

  bmark_workgroup = gtk_entry_new();
  gtk_entry_set_editable(GTK_ENTRY(bmark_workgroup), TRUE);
  gtk_entry_set_text(GTK_ENTRY(bmark_workgroup),  menubar_conf->get_workgroup());
  gtk_widget_set_sensitive(bmark_workgroup, FALSE);
  gtk_table_attach_defaults(GTK_TABLE(table), bmark_workgroup, 1,2, 2,3);
  gtk_widget_show(bmark_workgroup);

  button = gtk_button_new_with_label("Ok");
  gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->action_area), button);
  gtk_signal_connect(GTK_OBJECT(button), "clicked", 
		     GTK_SIGNAL_FUNC(bookmarks_edit_add_ok), NULL);

  button = gtk_button_new_with_label("Close");
  gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->action_area), button);
  gtk_signal_connect(GTK_OBJECT(button), "clicked", 
		     GTK_SIGNAL_FUNC(bookmarks_edit_add_close), NULL);

  gtk_widget_show_all(dialog);

  return TRUE;
}

void bookmarks_radio_local_toggle (GtkWidget *widget, gpointer data)
{
  if (GTK_TOGGLE_BUTTON (widget)->active) {
    /* If control reaches here, the toggle button is down */
    gtk_widget_set_sensitive(bmark_workgroup, FALSE);
    gtk_entry_set_text(GTK_ENTRY(bmark_workgroup), menubar_conf->get_workgroup());
  } else {
    /* If control reaches here, the toggle button is up */
    gtk_widget_set_sensitive(bmark_workgroup, TRUE);
  }
}

gint bookmarks_edit_add_close(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy(widget->parent->parent->parent);

  return TRUE;
}

gint bookmarks_edit_add_ok(GtkWidget *widget, gpointer data)
{
  GtkWidget *menuitem = NULL;
  gchar *server = NULL, *workgroup = NULL;
  Data *d = NULL;
  GList *glist = NULL;
  gchar *command = NULL;
  gboolean flag = FALSE;
  gchar *error;

  server = g_strdup(gtk_entry_get_text(GTK_ENTRY(bmark_server)));
  workgroup = g_strdup(gtk_entry_get_text(GTK_ENTRY(bmark_workgroup)));

  if (strlen(server)<1) return TRUE;
  if (strlen(workgroup)<1) return TRUE;

  g_strup(server);
  g_strup(workgroup);

  /* Check for workgroup validity */
  command = g_strdup_printf("list_workgroups.sh \"%s\"", localmasterbrowser_name);
  d = new Data(command, menubar_conf->get_plugin());
  glist = d->getData();
  if (!g_list_find_custom(glist->next, (gpointer)workgroup, 
			  (GCompareFunc)g_strcasecmp)) {
    error = g_strdup_printf("Could not find workgroup\n %s on the net\n"
			    "Possibly invalid workgroup name specified\n", 
			    workgroup);
    popup_dialog(170, "Warning...", error, "Ok");
    g_free(error);
    g_print("Invalid workgroup specified\n");
    delete d;
    return TRUE;
  }

  /* check for server name uniqueness */
  if (menubar_conf->get_nBmarks() > 0) {
    glist = g_list_copy(menubar_conf->get_bmarks());
    while (glist->next->next) {
      if (!g_strcasecmp((gchar *)glist->next->data, server)) {
        error = g_strdup_printf("Server with similar name %s\nis bookmarked "
				"allready\n", server);
        popup_dialog(150, "Warning...", error, "Ok");
        g_free(error);
	g_print("Server with similar name is bookmarked allready\n");
	delete d;
	flag=TRUE;
	break;
      }
      if (glist->next->next->next) 
	glist = glist->next->next;
      else 
	break;
    }
  }

  if (flag) return TRUE;

  menubar_conf->addBmark(server, workgroup);

  menuitem = gtk_menu_item_new_with_label_with_pixmap(server, "i-bookmark.xpm");
  gtk_widget_show(menuitem);
  gtk_container_add(GTK_CONTAINER(bookmarks_menu), menuitem);
  gtk_signal_connect(GTK_OBJECT(menuitem), "activate", 
		     GTK_SIGNAL_FUNC(bookmark_selected), jagsmb);
  gtk_widget_destroy(widget->parent->parent->parent);

  delete d;
  return TRUE;
}

gint bookmark_edit(GtkMenuItem *item, JagsMenuBar *jmb)
{
  GtkWidget *dialog, *scrolled_window, *clist, *button_up;
  GtkWidget *button_down, *button_remove, *button_close;// *button_man_add;
  gchar *titles[2];
  GList *glist = NULL;

  g_print("Edit bookmarks...\n");

  dialog = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW(dialog), "Edit bookmarks...");
  gtk_widget_set_usize(dialog, 500, 300);

  titles[0] = g_strdup("Server");
  titles[1] = g_strdup("Workgroup");

  clist = gtk_clist_new_with_titles(2, titles);

  gtk_clist_set_column_width(GTK_CLIST(clist), 0, 150);
  gtk_clist_set_column_width(GTK_CLIST(clist), 1, 150);
  gtk_signal_connect(GTK_OBJECT(clist), "select_row", GTK_SIGNAL_FUNC(edit_bookmarks_selection_made), (gpointer)clist);

  if (menubar_conf->get_nBmarks() > 0) {
    glist = g_list_copy(menubar_conf->get_bmarks());
    while (glist->next->next) {
      gchar *buffer2[1];
      buffer2[0] = g_strdup((gchar *)glist->next->data);
      buffer2[1] = g_strdup((gchar *)glist->next->next->data);
      gtk_clist_append(GTK_CLIST(clist), buffer2);
      if (glist->next->next->next) 
	glist = glist->next->next;
      else 
	break;
    }
  }

  button_up = gtk_button_new_with_label("Move up");
  gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->action_area), button_up);
  gtk_signal_connect(GTK_OBJECT(button_up), "clicked",  
		     GTK_SIGNAL_FUNC(edit_bookmarks_up), (gpointer)clist);

  button_down = gtk_button_new_with_label("Move down");
  gtk_container_add(GTK_CONTAINER(GTK_DIALOG(dialog)->action_area), button_down);
  gtk_signal_connect(GTK_OBJECT(button_down), "clicked", 
		     GTK_SIGNAL_FUNC(edit_bookmarks_down), (gpointer)clist);

  button_remove = gtk_button_new_with_label("Remove");
  gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->action_area), button_remove);
  gtk_signal_connect(GTK_OBJECT(button_remove), "clicked", 
		     GTK_SIGNAL_FUNC(edit_bookmarks_remove), (gpointer)clist);

  button_close = gtk_button_new_with_label("Close");
  gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->action_area), button_close);
  gtk_signal_connect(GTK_OBJECT(button_close), "clicked", 
		     GTK_SIGNAL_FUNC(edit_bookmarks_close), (gpointer)clist);

  //  titles[1] = g_strdup("Server-path");

  scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), 
				 GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window), clist);
  gtk_widget_show(scrolled_window);
  gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->vbox), scrolled_window);

  gtk_widget_show(clist);
  gtk_widget_show_all(dialog);

  return TRUE;
}

gint edit_bookmarks_selection_made(GtkCList *clist, gint row, gint column, 
				   GdkEventButton *event, gpointer user_data)
{
  bookmarks_selected_row = row;
  return TRUE;
}

gint edit_bookmarks_up(GtkWidget *widget, gpointer data)
{
  if ((bookmarks_selected_row != 0) && 
      (bookmarks_selected_row != -1) && 
      (GTK_CLIST(data)->rows > 1)) {
    gtk_clist_swap_rows(GTK_CLIST(data), bookmarks_selected_row, 
			bookmarks_selected_row-1);
    bookmarks_selected_row--;
  }
  return TRUE;
}

gint edit_bookmarks_down(GtkWidget *widget, gpointer data)
{
  if ((bookmarks_selected_row != 
       (GTK_CLIST(data)->rows)-1) && 
      (bookmarks_selected_row != -1) && 
      (GTK_CLIST(data)->rows > 1)) {
    gtk_clist_swap_rows(GTK_CLIST(data), bookmarks_selected_row, 
			bookmarks_selected_row+1);
    bookmarks_selected_row++;
  }

  return TRUE;
}

gint edit_bookmarks_remove(GtkWidget *widget, gpointer data)
{
  gchar *server[1];

  gtk_clist_get_text(GTK_CLIST(data), bookmarks_selected_row, 0, server);

  menubar_conf->delBmark(server[0]);

  gtk_clist_remove(GTK_CLIST(data), bookmarks_selected_row);

  return TRUE;
}


gint edit_bookmarks_close(GtkWidget *widget, gpointer data)
{
  GtkWidget *menuitem;
  GList *glist = NULL;

  gtk_widget_destroy(bookmarks_menu);

  /* Bookmarks-menu */
  bookmarks_menu = gtk_menu_new();
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(bookmarks_item), bookmarks_menu);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Bookmark server", 
						      "new_item.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(bookmark_add), jagsmb);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Add bookmark manually", 
						      "new_item.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(bookmarks_add_edit), jagsmb);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Edit bookmarks...", 
						      "settings.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(bookmark_edit), jagsmb);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);


  if (menubar_conf->get_nBmarks() > 0) {
    glist = g_list_copy(menubar_conf->get_bmarks());
    while (glist->next->next) {
      menuitem = 
	gtk_menu_item_new_with_label_with_pixmap((gchar *)glist->next->data, 
						 "i-bookmark.xpm");
      gtk_widget_show(menuitem);
      gtk_container_add(GTK_CONTAINER(bookmarks_menu), menuitem);
      gtk_signal_connect(GTK_OBJECT(menuitem), "activate", 
			 GTK_SIGNAL_FUNC(bookmark_selected), jagsmb);
      if (glist->next->next->next) 
	glist = glist->next->next;
      else 
	break;
    }
  }
  gtk_widget_destroy(widget->parent->parent->parent);

  return TRUE;
}


gint bookmark_selected(GtkMenuItem *menu_item, JagsMenuBar *jmb)
{
  GList *list_i, *list_j, *list_k, *glist;
  GtkTreeItem *item;
  gchar *server = g_strchomp(gtk_menu_item_get_text(GTK_WIDGET(menu_item)));
  gchar *workgroup = NULL, *error = NULL;
  gboolean flag = FALSE;
  gchar *label = NULL, *command = NULL, *mssg = NULL;
  GtkWidget *item2 = NULL;
  Data *d;
  GtkWidget *new_item = NULL, *subtree = NULL;


    /* get server workgroup */
  glist = g_list_copy(menubar_conf->get_bmarks());
  while (glist->next->next) {
    if (!g_strcasecmp((gchar *)glist->next->data, server)) {
      workgroup = g_strdup((gchar *)glist->next->next->data);
      break;
    }
    if (glist->next->next->next) 
      glist = glist->next->next;
    else
      break;
  }

  /* check if such workgroup is reachable now */
  list_i = gtk_container_children (GTK_CONTAINER (jagsmb->main_tree));

  item = GTK_TREE_ITEM (list_i->data);
  gtk_tree_item_collapse(item);
  gtk_tree_item_select(item);
  gtk_tree_item_expand(item);
  gtk_tree_item_deselect(item);

  list_j = gtk_container_children (GTK_CONTAINER (item->subtree));

  while (list_j) {
    item2 = GTK_WIDGET (list_j->data);
    
    if (GTK_WIDGET_VISIBLE(item2)==FALSE) {       
      list_j = g_list_remove_link (list_j, list_j);
      continue;
    }

    label = gtk_tree_item_get_text(item2);
    if (!g_strcasecmp(label, workgroup)) {
      flag = TRUE;
    }
    list_j = g_list_remove_link (list_j, list_j);
    if (flag) 
      while (list_j) 
	list_j = g_list_remove_link (list_j, list_j);
  }

  g_list_remove_link (list_i, list_i);
  
  /* Actions if workgroup cannot be reached */
  if (!flag) {
    error = g_strdup_printf("Could not find workgroup\n %s on the net\n"
			    "The workgroup may be not reachable\n"
			    "now or possibly bookmark is invalid\n", workgroup);
    popup_dialog(170, "Warning...", error, "Ok");
    g_free(error);
    g_print("Bookmark workgroup cannot be reached\n");
    return TRUE;
  }

  /* Check if server is present on RemoteLocalMasterBrowser */
  if (item2) {
    gtk_tree_item_select(GTK_TREE_ITEM(item2));
    gtk_tree_item_expand(GTK_TREE_ITEM(item2));
    gtk_tree_item_deselect(GTK_TREE_ITEM(item2));
    
    list_k = gtk_container_children (GTK_CONTAINER (GTK_TREE_ITEM(item2)->subtree));
    
    flag = FALSE;
    while (list_k) {
      gchar *label2;
      GtkWidget *item3;

      item3 = GTK_WIDGET (list_k->data);
      label2 = gtk_tree_item_get_text(item3);
      if ( (!g_strcasecmp(label2, server)) && (GTK_WIDGET_VISIBLE(item3)==TRUE) ) {
	gtk_tree_item_select(GTK_TREE_ITEM(item3));
	gtk_tree_item_expand(GTK_TREE_ITEM(item3));
	g_print ("%s on level %d deployed with bookmark\n", label2, 
		 GTK_TREE (item3->parent)->level);
	flag = TRUE;
      }
      list_k = g_list_remove_link (list_k, list_k);
      if (flag) 
	while 
	  (list_k) list_k = g_list_remove_link (list_k, list_k);
    }
  } else {
    g_print("Bookmark section: Error occured while working with main tree "
	    "structure\n");
  }
  if (flag) return TRUE;
  
  /* Check if the server is online */
  command = g_strdup_printf("is_server_online.sh \"%s\"", server);
  d = new Data(command, menubar_conf->get_plugin());
  glist = d->getData();
  if (!g_strncasecmp((gchar *)glist->next->data, "Error", 5)) {
    error = g_strdup_printf("Could not connect %s server\nServer is offline "
			    "or unreachable\n", server);
    popup_dialog(170, "Warning...", error, "Ok");
    g_free(error);
    g_print("Server is offline or unreachable\n");
    delete d;
    return TRUE;
  }

  mssg = g_strdup_printf("%s broadcast lookup success: server ip %s\n", 
			 server, (gchar *)glist->next->data);
  g_print(mssg);
  g_free(mssg);
  delete d;

  new_item = gtk_tree_item_new_with_label_with_pixmap(server, "computer.xpm");
  gtk_tree_append(GTK_TREE(GTK_TREE_ITEM(item2)->subtree), new_item);
  subtree = gtk_tree_new();
  gtk_tree_item_set_subtree(GTK_TREE_ITEM(new_item), subtree);
  gtk_widget_show(new_item);
  
  gtk_signal_connect_after(GTK_OBJECT(new_item), "expand", 
			   GTK_SIGNAL_FUNC(expand_server), 
			   GTK_TREE(GTK_TREE_ITEM(item2)->subtree));
  gtk_signal_connect(GTK_OBJECT(new_item), "collapse", 
		     GTK_SIGNAL_FUNC(on_collapse), menubar_mainw);
  gtk_signal_connect(GTK_OBJECT(new_item), "button_press_event", 
		     GTK_SIGNAL_FUNC(check_server_click), menubar_mainw);

  gtk_tree_item_select(GTK_TREE_ITEM(new_item));
  gtk_tree_item_expand(GTK_TREE_ITEM(new_item));
  
  return TRUE;
}

/* Sample main test function */			      
/*
main(int argc, char *argv[])
{
  GtkWidget *window1, *vbox1;
  JagsMenuBar *m;
  gtk_init(&argc, &argv);
  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_object_set_data (GTK_OBJECT (window1), "window1", window1);
  gtk_window_set_title (GTK_WINDOW (window1), "window1");

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox1);
  gtk_object_set_data_full (GTK_OBJECT (window1), "vbox1", vbox1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (window1), vbox1);
  
  m = new JagsMenuBar(vbox1);

  gtk_widget_show(window1);
  gtk_main();
}
*/
