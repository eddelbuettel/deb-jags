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


#ifndef __JAGSMENUBAR_H
#define __JAGSMENUBAR_H

#include <gtk/gtk.h>
#include "jagsconfig.h"
#include "mount.h"
#include "mainwindow.h"

class JagsMenuBar;
gint mount_and_browse(GtkMenuItem *item, JagsMenuBar *jmb);
gint browse(GtkMenuItem *item, JagsMenuBar *jmb);
gint mount(GtkMenuItem *item, JagsMenuBar *jmb);
gint mount_with(GtkMenuItem *item, JagsMenuBar *jmb);
gint mount_with_command(GtkMenuItem *item, JagsMenuBar *jmb);
gint preferences(GtkMenuItem *item, JagsConfig *conf);
gint about(GtkMenuItem *item, JagsMenuBar *jmb);
gint my_search(GtkMenuItem *item, JagsMenuBar *jmb);
gint umount(GtkMenuItem *item, JagsMenuBar *jmb);
gint mnts_window(GtkMenuItem *item, JagsMenuBar *jmb);
gint bookmark_menu(GtkMenuItem *item, JagsMenuBar *jmb);
gint bookmark_add(GtkMenuItem *item, JagsMenuBar *jmb);
gint bookmark_edit(GtkMenuItem *item, JagsMenuBar *jmb);
gint bookmark_selected(GtkMenuItem *item, JagsMenuBar *jmb);
gint bookmarks_add_edit(GtkMenuItem *item, JagsMenuBar *jmb);
void bookmarks_radio_local_toggle (GtkWidget *widget, gpointer data);
gint bookmarks_edit_add_close(GtkWidget *widget, gpointer data);
gint bookmarks_edit_add_ok(GtkWidget *widget, gpointer data);

class JagsMenuBar
{
private:
  GtkWidget *handlebox;
  GtkWidget *menubar;
  GtkWidget *menu;
  GtkWidget *menuitem;

  //gchar *server_name;
  //gchar *filter(gchar *);
public:  
  JagsConfig *conf;

  friend gint mount_and_browse(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint browse(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint mount(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint mount_with(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint mount_with_command(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint preferences(GtkMenuItem *item, JagsConfig *conf);
  friend gint about(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint my_search(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint umount(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint mnts_window(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint bookmark_menu(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint bookmark_add(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint bookmark_edit(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint bookmark_selected(GtkMenuItem *item, JagsMenuBar *jmb);
  friend gint bookmarks_add_edit(GtkMenuItem *item, JagsMenuBar *jmb);
  friend void bookmarks_radio_local_toggle (GtkWidget *widget, gpointer data);
  friend gint bookmarks_edit_add_close(GtkWidget *widget, gpointer data);
  friend gint bookmarks_edit_add_ok(GtkWidget *widget, gpointer data);

  JagsMenuBar(GtkWidget *vbox, GtkWidget *itree, JagsConfig *conf, 
	      Mount *imount, MainWindow *mainw);
  ~JagsMenuBar();

  void mount_and_browse_ex(GtkMenuItem *item, JagsMenuBar *jmb);
  GtkWidget *get_popupmenu(void);
  void toggle_menu_items(gboolean view);
  void set_server_name(gchar *name);
  void set_share_name(gchar *name);
  void set_workgroup_name(gchar *name);
  void set_localmasterbrowser_name(gchar *name);
  void set_remotelocalmasterbrowser_name(gchar *name);
  gchar *get_server_name(void);
  gchar *get_share_name(void);
  gchar *get_workgroup_name(void);
  gchar *get_localmasterbrowser_name(void);
  gchar *get_remotelocalmasterbrowser_name(void);

  void toggle_browse(gboolean value);
  void toggle_mount_and_browse(gboolean value);
  void toggle_mount(gboolean value);
  void toggle_mount_with(gboolean value);
  void toggle_greyall(void);
  void toggle_on_share_select(void);
  void toggle_on_mount(void);
  void toggle_mount_with_command(gboolean value);
  void toggle_unshade(void);
  
  GtkWidget *main_tree;

};

#endif
