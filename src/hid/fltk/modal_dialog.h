/*!
 * \file src/hid/fltk/modal_dialog.h
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


#ifndef PCB_SRC_HID_FLTK_MODAL_DIALOG_H
#define PCB_SRC_HID_FLTK_MODAL_DIALOG_H


/* Standard headers */
#include <string>


/* Fltk headers */
#include "FLTK_headers.h"
#include "themes.h"
#include "icons.h"
#include "label.h"
#include "default_button.h"
#include "os_button.h"


class Modal_Dialog
{
  public:
    enum class Icon
    {
      NO_ICON,
      SUCCESS_ICON,
      WARNING_ICON,
      ERROR_ICON,
      APP_ICON
    };
    static Fl_Pixmap SUCCESS_SHIELD_ICON;
    static Fl_Pixmap WARNING_SHIELD_ICON;
    static Fl_Pixmap ERROR_SHIELD_ICON;
    static Fl_Pixmap PROGRAM_ICON;

  private:
    Icon _icon_type;
    std::string _title;
    std::string _subject;
    std::string _message;
    int _min_w;
    int _max_w;
    bool _canceled;
    Fl_Window *_top_window;
    Fl_Double_Window *_dialog;
    Fl_Box *_icon;
    Label *_heading;
    Label *_body;
    Default_Button *_ok_button;
    OS_Button *_cancel_button;

  public:
    Modal_Dialog (Fl_Window *top, const char *t = NULL, Icon c = Icon::NO_ICON, bool cancel = false);
    ~Modal_Dialog ();

  private:
    void initialize (void);
    void refresh (void);

  public:
    inline void icon (Icon c) { _icon_type = c; }
    inline void title (const std::string &t) { _title = t; }
    inline void subject (const std::string &s) { _subject = s; }
    inline void message (const std::string &m) { _message = m; }
    inline void width_range (int min_w, int max_w) { _min_w = min_w; _max_w = max_w; }
    inline bool canceled (void) const { return _canceled; }
    inline void canceled (bool c) { _canceled = c; }
    void show (const Fl_Widget *p);

  private:
    static void close_cb (Fl_Widget *, Modal_Dialog *md);
    static void cancel_cb (Fl_Widget *, Modal_Dialog *md);
};


#endif /* PCB_SRC_HID_FLTK_MODAL_DIALOG_H */


/* EOF */
