/*
 **  Copyright (C) 2000-2003 Daniel Sundberg <sumpan@sumpan.com>
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
 ** Jags contact information:
 ** Made by:    Daniel Sundberg
 ** E-Mail:     sumpan@sumpan.com
 ** Homepage:   http://jags.sf.net
 ** 
 ** ChangeLog:
 **
 **   Sat Aug 9 2003 Daniel Sundberg <sumpan@sumpan.com>
 **     - Coding style
 **
 **   Mon June 30 2003 Anatoly Demchishin <demch@iptelecom.net.ua>
 **     - Various updates
 **
 **   May 2001 mike@penbex.com.tw
 **     - Quote spaces
 */

#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <gtk/gtk.h>

class MainWindow
{
private:
  /* Callbacks */
  friend gint expand_network(GtkWidget *widget, MainWindow *mw);
  friend gint expand_workgroup(GtkWidget *widget, MainWindow *mw);
  friend gint expand_server(GtkWidget *widget, GtkTree *root_tree);
  friend gint on_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data);
  friend gint on_workgroup_selected(GtkTree *tree, GtkWidget *widget, GtkTree *root_tree);
  friend gint check_d_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw);
  friend gint button_press(GtkWidget *, GdkEventButton *, MainWindow *mw);
  void debug(gchar *txt);
  void tooltip(GtkWidget *widget, gchar *txt);
public:
  MainWindow(int argc, char *argv[]);
  ~MainWindow();
  void run(void);
  GtkWidget *tree;
};

gint on_collapse(GtkWidget *item, MainWindow *mw);
gint check_server_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw);

#endif
