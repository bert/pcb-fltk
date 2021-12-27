/*!
 * \file src/hid/fltk/default_button.cpp
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


#include "default_button.h"


Default_Button::Default_Button (int x, int y, int w, int h, const char *l) : Fl_Button(x, y, w, h, l)
{
  labelfont (OS_FONT);
  labelsize (OS_FONT_SIZE);
  box (OS_DEFAULT_BUTTON_UP_BOX);
  down_box (OS_DEFAULT_DEPRESSED_DOWN_BOX);
  shortcut (FL_Enter);
}


int
Default_Button::handle (int event)
{
  if (OS::current_theme () == OS::Theme::AERO
    || OS::current_theme () == OS::Theme::METRO
    || OS::current_theme () == OS::Theme::BLUE
    || OS::current_theme () == OS::Theme::OLIVE
    || OS::current_theme () == OS::Theme::ROSE_GOLD
    || OS::current_theme () == OS::Theme::HIGH_CONTRAST)
  {
    switch (event)
    {
      case FL_ENTER:
        if (active_r ())
        {
          box (OS_DEFAULT_HOVERED_UP_BOX);
          redraw ();
          return 1;
        }
        return 0;

      case FL_LEAVE:
      case FL_HIDE:
      case FL_DEACTIVATE:
        box (OS_DEFAULT_BUTTON_UP_BOX);
        redraw ();
        return 1;
    }
  }

  return Fl_Button::handle (event);
}


/* EOF */
