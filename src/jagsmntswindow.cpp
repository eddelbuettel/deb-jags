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

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "jagsmntswindow.h"
#include "gtk_common.h"

GtkWidget *mnts_window_clist;
GtkWidget *mnts_window_local;
GtkWidget *mnts_window_popup_menu;
GtkWidget *mnts_window_file_selector;
gint selected_row, selected_col;
JagsConfig *mnts_win_conf = NULL;
Mount *mnts_window_mnt;
gboolean sel_set = false;

gint mnts_win_dir_selected(GtkWidget *selector, gpointer *user_data);
gint file_select_destroy(GtkWidget *selector, gpointer *user_data);

JagsMntsWindow::JagsMntsWindow(Mount *imnt, JagsConfig *iconf)
{
  GtkWidget *window, *scrolled_window, *vbox, *handle_box, *toolbar, *icon;
  GtkWidget *item;

  mnts_window_mnt = imnt;
  mnts_win_conf = iconf;
  actual_mounts = g_list_alloc();

  /* Setup the window */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Mounted shares...");
  gtk_widget_set_usize(window, 600, 400);
  gtk_signal_connect(GTK_OBJECT(window), "delete_event", 
		     GTK_SIGNAL_FUNC(close_mntswindow), this); 

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
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Close", "Close this window", 
			  "Private", icon, GTK_SIGNAL_FUNC(close_mntswindow), this);
  icon = gtk_icon2widget("browse.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Browse", "Browse this share", 
			  "Private", icon, GTK_SIGNAL_FUNC(mnts_browse), this);
  icon = gtk_icon2widget("mount.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Automount", 
			  "Remount selected share next\ntime jag is started", 
			  "Private", icon, GTK_SIGNAL_FUNC(toggle_automount), this);
  icon = gtk_icon2widget("unmount.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Unmount", "Unmount this share", 
			  "Private", icon, GTK_SIGNAL_FUNC(unmount_share), this);
  icon = gtk_icon2widget("browse.xpm", toolbar);
  gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "Mountpath", "Change mount path", 
			  "Private", icon, GTK_SIGNAL_FUNC(change_mnt_path), this);
  
  gtk_widget_show(toolbar);
  gtk_container_add(GTK_CONTAINER(handle_box), toolbar);

  /* Setup scrolled window */
  scrolled_window = gtk_scrolled_window_new((GtkAdjustment *)NULL, 
					    (GtkAdjustment *)NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), 
				 GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
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
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window), 
					mnts_window_clist);
  gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, true, true, 0);  

  /* Setup the popup-menu */
  mnts_window_popup_menu = gtk_menu_new();

  item = gtk_menu_item_new_with_label_with_pixmap("Browse...", "browse.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER(mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", 
		     GTK_SIGNAL_FUNC(mnts_browse), this);

  item = gtk_menu_item_new();
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER(mnts_window_popup_menu), item);

  item = gtk_menu_item_new_with_label_with_pixmap("Toggle automount", "mount.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER (mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", 
		     GTK_SIGNAL_FUNC(toggle_automount), this);

  item = gtk_menu_item_new_with_label_with_pixmap("Unmount this share", 
						  "unmount.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER (mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", 
		     GTK_SIGNAL_FUNC(unmount_share), this);

  item = gtk_menu_item_new();
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER(mnts_window_popup_menu), item);

  item = gtk_menu_item_new_with_label_with_pixmap("Change mount path...", 
						  "browse.xpm");
  gtk_widget_show(item);
  gtk_container_add(GTK_CONTAINER (mnts_window_popup_menu), item);
  gtk_signal_connect(GTK_OBJECT(item), "activate", 
		     GTK_SIGNAL_FUNC(change_mnt_path), this);
   
  mnts_window_local = window;
  update();
}

void JagsMntsWindow::update_from_kernel(void)
{
  char *cmd, *file,*path;
  path = getenv("HOME");
  gchar *buffer = new gchar[250];
  gchar *mnt  = new gchar[250];
  gchar *mntpath  = new gchar[250];
  gint i, j;
  GList *glist = g_list_copy(mnts_win_conf->get_mnts());

  //--------------check if the share was already mounted------------------
  //---------------kernel mount check--------------------------------
  g_print("Adding allready mounted shares\n");
  cmd = g_strdup_printf("sh %s/.jags/plugins/%s/ls_mnts_load.sh > %s/.jags/outfile",path, mnts_win_conf->get_plugin(), path);
  system(cmd);
  file = g_strdup_printf("%s/.jags/outfile", path);
  ifstream onf(file);
  while (onf.good()) {
    i=0; 
    j=0;
    onf.getline(buffer, 250, '\n');
    if ((buffer[0]==0) || (buffer[0]=='\n')) break;
    while (buffer[i]!=' ') {
      mnt[j]=buffer[i];
      i++; 
      j++;
    }
    mnt[j]=0;
    
    i++;
    j=0;
    while (1) {
      if ((buffer[i]=='\n') || (buffer[i]==0)) break;
      mntpath[j]=buffer[i];
      i++; 
      j++;
    }
    mntpath[j]=0;
    if (mnts_win_conf->get_nMnts() > 0)
      if (g_list_find_custom(glist->next, 
			     (gpointer)mnt, 
			     (GCompareFunc)g_strcasecmp)) {	
	addMount(mnt, mntpath,1);	}
      else 
	addMount(mnt, mntpath,0);
    else
      addMount(mnt, mntpath,0);

    mnts_window_mnt->mounts = g_list_append(mnts_window_mnt->mounts, 
					    (gpointer)g_strdup(mntpath)); 
    actual_mounts = g_list_append(actual_mounts, (gpointer)g_strdup(mnt)); 
  }

  g_free(file);
  delete [] mnt;
  delete [] mntpath;
  delete [] buffer;
}

void JagsMntsWindow::update(void)
{
  GList *glist = NULL;
  gchar *content[3];

  if (mnts_win_conf->get_show_debug()) 
    g_print("Opening mounted shares window...\n");

  update_from_kernel();										//actual_mounts get initialized here
  
  if (mnts_win_conf->get_nMnts() > 0) {
    glist = g_list_copy(mnts_win_conf->get_mnts());
    
    while (glist->next->next) {
      if (mnts_win_conf->get_show_debug()) 
	g_print("Premounting: %s into %s: ", (gchar *)glist->next->data, 
		(gchar *)glist->next->next->data);
      if (g_list_find_custom(actual_mounts->next, 
			     (gpointer)glist->next->data, 
			     (GCompareFunc)g_strcasecmp)) {
	if (mnts_win_conf->get_show_debug()) 
	  g_print("allready mounted from previous action\n");	}
      else {
	if (mnts_win_conf->get_show_debug()) g_print("\n");
	/* Mount this server */
	mnts_window_mnt->addMountWithPath((gchar *)glist->next->data, 
					  (gchar *)glist->next->next->data);
	/* Add it to clist here */
	content[0] = g_strdup((gchar *)glist->next->next->data);
	content[1] = g_strdup((gchar *)glist->next->data);
	content[2] = g_strdup("Yes");
	gtk_clist_append(GTK_CLIST(mnts_window_clist), content);
      }
      if (glist->next->next->next) 
	glist = glist->next->next;
      else 
	break;
    }
  } else {
    if (mnts_win_conf->get_show_debug()) g_print("No shares to premount\n");
  }
}

void JagsMntsWindow::show(void)
{
  gtk_widget_show(mnts_window_local);
}

void JagsMntsWindow::addMount(gchar *mnt, gchar *mntpath, gint i)
{
  gchar *content[3];

  content[0] = g_strdup(mntpath);
  content[1] = g_strdup(mnt);
  if (i) { 
    content[2] = g_strdup("Yes");	
  } else {
    content[2] = g_strdup("No");
  }

  gtk_clist_append(GTK_CLIST(mnts_window_clist), content);
}

void JagsMntsWindow::clear_list()
{
  gtk_clist_clear(GTK_CLIST(mnts_window_clist));
}


gint mnts_browse(GtkWidget *widget, JagsMntsWindow *me)
{
  gchar *content[3];
  gchar *command = NULL;

  if (sel_set) {
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, content);
    //  g_print("%s,%s,%s\n", content[0], content[1], content[2]);
    command = g_strdup_printf("%s \"%s\" &", mnts_win_conf->get_browser(), 
			      content[0]);
    if (mnts_win_conf->get_show_debug()) g_print("%s\n", command);
    system(command);
  } else {
    popup_dialog(200, "Warning!", "Select a row before browsing!", 
		 "Ok");
  }
  return TRUE;
}

void selection_made(GtkWidget *clist, gint irow, gint column, GdkEventButton *event, gpointer data, JagsMntsWindow *me)
{
  selected_row = irow;
  selected_col = column;
  sel_set = true;
  //  g_print("(row, col) == (%d, %d)\n", selected_row, selected_col);
  return;
}

/* Display the popup menu if you press a button on a share. Mount and browse on double click */

gint mw_button_press(GtkWidget *widget, GdkEventButton *event, JagsMntsWindow *me)
{
  if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) {
    /* Browse here */
    mnts_browse(widget, me);
    return TRUE;
  } else if ((event->type == GDK_BUTTON_PRESS) && (event->button == 3)) {
    /* Take care of right click */
    gtk_menu_popup(GTK_MENU(mnts_window_popup_menu), NULL, NULL, NULL, 
		   NULL, event->button, event->time);
    return TRUE;
  }
  return FALSE;
}

gint close_mntswindow(GtkWidget *widget, JagsMntsWindow *me)
{
  gtk_widget_hide(mnts_window_local);
  return TRUE;
}

gint toggle_automount(GtkWidget *widget, JagsMntsWindow *me)
{
  gchar *content[3], *mnt[1], *mntpath[1];
 
  if (sel_set) {
    /* Write or remove selected share from config */
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 2, content);
    if (g_strcasecmp("Yes", content[0]) == 0) {
      /* delete share from config */
      gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 1, mnt);
      gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, mntpath);
      //    g_print("delMnt(%s, %s).....mnts_win_conf == \n", mnt[0], mntpath[0]);
      
      mnts_win_conf->delMnt(mnt[0]);
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
    popup_dialog(200, "Warning!", "Please select a before you do this!", "Ok");
  }

  return TRUE;
}

gint unmount_share(GtkWidget *widget, JagsMntsWindow *me)
{
  gchar *mntpath = NULL;

  if (sel_set) {
    /* Ummount selected share */
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, &mntpath);
    mnts_window_mnt->rmMount(&mntpath[0]);
    gtk_clist_remove(GTK_CLIST(mnts_window_clist), selected_row); 
  } else {
    popup_dialog(200, "Warning!", "You better select a row first!", "Ok");
  }
  return TRUE;
}


/*  For now I'll use a fileselection dialog to find out the new mount-path */
gint change_mnt_path(GtkWidget *widget, JagsMntsWindow *me)
{
  if (sel_set) {
    /* Create the selector */
    mnts_window_file_selector = gtk_file_selection_new("Select a new mount-point");
    gtk_signal_connect(
      GTK_OBJECT(GTK_FILE_SELECTION(mnts_window_file_selector)->ok_button),
      "clicked", GTK_SIGNAL_FUNC(mnts_win_dir_selected), NULL);
    /* Ensure that the dialog box is destroyed when the user clicks a button. */
    gtk_signal_connect_object(
      GTK_OBJECT(GTK_FILE_SELECTION(mnts_window_file_selector)->ok_button),
      "clicked", GTK_SIGNAL_FUNC(file_select_destroy), NULL);

    gtk_signal_connect_object(
      GTK_OBJECT(GTK_FILE_SELECTION(mnts_window_file_selector)->cancel_button),
      "clicked", GTK_SIGNAL_FUNC(file_select_destroy), NULL);
    gtk_widget_show(mnts_window_file_selector);
  } else {
    popup_dialog(200, "Warning!", "You better select a row first!", "Ok");
  }
  return TRUE;
}

/* Here is the actual change of mount path done  */
gint mnts_win_dir_selected(GtkWidget *selector, gpointer *user_data)
{
  gchar *selected_file, *automnt[1], *mnt[1], *mntpath[1];//, *cmd, *path;

  selected_file = gtk_file_selection_get_filename(GTK_FILE_SELECTION(mnts_window_file_selector));
  g_print("filename == %s\n", selected_file);
  if (strlen(selected_file) <= 1) {
    /* This will probably never happen unless you choose the root-dir */
    popup_dialog(150, "Warning!", "You better select a directory!", "Ok");
  } else {
    g_print("Changing mount path to \"%s\"\n", selected_file);
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 0, mntpath);
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 1, mnt);
    gtk_clist_get_text(GTK_CLIST(mnts_window_clist), selected_row, 2, automnt);
    /* Determine if this is an automounted share */

    if (g_strcasecmp("Yes", automnt[0]) == 0) {
      /* If we're dealing with an automounted share we must write to cfg file */
      mnts_win_conf->delMnt(mnt[0]);
      mnts_win_conf->addMnt(mnt[0], selected_file);
    }

    /* If this is just a mounted share, unmount and mount it again in the new place */
    mnts_window_mnt->rmMount(mnt[0]);
    mnts_window_mnt->addMountWithPath(mnt[0], selected_file);
    gtk_clist_set_text(GTK_CLIST(mnts_window_clist), selected_row, 0, selected_file);
  }
  return FALSE;
}


gint file_select_destroy(GtkWidget *selector, gpointer *user_data)
{
  gtk_widget_destroy(GTK_WIDGET(mnts_window_file_selector));

  return TRUE;
}

JagsMntsWindow::~JagsMntsWindow()
{
  g_list_free(actual_mounts);
}
