/*
 **  JagsMenuaBar v0.1
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
 ** Started on  Mon Jul  3 20:00:00 2000 Daniel Sundberg 
 ** Last update Mon May  7 17:23:00 2001 Daniel Sundberg
 */


#ifndef __JAGSMENUBAR_H
#define __JAGSMENUBAR_H

#include <gtk/gtk.h>
#include "jagsconfig.h"
#include "mount.h"

class JagsMenuBar {
private:
  GtkWidget *handlebox;
  GtkWidget *menubar;
  GtkWidget *menu;
  GtkWidget *menuitem;
  JagsConfig *conf;

  //gchar *server_name;
  //gchar *filter(gchar *);
public:  

  friend gint mount_and_browse(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint browse(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint mount(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint mount_with(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint mount_with_command(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint preferences(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint about(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint search(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint umount(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint mnts_window(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint bookmark_menu(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint bookmark_add(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint bookmark_edit(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);
  friend gint bookmark_selected(GtkMenuItem *item, gpointer *data, JagsMenuBar *jmb);

 
 JagsMenuBar(GtkWidget *vbox, JagsConfig *conf, Mount *imount);
  ~JagsMenuBar();
  void mount_and_browse_ex(GtkMenuItem *item, gpointer *data);
  GtkWidget *get_popupmenu(void);
  void toggle_menu_items(gboolean view);
  void set_server_name(gchar *name);
  void set_share_name(gchar *name);
  gchar *get_server_name(void);
  gchar *get_share_name(void);

  void toggle_browse(gboolean value);
  void toggle_mount_and_browse(gboolean value);
  void toggle_mount(gboolean value);
  void toggle_mount_with(gboolean value);
  void toggle_greyall(void);
  void toggle_on_share_select(void);
  void toggle_on_mount(void);
  void toggle_mount_with_command(gboolean value);
};



#endif
