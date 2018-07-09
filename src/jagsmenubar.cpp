/*
 **  jagsMenuBar v0.1.1
 **  Copyright (C) 2000-2001 Daniel Sundberg
 **
 **  Quote spaces patch by mike@penbex.com.tw
 **
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
 ** jagsmenubarcpp
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Mon Jul  3 20:00:00 2000 Daniel Sundberg 
 ** Last update Fri May 18 00:58:00 2001 Daniel Sundberg
 */

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gtk_common.h"
#include "jagsmenubar.h"
#include "jagsprefsdialog.h"
#include "jagsabout.h"
#include "jagsconfig.h"
#include "jagsmountwith.h"
#include "jagsmountwithcommand.h"
#include "jagssearchdialog.h"
#include "jagsmntswindow.h"

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

gchar *server_name;
gchar *share_name;
gint mount_error;
gint bm_updated = TRUE;

gchar *clean(gchar *s);
Mount *mmnt;
JagsMntsWindow *mb_mnts_window;
JagsConfig *menubar_conf;

/*
 * Extra callbacks for the bookmarks dialog 
 */
static gint edit_bookmarks_close(GtkWidget *, gpointer data);
static gint edit_bookmarks_up(GtkWidget *, gpointer data);
static gint edit_bookmarks_down(GtkWidget *, gpointer data);
static gint edit_bookmarks_remove(GtkWidget *, gpointer data);
static gint edit_bookmarks_selection_made(GtkCList *clist, gint row, gint column,
					  GdkEventButton *event, gpointer user_data);
gint bookmarks_selected_row = -1;

JagsMenuBar::JagsMenuBar(GtkWidget *vbox, JagsConfig *iconf, Mount *imount) {
  conf = iconf;
  menubar_conf = iconf;
  mmnt = imount;
  mb_mnts_window = new JagsMntsWindow(mmnt, conf);

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
 
  mount_and_browse_item = gtk_menu_item_new_with_label_with_pixmap("Mount & browse...", "browse.xpm");
  gtk_widget_show (mount_and_browse_item);
  gtk_container_add (GTK_CONTAINER (menu), mount_and_browse_item);
  gtk_signal_connect (GTK_OBJECT(mount_and_browse_item), "activate", GTK_SIGNAL_FUNC (mount_and_browse), NULL);

  browse_item = gtk_menu_item_new_with_label_with_pixmap("Browse...", "browse.xpm");
  gtk_widget_show (browse_item);
  gtk_container_add (GTK_CONTAINER (menu), browse_item);
  gtk_signal_connect(GTK_OBJECT(browse_item), "activate", GTK_SIGNAL_FUNC(browse), NULL);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);
   
  mount_item = gtk_menu_item_new_with_label_with_pixmap("Mount", "mount.xpm");
  gtk_widget_show (mount_item);
  gtk_container_add (GTK_CONTAINER (menu), mount_item);
  gtk_signal_connect (GTK_OBJECT(mount_item), "activate", GTK_SIGNAL_FUNC (mount), NULL);
 
  mount_with_item = gtk_menu_item_new_with_label_with_pixmap("Mount with...", "mount.xpm");
  gtk_widget_show (mount_with_item);
  gtk_container_add (GTK_CONTAINER (menu), mount_with_item);
  gtk_signal_connect (GTK_OBJECT(mount_with_item), "activate", GTK_SIGNAL_FUNC (mount_with), NULL);

  /* Mount with command */
  mount_with_command_item = gtk_menu_item_new_with_label_with_pixmap("Mount with command...", "mount.xpm");
  gtk_widget_show (mount_with_command_item);
  gtk_container_add (GTK_CONTAINER (menu), mount_with_command_item);
  gtk_signal_connect (GTK_OBJECT(mount_with_command_item), "activate", GTK_SIGNAL_FUNC (mount_with_command), NULL);

 
  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Exit", "exit.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC (gtk_main_quit), NULL);

  menuitem = gtk_menu_item_new_with_label("Settings");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Preferences...", "settings.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC (preferences), conf);

  /* Search menu */
  menuitem = gtk_menu_item_new_with_label("Search");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Search computer...", "search.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC (search), NULL);

  /* Shares menu */
  menuitem = gtk_menu_item_new_with_label("Shares");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menubar), menuitem);

  menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Unmount all...", "unmount.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC(umount), NULL);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Mounted shares...", "browse.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC(mnts_window), NULL);

  /* Bookmarks-menu */
  bookmarks_item = gtk_menu_item_new_with_label("Bookmarks");
  gtk_widget_show(bookmarks_item);
  gtk_container_add(GTK_CONTAINER(menubar), bookmarks_item);
  gtk_signal_connect(GTK_OBJECT(bookmarks_item), "activate", GTK_SIGNAL_FUNC(bookmark_menu), NULL);

  bookmarks_menu = gtk_menu_new();
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(bookmarks_item), bookmarks_menu);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Add bookmark", "new_item.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC(bookmark_add), NULL);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Edit bookmarks...", "settings.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC(bookmark_edit), NULL);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);

  /* Add the bookmarks */
  gchar *file = g_strdup_printf("%s/.jags/bookmarks", getenv("HOME"));
  ifstream inf(file);
  while (inf.good()) {
    gchar *buffer = g_new(gchar, 30);
    inf.getline(buffer, 30, '\n');
    if (strlen(buffer) > 0) {
      menuitem = gtk_menu_item_new_with_label_with_pixmap(buffer, "i-bookmark.xpm");
      gtk_widget_show(menuitem);
      gtk_container_add(GTK_CONTAINER(bookmarks_menu), menuitem);
      gtk_signal_connect(GTK_OBJECT(menuitem), "activate", 
			 GTK_SIGNAL_FUNC(bookmark_selected), NULL);
    }
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
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC (about), NULL);

  /* Setup the popup menu */
  popup_menu = gtk_menu_new();

  mount_and_browse_item2 = gtk_menu_item_new_with_label_with_pixmap("Mount & browse...", "browse.xpm");
  gtk_widget_show (mount_and_browse_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), mount_and_browse_item2);
  gtk_signal_connect (GTK_OBJECT(mount_and_browse_item2), "activate", GTK_SIGNAL_FUNC (mount_and_browse), NULL);

  browse_item2 = gtk_menu_item_new_with_label_with_pixmap("Browse...", "browse.xpm");
  gtk_widget_show (browse_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), browse_item2);
  gtk_signal_connect (GTK_OBJECT(browse_item2), "activate", GTK_SIGNAL_FUNC (browse), NULL);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (popup_menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);
   
  mount_item2 = gtk_menu_item_new_with_label_with_pixmap("Mount", "mount.xpm");
  gtk_widget_show (mount_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), mount_item2);
  gtk_signal_connect (GTK_OBJECT(mount_item2), "activate", GTK_SIGNAL_FUNC (mount), NULL);
 
  mount_with_item2 = gtk_menu_item_new_with_label_with_pixmap("Mount with...", "mount.xpm");
  gtk_widget_show (mount_with_item2);
  gtk_container_add (GTK_CONTAINER (popup_menu), mount_with_item2);
  gtk_signal_connect (GTK_OBJECT(mount_with_item2), "activate", GTK_SIGNAL_FUNC (mount_with), NULL);

//    menuitem = gtk_menu_item_new_with_label("popup");
//    gtk_widget_show(menuitem);
//    gtk_container_add(GTK_CONTAINER(menubar), menuitem);
//    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), popup_menu);
//    gtk_widget_show(popup_menu);
  

}

JagsMenuBar::~JagsMenuBar() {

}


GtkWidget *JagsMenuBar::get_popupmenu(void) {
  return popup_menu;
}

void JagsMenuBar::set_server_name(gchar *name) {
  server_name = g_strdup_printf("%s", name);
  //  g_print("%s&\n", server_name);
}

void JagsMenuBar::set_share_name(gchar *name) {
  share_name = g_strdup_printf("%s", name);
  //  g_print("%s\n", share_name);
}

gchar *JagsMenuBar::get_server_name(void) {
  return server_name;
}

gchar *JagsMenuBar::get_share_name(void) {
  return share_name;
}


/* Grey or ungrey the menuitems, Actually vi reset the menuitems 
   here if TRUE  */
void JagsMenuBar::toggle_menu_items(gboolean view) {
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

void JagsMenuBar::toggle_mount_with_command(gboolean value) {
  gtk_widget_set_sensitive(GTK_WIDGET(mount_with_command_item), value);
}

void JagsMenuBar::toggle_greyall(void) {
  toggle_browse(FALSE);
  toggle_mount_and_browse(FALSE);
  toggle_mount(FALSE);
  toggle_mount_with(FALSE);
  toggle_mount_with_command(FALSE);
}

void JagsMenuBar::toggle_on_share_select(void) {
  toggle_browse(FALSE);
  toggle_mount_and_browse(TRUE);
  toggle_mount(TRUE);
  toggle_mount_with(TRUE);
  toggle_mount_with_command(TRUE);
}

void JagsMenuBar::toggle_on_mount(void) {
  toggle_browse(TRUE);
  toggle_mount_and_browse(TRUE);
  toggle_mount(TRUE);
  toggle_mount_with(TRUE);
  toggle_mount_with_command(TRUE);
}


void JagsMenuBar::mount_and_browse_ex(GtkMenuItem *item, gpointer *data) {
  mount(item, data, NULL);
  if (!mount_error)
    browse(item, data, NULL);
}

/* Callbacks */
gint mount_and_browse(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  mount(item, data, jmb);
  if (!mount_error)
    browse(item, data, jmb);
  return TRUE;
}

gint browse(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  JagsConfig *conf = new JagsConfig();
  gchar *server = g_strdup(g_strchomp(server_name));
  g_strup(server);
  gchar *command = g_strdup_printf("%s \"%s/%s/%s\" &", conf->get_browser(), conf->get_mount_dir(), server, share_name);
  if (conf->get_show_debug()) g_print("%s\n", command);
  system(command);
  return TRUE;
}

gint mount(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  JagsConfig *conf = new JagsConfig();
  
  /* Here I use my new mount-class */
  gint result = mmnt->addMount(server_name, share_name);
  if (conf->get_show_debug())
    g_print("result == %d\n", result);
  if (result == OK) {
    mount_error = 0;
    /* Do nothing */
  } else if (result == ERROR) {
    /* Popup mount with here */
    mount_error = 1;
    JagsMountWith *mw = new JagsMountWith(new JagsConfig(), server_name, share_name, jmb, mmnt, mb_mnts_window);
    gint i = mw->get_result();
    if (i) {g_print("debug: %d\n",i);}else{g_print("debug %d\n",i);}
    return TRUE;
  } else {
    mount_error = 0;
    popup_dialog(200, "Error:", "Share probably already mounted...", "Ok");
    return TRUE;
  }
  jmb->toggle_on_mount();
  /* Call jagsmntswindow.addMnt() here */
  gchar *server = g_strdup(server_name);
  g_strup(server);
  gchar *mntpath = g_strdup_printf("%s/%s/%s", conf->get_mount_dir(), server, share_name);
  gchar *mnt = g_strdup_printf("//%s/%s", server, share_name);
  mb_mnts_window->addMount(mnt, mntpath);
  return TRUE;
}

gchar *clean(gchar *s) {
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

gint mount_with_command(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  JagsMountWithCommand *mw = new JagsMountWithCommand(new JagsConfig());
  //   printf("%d\n", mw);
  if (mw) g_print("mount with command: ok\n");
  jmb->toggle_on_mount();
  return TRUE;
}

gint mount_with(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  JagsMountWith *mw = new JagsMountWith(new JagsConfig(), server_name, share_name, jmb, mmnt, mb_mnts_window);
  if (mw) g_print("mount with: ok\n");
  jmb->toggle_on_mount();
  return TRUE;
}


gint preferences(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  JagsPrefsDialog *d = new JagsPrefsDialog((JagsConfig *)data);
  if (d) g_print("prefs dialog: ok\n");
  return TRUE;
}

gint about(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  JagsAbout *a = new JagsAbout();
  if (a) g_print("about: ok\n");
  return TRUE;
}

gint search(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  JagsSearchDialog *d = new JagsSearchDialog(mmnt, jmb);
  if (d) g_print("mount with command: ok\n");
  return TRUE;
}

gint umount(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  mmnt->uMountAll();
  return TRUE;
}

gint mnts_window(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  //  JagsMntsWindow *m = new JagsMntsWindow(mmnt, jmb->conf);
  mb_mnts_window->show();
  return TRUE;
}

gint bookmark_menu(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  //  GtkWidget *menuitem;
    /* Build bookmarks menu from file */    
  //  g_print("%d\n", bookmarks_item->window);

  return TRUE;
}

gint bookmark_add(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  GtkWidget *menuitem;
  g_print("Add bookmark\n");
  /* If we have selected a server, add it to bookmarks */
  if (server_name) {
    gchar *file = g_strdup_printf("%s/.jags/bookmarks", getenv("HOME"));
    ofstream outf(file, ios::app);
    if (outf.good()) {
      outf << server_name << '\n';
      outf.close();
      menuitem = gtk_menu_item_new_with_label_with_pixmap(server_name, "i-bookmark.xpm");
      gtk_widget_show(menuitem);
      gtk_signal_connect(GTK_OBJECT(menuitem), "activate", 
			 GTK_SIGNAL_FUNC(bookmark_selected), NULL);
      gtk_menu_append(GTK_MENU(bookmarks_menu), menuitem);
    }
  }
  return TRUE;
}

gint bookmark_edit(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  GtkWidget *dialog, *scrolled_window, *clist, *button_up;
  GtkWidget *button_down, *button_remove, *button_close;

  g_print("Edit bookmarks: th ereally funny part...\n");
  dialog = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW(dialog), "Edit bookmarks...");
  gtk_widget_set_usize(dialog, 400, 300);

  gchar *titles[1];
  titles[0] = g_strdup("Bookmarks");
  clist = gtk_clist_new_with_titles(1, titles);
  gtk_signal_connect(GTK_OBJECT(clist), "select_row",
		     GTK_SIGNAL_FUNC(edit_bookmarks_selection_made), (gpointer)clist);

  gchar *file = g_strdup_printf("%s/.jags/bookmarks", getenv("HOME"));
  ifstream inf(file);
  while (inf.good()) {
    gchar *buffer = g_new(gchar, 30);
    inf.getline(buffer, 30, '\n');
    if (strlen(buffer) > 0) {
      gchar *buffer2[1];
      buffer2[0] = g_strdup(buffer);
      gtk_clist_append(GTK_CLIST(clist), buffer2);
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


  //gtk_signal_connect
  //  titles[1] = g_strdup("Server-path");
  //  titles[2] = g_strdup("Automount");



  scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window), clist);
  gtk_widget_show(scrolled_window);
  gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->vbox), scrolled_window);

  gtk_widget_show(clist);
  gtk_widget_show_all(dialog);
  return TRUE;
}

gint edit_bookmarks_selection_made(GtkCList *clist, gint row, gint column,
				   GdkEventButton *event, gpointer user_data) {
  bookmarks_selected_row = row;
  return TRUE;
}

gint edit_bookmarks_up(GtkWidget *widget, gpointer data) {
  if ((bookmarks_selected_row != 0) && (bookmarks_selected_row != -1) && 
      (GTK_CLIST(data)->rows > 1)) {
    gtk_clist_swap_rows(GTK_CLIST(data), bookmarks_selected_row, bookmarks_selected_row - 1);
    gtk_clist_unselect_all(GTK_CLIST(data));
  }
  return TRUE;
}

gint edit_bookmarks_down(GtkWidget *widget, gpointer data) {
  if ((bookmarks_selected_row != (GTK_CLIST(data)->rows)-1) && 
      (bookmarks_selected_row != -1) && 
      (GTK_CLIST(data)->rows > 1)) {
    gtk_clist_swap_rows(GTK_CLIST(data), bookmarks_selected_row, bookmarks_selected_row + 1);
    gtk_clist_unselect_all(GTK_CLIST(data));
  }
  return TRUE;
}

gint edit_bookmarks_remove(GtkWidget *widget, gpointer data) {
  gtk_clist_remove(GTK_CLIST(data), bookmarks_selected_row);
  return TRUE;
}


gint edit_bookmarks_close(GtkWidget *widget, gpointer data) {
  GtkWidget *menuitem;

  gchar *file = g_strdup_printf("%s/.jags/bookmarks", getenv("HOME"));
  ofstream of(file);
  for (int i = 0; i < GTK_CLIST(data)->rows; i++) {
    gchar *buffer[1];
    gtk_clist_get_text(GTK_CLIST(data), i, 0, buffer);
    of << buffer[0] << endl;

  }

  gtk_widget_destroy(bookmarks_menu);

  /* Bookmarks-menu */
  bookmarks_menu = gtk_menu_new();
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(bookmarks_item), bookmarks_menu);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Add bookmark", "new_item.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", GTK_SIGNAL_FUNC(bookmark_add), NULL);

  menuitem = gtk_menu_item_new_with_label_with_pixmap("Edit bookmarks...", "settings.xpm");
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_signal_connect (GTK_OBJECT(menuitem), "activate", 
		      GTK_SIGNAL_FUNC(bookmark_edit), NULL);

  menuitem = gtk_menu_item_new ();
  gtk_widget_show (menuitem);
  gtk_container_add (GTK_CONTAINER (bookmarks_menu), menuitem);
  gtk_widget_set_sensitive (menuitem, FALSE);


  ifstream inf(file);
  while (inf.good()) {
    gchar *buffer = g_new(gchar, 30);
    inf.getline(buffer, 30, '\n');
    if (strlen(buffer) > 0) {
      menuitem = gtk_menu_item_new_with_label_with_pixmap(buffer, "i-bookmark.xpm");
      gtk_widget_show(menuitem);
      gtk_container_add(GTK_CONTAINER(bookmarks_menu), menuitem);
      gtk_signal_connect(GTK_OBJECT(menuitem), "activate", 
  			 GTK_SIGNAL_FUNC(bookmark_selected), NULL);
    }
  }
  //  gtk_widget_show(bookmarks_menu);
  
  gtk_widget_destroy(widget->parent->parent->parent);
  return TRUE;
}

gint bookmark_selected(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb) {
  gchar *text = g_strchomp(gtk_menu_item_get_text(GTK_WIDGET(item)));
  menubar_conf->set_searchfor(text);
  menubar_conf->setsearchfor(1);
  JagsSearchDialog *d = new JagsSearchDialog(mmnt, jmb);
  d->set_string(text);
  return TRUE;
}
/* Sample main test function */			      
/*
main(int argc, char *argv[]) {
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
