/*
 **  Data v0.1
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
 ** data.cpp
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se/software/jags
 ** 
 ** Started on  Mon Jul  3 20:00:00 2000 Daniel Sundberg 
 ** Last update Mon Mar 19 23:01:00 2001 Daniel Sundberg
 */

#include <gtk/gtk.h>
//#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

/*
 * This constructor will run the fetchCommand and store 
 * the result in a GList.
 *
 */
Data::Data(const gchar *fetchCommand, const gchar *plugin) {
  glist = g_list_alloc();
  
  /* Open the outfile and read the contents, put this in the GList */
  gchar *path = g_get_home_dir();
  gchar *file = g_strdup_printf("%s/.jags/outfile", path);
  
  /* Wants to run a script in the plugin-dir and output it to "file" */
  gchar *command = g_strdup_printf("sh %s/.jags/plugins/%s/%s > %s", path, plugin, fetchCommand, file);
  system(command);

  ifstream fin(file);

  /* Check if we could open the file */
  if (fin) {
    /* Read the file content and feed the list until we're done
       Here we need to check wheter the file have content or not... */
    while (fin.good()) {
      gchar *buffer = g_new(gchar, 100);
      fin.getline(buffer, 100, '\n');
      gint i = strlen(buffer);
      if (i > 1) {
	glist = g_list_append(glist, buffer);
      }
    }
    fin.close();
  } else {
    g_print("Couldn't open %s\n", file);
  }
}

Data::~Data() {
  g_list_free(glist);
}

GList *Data::getData(void) {
  return glist;
}

/*
main() {
  Data *d = new Data("fetch_master_browser.sh 6AN", "offline.plugin");
  GList *glist = d->getData();
  while (glist->next) {
    glist = glist->next;
    cout << (gchar *)glist->data << '\n';
  }
  return 0;
} 

*/
