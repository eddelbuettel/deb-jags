/*
 **  jagsConfig v0.1.1
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
 ** jagsconfig.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se/software/jags
 ** 
 ** Started on  Thi Jul  13 18:28:00 2000 Daniel Sundberg 
 ** Last update Wed Mar  21 22:42:00 2001 Daniel Sundberg
 */

#ifndef __JAGSCONFIG_H
#define __JAGSCONFIG_H

#include <gtk/gtk.h>
#include "cconfig.h"

#define JAGS_CONFIG_FILE_NAME ".jags/jags.conf"

struct JagsConf {
  gchar *mount_dir;
  gchar *workgroup;
  gchar *plugin;
  gchar *browser;
  gboolean hide_ipc_shares;
  gboolean show_debug;
  gboolean show_tooltips;
  gint nMnts;
  gchar *username;
  gchar *password;
  gchar *searchfor;
  gint isset;
  GList *mnts;
};

class JagsConfig {
private:
  JagsConf conf;
  CConfig *cfile;
public:
  JagsConfig();
  ~JagsConfig();
  gchar *get_mount_dir(void);
  gchar *get_workgroup(void);
  gchar *get_plugin(void);
  gchar *get_browser(void);
  gboolean get_hide_ipc_shares(void);
  gboolean get_show_debug(void);
  gboolean get_show_tooltips(void);
  gchar *get_username(void);
  gchar *get_password(void);
  gint get_nMnts(void);
  void addMnt(gchar *mnt, gchar *mntpath);
  void delMnt(gchar *mnt, gchar *mntpath);
  GList *get_mnts(void);
  void set_searchfor(gchar *s);
  gchar *get_searchfor(void);
  void reload(void);
  gint searchisset(void);
  void setsearchfor(gint i);
};


#endif
 
