/***************************************************************************
                         fixsmbcop.cpp  -  description
                             -------------------
    begin                : Sun Jun 4 2000
    copyright            : (C) 2000 by Daniel Sundberg
    email                : dansun-8@student.luth.se
    homepage             : http://sumpan.campus.luth.se

    This program parses out either reads lines from stdin. After finding 
    two lines containing the first two args the program starts dumping 
    until last pattern is found. Can be _NEWLINE which is an empty line.

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int
main(int args, char *argv[]) {
  if (args > 3) {
    if (cin) {
      char *buffer = new char[100];

      while (cin.good()) {
	    /* Search for start-pattern-1 */
	    cin.getline(buffer, 100, '\n');
	    if (!strncmp(buffer, argv[1], strlen(argv[1]) )) {
	      /* Search for start-pattern-2 */
	      cin.getline(buffer, 100, '\n');
	      if (!strncmp(buffer, argv[2], strlen(argv[2]) )) {
		/* Here we want to start output text */
		while (cin.good()) {
		  cin.getline(buffer, 100, '\n');
		  
		  /* Until we find the end-pattern: newline or <pattern> */
		  if (!strcmp(argv[3],"_NEWLINE")) {
		    if (!strcmp(buffer,"")) {
		      exit(0);
		    } else {
		      cout << buffer << '\n';
		    }
		  } else {
		    if (!strncmp(buffer, argv[3],strlen(argv[3]))) {
		      exit(0);
		    } else {
		      cout << buffer << '\n';
		    }
		  } // Newline if
		} // while
	      } else {
		exit(0);
	      }// Pattern 2 if
	    }
      }
    } else {
      cout << "File " << argv[1] << " not found\n";
    }
  } else {
    cout << "Usage: fixsmbcop [start-pattern1] [start-pattern2] [end-pattern]\n" << 
            "       where end-pattern can be _NEWLINE == stop parsing on next empty line\n";
  }
  return 0;
}
