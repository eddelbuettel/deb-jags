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

#ifndef __MOUNT_H
#define __MOUNT_H

#include <gtk/gtk.h>
#include <string.h>

#include "jagsconfig.h"

#define OK 1
#define ERROR -1

class Mount
{
 private:
  gchar *last_error;
  JagsConfig *cfg;
 public:
  GList *mounts;
  Mount(JagsConfig *);
  ~Mount();

  gint addMount(gchar *iserver, gchar *ishare, gchar *iworkgroup=(gchar *)NULL, 
		gchar *irmb=(gchar *)NULL, gchar *iusername=(gchar *)NULL, 
		gchar *ipassword=(gchar *)NULL );
  gint addMountWithPath(gchar *iservershare, gchar *imountpath);
  gint rmMount(gchar *mnt);
  gchar *getLastError(void);
};

#endif
