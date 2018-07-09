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
 ** jagsprefsdialog.cpp 0.1
 **
 ** +Now writes the config to default config-file ($HOME/.jags/jags.conf)
 ** +Now reads some default values from config file
 ** +Now gets avaliable plugins automaticly 
 **
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Sun Jul   9 19:50:00 2000 Daniel Sundberg 
 ** Last update Fri Oct   6 16:37:00 2000 Daniel Sundberg
 */

#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>
#include <string.h>

#include "cconfig.h"
#include "jagsprefsdialog.h"
#include "jagsconfig.h"
#include "gtk_common.h"

/* I know it's ugly declaring this global but it wont work with 
   this as private fields in the jagsprefsdialog class */
GtkWidget *window;
GtkWidget *edit_workgroup;
GtkWidget *edit_browser;
GtkWidget *edit_mountdir;
GtkWidget *toggle_hideipc;
GtkWidget *toggle_showdebuginfo;
GtkWidget *toggle_showtooltips;
GtkWidget *pulldown_plugins;
GtkWidget *edit_username;
GtkWidget *edit_password;

/* This is big but... */
JagsPrefsDialog::JagsPrefsDialog(JagsConfig *iconfig) {
  JagsConfig *conf = new JagsConfig();
  GtkWidget *button, *label, *hbox;//, *menu, *item;

  window = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW(window), "Preferences...");
  gtk_window_set_policy(GTK_WINDOW(window), TRUE,TRUE,FALSE);

  /* Setup the buttons */
  button = gtk_button_new_with_label_with_pixmap("Cancel", "cancel.xpm");
  gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(on_cancel), NULL);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->action_area), button, TRUE, TRUE, 0);
  gtk_widget_show(button);

  button = gtk_button_new_with_label_with_pixmap("Apply", "apply.xpm");
  gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(on_apply), NULL);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->action_area), button, TRUE, TRUE, 0);
  gtk_widget_show(button);

  button = gtk_button_new_with_label_with_pixmap("Close", "ok.xpm");
  gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(on_close), NULL);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->action_area), button, TRUE, TRUE, 0);
  gtk_widget_show(button);

  /* Fix the config options in the layout above the buttons */
  /* Workgroup cfg option */
  hbox = gtk_hbox_new(TRUE, 3);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show(hbox);
  
  label = gtk_label_new("Workgroup:");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 0);
  gtk_widget_show(label);

  edit_workgroup = gtk_entry_new();
  gtk_entry_set_editable(GTK_ENTRY(edit_workgroup), TRUE);
  gtk_entry_set_text(GTK_ENTRY(edit_workgroup), conf->get_workgroup());
  gtk_box_pack_start(GTK_BOX(hbox), edit_workgroup, TRUE, TRUE, 0);
  gtk_widget_show(edit_workgroup);

  /* browser cfg option */
  hbox = gtk_hbox_new(TRUE, 3);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show(hbox);
  
  label = gtk_label_new("Browser:");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  gtk_widget_show(label);

  edit_browser = gtk_entry_new();
  gtk_entry_set_editable(GTK_ENTRY(edit_browser), TRUE);
  gtk_entry_set_text(GTK_ENTRY(edit_browser), conf->get_browser());
  gtk_box_pack_start(GTK_BOX(hbox), edit_browser, TRUE, TRUE, 0);
  gtk_widget_show(edit_browser);

  /* mount dir cfg option */
  hbox = gtk_hbox_new(TRUE, 3);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show(hbox);
  
  label = gtk_label_new("Mount dir:");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  gtk_widget_show(label);

  edit_mountdir = gtk_entry_new();
  gtk_entry_set_editable(GTK_ENTRY(edit_mountdir), TRUE);
  gtk_entry_set_text(GTK_ENTRY(edit_mountdir), conf->get_mount_dir());
  gtk_box_pack_start(GTK_BOX(hbox), edit_mountdir, TRUE, TRUE, 0);
  gtk_widget_show(edit_mountdir);

  /* Username cfg option */
  hbox = gtk_hbox_new(TRUE, 3);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show(hbox);
  
  label = gtk_label_new("Username:");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  gtk_widget_show(label);

  edit_username = gtk_entry_new();
  gtk_entry_set_editable(GTK_ENTRY(edit_username), TRUE);
  gtk_entry_set_text(GTK_ENTRY(edit_username), conf->get_username());
  gtk_box_pack_start(GTK_BOX(hbox), edit_username, TRUE, TRUE, 0);
  gtk_widget_show(edit_username);

  /* Password cfg option */
  hbox = gtk_hbox_new(TRUE, 3);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show(hbox);
  
  label = gtk_label_new("Password:");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  gtk_widget_show(label);

  edit_password = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(edit_password),FALSE);
  gtk_entry_set_editable(GTK_ENTRY(edit_password), TRUE);
  gtk_entry_set_text(GTK_ENTRY(edit_password), conf->get_password());
  gtk_box_pack_start(GTK_BOX(hbox), edit_password, TRUE, TRUE, 0);
  gtk_widget_show(edit_password);


  /* Hide $IPC-shares cfg option */
  toggle_hideipc = gtk_check_button_new_with_label("Hide IPC$ shares");
  gtk_widget_show(toggle_hideipc);
  if (conf->get_hide_ipc_shares() == 1) {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_hideipc), TRUE);    
  } 
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), toggle_hideipc, TRUE, TRUE, 0);

  /* Show debug info cfg option */
  toggle_showdebuginfo = gtk_check_button_new_with_label("Show debug-info");
  gtk_widget_show(toggle_showdebuginfo);
  if (conf->get_show_debug() == 1) {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_showdebuginfo), TRUE);    
  } 
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), toggle_showdebuginfo, TRUE, TRUE, 0);

  /* Show tooltips cfg option */
  toggle_showtooltips = gtk_check_button_new_with_label("Show tooltips");
  gtk_widget_show(toggle_showtooltips);
  if (conf->get_show_tooltips() == 1) {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_showtooltips), TRUE);    
  } 
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), toggle_showtooltips, TRUE, TRUE, 0);
  
  /* Plugins cfg option */
  hbox = gtk_hbox_new(TRUE, 3);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show(hbox);

  label = gtk_label_new("Plugins:");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  gtk_widget_show(label);

  GList *glist = g_list_alloc();
  
  /* lists the plugin dirs to the plugins-conf-file */
  gchar *path = g_strdup_printf("%s/.jags", getenv("HOME"));
  gchar *command = g_strdup_printf("ls %s/plugins | grep plugin > %s/plugins.conf", path, path);
  system(command);
  //gchar *plugins_path = g_strdup_printf("%s/plugins", path);
  //gchar *command2 = g_strdup_printf("cat %s/plugins.conf | cut -b %d", path, strlen(plugins_path)); 

  /* Debug */
  //cout << path << '\n';
  //cout << command2 << '\n';
  ifstream plugins_in(g_strdup_printf("%s/plugins.conf", path));
  gchar *def_plugin = g_strdup(conf->get_plugin());
  glist = g_list_append(glist, g_strndup(def_plugin, strlen(def_plugin) - 7) );
  if (plugins_in) {
    while (plugins_in.good()) {
      gchar *buffer = g_new(gchar, 100);
      plugins_in.getline(buffer, 100, '\n');
      if (strlen(buffer) > 1) {
	guint length = strlen(buffer) - 7; // strlen("buffer") = 7
	gchar *buffer2 = g_strndup(buffer, length);
	if (strcmp(buffer, def_plugin))
	  glist = g_list_append(glist, buffer2);
	//cout << buffer << '\n';	
	//cout << glist->next->data << '\n';
      }

    }
  } else {
    cout << "No plugins found in " << path << "/plugins\n" 
	 << "Please put some plugins there!\n";      
  }
  pulldown_plugins = gtk_option_menu_new_with_glist(glist);
  gtk_box_pack_start(GTK_BOX(hbox), pulldown_plugins, TRUE, TRUE, 0);
  gtk_widget_show(pulldown_plugins);  
  gtk_widget_show(window); 
}

JagsPrefsDialog::~JagsPrefsDialog() {

}

gint onPluginsChanged(GtkWidget *widget, GdkEvent *event, gpointer data, JagsPrefsDialog *pd) {
  return TRUE;
}

gint on_cancel(GtkWidget *widget, JagsPrefsDialog *pd) {
  gtk_widget_destroy(GTK_WIDGET(window));
  return TRUE;
}

/* Write config here, make jags reload config after closing the dialog */
gint on_apply(GtkWidget *widget, JagsPrefsDialog *pd) {
  gchar *file = g_strdup_printf("%s/%s", getenv("HOME"), JAGS_CONFIG_FILE_NAME);
  CConfig *conf = new CConfig(file);

  gchar *mountdir = g_strdup(gtk_entry_get_text(GTK_ENTRY(edit_mountdir)));
  if (strlen(mountdir)>0) {
    conf->writeConfigKey("MountDir", gtk_entry_get_text(GTK_ENTRY(edit_mountdir)));
  } else {
    popup_dialog(150, "Warning", "Please enter a mount directory!", "Ok");
  }

  gchar *workgroup = g_strdup(gtk_entry_get_text(GTK_ENTRY(edit_workgroup)));
  if (strlen(workgroup) > 0) {
    conf->writeConfigKey("Workgroup", gtk_entry_get_text(GTK_ENTRY(edit_workgroup)));
  } else {
    popup_dialog(150, "Warning", "Please enter a workgroup!", "Ok");
  }

  conf->writeConfigKey("UserName", gtk_entry_get_text(GTK_ENTRY(edit_username)));
  conf->writeConfigKey("Password", gtk_entry_get_text(GTK_ENTRY(edit_password)));
  /* Do this to cause .plugin to be written to conf...removed this in the prefs 
     after implementing plugin loading... */
  gchar *plugin = g_strdup_printf("%s.plugin", gtk_button_get_text(pulldown_plugins)); 
  conf->writeConfigKey("Plugin",plugin);

  gboolean hideipc = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(toggle_hideipc));
  conf->writeConfigKey("HideIPCShares", g_strdup_printf("%d",hideipc));
  gboolean showdebug = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(toggle_showdebuginfo));
  conf->writeConfigKey("ShowDebugInfo", g_strdup_printf("%d",showdebug));
  gboolean showtooltips = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(toggle_showtooltips));
  conf->writeConfigKey("ShowTooltips", g_strdup_printf("%d",showtooltips));

  gchar *browser = g_strdup(gtk_entry_get_text(GTK_ENTRY(edit_browser)));
  if (strlen(browser) > 0) {
    conf->writeConfigKey("Browser", gtk_entry_get_text(GTK_ENTRY(edit_browser)));
  } else {
    popup_dialog(150, "Warning", "Please enter a file browser!", "Ok");
  }

  return TRUE;
}

gint on_close(GtkWidget *widget, JagsPrefsDialog *pd) {
  on_cancel(widget, pd);
  return TRUE;
}

/*
main(int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  JagsPrefsDialog *d = new JagsPrefsDialog();;

  gtk_main ();
}
*/
