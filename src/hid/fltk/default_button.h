/*!
 * \file src/hid/fltk/default_button.h
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


#ifndef PCB_SRC_HID_FLTK_DEFAULT_BUTTON_H
#define PCB_SRC_HID_FLTK_DEFAULT_BUTTON_H


/* Standard headers */
#include <string>


/* Fltk headers */
#include "FLTK_headers.h"
#include "themes.h"
#include "utils.h"


class Default_Button : public Fl_Button
{
  public:
    Default_Button (int x, int y, int w, int h, const char *l = NULL);

  protected:
    int handle (int event);
};


#endif /* PCB_SRC_HID_FLTK_DEFAULT_BUTTON_H */


/* EOF */
