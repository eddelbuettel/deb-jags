/*
 **  Copyright (C) 2001-2003 Daniel Sundberg <sumpan@sumpan.com>
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
 */

#ifndef __JAGSMNTSWINDOW_H
#define __JAGSMNTSWINDOW_H

#include <gtk/gtk.h>
#include "jagsconfig.h"
#include "mount.h"

class JagsMntsWindow
{
private:
  GList *actual_mounts;
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
  friend gint mw_button_press(GtkWidget *widget, GdkEventButton *event, 
			      JagsMntsWindow *me);

public:  
  JagsMntsWindow(Mount *imnt, JagsConfig *iconf);
  ~JagsMntsWindow();
  void addMount(gchar *mnt, gchar *mntpath, gint i=0);
  void update(void);
  void show(void);
  void update_from_kernel(void);
  void clear_list(void);

};

#endif
