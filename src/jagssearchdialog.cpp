/*
 **  JagsSearchDialog v0.1
 **  Copyright (C) 2000-2001 Daniel Sundberg
 **
 **  Quote spaces patch by mike@penbex.com.tw
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
 ** jagsmenubar.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Wed Dec 13 16:32:00 2000 Daniel Sundberg 
 ** Last update Mon Mar  5 21:31:00 2001 Daniel Sundberg
 */

#include <string.h>
#include <stdlib.h>
#include "jagssearchdialog.h"
#include "jagsconfig.h"
#include "gtk_common.h"
#include "data.h"
#include "jagsmenubar.h"

gchar *server, *share;
gchar *sclean(gchar *s);
JagsMenuBar *search_menubar;

JagsSearchDialog::JagsSearchDialog(Mount *imnt, JagsMenuBar *imb) {
  mnt = imnt;
  search_menubar = imb;
  //  search_menubar = new JagsMenuBar(gtk_vbox_new(true, 0), new JagsConfig(), mnt);
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_signal_connect(GTK_OBJECT(window), "delete_event", GTK_SIGNAL_FUNC(on_close), NULL);
  gtk_window_set_title(GTK_WINDOW(window), "Search for server...");
  gtk_widget_set_usize(window, 400, 300);

  GtkWidget *table = gtk_table_new(7, 3, false);
  
  GtkWidget *label = gtk_label_new("Search: ");
  gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 0, 1);
  search_string = gtk_entry_new();
  gtk_table_attach_defaults(GTK_TABLE(table), search_string, 1, 2, 0, 1);

  /* I put the button in a box to trick gtk not to draw the button huge */
  GtkWidget *vbox = gtk_vbox_new(false, 10);
  gtk_widget_show(vbox);
  GtkWidget *button = gtk_button_new_with_label_with_pixmap("Search", "search.xpm");
  gtk_box_pack_start(GTK_BOX(vbox), button, true, false, false);
  gtk_table_attach_defaults(GTK_TABLE(table), vbox, 2, 3, 0, 1);
  gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(search_clicked), this);

  /* This gives a wanring but...whatever... */
  scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_table_attach_defaults(GTK_TABLE(table), scrolled_window, 0, 3, 1, 7);
  tree = gtk_tree_new();
  gtk_widget_show(tree);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window), tree);
  
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_signal_connect (GTK_OBJECT(search_string), "activate", GTK_SIGNAL_FUNC(search_clicked), this);
  
  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(table));
  gtk_table_set_row_spacings(GTK_TABLE(table), 5);
  gtk_table_set_col_spacings(GTK_TABLE(table), 5);
  gtk_widget_show(table);
  gtk_widget_show(label);
  gtk_widget_show(search_string);
  gtk_widget_show(button);
  gtk_widget_show(scrolled_window);
  gtk_widget_show(window);
  gtk_widget_grab_focus(search_string);
}

void JagsSearchDialog::set_string(gchar *s) {
  gtk_entry_set_text(GTK_ENTRY(search_string), s);
  search_clicked(gtk_button_new(), this);
}

gint on_close(GtkWidget *widget, JagsSearchDialog *me) {
  gtk_widget_destroy(widget);
  return TRUE;
}

gint search_clicked(GtkWidget *widget, JagsSearchDialog *me) {
  gtk_widget_destroy(me->tree);
  me->tree = gtk_tree_new();
  gtk_widget_show(me->tree);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(me->scrolled_window), me->tree);
  
  gchar *search = g_strdup_printf("%s", gtk_entry_get_text(GTK_ENTRY(me->search_string)));
  if (strlen(search)>0) {
    JagsConfig *conf = new JagsConfig();
    gchar *cmd = g_strdup_printf("search.sh %s", search);
    Data *d = new Data(cmd, conf->get_plugin());
    GList *glist = d->getData();
    /* If we found something */
    if (glist) {
      if (strncmp((gchar *)glist->next->data, "Sorry, can" ,10) == 0) {
	GtkWidget *item = gtk_tree_item_new_with_label((gchar *)glist->next->data);
	gtk_tree_append(GTK_TREE(me->tree),item);
	gtk_widget_show(item);
      } else {
	GtkWidget *item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, "network.xpm");
	gtk_tree_append(GTK_TREE(me->tree),item);
	me->subtree = gtk_tree_new();
	gtk_tree_item_set_subtree(GTK_TREE_ITEM(item), me->subtree);
	gtk_widget_show(item);
	/* Insert the tooltip */
	gtk_signal_connect(GTK_OBJECT(item), "expand", GTK_SIGNAL_FUNC(expandd_server), me);
	gtk_signal_connect(GTK_OBJECT(item), "collapse", GTK_SIGNAL_FUNC(onn_collapse), me);
      }
    }
    
  }
  return TRUE;
}

gint onn_collapse(GtkWidget *item, JagsSearchDialog *mw) {
  GtkWidget *widget = GTK_TREE_ITEM_SUBTREE(item);
  /* Delete most items except from the first */
  if (GTK_TREE(widget)->children) {
    if (GTK_TREE(widget)->children->next) {
    gtk_tree_remove_items(GTK_TREE(widget), GTK_TREE(widget)->children->next);

    GList *glist = GTK_TREE(widget)->children;
    gtk_widget_hide(GTK_WIDGET(glist->data));
    return TRUE; // We did do something
    } else {
      gtk_widget_hide(GTK_WIDGET(GTK_TREE(widget)->children->data));
      return FALSE;
    }
    //    gtk_widget_hide(GTK_WIDGET(GTK_TREE(widget)->children->data));
  } else {

    return TRUE;
  }
}

gint expandd_server(GtkWidget *widget, JagsSearchDialog *mw) {
  GtkWidget *parent_tree = GTK_TREE_ITEM_SUBTREE(widget);

  Data *d;
  GList *glist;
  GtkWidget *item;//, *subtree;
  JagsConfig *conf = new JagsConfig();
  /* Get the text on this treeitem into "workgroup" */
  gchar *server;
  item = GTK_TREE(parent_tree)->tree_owner;
  server = g_strdup_printf("%s", gtk_tree_item_get_text(item));
  //  menubar->set_server_name(server);
  
  //  gchar *s_bar_msg = g_strdup_printf("Listing shares on %s...", server);
  //statusbar->set_text(s_bar_msg);

  gchar *command = g_strdup_printf("list_shares.sh \"%s\" ", server);
  //  mw->debug(g_strdup_printf("Listing shares on %s...", server));
  d = new Data(command, conf->get_plugin());
  //  mw->debug("done!\n");
  glist = d->getData();
  gtk_signal_connect(GTK_OBJECT(parent_tree), "select-child", GTK_SIGNAL_FUNC(onn_share_selected), mw);
  //  gtk_signal_connect(GTK_OBJECT(parent_tree), "", GTK_SIGNAL_FUNC(button_press), parent_tree);
  if (glist) {
    while (glist->next) {
      if (conf->get_hide_ipc_shares()) {
	if (g_strncasecmp("IPC$", (gchar *)glist->next->data, 4)) {
	  item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, "browse.xpm");
	  //	  gtk_signal_connect(GTK_OBJECT(item), "event", GTK_SIGNAL_FUNC(button_press), mw);
	  gtk_signal_connect(GTK_OBJECT(item), "button_press_event", GTK_SIGNAL_FUNC(button_presss), mw);
	  gtk_tree_append(GTK_TREE(parent_tree), item);
	  gtk_widget_show(item);
	  
	}
      } else {
	  item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, "browse.xpm");
	  gtk_signal_connect(GTK_OBJECT(item), "select", GTK_SIGNAL_FUNC(button_presss), mw);
	  gtk_tree_append(GTK_TREE(parent_tree), item);
	  gtk_widget_show(item);

      }
      /* Insert the tooltip */
      //      mw->tooltip(item, "Double click to browse this share\nRight click for menu ");
      
      glist = glist->next;
    }
    //    statusbar->set_text("Share listning finished!");
  }

  /* Remove '+'-sign in front of share or computer if nu sub-items found */
  glist = GTK_TREE(parent_tree)->children;
  if (glist) {
    GtkWidget *item = GTK_WIDGET(glist->data);
    gchar *text = gtk_tree_item_get_text(item);
    if (!g_strncasecmp(text, "rror returning", 13)) {
      //      mw->debug("Found Windows 2000 server with guest account disabled!\n");
      GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
      gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
    }
  } else {
    GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
    gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
  }

  return TRUE;
}

gint onn_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data, JagsSearchDialog *mw) {
  /* Here we get the treeitem where the server name is stored */
  GtkWidget *tree_item = tree->tree_owner;
  server = g_strdup_printf("%s", gtk_tree_item_get_text(tree_item));
  search_menubar->set_server_name(server);
  share = gtk_tree_item_get_text(widget);
  search_menubar->set_share_name(share);
  search_menubar->toggle_on_share_select();
  return TRUE;
}

gint check_dd_click(GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw) {
  if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) {
    gtk_tree_item_expand(GTK_TREE_ITEM(widget));
    return TRUE;
  } else {
    return FALSE;
  }
}

/* Display the popup menu if you press a button on a share. 
   Mount and browse on double klick */
gint button_presss (GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw) {
  if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) {
    /* Mount with the mount-class here */
    search_menubar->mount_and_browse_ex(GTK_MENU_ITEM(gtk_menu_item_new()), NULL);
    return TRUE;
  } else if ((event->type == GDK_BUTTON_PRESS) && (event->button == 3)) {
    /* Take care of right click */
    gtk_tree_item_select(GTK_TREE_ITEM(widget));
    search_menubar->set_share_name(gtk_tree_item_get_text(widget));
    gtk_menu_popup (GTK_MENU(search_menubar->get_popupmenu()), NULL, NULL, NULL, NULL,
		    event->button, event->time);
    return TRUE;
  }

  return FALSE;
}

gchar *sclean(gchar *s) {
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

//main (int argc, char **argv) {
//    gtk_init(&argc, &argv);
//    JagsSearchDialog *d = new JagsSearchDialog();
//    gtk_main();
//  }
