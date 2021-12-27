/*!
 * \file src/hid/fltk/help_window.cpp
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


#include "help_window.h"


Help_Window::Help_Window (int x, int y, int w, int h, const char *t) :
  _dx (x),
  _dy (y),
  _width (w),
  _height (h),
  _title (t),
  _content (NULL),
  _window (NULL),
  _body (NULL),
  _ok_button (NULL),
  _spacer (NULL)
{
}


Help_Window::~Help_Window()
{
  delete _window;
  delete _body;
  delete _ok_button;
  delete _spacer;
}


void
Help_Window::initialize ()
{
  if (_window)
  {
    return;
  }

  Fl_Group *prev_current = Fl_Group::current ();
  Fl_Group::current (NULL);

  /* Populate window. */
  _window = new Fl_Double_Window (_dx, _dy, _width, _height, _title);
  _body = new HTML_View (10, 10, _width - 20, _height - 52);
  _ok_button = new Default_Button (_width - 90, _height - 32, 80, 22, "OK");
  _spacer = new Fl_Box (10, 10, _width - 110, _height - 52);
  _window->end ();

  /* Initialize window. */
  _window->box (OS_BG_BOX);
  _window->resizable (_spacer);
  _window->callback ((Fl_Callback *) close_cb, this);

  /* Initialize window's children. */
  _ok_button->tooltip ("OK (Enter)");
  _ok_button->callback ((Fl_Callback *) close_cb, this);
  Fl_Group::current (prev_current);
}


void
Help_Window::refresh ()
{
  _window->label (_title ? _title : "Help");
  _body->value (_content ? _content : "");
}


void
Help_Window::show (const Fl_Widget *p)
{
  initialize ();
  refresh ();
  Fl_Window *prev_grab = Fl::grab ();
  _window->position (p->x () + _dx, p->y () + _dy);
  Fl::grab (NULL);
  _window->show ();
  Fl::grab (prev_grab);
}


void
Help_Window::close_cb (Fl_Widget *, Help_Window *hw)
{
  hw->_window->hide ();
}


/* EOF */
