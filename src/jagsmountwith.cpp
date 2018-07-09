/*
 **  JagsMountWith v0.1.1
 **  Copyright (C) 2000-2001 Daniel Sundberg
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
 ** jagsmountwith.cpp
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Sun Jul 16 20:00:00 2000 Daniel Sundberg 
 ** Last update Mon Mar  5 21:31:00 2001 Daniel Sundberg
 */

#include <gtk/gtk.h>
#include <stdlib.h>
#include "jagsmountwith.h"
#include "jagsconfig.h"
#include "gtk_common.h"
//#include "jagsmenubar.h"

GtkWidget *entry_username;
GtkWidget *entry_password;
GtkWidget *dialog1;
JagsMenuBar *mount_with_menubar;
JagsConfig *conf2;
Mount *mnt2;
gint rresult;
JagsMntsWindow *mw_mnts_window;
JagsMountWith::JagsMountWith(JagsConfig *iconf, gchar *i1, gchar *i2, JagsMenuBar *ijmb, 
			     Mount *imnt, JagsMntsWindow *mw) {
  GtkWidget *dialog_vbox1;
  GtkWidget *vbox1;
  GtkWidget *label1;
  GtkWidget *dialog_action_area1;
  GtkWidget *hbuttonbox1;
  GtkWidget *mount_with_ok;
  GtkWidget *mount_with_cancel;

  mw_mnts_window = mw;
  conf2 = iconf;
  mnt2 = imnt;
  /* Assign menubar ptr */

  mount_with_menubar = ijmb;
  server_name = g_strdup(i1);
  share_name = g_strdup(i2);

  /* Init the dialog box */
  dialog1 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog1), "Mount with...");
  gtk_window_set_policy (GTK_WINDOW (dialog1), TRUE, TRUE, FALSE);

  /* Put a vertical box into the dialog */
  dialog_vbox1 = GTK_DIALOG (dialog1)->vbox;
  gtk_widget_show (dialog_vbox1);

  vbox1 = gtk_vbox_new (FALSE, 0);
  //vbox1 = dialog_vbox1;
  gtk_widget_show (vbox1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), vbox1, TRUE, TRUE, 0);

  /* Define a label to display additional info */
  label1 = gtk_label_new("Mount with username andd pasword (use this when you want to mount a share which is protected with a username and maybe a password, obs: the password is sent in plain text and this means that you shouldn't type any important passwords here):");
  gtk_widget_show (label1);
  gtk_box_pack_start (GTK_BOX (vbox1), label1, FALSE, FALSE, 0);
  gtk_label_set_line_wrap (GTK_LABEL (label1), TRUE);

  /* The username and password text-entries */
  
  /* Add a horizontal box to the dialog */
  GtkWidget *hbox = gtk_hbox_new (TRUE, 2);
  gtk_widget_show(hbox);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox, TRUE, TRUE, 0);

  /* Add a label to the horizontal box */
  label1 = gtk_label_new("Username:");
  gtk_widget_show (label1);
  gtk_box_pack_start (GTK_BOX(hbox), label1, FALSE, FALSE, 0);
  gtk_label_set_line_wrap(GTK_LABEL(label1), TRUE);

  /* Add username entry to the hbox */
  entry_username = gtk_entry_new ();
  gtk_entry_set_text(GTK_ENTRY(entry_username), conf2->get_username());
  gtk_widget_show(entry_username);
  gtk_box_pack_start(GTK_BOX(hbox), entry_username, FALSE, FALSE, 3);

  /* Add another horizontal box to the dialog */
  hbox = gtk_hbox_new (TRUE, 2);
  gtk_widget_show(hbox);
  gtk_box_pack_start(GTK_BOX(vbox1), hbox, TRUE, TRUE, 0);

  /* Add a label to the horizontal box */
  label1 = gtk_label_new("Password:");
  gtk_widget_show (label1);
  gtk_box_pack_start(GTK_BOX(hbox), label1, FALSE, FALSE, 0);
  gtk_label_set_line_wrap(GTK_LABEL(label1), TRUE);

  /* Add password entry to the hbox */
  entry_password = gtk_entry_new ();
  gtk_entry_set_visibility(GTK_ENTRY(entry_password), FALSE);
  gtk_entry_set_text(GTK_ENTRY(entry_password), conf2->get_password());
  gtk_widget_show(entry_password);
  gtk_box_pack_start(GTK_BOX(hbox), entry_password, FALSE, FALSE, 3);

  /* Setup the dialog buttons */
  dialog_action_area1 = GTK_DIALOG (dialog1)->action_area;
  gtk_widget_show (dialog_action_area1);
  gtk_container_set_border_width (GTK_CONTAINER (dialog_action_area1), 10);

  /* The buttons */
  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (dialog_action_area1), hbuttonbox1, TRUE, TRUE, 0);

  mount_with_ok = gtk_button_new_with_label_with_pixmap("OK", "ok.xpm");
  gtk_widget_show (mount_with_ok);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), mount_with_ok);
  GTK_WIDGET_SET_FLAGS (mount_with_ok, GTK_CAN_DEFAULT);

  mount_with_cancel = gtk_button_new_with_label_with_pixmap("Cancel", "cancel.xpm");
  gtk_widget_show (mount_with_cancel);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), mount_with_cancel);
  GTK_WIDGET_SET_FLAGS (mount_with_cancel, GTK_CAN_DEFAULT);

  gtk_signal_connect (GTK_OBJECT (mount_with_ok), "clicked",
		      GTK_SIGNAL_FUNC (on_mount_with_ok),
		      NULL);
  gtk_signal_connect (GTK_OBJECT (mount_with_cancel), "clicked",
		      GTK_SIGNAL_FUNC (on_mount_with_cancel),
		      NULL);
  gtk_widget_show(dialog1);
}


JagsMountWith::~JagsMountWith() {

}

gint JagsMountWith::get_result(void) {
  return rresult;
}

void JagsMountWith::browse(void) {
  JagsConfig *conf = new JagsConfig();
  gchar *server = g_strdup(g_strchomp(mount_with_menubar->get_server_name()));
  g_strup(server);
  gchar *command = g_strdup_printf("%s \"%s/%s/%s\" &", conf->get_browser(), conf->get_mount_dir(), server, mount_with_menubar->get_share_name());
  if (conf->get_show_debug()) g_print("%s\n", command);
  system(command);
}

gint on_mount_with_ok(GtkWidget *widget, JagsMountWith *mw) {
  gchar *username = gtk_entry_get_text(GTK_ENTRY(entry_username));
  gchar *password = gtk_entry_get_text(GTK_ENTRY(entry_password));
  
  rresult = mnt2->addMount(mount_with_menubar->get_server_name(), mount_with_menubar->get_share_name(), username, password);

  if (conf2->get_show_debug())
    g_print("result == %d\n", rresult);
  if (rresult == OK) {
    /* Do nothing */
    gtk_widget_destroy(dialog1);
    mw->browse();
    gchar *server = g_strdup(mount_with_menubar->get_server_name());
    g_strup(server);
    gchar *mnt = g_strdup_printf("//%s/%s", server, mount_with_menubar->get_share_name());
    gchar *mntpath = g_strdup_printf("%s/%s/%s", conf2->get_mount_dir(), server, 
				     mount_with_menubar->get_share_name());
    mw_mnts_window->addMount(mnt, mntpath);
  } else if (rresult == ERROR) {
    /* Popup mount with here */
    popup_dialog(200, "Error:", "Error mounting the share\nProbably bad password", "Ok");
    return TRUE;
  } else {
    popup_dialog(200, "Error:", "Share probably already mounted...", "Ok");
    gtk_widget_destroy(dialog1);
    return TRUE;
  }
  mount_with_menubar->toggle_on_mount();

  return TRUE;
}

gint on_mount_with_cancel(GtkWidget *widget, JagsMountWith *mw) {
  gtk_widget_destroy(dialog1);
  return TRUE;
}



/* Sample main test function */			      
/*
main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);
  JagsMountWith *m = new JagsMountWith(new JagsConfig());
  gtk_main();
} 
*/
