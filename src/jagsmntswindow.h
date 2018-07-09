/*
 **  JagsMntsWindow v0.1
 **  Copyright (C) 2001 Daniel Sundberg
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
 ** jagsmntswindow.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Thu Mar 22 14:59:00 2001 Daniel Sundberg 
 ** Last update Thu Mar 22 23:13:00 2001 Daniel Sundberg 
 */

#ifndef __JAGSMNTSWINDOW_H
#define __JAGSMNTSWINDOW_H

#include <gtk/gtk.h>
#include "jagsconfig.h"
#include "mount.h"

class JagsMntsWindow {
private:

  gchar *browse_path;
  //  gint selected_row, selected_col;
  //  GtkWidget *scrolled_window;
  friend gint close_mntswindow(GtkWidget *widget, JagsMntsWindow *me);
  friend gint toggle_automount(GtkWidget *widget, JagsMntsWindow *me);
  friend gint unmount_share(GtkWidget *widget, JagsMntsWindow *me);
  friend gint mnts_browse(GtkWidget *widget, JagsMntsWindow *me);
  friend gint change_mnt_path(GtkWidget *widget, JagsMntsWindow *me);
  friend void selection_made(GtkWidget *, gint, gint, GdkEventButton *, 
			     gpointer, JagsMntsWindow *);
  friend gint mw_button_press(GtkWidget *widget, GdkEventButton *event, JagsMntsWindow *me);
public:  
  JagsMntsWindow(Mount *imnt, JagsConfig *iconf);
  void addMount(gchar *mnt, gchar *mntpath);
  void update();
  void show();

};

#endif
