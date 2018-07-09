/*
 **  GtkCommon v0.1
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
 ** gtk_common.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se/software/jags
 ** 
 ** Started on  Sun Jul  30 17:53:00 2000 Daniel Sundberg 
 ** Last update Tue Mar   3 20:40:00 2001 Daniel Sundberg
 */

#include <gtk/gtk.h>

#ifndef __GTK_COMMON_H
#define __GTK_COMMON_H

GtkWidget *xpm_label_box(GtkWidget *parent, gchar *xpm_filename, gchar *label_text);
gchar *xpm_label_box_get_text(GtkWidget *);
GtkWidget *gtk_button_new_with_label_with_pixmap(gchar *label, gchar *pixmap);
gchar *gtk_button_get_text(GtkWidget *button);
GtkWidget *gtk_menu_item_new_with_label_with_pixmap(gchar *label, gchar *pixmap);
gchar *gtk_menu_item_get_text(GtkWidget *menu_item);
GtkWidget *gtk_tree_item_new_with_label_with_pixmap(gchar *label, gchar *pixmap);
gchar *gtk_tree_item_get_text(GtkWidget *tree_item);
GtkWidget *gtk_option_menu_new_with_glist(GList *glist);
void gtk_combo_set_default_text(GtkWidget *combo, gchar *text);
GtkWidget *gtk_icon2widget(gchar *icon, GtkWidget *parent);

/* Funtions by Robert Kling (robkli-8@student.luth.se */
void popup_dialog(gint height, gchar *title, gchar *text, gchar *button_text);
gint close_popup_dialog(GtkWidget *widget, gpointer data);

#endif
