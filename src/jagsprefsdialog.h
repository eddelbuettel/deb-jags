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
 ** jagsprefsdialog.h 0.1
 **
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Tue Jul  11 20:12:00 2000 Daniel Sundberg 
 ** Last update Thu Aug  24 13:42:00 2000 Daniel Sundberg
 */

#ifndef __JAGSPREFSDIALOG_H
#define __JAGSPREFSDIALOG_H

#include <gtk/gtk.h>
#include "jagsconfig.h"

class JagsPrefsDialog {
private:
  /* Change these to provate again */
  //GtkWidget *edit_workgroup;
  //GtkWidget *edit_browser; 
  //GtkWidget *edit_mountdir; 
  //GtkWidget *toggle_hideipc; 
  //GtkWidget *pulldown_plugins; 
  //GtkWidget *window;
  JagsConfig *config;
  friend gint onPluginsChanged(GtkWidget *, GdkEvent *, gpointer, JagsPrefsDialog *pd);
  friend gint on_cancel(GtkWidget *widget, JagsPrefsDialog *pd);
  friend gint on_apply(GtkWidget *widget, JagsPrefsDialog *pd);
  friend gint on_close(GtkWidget *widget, JagsPrefsDialog *pd);

public:
  JagsPrefsDialog(JagsConfig *iconfig);
  ~JagsPrefsDialog();
};

#endif
