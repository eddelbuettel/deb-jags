/*
 **  Copyright (C) 2003 Anatoly Demchishin & Daniel Sundberg
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

#include "jagsprogressbar.h"

GtkWidget *progressbar;
static gint pbarenabled;

JagsProgressBar::JagsProgressBar(GtkWidget *vbox)
{
  pbarenabled = 1; 
  separator = gtk_hseparator_new ();
  gtk_box_pack_start (GTK_BOX (vbox), separator, FALSE, FALSE, 0);
  gtk_widget_show(separator);
  
  /* Create a Adjusment object to hold the range of the progress bar */
  adj = (GtkAdjustment *) gtk_adjustment_new (0, 1, 150, 0, 0, 0);

  progressbar = gtk_progress_bar_new_with_adjustment (adj);
  gtk_progress_set_activity_mode (GTK_PROGRESS (progressbar),TRUE);
  gtk_box_pack_start(GTK_BOX(vbox), progressbar, FALSE, FALSE, 0);
  
  gtk_widget_show(progressbar);

  /* Add a timer callback to update the value of the progress bar */
  timer = gtk_timeout_add (40, progress_timeout, progressbar);
}

JagsProgressBar::~JagsProgressBar() 
{
  gtk_timeout_remove (timer);
  timer = 0;
}

gint progress_timeout( gpointer data )
{
  gfloat new_val;
  GtkAdjustment *adj;

  adj = GTK_PROGRESS (data)->adjustment;
  new_val = gtk_progress_get_value( GTK_PROGRESS(data) );

  if (pbarenabled) {
    new_val += 3;
    if (new_val > adj->upper)
      new_val = adj->lower;
  }
  gtk_progress_set_value (GTK_PROGRESS (data), new_val);
  /* As this is a timeout function, return TRUE so that it continues to get called */
  
  return TRUE;
} 

void JagsProgressBar::start()
{	
  pbarenabled = 1;
}

void JagsProgressBar::stop()
{	
  pbarenabled = 0;
}
