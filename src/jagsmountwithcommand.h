/*
 **  JagsMountWithCommand v0.1
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
 ** jagsmountwithcommand.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Thu Oct  5 17:09:00 2000 Daniel Sundberg 
 ** Last update Thu Oct  5 17:09:00 2000 Daniel Sundberg
 */

#include "jagsconfig.h"

#ifndef __JAGSMOUNTWITHCOMMAND_H
#define __JAGSMOUNTWITHCOMMAND_H


class JagsMountWithCommand {
 private:
  friend gint on_mount_with_command_ok(GtkWidget *, JagsMountWithCommand *);
  friend gint on_mount_with_command_cancel(GtkWidget *, JagsMountWithCommand *);
 public:
  JagsMountWithCommand(JagsConfig *conf);
  ~JagsMountWithCommand();
};


#endif
