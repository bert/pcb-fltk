/*!
 * \file src/hid/fltk/help_window.h
 *
 * \author Bert Timmerman <bert.timmerman@xs4all.nl>
 *
 * \copyright (C) 2021 PCB Contributors.
 *
 * <hr>
 *
 * <h1><b>Copyright.</b></h1>\n
 *
 * PCB, interactive printed circuit board design
 *
 * Copyright (C) 1994,1995,1996, 2004 Thomas Nau
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Contact addresses for paper mail and Email:
 * Thomas Nau, Schlehenweg 15, 88471 Baustetten, Germany
 * Thomas.Nau@rz.uni-ulm.de
 */


#ifndef PCB_SRC_HID_FLTK_HELP_WINDOW_H
#define PCB_SRC_HID_FLTK_HELP_WINDOW_H


#include <string>


#include "FLTK_headers.h"
#include "themes.h"
#include "default_button.h"
#include "html_view.h"


class Help_Window
{
  private:
    int _dx;
    int _dy;
    int _width;
    int _height;
    const char *_title;
    const char *_content;
    Fl_Double_Window *_window;
    HTML_View *_body;
    Default_Button *_ok_button;
    Fl_Box *_spacer;

  public:
    Help_Window (int x, int y, int w, int h, const char *t = NULL);
    ~Help_Window ();
    inline void title (const char *t) { _title = t; }
    inline void content (const char *c) { _content = c; }

  private:
    void initialize (void);
    void refresh (void);

  public:
    void show (const Fl_Widget *p);

  private:
    static void close_cb (Fl_Widget *w, Help_Window *hw);
};

#endif /* PCB_SRC_HID_FLTK_HELP_WINDOW_H */


/* EOF */
