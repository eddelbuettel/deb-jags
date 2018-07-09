/*
 **  data v0.1
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
 ** data.h
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Started on  Mon Jul  3 20:00:00 2000 Daniel Sundberg 
 ** Last update Sat Jul 15 22:58:00 2000 Daniel Sundberg
 */

#ifndef __DATA_H
#define __DATA_H

#include <gtk/gtk.h>

class Data {
 private:
  GList *glist;
 public:
  Data(const gchar *fetchCommand, const gchar *plugin);
  ~Data();
  GList *getData(void);
};

#endif
