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
 */

#ifndef __JAGSCONFIG_H
#define __JAGSCONFIG_H

#include <gtk/gtk.h>
#include "cconfig.h"

#define JAGS_CONFIG_FILE_NAME ".jags/jags.conf"

struct JagsConf
{
  gchar *mount_dir;
  gchar *workgroup;
  gchar *wins;
  gchar *plugin;
  gchar *browser;
  gchar *sound_params;
  gboolean sound_enabled;
  gboolean hide_ipc_shares;
  gboolean show_debug;
  gboolean show_tooltips;
  gint nMnts;
  gint nBmarks;
  gchar *username;
  gchar *password;
  gchar *searchfor;
  gint isset;
  GList *mnts;
  GList *bmarks;
};

class JagsConfig
{
 private:
  JagsConf conf;
  CConfig *cfile;

 public:
  JagsConfig();
  ~JagsConfig();

  gchar *get_mount_dir(void);
  gchar *get_workgroup(void);
  gchar *get_wins(void);
  gchar *get_plugin(void);
  gchar *get_browser(void);
  gchar *get_sound_params(void);
  gboolean get_sound_enabled(void);
  gboolean get_hide_ipc_shares(void);
  gboolean get_show_debug(void);
  gboolean get_show_tooltips(void);
  gchar *get_username(void);
  gchar *get_password(void);

  gint get_nMnts(void);
  void addMnt(gchar *mnt, gchar *mntpath);
  void delMnt(gchar *mnt);
  GList *get_mnts(void);

  gint get_nBmarks(void);
  void addBmark(gchar *server, gchar *workgroup);
  void delBmark(gchar *server);
  GList *get_bmarks(void);

  void set_searchfor(gchar *s);
  gchar *get_searchfor(void);
  void reload();
  gint searchisset(void);
  void setsearchfor(gint i);
};

#endif
 
