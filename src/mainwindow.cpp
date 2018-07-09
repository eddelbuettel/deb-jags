/*
 **  Jags v0.1 
 **  Copyright (C) 2000 Daniel Sundberg
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
 ** mainwindow.cpp 0.1
 **
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Mon Jul  3 20:00:00 2000 Daniel Sundberg 
 ** Last update Mon Mar  5 21:31:00 2001 Daniel Sundberg
 */

#include <gtk/gtk.h>
#include <fstream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "jagsstatusbar.h"
#include "jagsmenubar.h"
#include "jagssearchdialog.h"
#include "jagsmountwith.h"
#include "jagsconfig.h"
#include "mount.h"
#include "jags.h"
#include "data.h"
#include "gtk_common.h"
#include "mount.h"

class MainWindow{
private:
  /* Callbacks */
  friend gint on_collapse(GtkWidget *item, MainWindow *mw);
  friend gint expand_network(GtkWidget *widget, MainWindow *mw);
  friend gint expand_workgroup(GtkWidget *widget, MainWindow *mw);
  friend gint expand_server(GtkWidget *widget, MainWindow *mw);
  friend gint on_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data, MainWindow *mw);
  
  friend gint check_d_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw);
  friend gint button_press(GtkWidget *, GdkEventButton *, MainWindow *mw);
  void debug(gchar *txt);
  void tooltip(GtkWidget *widget, gchar *txt);
public:
  MainWindow(int argc, char *argv[]);
  ~MainWindow();
  void run(void);
};

//static gint on_collapse(GtkWidget *widget);

static JagsStatusBar *statusbar;
JagsConfig *conf;
JagsMenuBar *menubar;

MainWindow::MainWindow(int argc, char *argv[]) {
  GtkWidget *window, *vbox, *scrolled_win, *tree, *item, *subtree;
  gboolean nowindows = false;
  
  conf = new JagsConfig();
  Mount *mnt = new Mount(conf);  

  for (int i = 1; i < argc; i++) {
    if (argv[i+1] != NULL) {
      if (strcmp(argv[i],"-c")==0) {
	g_print("Will open search dialog for %s\n", argv[i+1]);
	conf->set_searchfor(argv[i+1]);
	conf->setsearchfor(1);
      } 
      if (strcmp(argv[i],"--nowindows")==0) {
	g_print("Starting jags in nowindows mode\n");
	nowindows = true;
      } 

    } else if ((strcmp(argv[i],"-h")==0) || (strcmp(argv[i],"--help")==0)) {
      g_print("\n(C) Daniel Sundberg 2000-2001\n");
      g_print("E-mail: dansun-8@student.luth.se\n");
      g_print("http://sumpan.campus.luth.se/software/jags\n\n");
      g_print("This is free software, free as in speach AND beer.\n\n");
      g_print("Command line options:\n");
      g_print("-c [SERVER]    : Server to search for\n");
      g_print("--nowindows    : Just mount shares in config-file.\n");
      g_print("                 Do not show Jags main-window.\n");
      g_print("-h --help      : This help screen\n\n");
      exit(0);
    } else if (strcmp(argv[i],"--nowindows")==0) {
      g_print("Starting jags in nowindows mode\n");
      nowindows = true;
    } 
 
  }

  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
  char *buffer = new char[100];
  sprintf(buffer, "%s v%s", PROGRAM_NAME, VERSION);
  gtk_window_set_title(GTK_WINDOW(window), buffer);
  gtk_signal_connect(GTK_OBJECT(window), "delete_event", GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
  
  /* Fix the box */
  vbox=gtk_vbox_new(FALSE, 5);
  gtk_container_set_border_width(GTK_CONTAINER(vbox), 2);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show(vbox);

  /* Add the menubar to the program */
  menubar = new JagsMenuBar(vbox, conf, mnt);
  if (nowindows) { exit(0); }
  menubar->toggle_greyall();
  
  /* A generic scrolled window */
  scrolled_win = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(scrolled_win),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_widget_set_usize (scrolled_win, 500, 400);
  gtk_box_pack_start(GTK_BOX(vbox), scrolled_win, TRUE, TRUE, 0);
  gtk_widget_show (scrolled_win);
  
  statusbar = new JagsStatusBar(vbox);
  statusbar->set_text(buffer);

  /* Create the root tree */
  tree = gtk_tree_new();

  /* Add it to the scrolled window */
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_win), tree);

  /* Setup the tree */
  item = gtk_tree_item_new_with_label_with_pixmap("Network", "network.xpm");

  /* Insert the tooltip */
  if (conf->get_show_tooltips()) {
    GtkTooltips *tooltip = gtk_tooltips_new();
    gtk_tooltips_set_tip(tooltip, item, "Click on the '+' to expand the network-view", NULL);
  }

  gtk_tree_append(GTK_TREE(tree), item);
  gtk_widget_show(item);
  subtree = gtk_tree_new();
  gtk_tree_item_set_subtree(GTK_TREE_ITEM(item), subtree);
  gtk_widget_show(subtree);
  gtk_signal_connect(GTK_OBJECT(item), "expand", GTK_SIGNAL_FUNC(expand_network), subtree);
  gtk_signal_connect(GTK_OBJECT(item), "collapse", GTK_SIGNAL_FUNC(on_collapse), subtree);
  gtk_signal_connect(GTK_OBJECT(item), "button_press_event", GTK_SIGNAL_FUNC(check_d_click), NULL);

  gtk_widget_show(tree);
  gtk_widget_show(window);
  if (conf->searchisset()) {
    gchar *s = g_strdup_printf("%s", conf->get_searchfor());
    g_print("Will open search dialog...%s\n", s);
    JagsSearchDialog *sd = new JagsSearchDialog(mnt, menubar);
    sd->set_string(s);
  }
}

MainWindow::~MainWindow() {
  
}


/* Modified...now we just hide the first item in the tree, 
   we remove the rest, this will cause a much smaller memory 
   leak than when we were hiding all sub-items */
gint on_collapse(GtkWidget *item, MainWindow *mw) {
  GtkWidget *widget = GTK_TREE_ITEM_SUBTREE(item);
  /* Delete most items except from the first */
  if (GTK_TREE(widget)->children) {
    if (GTK_TREE(widget)->children->next) {
    gtk_tree_remove_items(GTK_TREE(widget), GTK_TREE(widget)->children->next);
    GList *glist = GTK_TREE(widget)->children;
    gtk_widget_hide(GTK_WIDGET(glist->data));
    
    return TRUE; // We did do something
    } else {
      return FALSE;
    }
  } else {
    return FALSE;
  }
}

/* This happens when you expand the root network tree */
gint expand_network(GtkWidget *widget, MainWindow *mw) {
  GtkWidget *parent_tree = GTK_TREE_ITEM_SUBTREE(widget);

  Data *d;
  GList *glist;
  GtkWidget *item, *subtree;

  /* First reload config... */
  conf->reload();

  /* First get masterbrowser, this should put the ip of your masterbrowser 
     int the file ~/.jags/outfile */
  gchar *s_bar_msg = g_strdup_printf("Fetching masterbrowser ip for %s...", conf->get_workgroup());
  statusbar->set_text(s_bar_msg);
  
  mw->debug(g_strdup_printf("%s\n", s_bar_msg));

  /* Get the masterbrowser into a Data-object */

  gchar *command = g_strdup_printf("fetch_master_browser.sh \"%s\"", conf->get_workgroup());
  d = new Data(command, conf->get_plugin()); 
  glist = d->getData();

  mw->debug(g_strdup_printf("Found masterbrowser....%s\nNow trying to list workgroups...", (gchar *)glist->next->data));
  
  /* Now we have the data stored in d */
  if (glist) {
    command = g_strdup_printf("list_workgroups.sh \"%s\"", (gchar *)glist->next->data);
    d = new Data(command, conf->get_plugin());
    glist = d->getData();
    if (glist) {
      while (glist->next) {
	item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, "network.xpm");
	gtk_tree_append(GTK_TREE(parent_tree),item);
	subtree = gtk_tree_new();
	gtk_tree_item_set_subtree(GTK_TREE_ITEM(item), subtree);
	gtk_widget_show(item);
	/* Insert the tooltip */
	mw->tooltip(item, "Click on the '+' to expand the workgroup");
	gtk_signal_connect(GTK_OBJECT(item), "expand", GTK_SIGNAL_FUNC(expand_workgroup), subtree);
	gtk_signal_connect(GTK_OBJECT(item), "collapse", GTK_SIGNAL_FUNC(on_collapse), NULL);
	glist = glist->next;
      }
      mw->debug("done!\n");
      statusbar->set_text("Workgroups listning finished!");
    }
  } else {
    statusbar->set_text("Could not list workgroups");
    mw->debug("check ~/.jags/outfile\n");
  }

  return TRUE;
}

/* This happens when you expand a workgroup */
gint expand_workgroup(GtkWidget *widget, MainWindow *mw) {
  GtkWidget *parent_tree = GTK_TREE_ITEM_SUBTREE(widget);
  Data *d;
  GList *glist;
  GtkWidget *item, *subtree;

  if (GTK_TREE(parent_tree)->children) 
    gtk_tree_remove_items(GTK_TREE(parent_tree), GTK_TREE(parent_tree)->children->next);
  

  /* Get the text on this treeitem into "workgroup" */
  gchar *workgroup;
  item = GTK_TREE(parent_tree)->tree_owner;
  workgroup = g_strdup_printf("%s", gtk_tree_item_get_text(item));
  //  gchar *s_bar_msg = g_strdup_printf("Fetching masterbrowser ip for %s...", workgroup);
  
  /* Get the masterbrowser into a Data-object */
  gchar *command = g_strdup_printf("fetch_master_browser.sh \"%s\"", workgroup);
  mw->debug(g_strdup_printf("Fetching masterbrowser for %s...", workgroup));
  d = new Data(command, conf->get_plugin()); 
  glist = d->getData();
  
  /* Now we have the masterbrowser stored in d, just the same as above 
     but with another command sent to the Data-class */
  if (glist) {
    mw->debug(g_strdup_printf("%s\n", (gchar *)glist->next->data));
    command = g_strdup_printf("list_servers.sh \"%s\"", (gchar *)glist->next->data);
    mw->debug(g_strdup_printf("Listing servers in %s...", workgroup));
    d = new Data(command, conf->get_plugin());
    glist = d->getData();
    mw->debug("done!\nPlease wait for graphics...");
    if (glist) {

      while (glist->next) {
	item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, "computer.xpm");
	gtk_tree_append(GTK_TREE(parent_tree), item);
	subtree = gtk_tree_new();
	gtk_tree_item_set_subtree(GTK_TREE_ITEM(item), subtree);
	gtk_widget_show(item);
	/* Insert the tooltip */
	mw->tooltip(item, "Click on the '+' to view the shares on this server");

	gtk_signal_connect(GTK_OBJECT(item), "expand", GTK_SIGNAL_FUNC(expand_server), subtree);
	gtk_signal_connect(GTK_OBJECT(item), "collapse", GTK_SIGNAL_FUNC(on_collapse), subtree);
	glist = glist->next;
      }
      mw->debug("done!\n");
      statusbar->set_text("Server listning finished!");
    }
  } else {
    statusbar->set_text("Could not list server");
    mw->debug("check ~/.jags/outfile\n");
  }
  
  if (GTK_TREE(parent_tree)->children) {
    /* Here we got a subtree containing at least one item: do nothing! */
  } else {
    GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
    gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
  }

  return TRUE;
}

gint expand_server(GtkWidget *widget, MainWindow *mw) {
  GtkWidget *parent_tree = GTK_TREE_ITEM_SUBTREE(widget);

  Data *d;
  GList *glist;
  GtkWidget *item;//, *subtree;

  /* Get the text on this treeitem into "workgroup" */
  gchar *server;
  item = GTK_TREE(parent_tree)->tree_owner;
  server = g_strdup_printf("%s", gtk_tree_item_get_text(item));
  menubar->set_server_name(server);
  
  gchar *s_bar_msg = g_strdup_printf("Listing shares on %s...", server);
  statusbar->set_text(s_bar_msg);

  gchar *command = g_strdup_printf("list_shares.sh \"%s\" ", server);
  mw->debug(g_strdup_printf("Listing shares on %s...", server));
  d = new Data(command, conf->get_plugin());
  mw->debug("done!\n");
  glist = d->getData();
  gtk_signal_connect(GTK_OBJECT(parent_tree), "select-child", GTK_SIGNAL_FUNC(on_share_selected), parent_tree);
//    gtk_signal_connect(GTK_OBJECT(parent_tree), "", GTK_SIGNAL_FUNC(button_press), parent_tree);
  if (glist) {
    while (glist->next) {
      if (conf->get_hide_ipc_shares()) {
	if (g_strncasecmp("IPC$", (gchar *)glist->next->data, 4)) {
	  item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, "browse.xpm");
	  //	  gtk_signal_connect(GTK_OBJECT(item), "event", GTK_SIGNAL_FUNC(button_press), glist);
	  gtk_signal_connect(GTK_OBJECT(item), "button_press_event", GTK_SIGNAL_FUNC(button_press), NULL);
	  gtk_tree_append(GTK_TREE(parent_tree), item);
	  gtk_widget_show(item);
	  
	}
      } else {
	  item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, "browse.xpm");
	  //        gtk_signal_connect(GTK_OBJECT(item), "select", GTK_SIGNAL_FUNC(button_press), glist);
	  gtk_tree_append(GTK_TREE(parent_tree), item);
	  gtk_widget_show(item);

      }
      /* Insert the tooltip */
      mw->tooltip(item, "Double click to browse this share\nRight click for menu ");
      
      glist = glist->next;
    }
    statusbar->set_text("Share listning finished!");
  }

  /* Remove '+'-sign in front of share or computer if nu sub-items found */
  glist = GTK_TREE(parent_tree)->children;
  if (glist) {
    GtkWidget *item = GTK_WIDGET(glist->data);
    gchar *text = gtk_tree_item_get_text(item);
    if (!g_strncasecmp(text, "rror returning", 13)) {
      mw->debug("Found Windows 2000 server with guest account disabled!\n");
      GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
      gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
    }
  } else {
    GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
    gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
  }

  return TRUE;
}

gint on_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data, MainWindow *mw) {
  gchar *share, *server;

  /* Here we get the treeitem where the server name is stored */
  GtkWidget *tree_item = tree->tree_owner;
  server = g_strdup_printf("%s", gtk_tree_item_get_text(tree_item));
  menubar->set_server_name(server);
  share = gtk_tree_item_get_text(widget);
  menubar->set_share_name(share);
  menubar->toggle_on_share_select();
  return TRUE;
}

gint check_d_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw) {
  if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) {
    gtk_tree_item_expand(GTK_TREE_ITEM(widget));
    return TRUE;
  } else {
    return FALSE;
  }
}

/* Display the popup menu if you press a button on a share. 
   Mount and browse on double klick */
gint button_press(GtkWidget *widget, GdkEventButton *event, MainWindow *mw) {
  if ((event->type == GDK_BUTTON_PRESS) && (event->button == 3)) {
      gtk_tree_item_select(GTK_TREE_ITEM(widget));
      menubar->set_share_name(gtk_tree_item_get_text(widget));
      gtk_menu_popup (GTK_MENU(menubar->get_popupmenu()), NULL, NULL, NULL, NULL,
		      event->button, event->time);
      /* Tell calling code that we have handled this event; the buck
       * stops here. */
      return TRUE;
  } else if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) {
    menubar->mount_and_browse_ex(GTK_MENU_ITEM(gtk_menu_item_new()), NULL);
  }

  return FALSE;
}

/* This function takes a string and prints it if debugging is enabled */
void MainWindow::debug(gchar *txt) {
  if (conf->get_show_debug()) {
    g_print(txt);
  }
}

void MainWindow::tooltip(GtkWidget *widget, gchar *txt) {
  if (conf->get_show_tooltips()) {
    GtkTooltips *tooltip = gtk_tooltips_new();
    gtk_tooltips_set_tip(tooltip, widget, txt, NULL);
  }
}

void MainWindow::run(void) {
  gtk_main();
}

int
main(int argc, char *argv[]) {
  MainWindow w(argc, argv);
  w.run();
  return 0;
}
