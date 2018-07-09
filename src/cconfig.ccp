/*
 **  CConfig v0.1.1
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
 ** cconfig.cpp
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se
 ** 
 ** Changes:
 ** + Added autocheck of the HOME-dir path
 **
 ** Started on  Mon Jul  3 20:00:00 2000 Daniel Sundberg 
 ** Last update Wed Jul  5 19:28:00 2000 Daniel Sundberg
 */

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "cconfig.h"

CConfig::CConfig(char *configFileName) {
  fileName = new char[MAX_CONFIG_FILENAME_LENGTH];
  confKeyList = new confKey[MAX_CONFIG_KEYS];
  /* Check if we have a global configfile here */
  if (configFileName[0] != '/') {
    cout << getenv("HOME") << '\n';
    sprintf(fileName,"~/%s", configFileName);
  } else {
    fileName = strdup(configFileName);
  }
  //cout << fileName << '\n';
  ifstream fin(fileName);
  if (fin) {
    int i = 0;
    while (fin.good()) {
      char *buffer = new char[100];
      fin.getline(buffer, 100, '\n');      
      /* If this is true we found a config-key */
      if (strstr(buffer, "=")) {
	/* Debugging....boring */
	//cout << buffer << '\n';
	/* Calculate size of the data & key strings */
	int dataLength = strlen( strstr( buffer, "=" ) );
	int keyLength  = strlen( buffer ) - dataLength;
	/* The data length is actually -- to the pre calculated value */
	dataLength--;
	/* Get rid of the '=' */
	confKeyList[i].data = new char[dataLength];
	confKeyList[i].data = strdup( strstr(buffer, "=" ) );
	char *buffer2 = new char[dataLength];
	buffer2 = strdup(confKeyList[i].data);
	confKeyList[i].data = new char[dataLength - 1];
	confKeyList[i].data = strdup(&buffer2[1]);
	/* Fix the key */
	confKeyList[i].key = new char[keyLength];
	confKeyList[i++].key = strdup(strtok(buffer, "="));
      }  
      nRows = i;
    }
    fin.close();
  } else {
    cout << "error in opening " << fileName << '\n';
  }
}

CConfig::~CConfig() {

}

void CConfig::writeConfigKey(char *key, char *data) {
  int i = 0;
  int found = 0;
  
  /* Search for the key we want to change */
  while (i < nRows) {
    if (strcmp(key, confKeyList[i].key) == 0) {
      found = 1;
      break;
    } else {
      i++;
    }
  }
  
  /* Change the key */
  if (found) {
    confKeyList[i].data = new char[strlen(data)];
    confKeyList[i].data = strdup(data);
  } else {
    confKeyList[++i].data = new char[strlen(data)];
    confKeyList[i].data = strdup(data);
  }
  /* Write the shit here */
  ofstream fout(fileName);
  if (fout) {
    for (int i = 0; i < nRows; i++) {
      fout << confKeyList[i].key << '=' << confKeyList[i].data << '\n';
    }
    fout.close();
  } else {
    cout << "Connot open file";
  }
}

char *CConfig::getConfigKey(char *key) {
  int i = 0;
  for (int i = 0; i < nRows; i++) {
    if (strcmp(key, confKeyList[i].key) == 0) {
      return confKeyList[i].data;
    }
  }
  return NULL;  
}

int CConfig::getNKeys(void) {
  return nRows;
}

/* Sample main function */

main() {
  CConfig c(".jags");

  cout << "BrowserCommand: " << c.getConfigKey("BrowserCommand") << '\n';

  c.writeConfigKey("BrowserCommand", "kfm %d");

  CConfig d("/mnt/daniels/home/sumpan/.jags");
  
  cout << "BrowserCommand: " << d.getConfigKey("BrowserCommand") << '\n';
 
  return 0;
}

