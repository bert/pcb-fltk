/*!
 * \file src/hid/fltk/about_dialog.h
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


#ifndef PCB_SRC_HID_FLTK_ABOUT_DIALOG_H__
#define PCB_SRC_HID_FLTK_ABOUT_DIALOG_H__


/* Standard headers */
#include <string>


#pragma warning (push, 0)


/* Fltk headers */
#include "FLTK_headers.h"
#include "modal_dialog.h"


#pragma warning (pop)


/*!
 * \class About_Dialog.
 * 
 * \brief Create a modal about dialog.
 *
 * 
*/
class About_Dialog
{
  private:
    int _dx;
    int _dy;
    int _width;
    int _height;
    const char *_title;
    const char *_content;
    Fl_Double_Window *_window;
    Default_Button *_ok_button;

  public:
    About_Dialog (int x, int y, int w, int h, const char *t = NULL); /*!< Constructor. */
    ~About_Dialog (); /*!< Destructor. */
    void show (void); /*!< Show the dialog. */

  private:
    const char *name; /*!< Name of the dialog window. */
    const char *title; /*!< Title of the dialog. */
    const char *description; /*!< Description of the software. */
    const char *version; /*!< Version number or name of the software. */
    const char *copyright; /*!< Copyright year(s) and copyright holder(s). */
};


#endif /* PCB_SRC_HID_FLTK_ABOUT_DIALOG_H__ */


/* EOF */
