/*
 **  CMount v0.1
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
 ** data.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Sat Feb 17 21:10:00 2001 Daniel Sundberg 
 ** Last update Sat Feb 17 21:10:00 2001 Daniel Sundberg
 */

#ifndef __MOUNT_H
#define __MOUNT_H

#include <gtk/gtk.h>
#include <string.h>

#include "jagsconfig.h"

#define OK 1
#define ERROR -1

class Mount {
 private:
  GList *mounts;
  gchar *last_error;
  JagsConfig *cfg;
 public:
  Mount(JagsConfig *);
  gint addMount(gchar *iserver, gchar *ishare, gchar *iusername = (gchar *)NULL, gchar *ipassword = (gchar *)NULL);
  gint addMountWithPath(gchar *iservershare, gchar *imountpath);
  gint rmMount(gchar *mnt);
  gchar *getLastError(void);
  gint uMountAll(void);
  ~Mount();

};

#endif
