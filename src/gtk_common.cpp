/*
 **  GtkCommon v0.1
 **  Copyright (C) 2000-2001 Daniel Sundberg
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
 ** gtk_common.cpp
 ** 
 ** Made by:    Daniel Sundberg
 ** E-Mail:     dansun-8@student.luth.se
 ** Homepage:   http://sumpan.campus.luth.se/software/jags
 ** 
 ** Started on  Sun Jul  30 17:52:00 2000 Daniel Sundberg 
 ** Last update Tue Apr   3 20:54:00 2001 Daniel Sundberg
 */

/* 
 * This file contains routines to create buttons and 
 * menuitems etc. which contains a pixmap...see the 
 * gtk_common.h 
 *
 * This is pretty self-explaining...isn't it?
 *
 */

#include <gtk/gtk.h>
#include <iostream.h>
#include <stdlib.h>
#include "gtk_common.h"


/* Create a new hbox with an image and a label packed into it
 * and return the box. */
GtkWidget *xpm_label_box(GtkWidget *parent, gchar *xpm_filename, gchar *label_text )
{
  GtkWidget *box1;
  GtkWidget *label;
  GtkWidget *pixmapwid;
  GdkPixmap *pixmap;
  GdkBitmap *mask;
  GtkStyle *style;
  gchar *path, *filename;

  /* Create box for xpm and label */
  box1 = gtk_hbox_new (FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (box1), 0);
  
  /* Get the style of the button to get the
   * background color. */
  style = gtk_widget_get_style(parent);

  path = g_strdup_printf("%s/.jags/pixmaps/", getenv("HOME"));
  filename = g_strdup_printf("%s%s", path, xpm_filename);

  pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, &style->bg[GTK_STATE_NORMAL], filename);

  if (!pixmap) {
    path = g_strdup_printf("/usr/share/jags/pixmaps/");
    filename = g_strdup_printf("%s%s", path, xpm_filename);
    
    pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, &style->bg[GTK_STATE_NORMAL], filename);
    if (!pixmap) {
      path = g_strdup_printf("pixmaps/");
      filename = g_strdup_printf("%s%s", path, xpm_filename);
      
      pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, &style->bg[GTK_STATE_NORMAL], filename);

    }
  }

//    pixmap = gdk_pixmap_create_from_xpm (parent->window, &mask,
//  				       &style->bg[GTK_STATE_NORMAL],
//  				       xpm_filename);
  pixmapwid = gtk_pixmap_new (pixmap, mask);
  
  /* Create a label for the button */
  label = gtk_label_new (label_text);
  
  /* Pack the pixmap and label into the box */
  gtk_box_pack_start (GTK_BOX (box1),
		      pixmapwid, FALSE, FALSE, 3);
  
  gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 3);
  
  gtk_widget_show(pixmapwid);
  gtk_widget_show(label);
  
  return(box1);
}

/* Get the text of the label we packed into a box 
   in the function above */
gchar *xpm_label_box_get_text(GtkWidget *box) {
  gchar *text;
  GList *glist = GTK_BOX(box)->children;
  GtkBoxChild *boxchild = (GtkBoxChild *)glist->next->data;
  GtkWidget *widget = boxchild->widget;
  gtk_label_get(GTK_LABEL(widget), &text);

  return text;
}

GtkWidget *gtk_button_new_with_label_with_pixmap(gchar *label, gchar *pixmap) {
  GtkWidget *button, *box;

  button = gtk_button_new();
  box = xpm_label_box(button, pixmap, label);
  gtk_widget_show(box);
  gtk_container_add(GTK_CONTAINER(button), box);
  return button;
}

gchar *gtk_button_get_text(GtkWidget *button) {
  if (GTK_IS_LABEL(GTK_BIN(button)->child)) {
    gchar *text;
    GtkWidget *label = GTK_BIN(button)->child;
    gtk_label_get(GTK_LABEL(label), &text);
    return text;
  } else {
    return xpm_label_box_get_text(GTK_BIN(button)->child);  
  }
}

GtkWidget *gtk_menu_item_new_with_label_with_pixmap(gchar *label, gchar *pixmap) {
  GtkWidget *menu_item, *box;

  menu_item = gtk_menu_item_new();
  box = xpm_label_box(menu_item, pixmap, label);
  gtk_widget_show(box);
  gtk_container_add(GTK_CONTAINER(menu_item), box);
  return menu_item;
}

gchar *gtk_menu_item_get_text(GtkWidget *menu_item) {
  if (GTK_IS_LABEL(GTK_BIN(menu_item)->child)) {
    gchar *text;
    GtkWidget *label = GTK_BIN(menu_item)->child;
    gtk_label_get(GTK_LABEL(label), &text);
    return text;
  } else {
    return xpm_label_box_get_text(GTK_BIN(menu_item)->child);  
  }
}

GtkWidget *gtk_tree_item_new_with_label_with_pixmap(gchar *label, gchar *pixmap) {
  GtkWidget *tree_item, *box;

  tree_item = gtk_tree_item_new();
  box = xpm_label_box(tree_item, pixmap, label);
  gtk_widget_show(box);
  gtk_container_add(GTK_CONTAINER(tree_item), box);
  return tree_item;
}

gchar *gtk_tree_item_get_text(GtkWidget *tree_item) {
  if (GTK_IS_LABEL(GTK_BIN(tree_item)->child)) {
    gchar *text;
    GtkWidget *label = GTK_BIN(tree_item)->child;
    gtk_label_get(GTK_LABEL(label), &text);
    return text;
  } else {
    return xpm_label_box_get_text(GTK_BIN(tree_item)->child);  
  }
}

GtkWidget *gtk_option_menu_new_with_glist(GList *glist) {
  GtkWidget *option_menu = gtk_option_menu_new();
  GtkWidget *menu = gtk_menu_new();
  while (glist->next) {
    GtkWidget *item = gtk_menu_item_new_with_label((gchar *)glist->next->data);    
    gtk_widget_show(item);
    gtk_menu_append(GTK_MENU(menu), item);
    glist = glist->next;
  }
  gtk_widget_show(menu);
  gtk_option_menu_set_menu(GTK_OPTION_MENU(option_menu), menu);
  return option_menu;
}

void gtk_combo_set_default_text(GtkWidget *combo, gchar *text) {
  gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(combo)->entry), text);
}

/*
 * This will load the xpm from a file into a widget which 
 * you can use in toolbars.
 */
GtkWidget *gtk_icon2widget(gchar *xpm, GtkWidget *parent) {
  GdkBitmap *mask;
  GtkWidget *iconw;
  GdkPixmap *pixmap;
  //  GtkStyle  *style;
  gchar     *filename, *path;

  path = g_strdup_printf("%s/.jags/pixmaps/", getenv("HOME"));  
  filename = g_strdup_printf("%s/%s", path, xpm);
  
  //  pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, &style->bg[GTK_STATE_NORMAL], filename);


  pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, NULL, filename);

  if (!pixmap) {
    path = g_strdup_printf("/usr/share/jags/pixmaps/");
    filename = g_strdup_printf("%s%s", path, xpm);
    
    //    pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, &style->bg[GTK_STATE_NORMAL], filename);

    pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, NULL, filename);
    if (!pixmap) {
      path = g_strdup_printf("pixmaps/");
      filename = g_strdup_printf("%s%s", path, xpm);
      
      //      pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, &style->bg[GTK_STATE_NORMAL], filename);

      pixmap = gdk_pixmap_colormap_create_from_xpm(parent->window, gtk_widget_get_colormap(parent), &mask, NULL, filename);

    }
  }
  iconw = gtk_pixmap_new(pixmap, mask);
  return iconw;

}

/* By Robert Kling (robkli-8@student.luth.se */
void popup_dialog(gint height, gchar *title, gchar *text, gchar *button_text) {
  GtkWidget *window, *textlabel, *button;
  
  window = gtk_dialog_new();
  gtk_signal_connect(GTK_OBJECT(window), "delete_event", GTK_SIGNAL_FUNC(close_popup_dialog), window);
  gtk_widget_set_usize(GTK_WIDGET(window), 300, height);
  gtk_window_set_policy(GTK_WINDOW(window), FALSE, FALSE, FALSE);
  gtk_window_set_title(GTK_WINDOW (window), title);
  gtk_container_set_border_width(GTK_CONTAINER (window), 3);
  //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);
  
  textlabel = gtk_label_new(text);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->vbox), textlabel, TRUE, TRUE, 0);
  gtk_widget_show(textlabel);
  
  button = gtk_button_new_with_label_with_pixmap(button_text, "ok.xpm");
  gtk_signal_connect(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(close_popup_dialog), window);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(window)->action_area), button, FALSE, TRUE, 0);
  gtk_widget_show(button);
  
  gtk_widget_show(window);
}

gint close_popup_dialog(GtkWidget *widget, gpointer data) {
  gtk_widget_destroy(GTK_WIDGET(data));
  return TRUE;
}


/* 
main(int argc, char *argv[]) {
  GtkWidget *window, *button;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  button = gtk_button_new_with_label_with_pixmap("Button", "browse.xpm");
  //gtk_widget_show(button);
  //gtk_container_add(GTK_CONTAINER(window), button);
  //g_print(gtk_button_get_text(button));
  //button = gtk_button_new_with_label("Hejsan");
  gtk_widget_show(button);
  gtk_container_add(GTK_CONTAINER(window), button);
  gtk_widget_show(window);

  gtk_main();
  return 0;
}
*/
//      button = gtk_button_new ();

//      /* Connect the "clicked" signal of the button to our callback */
//      gtk_signal_connect (GTK_OBJECT (button), "clicked",
//  			GTK_SIGNAL_FUNC (callback), (gpointer) "cool button");

//      /* This calls our box creating function */
//      box1 = xpm_label_box(window, "info.xpm", "cool button");

//      /* Pack and show all our widgets */
//      gtk_widget_show(box1);

//      gtk_container_add (GTK_CONTAINER (button), box1);

//      gtk_widget_show(button);

//      gtk_container_add (GTK_CONTAINER (window), button);

//      gtk_widget_show (window);

//      /* Rest in gtk_main and wait for the fun to begin! */
//      gtk_main ();

//      return(0);
