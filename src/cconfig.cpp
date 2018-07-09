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

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "cconfig.h"

CConfig::CConfig(char *configFileName)
{
  fileName = new char[MAX_CONFIG_FILENAME_LENGTH];
  confKeyList = g_list_alloc();

  /* Check if we have a global configfile here. Checks if we have a global 
     conf ('/' first), if we don't we check for the path to the home-dir 
     (must be set ENV-var) */
  if (configFileName[0] != '/') {    
    sprintf(fileName,"%s/%s", getenv("HOME"), configFileName);
  } else { 
    delete [] fileName;
    fileName = g_strdup(configFileName);
  }
  //  cout << fileName << '\n';
  ifstream fin(fileName);
  if (fin) {
    char *buffer = g_new(char, 100);      
    while (!fin.eof()) {
      fin.getline(buffer, 100, '\n');
      /* If this is true we found a config-key */
      //cout << buffer << '\n';
      if (strstr(buffer, "=")) {
	gchar **keydata = g_strsplit(buffer, "=", 1);
	/* Add error checking here */
	confKeyList = g_list_append(confKeyList, (gpointer)g_strdup(keydata[0]));
	confKeyList = g_list_append(confKeyList, (gpointer)g_strdup(keydata[1]));
	g_strfreev(keydata);
      }
    }
    fin.close();
  } else {
    confKeyList = g_list_append(confKeyList, (gpointer)g_strdup("nada"));
    confKeyList = g_list_append(confKeyList, (gpointer)g_strdup("nada"));
  }
}

CConfig::~CConfig()
{
  g_list_free(confKeyList);
  delete [] fileName;
}

/* Adds new config-key OR updates a present key */

void CConfig::writeConfigKey(char *key, char *data)
{
  GList *glist = g_list_find_custom(confKeyList->next, (gpointer)key, (GCompareFunc)g_strcasecmp);
  /* If key exists */
  if (glist) {
    glist->next->data = (gpointer)g_strdup(data);
  } else {
    confKeyList = g_list_append(confKeyList, (gpointer)g_strdup(key));
    confKeyList = g_list_append(confKeyList, (gpointer)g_strdup(data));
  }
  write();
}

/* Returns the wanted cfg-key */

char *CConfig::getConfigKey(char *key)
{
  GList *glist = g_list_find_custom(confKeyList->next, (gpointer)key, 
				    (GCompareFunc)g_strcasecmp);

  if (glist) {
    return g_strdup((gchar *)glist->next->data);
  } else {
    return g_strdup("");  // empty string
  }
}

int CConfig::getNKeys(void)
{
  return (gint)(g_list_length(confKeyList) / 2);
}

/* Deletes a config-key if it's present */

void CConfig::rmConfigKey(char *key)
{
  GList *glist = g_list_find_custom(confKeyList->next, (gpointer)key, 
				    (GCompareFunc)g_strcasecmp);
 
 if (glist) {
    g_list_remove_link(confKeyList, glist->next);
    g_list_remove_link(confKeyList, glist);
    write();
  }
}

/* Deletes a config key and it's data by the data */

void CConfig::rmConfigKeyByData(char *data)
{
GList *glist = g_list_find_custom(confKeyList->next, (gpointer)data, (GCompareFunc)g_strcasecmp);

  if (glist) {
    g_list_remove_link(confKeyList, glist->prev);
    g_list_remove_link(confKeyList, glist);
    write();
  }
}

/* Writes cfg-file to disk */

void CConfig::write(void)
{
  GList *glist=NULL;

  /* Write the shit here */
  ofstream fout(fileName);
  if (fout) {
    glist = g_list_copy(confKeyList);
    while (glist->next->next) {
      fout << (gchar *)glist->next->data << "=" << 
	(gchar *)glist->next->next->data << '\n';
      if (glist->next->next->next) {
	glist = glist->next->next;
      } else {
	break;
      }
    }
    fout.close();
  } else {
    cout << "Connot open file";  
  }

}

void CConfig::printCfg(void)
{
  GList *glist = g_list_copy(confKeyList);

  while (glist->next->next) {
    g_print("%s=%s\n",  
	    (gchar *)glist->next->data, 
	    (gchar *)glist->next->next->data);
    if (glist->next->next->next) {
      glist = glist->next->next;
    } else {
      break;
    }
  }
}

/* Sample main function */
//  main() { 
//    CConfig c("/home/sumpan/.jags/jags.conf"); 
//    c.writeConfigKey("Browser", "gmc"); 
//    c.printCfg();
//    cout << "-----------\n";
//    c.writeConfigKey("BrowserCommand", "gmc %d"); 
//    c.printCfg();
//    cout << "-----------\n";
//    c.rmConfigKey("BrowserCommand");
//    c.printCfg();
//    cout << "-----------\n";
//    c.rmConfigKey("BrowserCommand");
//    c.printCfg();
//    cout << "-----------\n";
//    c.writeConfigKey("Browser", "gmc"); 
//    c.printCfg();
//  CConfig d("/mnt/daniels/home/sumpan/.jags"); 
//  cout << "BrowserCommand: " << d.getConfigKey("BrowserCommand") << '\n'; 
//    return 0; 
//  } 

