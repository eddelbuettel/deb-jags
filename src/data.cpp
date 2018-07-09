/*
 **  Copyright (C) 2000-2003 Daniel Sundberg & Anatoly Demchishin
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
 */

#include <gtk/gtk.h>
//#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

#include "data.h"

/* This constructor will run the fetchCommand and store the result in a GList */
Data::Data(const gchar *fetchCommand, const gchar *plugin)
{
  gchar *path = NULL, *file = NULL, *command = NULL;
  gint j;
  gint i;

  glist = g_list_alloc();
  
  /* Open the outfile and read the contents, put this in the GList */
  path = g_get_home_dir();
  file = g_strdup_printf("%s/.jags/outfile", path);
  
  /* Wants to run a script in the plugin-dir and output it to "file" */
  command = g_strdup_printf("sh %s/.jags/plugins/%s/%s > %s", path, plugin, 
			    fetchCommand, file);
  system(command);
  g_free(command);

  ifstream fin(file);

  /* Check if we could open the file */
  if (fin) {
    /* Read the file content and feed the list until we're done. Here we need to check wheter the file have content or not... */
    while (fin.good()) {
      gchar *buffer= new gchar [200];
      fin.getline(buffer, 200, '\n');
      if (!fin.good()) break;
      i = strlen(buffer);
      if (i > 1) {
      	j=i-1;
      	while(buffer[j]==' ')
		j--;
      	buffer[j+1]=0;
      }	

      glist = g_list_append(glist, buffer);
    }
    fin.close();
  } else {
    g_print("Couldn't open %s\n", file);  
  }

  g_free(file);
}

Data::~Data()
{	
  g_list_free(glist);
}

GList *Data::getData(void)
{  
  return glist;	
}

/*
main()
{
  Data *d = new Data("fetch_master_browser.sh 6AN", "offline.plugin");
  GList *glist = d->getData();
  while (glist->next) {
    glist = glist->next;
    cout << (gchar *)glist->data << '\n';
  }
  return 0;
} 
*/
