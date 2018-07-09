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

#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "jagsstatusbar.h"
#include "jagsmenubar.h"
//#include "jagsprogressbar.h"
#include "jagssearchdialog.h"
#include "jagsmountwith.h"
#include "jagsconfig.h"
#include "mount.h"
#include "jags.h"
#include "data.h"
#include "gtk_common.h"
#include "mount.h"
#include "mainwindow.h"

//static gint on_collapse(GtkWidget *widget);

static JagsStatusBar *statusbar = NULL;
JagsConfig *conf = NULL;
JagsMenuBar *menubar = NULL;
MainWindow *mainw = NULL;
//static JagsProgressBar *progressbar = NULL;
gchar *LocalMasterBrowser = NULL;
gchar *RemoteLocalMasterBrowser = NULL;
GtkStyle *style;

MainWindow::MainWindow(int argc, char *argv[])
{
  GtkWidget *window = NULL, *vbox = NULL, *scrolled_win = NULL, *item = NULL, 
    *subtree = NULL;
  gboolean nowindows = false;
  Mount *mnt = NULL;
  gchar *cmd = NULL, *s_bar_msg = NULL, *buffer = NULL;
  Data *d = NULL;
  GList *glist = NULL;

  mainw=this;
  conf = new JagsConfig();
  mnt = new Mount(conf);  

  //-------------------parsing command line for a sane params-----------------------
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
      g_print("\n(C) Daniel Sundberg 2000-2003\n");
      g_print("E-mail: sumpan@sumpan.com\n");
      g_print("\nAnatoliy Demchishin 2003\n");
      g_print("E-mail: demch@iptelecom.net.ua\n\n");
      g_print("http://jags.sf.net\n");
      g_print("\n\n");
      g_print("Command line options:\n\n");
      g_print("   -c [SERVER]    : Server to search for\n");
      g_print("   --nowindows    : Just mount shares in config-file.\n");
      g_print("                    Do not show Jags main-window.\n");
      g_print("   -h --help      : This help screen\n\n");
      exit(0);
    } else if (strcmp(argv[i],"--nowindows")==0) {
      g_print("Starting jags in nowindows mode\n");
      nowindows = true;
    } 
  }
  
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
  /* Setting title */
  buffer = new char[100];
  sprintf(buffer, "%s v%s", PROGRAM_NAME, VERSION);
  gtk_window_set_title(GTK_WINDOW(window), buffer);
  
  gtk_signal_connect(GTK_OBJECT(window), "delete_event", 
		     GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
  
  /* Fix the box */
  vbox=gtk_vbox_new(FALSE, 5);
  gtk_container_set_border_width(GTK_CONTAINER(vbox), 2);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show(vbox);

  /* Create the root tree */
  tree = gtk_tree_new();

  /* Add the menubar to the program */
  menubar = new JagsMenuBar(vbox, tree, conf, mnt, this);

  if (nowindows) exit(0);
  menubar->toggle_greyall();
  
  /* A generic scrolled window */
  scrolled_win = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(scrolled_win), 
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_widget_set_usize (scrolled_win, 500, 400);
  gtk_box_pack_start(GTK_BOX(vbox), scrolled_win, TRUE, TRUE, 0);
  gtk_widget_show (scrolled_win);
  
  //  progressbar = new JagsProgressBar(vbox);

  statusbar = new JagsStatusBar(vbox);
  statusbar->set_text(buffer);

  /* Add the tree to the scrolled window */
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_win), tree);

  /* Setup the tree */
  item = gtk_tree_item_new_with_label_with_pixmap("SAMBA Network", "smbnet.xpm");

  /* Insert the tooltip */
  tooltip(item, "Click on the + to expand the network-view");

  gtk_tree_append(GTK_TREE(tree), item);
  gtk_widget_show(item);
  subtree = gtk_tree_new();
  gtk_tree_item_set_subtree(GTK_TREE_ITEM(item), subtree);
  //  gtk_widget_show(subtree);
  gtk_signal_connect(GTK_OBJECT(item), "expand", 
		     GTK_SIGNAL_FUNC(expand_network), mainw);
  gtk_signal_connect(GTK_OBJECT(item), "collapse", 
		     GTK_SIGNAL_FUNC(on_collapse), mainw);
  gtk_signal_connect(GTK_OBJECT(item), "button_press_event", 
		     GTK_SIGNAL_FUNC(check_d_click), mainw);

  gtk_widget_show(tree);
  gtk_widget_show(window);
  if (conf->searchisset()) {
    gchar *s = g_strdup_printf("%s", conf->get_searchfor());
    g_print("Will open search dialog...%s\n", s);
    JagsSearchDialog *sd = new JagsSearchDialog(mnt, menubar);
    sd->set_string(s);
  }

  if (conf->get_sound_enabled()) {
    cmd = g_strdup_printf("ogg123 %s %s/.jags/sounds/jags2.ogg &", 
			  conf->get_sound_params(), g_get_home_dir());
    system(cmd);
    g_free(cmd);
  }

//-------------LocalMasterBrowser detection---------------------------------------
  s_bar_msg = g_strdup_printf("Fetching LocalMasterBrowser IP for native "
			      "workgroup %s...", conf->get_workgroup());
  debug(g_strdup_printf("%s\n", s_bar_msg));
  
  /* Get the masterbrowser into a Data-object */
  cmd = g_strdup_printf("fetch_master_browser.sh \"%s\"",conf->get_workgroup());
  d = new Data(cmd, conf->get_plugin()); 
  glist = d->getData();
  if (!g_strncasecmp((gchar *)glist->next->data,"Error",5)) {
    LocalMasterBrowser=g_strdup(conf->get_wins());
    debug(g_strdup_printf("Broadcast LocalMasterBrowser search failed. Using "
			  "hardcoded WINS: %s...\n", LocalMasterBrowser));	  
  } else {
    debug(g_strdup_printf("Broadcast LocalMasterBrowser search success\n"));	  
    LocalMasterBrowser=g_strdup((gchar *)glist->next->data);
  }
  delete d;
  g_free(cmd);

  menubar->set_localmasterbrowser_name(LocalMasterBrowser);
  debug(g_strdup_printf("Found LocalMasterBrowser....%s\n", LocalMasterBrowser));

  style=gtk_rc_get_style(window);
  
}

MainWindow::~MainWindow()
{
  delete conf;
  delete menubar;
  //  delete progressbar;
  g_free(LocalMasterBrowser);
  g_free(RemoteLocalMasterBrowser);
}

/* Modified...now we just hide the first item in the tree, we remove the rest, 
   this will cause a much smaller memory leak than when we were hiding all 
   sub-items */
gint on_collapse(GtkWidget *item, MainWindow *mw)
{
  GtkWidget *widget = GTK_TREE_ITEM_SUBTREE(item);
  /* Delete most items except from the first */

  if (GTK_TREE(widget)->children) {
    if (GTK_TREE(widget)->children->next) {
      gtk_tree_remove_items(GTK_TREE(widget), GTK_TREE(widget)->children->next);
      GList *glist = GTK_TREE(widget)->children;
      gtk_widget_hide(GTK_WIDGET(glist->data));
      menubar->toggle_greyall();
      
      return TRUE; // We did do something
    } else {
      GList *glist = GTK_TREE(widget)->children;
      gtk_widget_hide(GTK_WIDGET(glist->data));
      menubar->toggle_greyall();
      
      return TRUE;
    }
  } else { 
    return FALSE;
  }
}

/* This happens when you expand the root network tree */
gint expand_network(GtkWidget *widget, MainWindow *mw)
{
  GtkWidget *parent_tree = GTK_TREE_ITEM_SUBTREE(widget);
  Data *d = NULL;
  GList *glist = NULL;
  GtkWidget *item, *subtree = NULL;
  gchar *ServStr = new gchar[200];
  gchar *command = NULL;

  /* First reload config... */
  conf->reload();

  mw->debug(g_strdup_printf("Trying to list network workgroups..."));

  /* Now we have the LocalMasterBrowser NetBIOS name allready*/
  if (LocalMasterBrowser) {
    command = g_strdup_printf("list_workgroups.sh \"%s\"", LocalMasterBrowser);
    d = new Data(command, conf->get_plugin());
    glist = d->getData();
    if (glist) {
      while (glist->next) {
	item = gtk_tree_item_new_with_label_with_pixmap((gchar *)glist->next->data, 
							"network.xpm");
	gtk_tree_append(GTK_TREE(parent_tree),item);
	subtree = gtk_tree_new();
	gtk_tree_item_set_subtree(GTK_TREE_ITEM(item), subtree);
	gtk_widget_show(item);
	
	/* Insert the tooltip */
	sprintf(ServStr,"Click on the + to expand the workgroup %s",
		(gchar *)glist->next->data);
	mw->tooltip(item, ServStr);
	
	gtk_signal_connect(GTK_OBJECT(item), "expand", 
			   GTK_SIGNAL_FUNC(expand_workgroup), mainw);
	gtk_signal_connect(GTK_OBJECT(item), "collapse", 
			   GTK_SIGNAL_FUNC(on_collapse), mainw);
	gtk_signal_connect(GTK_OBJECT(item), "button_press_event", 
			   GTK_SIGNAL_FUNC(check_d_click), mainw);
	glist = glist->next;
      }
      mw->debug(g_strdup("done!\n"));
      statusbar->set_text("Workgroups listing finished!");
      delete d;
    }
  } else {
    delete d;
    statusbar->set_text("Could not list workgroups");
    mw->debug(g_strdup("check ~/.jags/outfile\n"));
  }

  delete [] ServStr;
  return TRUE;
}

/* This happens when you expand a workgroup */
gint expand_workgroup(GtkWidget *widget, MainWindow *mw)
{
  GtkWidget *parent_tree = GTK_TREE_ITEM_SUBTREE(widget);
  Data *d = NULL, *d2 = NULL;
  GList *glist = NULL, *glist2 = NULL;
  GtkWidget *item, *subtree = NULL;
  gchar *ServStr = new gchar[200];
  gchar *workgroup = NULL, *command = NULL, *comment = NULL, *comment2 = NULL;
  gint h;


  if (GTK_TREE(parent_tree)->children) 
    gtk_tree_remove_items(GTK_TREE(parent_tree), 
			  GTK_TREE(parent_tree)->children->next);
  

  /* Get the text on this treeitem into "workgroup" */
  item = GTK_TREE(parent_tree)->tree_owner;
  workgroup = g_strdup_printf("%s", gtk_tree_item_get_text(item));
  menubar->set_workgroup_name(workgroup);

  mw->debug(g_strdup_printf("Fetching masterbrowser for %s...", workgroup));
  /* Get the RemoteLocalMasterBrowser into a Data-object */
  if (g_strcasecmp(workgroup ,conf->get_workgroup() ) ) {
    command = g_strdup_printf("fetch_master_browser.sh \"%s\"", 
			      workgroup);
  } else {
    mw->debug(g_strdup_printf("LocalMasterBrowser..."));
    command = g_strdup_printf("echo.sh \"%s\"", LocalMasterBrowser);
  }

  
  d = new Data(command, conf->get_plugin()); 
  glist = d->getData();
  
  /* Now we have the masterbrowser stored in d, just the same as above but with another command sent to the Data-class */
  if (glist) {
    gtk_signal_connect(GTK_OBJECT(parent_tree), "select-child", 
		       GTK_SIGNAL_FUNC(on_workgroup_selected), parent_tree);
    RemoteLocalMasterBrowser=g_strdup((gchar *)glist->next->data);
    mw->debug(g_strdup_printf("%s\n", RemoteLocalMasterBrowser));
    delete d;
    menubar->set_remotelocalmasterbrowser_name(RemoteLocalMasterBrowser);

    command = g_strdup_printf("list_servers.sh \"%s\"", RemoteLocalMasterBrowser);
    mw->debug(g_strdup_printf("Listing servers in %s...", workgroup));
    d = new Data(command, conf->get_plugin());
    glist = d->getData();
    g_free(command);

    command = g_strdup_printf("cat_outfile.sh ~/.jags/outfile2.dat");
    mw->debug(g_strdup_printf("done\nReading servers comments (outfile2.dat)..."));
    d2 = new Data(command, conf->get_plugin());
    glist2 = d2->getData();
    g_free(command);

    mw->debug(g_strdup("done!\nPlease wait for graphics..."));

    while (glist->next) {
      //---get the string width in pixels----------------------------------
      h = gdk_string_width(style->font, "DDDDDDDDDDDDDDDDD") - 
	gdk_string_width(style->font, (gchar *)glist->next->data);
      h /= gdk_string_width(style->font, "D");
      
      comment = g_strnfill(h, 0x20);
      comment2 = g_strescape(g_strconcat((gchar *)glist->next->data, comment, 
					 (gchar *)glist2->next->data, NULL));
      g_free(comment);

      cout << comment2 << endl;

      item = gtk_tree_item_new_with_label_with_pixmap(comment2, "computer.xpm");
      gtk_tree_append(GTK_TREE(parent_tree), item);
      subtree = gtk_tree_new();
      gtk_tree_item_set_subtree(GTK_TREE_ITEM(item), subtree);
      gtk_widget_show(item);
      /* Insert the tooltip */
      sprintf(ServStr,"Click on the + to view the shares on %s",
	      (gchar *)glist->next->data);
      mw->tooltip(item, ServStr);
      
      gtk_signal_connect(GTK_OBJECT(subtree), "select-child", 
			 GTK_SIGNAL_FUNC(on_workgroup_selected), parent_tree);
      gtk_signal_connect_after(GTK_OBJECT(item), "expand", 
			       GTK_SIGNAL_FUNC(expand_server), parent_tree);
      gtk_signal_connect(GTK_OBJECT(item), "collapse", 
			 GTK_SIGNAL_FUNC(on_collapse), mainw);
      gtk_signal_connect(GTK_OBJECT(item), "button_press_event", 
			 GTK_SIGNAL_FUNC(check_server_click), mainw);
      glist = glist->next;
      glist2 = glist2->next;
    }
    mw->debug(g_strdup("done!\n"));
    statusbar->set_text("Server listing finished!");
  } else {
    statusbar->set_text("Could not list server");
    mw->debug(g_strdup("check ~/.jags/outfile\n"));
  }
  
  if (GTK_TREE(parent_tree)->children) {
    /* Here we got a subtree containing at least one item: do nothing! */
  } else {
    GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
    gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
  }

  delete [] ServStr;
  delete d;
  delete d2;
  return TRUE;
}

gint expand_server(GtkWidget *widget, GtkTree *root_tree)
{
  GtkWidget *parent_tree = GTK_TREE_ITEM_SUBTREE(widget);

  Data *d = NULL, *d2 = NULL, *d3 = NULL;
  GList *glist = NULL, *glist2 = NULL, *glist3 = NULL;
  GtkWidget *item = NULL;
  gchar *command = NULL, *s_bar_msg = NULL, *server = NULL;
  GtkWidget * root_tree_item = NULL;
  gchar *comment = NULL, *comment2 = NULL;
  gchar *ShareName = new gchar[100];
  gint h;

  /* Get the text on this treeitem into "workgroup" */
  item = GTK_TREE(parent_tree)->tree_owner;
  server = g_strdup_printf("%s", gtk_tree_item_get_text(item));
  menubar->set_server_name(server);

  root_tree_item = root_tree->tree_owner;
  menubar->set_workgroup_name(gtk_tree_item_get_text(root_tree_item));

  s_bar_msg = g_strdup_printf("Listing shares on %s...", server);
  statusbar->set_text(s_bar_msg);
 
  //-------------shares listing-----------------------------------------------------
  if (g_strcasecmp(menubar->get_workgroup_name() ,conf->get_workgroup() ) ) {	  
    mainw->debug(g_strdup_printf("Fetching masterbrowser for %s...", 
				 menubar->get_workgroup_name()));
    cout << "Local master browser = " << LocalMasterBrowser << endl;
    command = g_strdup_printf("fetch_master_browser_remote.sh \"%s\" \"%s\"", 
			      LocalMasterBrowser, menubar->get_workgroup_name());
    d = new Data(command, conf->get_plugin()); 
    glist = d->getData();
    if (RemoteLocalMasterBrowser) g_free(RemoteLocalMasterBrowser);
    RemoteLocalMasterBrowser=g_strdup((gchar *)glist->next->data);
    delete d;
    menubar->set_remotelocalmasterbrowser_name(RemoteLocalMasterBrowser);
    mainw->debug(g_strdup_printf("%s\nListing shares with "
				 "RemoteLocalMasterBrowser\n",
				 RemoteLocalMasterBrowser));
    command = g_strdup_printf("list_shares_remote.sh \"%s\" \"%s\"",  server, 
			      RemoteLocalMasterBrowser );
  } else {
    mainw->debug(g_strdup_printf("Listing shares with LocalMasterBrowser\n"));
    command = g_strdup_printf("list_shares_remote.sh \"%s\"", server );	  
  }
  mainw->debug(g_strdup_printf("%s\n", command));
  mainw->debug(g_strdup_printf("Listing shares in %s workgroup on %s server...", 
			       menubar->get_workgroup_name(), server));
  d = new Data(command, conf->get_plugin());
  g_free(command);
  mainw->debug(g_strdup("done!\n"));

  command = g_strdup_printf("cat_outfile.sh ~/.jags/outfile2.dat");
  mainw->debug(g_strdup_printf("Reading share type (outfile2.dat)..."));
  d2 = new Data(command, conf->get_plugin());
  glist2 = d2->getData();
  g_free(command);
  mainw->debug(g_strdup("done!\n"));

  command = g_strdup_printf("cat_outfile.sh ~/.jags/outfile3.dat");
  mainw->debug(g_strdup_printf("Reading share comments (outfile3.dat)..."));
  d3 = new Data(command, conf->get_plugin());
  //  glist3 = d3->getData();
  g_free(command);
  mainw->debug(g_strdup("done!\n"));

  glist = d->getData();
  glist2 = d2->getData();
  glist3 = d3->getData();
  //-------------------------------------------------------------------------------
  gtk_signal_connect(GTK_OBJECT(parent_tree), "select-child", 
		     GTK_SIGNAL_FUNC(on_share_selected), parent_tree);
  if (glist) {
    while (glist->next) {
      if (g_strncasecmp((gchar *)glist->next->data, "Error", 5)) {
	g_strdup_printf(ShareName,"%s", (gchar *)glist->next->data);
	h = gdk_string_width(style->font, "DDDDDDDDDDDDDDDDDDD") - 
	  gdk_string_width(style->font, (gchar *)glist->next->data);
	h /= gdk_string_width(style->font, " ");
	comment = g_strnfill(h, 0x20);
	comment2 = g_strconcat((gchar *)glist->next->data, comment, 
			       (gchar *)glist3->next->data, NULL);
      }
      if (!g_strcasecmp((gchar *)glist2->next->data, "Disk")) {
	if ( (ShareName[strlen(ShareName)-1]!='$') || 
	     (!conf->get_hide_ipc_shares()) ) {	
	  item = gtk_tree_item_new_with_label_with_pixmap(comment2, "browse.xpm");
	  gtk_signal_connect(GTK_OBJECT(item), "button_press_event", 
			     GTK_SIGNAL_FUNC(button_press), mainw);
	  gtk_tree_append(GTK_TREE(parent_tree), item);
	  gtk_widget_show(item);
	}
      }
      if ( (!g_strcasecmp((gchar *)glist2->next->data, "IPC")) && 
	   (!conf->get_hide_ipc_shares()) ) {
	item = gtk_tree_item_new_with_label_with_pixmap(comment2, "ipc.xpm");
	gtk_tree_append(GTK_TREE(parent_tree), item);
	gtk_widget_show(item);
      }
      if (!g_strcasecmp((gchar *)glist2->next->data, "Printer")) {
	item = gtk_tree_item_new_with_label_with_pixmap(comment2, "printer.xpm");
	gtk_tree_append(GTK_TREE(parent_tree), item);
	gtk_widget_show(item);
      }
      if (!g_strcasecmp((gchar *)glist2->next->data, "Error")) {
	item = gtk_tree_item_new_with_label_with_pixmap(comment2, "cancel.xpm");
	gtk_tree_append(GTK_TREE(parent_tree), item);
	gtk_widget_show(item);
      }

      /* Insert the tooltip */
      mainw->tooltip(item, "Double click to browse. Right click for menu ");
      
      glist = glist->next;
      glist2 = glist2->next;
      glist3 = glist3->next;
    }
    statusbar->set_text("Share listing finished!");
  }

  /* Remove '+'-sign in front of share or computer if nu sub-items found */
  glist = GTK_TREE(parent_tree)->children;
  if (glist) {
    GtkWidget *item = GTK_WIDGET(glist->data);
    gchar *text = gtk_tree_item_get_text(item);
    if (!g_strncasecmp(text, "rror returning", 13)) {
      mainw->debug(g_strdup("Found Windows 2000 server with guest "
			    "account disabled!\n"));
      GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
      gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
    }
  } else {
    GtkWidget *owner = GTK_TREE(parent_tree)->tree_owner;
    gtk_tree_item_remove_subtree(GTK_TREE_ITEM(owner));
  }

  delete d;
  delete d2;
  delete d3;
  delete [] ShareName;
  return TRUE;
}

gint on_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data)
{
  gchar *share, *server = NULL;
  GtkWidget *tree_item = NULL;

  /* Here we get the treeitem where the server name is stored */
  tree_item = tree->tree_owner;
  server = g_strdup_printf("%s", gtk_tree_item_get_text(tree_item));
  menubar->set_server_name(server);
  share = gtk_tree_item_get_text(widget);
  menubar->set_share_name(share);
  menubar->toggle_on_share_select();
  return TRUE;
}

gint on_workgroup_selected(GtkTree *tree, GtkWidget *widget, GtkTree *root_tree)
{
  /* Here we get the treeitem where the server name is stored */
  //  GtkTree *root_tree=GTK_TREE(data);
  GtkWidget * root_tree_item = root_tree->tree_owner;
  //  g_print(g_strdup_printf("%s\n",gtk_tree_item_get_text(root_tree_item)));
  menubar->set_workgroup_name(gtk_tree_item_get_text(root_tree_item));
  return TRUE;
}

gint check_d_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw)
{
  if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) { 
    gtk_tree_item_expand(GTK_TREE_ITEM(widget));
    return TRUE;
  }
  if ((event->type == GDK_BUTTON_PRESS) && (event->button == 1)) { 
    menubar->toggle_greyall();
    return TRUE;
  }
  return FALSE;
}

gint check_server_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw)
{
  menubar->set_server_name(gtk_tree_item_get_text(widget));
  //  g_print("%s\n", server);

  if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) { 
    gtk_tree_item_expand(GTK_TREE_ITEM(widget));
    return TRUE;
  }
  if ((event->type == GDK_BUTTON_PRESS) && (event->button == 1)) { 
    menubar->toggle_greyall();
    return TRUE;
  }
  return FALSE;
}


/* Display the popup menu if you press a button on a share. Mount and browse 
   on double klick */
gint button_press(GtkWidget *widget, GdkEventButton *event, MainWindow *mw)
{
  if ((event->type == GDK_BUTTON_PRESS) && (event->button == 3)) {
    gtk_tree_item_select(GTK_TREE_ITEM(widget));
    menubar->set_share_name(gtk_tree_item_get_text(widget));
    gtk_menu_popup (GTK_MENU(menubar->get_popupmenu()), NULL, NULL, NULL, 
		    NULL, event->button, event->time);
    /* Tell calling code that we have handled this event; the buck stops here. */
    return TRUE;
  } else if ((event->type == GDK_2BUTTON_PRESS) && (event->button == 1)) {    
    menubar->mount_and_browse_ex(GTK_MENU_ITEM(gtk_menu_item_new()), menubar);	 
  }

  return FALSE;
}

/* This function takes a string and prints it if debugging is enabled */
void MainWindow::debug(gchar *txt)
{
  if (conf->get_show_debug()) {
    g_print(txt);
  }
  g_free(txt);
}

void MainWindow::tooltip(GtkWidget *widget, gchar *txt)
{
  if (conf->get_show_tooltips()) {
    GtkTooltips *tooltip = gtk_tooltips_new();
    gtk_tooltips_set_tip(tooltip, widget, txt, NULL);
  }
}

void MainWindow::run(void)
{
  gtk_main();
}

int main(int argc, char *argv[])
{
  gchar *cmd = NULL;

  MainWindow w(argc, argv);
  w.run();

  if (conf->get_sound_enabled()) {
    cmd = g_strdup_printf("ogg123 %s %s/.jags/sounds/exit2.ogg &", 
			  conf->get_sound_params(), g_get_home_dir());
    system(cmd);
    g_free(cmd);
  }

  return 0;
}

