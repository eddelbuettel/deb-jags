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
#include <stdlib.h>
#include <string.h>
#include "jagsmountwithcommand.h"
#include "jagsconfig.h"
#include "gtk_common.h"

GtkWidget *entry11;
GtkWidget *dialog11;

JagsMountWithCommand::JagsMountWithCommand(JagsConfig *conf)
{
  GtkWidget *dialog_vbox1;
  GtkWidget *vbox1;
  GtkWidget *label1;
  GtkWidget *dialog_action_area1;
  GtkWidget *hbuttonbox1;
  GtkWidget *mount_with_ok;
  GtkWidget *mount_with_cancel;

  dialog11 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog11), "Mount with command...");
  gtk_widget_set_usize(dialog11, 500, 200);

  dialog_vbox1 = GTK_DIALOG (dialog11)->vbox;
  gtk_widget_show (dialog_vbox1);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), vbox1, TRUE, TRUE, 0);

  label1 = gtk_label_new("Mount with command\n(For example, use this "
			 "when you want to mount a share which is password "
			 "protected and you want full control of what's executed):");
  gtk_widget_show (label1);
  gtk_box_pack_start (GTK_BOX (vbox1), label1, TRUE, FALSE, 0);
  gtk_label_set_line_wrap (GTK_LABEL (label1), TRUE);

  entry11 = gtk_entry_new ();
  gtk_widget_show (entry11);
  gtk_box_pack_start (GTK_BOX (vbox1), entry11, FALSE, FALSE, 3);

  dialog_action_area1 = GTK_DIALOG (dialog11)->action_area;
  gtk_widget_show (dialog_action_area1);
  gtk_container_set_border_width (GTK_CONTAINER (dialog_action_area1), 10);

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
		      GTK_SIGNAL_FUNC (on_mount_with_command_ok), NULL);
  gtk_signal_connect (GTK_OBJECT (mount_with_cancel), "clicked", 
		      GTK_SIGNAL_FUNC (on_mount_with_command_cancel), NULL);
  gtk_widget_show(dialog11);
}


JagsMountWithCommand::~JagsMountWithCommand()
{
}

gint on_mount_with_command_ok(GtkWidget *widget, JagsMountWithCommand *mw)
{
  gchar *command = NULL;
  gboolean flag = TRUE;

  /* check that we don't do anything nasty here */
  command = gtk_entry_get_text(GTK_ENTRY(entry11));
  if (strstr(command,"|")) flag = FALSE;
  if (strstr(command,">")) flag = FALSE;
  if (strstr(command,"<")) flag = FALSE;
  if (strstr(command,"rm ")) flag = FALSE;
  if (strstr(command,"rmdir ")) flag = FALSE;
  if (strstr(command,"kill ")) flag = FALSE;
  if (strstr(command,"chmod ")) flag = FALSE;
  if ( !( (!strstr(command, "mount")) || 
	  (!strstr(command, "shlight")) || 
	  (!strstr(command, "smbclient")) )) 
    flag = FALSE;

  if (flag) 
    system(command);
  else 
    g_print("Banned command. Security risk encountered\n");
  gtk_widget_destroy(dialog11);

  return TRUE;
}

gint on_mount_with_command_cancel(GtkWidget *widget, JagsMountWithCommand *mw) {
  gtk_widget_destroy(dialog11);
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
