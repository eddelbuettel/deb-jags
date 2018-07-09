/*
 **  JagsMntsWindow v0.1
 **  Copyright (C) 2001 Daniel Sundberg
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
 ** jagsmntswindow.cpp
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Thu Mar 22 14:59:00 2001 Daniel Sundberg 
 ** Last update Fri May  4 25:53:00 2001 Daniel Sundberg 
 */

#include <stdlib.h>
#include <string.h>
#include "jagsmntswindow.h"
#include "gtk_common.h"

GtkWidget *mnts_window_clist;
GtkWidget *mnts_window_local;
GtkWidget *mnts_window_popup_menu;
GtkWidget *mnts_window_file_selector;
gint selected_row, selected_col;
JagsConfig *mnts_win_conf;
Mount *mnts_window_mnt;
gboolean sel_set = false;

gint mnts_win_dir_selected(GtkWidget *selector, gpointer *user_data);
gint file_select_destroy(GtkWidget *selector, gpointer *user_data);

JagsMntsWindow::JagsMntsWindow(Mount *imnt, JagsConfig *iconf) {
  GtkWidget *window, *scrolled_window, *vbox, *handle_box, *toolbar, *icon;
  GtkWidget *item;//, *menu;
  mnts_window_mnt = imnt;
  mnts_win_conf = iconf;

  /* Setup the window */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Mounted shares...");
  gtk_widget_set_usize(window, 600, 400);
  gtk_signal_connect(GTK_OBJECT(window), "delete_event",
		     GTK_SIGNAL_FUNC(close_mntswindow), NULL); 

  //  gtk_signal_connect (GTK_OBJECT(window), "destroy",
  //			GTK_SIGNAL_FUNC(close_mntswindow), NULL);

  /* Setup vbox */
  vbox = gtk_vbox_new(false, 1);
  gtk_widget_show(vbox);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  /* Setup handle-box */
  handle_box = gtk_handle_box_new();
  gtk_box_pack_start(GTK_BOX(vbox), handle_box, false, false, 0);
  gtk_widget_show(handle_box);

  /* Setup toolbar */
  toolbar = gtk_toolbar_new(GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH);
  icon = gtk_icon2widget("exit.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Close", 
			  "Close this window", "Private", 
			  icon, GTK_SIGNAL_FUNC(close_mntswindow), NULL);
  icon = gtk_icon2widget("browse.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Browse", 
			  "Browse this share", "Private", 
			  icon, GTK_SIGNAL_FUNC(mnts_browse), NULL);
  icon = gtk_icon2widget("mount.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Toggle\nAutomount", 
			  "Remount selected share next\ntime jag is started", "Private", 
			  icon, GTK_SIGNAL_FUNC(toggle_automount), NULL);
  icon = gtk_icon2widget("unmount.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Unmount", 
			  "Unmount this share", "Private", 
			  icon, GTK_SIGNAL_FUNC(unmount_share), NULL);
  icon = gtk_icon2widget("browse.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Mountpath", 
			  "Change mount path", "Private", 
			  icon, GTK_SIGNAL_FUNC(change_mnt_path), NULL);
  
  gtk_widget_show(toolbar);
  gtk_container_add(GTK_CONTAINER(handle_box), toolbar);

  /* Setup scrolled window */
  scrolled_window = gtk_scrolled_window_new((GtkAdjustment *)NULL, (GtkAdjustment *)NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_widget_show(scrolled_window);

  /* Setup clist */
  gchar *titles[3];
  titles[0] = g_strdup("Mount path");
  titles[1] = g_strdup("Server-path");
  titles[2] = g_strdup("Automount");

  mnts_window_clist = gtk_clist_new_with_titles(3, titles);
  gtk_clist_set_column_width(GTK_CLIST(mnts_window_clist), 0, 250);
  gtk_clist_set_column_width(GTK_CLIST(mnts_window_clist), 1, 250);
  gtk_signal_connect(GTK_OBJECT(mnts_window_clist), "select_row",
		     GTK_SIGNAL_FUNC(selection_made), NULL);
  gtk_signal_connect(GTK_OBJECT(mnts_window_clist), "button_press_event",
		     GTK_SIGNAL_FUNC(mw_button_press), NULL); 

  gtk_widget_show(mnts_window_clist);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window), mnts_window_clist);
  gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, true, true, 0);  

  /* Setup the popup-menu */
  mnts_window_popup_menu = gtk_menu_new();

  item = gtk_menu_item_new_with_label_with_pixmap("Browse...", "browse.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER(mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", GTK_SIGNAL_FUNC(mnts_browse), NULL);

  item = gtk_menu_item_new();
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER(mnts_window_popup_menu), item);

  item = gtk_menu_item_new_with_label_with_pixmap("Toggle automount", "mount.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER (mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", GTK_SIGNAL_FUNC(toggle_automount), NULL);

  item = gtk_menu_item_new_with_label_with_pixmap("Unmount this share", "unmount.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER (mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", GTK_SIGNAL_FUNC(unmount_share), NULL);

  item = gtk_menu_item_new();
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER(mnts_window_popup_menu), item);

  item = gtk_menu_item_new_with_label_with_pixmap("Change mount path...", "browse.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER (mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", GTK_SIGNAL_FUNC(change_mnt_path), NULL);
   
  mnts_window_local = window;
  update();
}

void JagsMntsWindow::update(void) {
  JagsConfig *conf = new JagsConfig();
  GList *glist = NULL;
  if (conf->get_show_debug()) g_print("Opening mounted shares window\n");
  if (conf->get_nMnts() > 0) {
    glist = g_list_copy(conf->get_mnts());
  } else {
    if (conf->get_show_debug()) g_print("No shares to premount\n");
  }
  if (conf->get_nMnts() > 0) {
    while (glist->next->next) {
      if (conf->get_show_debug())
	g_print("%s, %s\n", (gchar *)glist->next->data, (gchar *)glist->next->next->data);
      /* Mount this server */
      mnts_window_mnt->addMountWithPath((gchar *)glist->next->data, (gchar *)glist->next->next->data);
      /* Add it to clist here */
      gchar *content[3];
      content[0] = g_strdup((gchar *)glist->next->next->data);
      content[1] = g_strdup((gchar *)glist->next->data);
      content[2] = g_strdup("Yes");
      gtk_clist_append(GTK_CLIST(mnts_window_clist), content);
      if (glist->next->next->next)
        glist = glist->next->next;
      else 
        break;
    }
  }
}

void JagsMntsWindow::show(void) {
  gtk_widget_show(mnts_window_local);
}

void JagsMntsWindow::addMount(gchar *mnt, gchar *mntpath) {
  gchar *content[3];
  content[0] = g_strdup(mntpath);
  content[1] = g_strdup(mnt);
  content[2] = g_strdup("No");

  gtk_clist_append(GTK_CLIST(mnts_window_clist), content);
}

gint mnts_browse(GtkWidget *widget, JagsMntsWindow *me) {
  if (sel_set) {
    gchar *content[3];
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, content);
    //  g_print("%s,%s,%s\n", content[0], content[1], content[2]);
    gchar *command = g_strdup_printf("%s \"%s\" &", mnts_win_conf->get_browser(), 
				     content[0]);
    if (mnts_win_conf->get_show_debug()) g_print("%s\n", command);
    system(command);
  } else {
    popup_dialog(200, "Warning!", "You better select a row first!", "Ok, I'll do that");
  }
  return TRUE;
}

void selection_made(GtkWidget *clist, gint irow, gint column, 
		    GdkEventButton *event, gpointer data, JagsMntsWindow *me) {
  selected_row = irow;
  selected_col = column;
  sel_set = true;
  //  g_print("(row, col) == (%d, %d)\n", selected_row, selected_col);
  return;
}

/* Display the popup menu if you press a button on a share. 
   Mount and browse on double klick */
gint mw_button_press(GtkWidget *widget, GdkEventButton *event, JagsMntsWindow *me) {
  if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) {
    /* Browse here */
    mnts_browse(widget, me);
    return TRUE;
  } else if ((event->type == GDK_BUTTON_PRESS) && (event->button == 3)) {
    /* Take care of right click */
    gtk_menu_popup(GTK_MENU(mnts_window_popup_menu), NULL, NULL, NULL, NULL,
		    event->button, event->time);
    return TRUE;
  }
  return FALSE;
}

gint close_mntswindow(GtkWidget *widget, JagsMntsWindow *me) {
  gtk_widget_hide(mnts_window_local);
  return TRUE;
}

gint toggle_automount(GtkWidget *widget, JagsMntsWindow *me) {
  if (sel_set) {
    /* Write or remove selected share from config */
    gchar *content[3], *mnt[1], *mntpath[1];
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 2, content);
    if (g_strcasecmp("Yes", content[0]) == 0) {
      /* delete share from config */
      gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 1, mnt);
      gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, mntpath);
      //    g_print("delMnt(%s, %s).....mnts_win_conf == \n", mnt[0], mntpath[0]);
      
      mnts_win_conf->delMnt(mnt[0], mntpath[0]);
      gtk_clist_set_text(GTK_CLIST(mnts_window_clist), selected_row, 2, "No");
    } else {
      /* add this share to config */
      gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 1, mnt);
      gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, mntpath);
      //    g_print("%s   %s\n", mnt[0], mntpath[0]);
      mnts_win_conf->addMnt(mnt[0], mntpath[0]);
      gtk_clist_set_text(GTK_CLIST(mnts_window_clist), selected_row, 2, "Yes");
    }
  } else {
    popup_dialog(200, "Warning!", "You better select a row first!", "Ok, I'll do that");
  }
  return TRUE;
}

gint unmount_share(GtkWidget *widget, JagsMntsWindow *me) {
  if (sel_set) {
    /* Ummount selected share */
    gchar *mntpath[1], *cmd;
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, mntpath);
    g_print("%s\n", mntpath[0]);
    cmd = g_strdup_printf("sh %s/.jags/plugins/%s/umount.sh \"%s\"", getenv("HOME"), 
			mnts_win_conf->get_plugin(), mntpath[0]);
    system(cmd);
    gtk_clist_remove(GTK_CLIST(mnts_window_clist), selected_row);
  } else {
    popup_dialog(200, "Warning!", "You better select a row first!", "Ok, I'll do that");
  }
  return TRUE;
}

/*
 * For now I'll use a fileselection dialog to find out the new mount-path 
 */
gint change_mnt_path(GtkWidget *widget, JagsMntsWindow *me) {
  if (sel_set) {
    /* Create the selector */
    mnts_window_file_selector = gtk_file_selection_new("Select a new mount-point");
    gtk_signal_connect(GTK_OBJECT(GTK_FILE_SELECTION(mnts_window_file_selector)->ok_button),
		       "clicked", GTK_SIGNAL_FUNC(mnts_win_dir_selected), NULL);
    /* Ensure that the dialog box is destroyed when the user clicks a button. */
    gtk_signal_connect_object(GTK_OBJECT(GTK_FILE_SELECTION(mnts_window_file_selector)->ok_button),
			      "clicked", GTK_SIGNAL_FUNC(file_select_destroy), NULL);

    gtk_signal_connect_object(GTK_OBJECT(GTK_FILE_SELECTION(mnts_window_file_selector)->cancel_button),
			      "clicked", GTK_SIGNAL_FUNC(file_select_destroy), NULL);
    gtk_widget_show(mnts_window_file_selector);
  } else {
    popup_dialog(200, "Warning!", "You better select a row first!", "Ok, I'll do that");
  }
  return TRUE;
}

/*
 * Here is the actual change of mount path done 
 */
gint mnts_win_dir_selected(GtkWidget *selector, gpointer *user_data) {
  gchar *selected_file, *automnt[1], *mnt[1], *mntpath[1];//, *cmd, *path;
  selected_file = gtk_file_selection_get_filename(GTK_FILE_SELECTION(mnts_window_file_selector));
  g_print("filename == %s\n", selected_file);
  if (strlen(selected_file) <= 1) {
    /* This will probably never happen unless you choose the root-dir */
    popup_dialog(150, "Warning!", "You better select a directory!", "Ok, I'll do that");
  } else {
    g_print("Changing mount path to \"%s\"\n", selected_file);
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, mntpath);
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 1, mnt);
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 2, automnt);
    /* Determine if this is an automounted share */

    if (g_strcasecmp("Yes", automnt[0]) == 0) {
      /* If we're dealing with an automounted share we must write to cfg file */
      mnts_win_conf->delMnt(mnt[0], mntpath[0]);
      mnts_win_conf->addMnt(mnt[0], selected_file);
    }

    /* If this is just a mounted share, unmount and mount it again in the new place */
    mnts_window_mnt->rmMount(mnt[0]);
    mnts_window_mnt->addMountWithPath(mnt[0], selected_file);
    gtk_clist_set_text(GTK_CLIST(mnts_window_clist), selected_row, 0, selected_file);
  }
  return FALSE;
}

gint file_select_destroy(GtkWidget *selector, gpointer *user_data) {
  gtk_widget_destroy(GTK_WIDGET(mnts_window_file_selector));
  return TRUE;
}
