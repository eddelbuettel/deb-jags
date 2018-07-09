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
 ** jagsabout.cpp 0.1.1
 **
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Sun Jul  15 23:35:00 2000 Daniel Sundberg 
 ** Last update Wed Aug  23 11:37:00 2000 Daniel Sundberg
 */

#include <stdlib.h>
#include <fstream.h>
#include <string.h>

#include "jags.h"
#include "jagsabout.h"
#include "gtk_common.h"

GtkWidget *about_window;

JagsAbout::JagsAbout() {
  GtkWidget *vbox, *scrolledwindow, *text, *action_area, *button;

  /* Create the dialog window */
  about_window = gtk_dialog_new ();
  gtk_window_set_title(GTK_WINDOW(about_window), "About jags...");
  gtk_window_set_policy(GTK_WINDOW(about_window), TRUE, TRUE, FALSE);

  /* Setup the scolled window & text */
  vbox = GTK_DIALOG(about_window)->vbox;
  gtk_widget_show(vbox);

  scrolledwindow = gtk_scrolled_window_new(NULL, NULL);
  gtk_widget_show(scrolledwindow);
  gtk_box_pack_start(GTK_BOX(vbox), scrolledwindow, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledwindow), 
                                 GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  text = gtk_text_new(NULL, NULL);
  gtk_widget_show(text);
  gtk_container_add(GTK_CONTAINER(scrolledwindow), text);
  gtk_widget_realize(text);
  gtk_widget_set_usize(about_window, 500, 400);
  gchar *titleinfo = g_strdup_printf("%s %s\n", PROGRAM_NAME, VERSION);
  gchar *cr = g_strdup_printf("Copyright (C) 2000-2001 %s\n\n", AUTHOR);
  gchar *info1 = g_strdup_printf("Made by:  %s\nE-mail:  %s\nHomepage:  %s\n\n", AUTHOR, EMAIL, HOMEPAGE);
  gchar *started = g_strdup_printf("Started on %s %s\n", STARTEDON, AUTHOR);
  gchar *lastup = g_strdup_printf("Last updated on %s %s\n\n", LASTUPDATE, AUTHOR);
  gchar *gpl = g_strdup_printf("%s", INFO);
  gtk_text_insert(GTK_TEXT(text), NULL, NULL, NULL, titleinfo, -1);
  gtk_text_insert(GTK_TEXT(text), NULL, NULL, NULL, cr, -1);  
  gtk_text_insert(GTK_TEXT(text), NULL, NULL, NULL, info1, -1);
  gtk_text_insert(GTK_TEXT(text), NULL, NULL, NULL, started, -1);
  gtk_text_insert(GTK_TEXT(text), NULL, NULL, NULL, lastup, -1);
  gtk_text_insert(GTK_TEXT(text), NULL, NULL, NULL, gpl, -1);
  action_area = GTK_DIALOG(about_window)->action_area;
  gtk_widget_show(action_area);
  gtk_container_set_border_width(GTK_CONTAINER(action_area), 10);

  /* the button */
  button = gtk_button_new_with_label_with_pixmap("Big deal...", "ok.xpm");
  gtk_widget_show(button);
  gtk_box_pack_start(GTK_BOX(action_area), button, FALSE, FALSE, 0);

  gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(on_close), NULL);

  gtk_widget_show(about_window);
}

JagsAbout::~JagsAbout() {

}


gint on_close(GtkWidget *widget, JagsAbout *about) {
  gtk_widget_destroy(about_window);
  return TRUE;
}

/*
main(int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  JagsAbout *a = new JagsAbout();;
  gtk_main ();
}
*/
