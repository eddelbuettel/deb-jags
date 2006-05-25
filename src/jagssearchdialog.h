/*
 **  JagsSearchDialog v0.1
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
 ** jagsmenubar.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Wed Dec 13 16:32:00 2000 Daniel Sundberg 
 ** Last update Mon Feb 12 17:41:00 2001 Daniel Sundberg
 */

#ifndef __JAGSSEARCHDIALOG_H
#define __JAGSSEARCHDIALOG_H

#include <gtk/gtk.h>
#include "jagsmenubar.h"
#include "mount.h"

class JagsSearchDialog;
gint search_clicked(GtkWidget *widget, JagsSearchDialog *me);
gint on_close(GtkWidget *widget, JagsSearchDialog *me);
gint onn_collapse(GtkWidget *item, JagsSearchDialog *mw);
gint expandd_server(GtkWidget *widget, JagsSearchDialog *mw);
gint onn_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data, JagsSearchDialog *mw);
gint check_dd_click(GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw);
gint button_presss (GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw);

class JagsSearchDialog {
private:
  Mount *mnt;
  GtkWidget *search_string;
  GtkWidget *tree;
  GtkWidget *subtree;
  GtkWidget *scrolled_window;
  friend gint search_clicked(GtkWidget *widget, JagsSearchDialog *me);
  friend gint on_close(GtkWidget *widget, JagsSearchDialog *me);
  friend gint onn_collapse(GtkWidget *item, JagsSearchDialog *mw);
  friend gint expandd_server(GtkWidget *widget, JagsSearchDialog *mw);
  friend gint onn_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data, JagsSearchDialog *mw);
  friend gint check_dd_click(GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw);
  friend gint button_presss (GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw);
public:  
  JagsSearchDialog(Mount *imnt, JagsMenuBar *imb);
  void set_string(gchar *s);
};



#endif
