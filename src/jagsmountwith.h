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
#include <gtk/gtk.h>
#include "jagsconfig.h"
#include "jagsmenubar.h"
#include "jagsmntswindow.h"

#ifndef __JAGSMOUNTWITH_H
#define __JAGSMOUNTWITH_H


class JagsMountWith {
 private:
  gchar *server_name, *share_name;
  friend gint on_mount_with_ok(GtkWidget *, JagsMountWith *);
  friend gint on_mount_with_cancel(GtkWidget *, JagsMountWith *);
 public:
  JagsMountWith(JagsConfig *, gchar *, gchar *, JagsMenuBar *, 
		Mount *imnt, JagsMntsWindow *mw);
  ~JagsMountWith();
  gint get_result(void);
  void browse(void);
};

#endif
