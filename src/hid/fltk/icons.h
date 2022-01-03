/*!
 * \file src/hid/fltk/icons.h
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


#ifndef PCB_SRC_HID_FLTK_ICONS_H
#define PCB_SRC_HID_FLTK_ICONS_H


#include "FLTK_headers.h"


#include "app.xpm"
#include "app-icon.xpm"
#include "arc.xpm"
#include "blank.xpm"
#include "buf.xpm"
#include "del.xpm"
#include "error.xpm"
#include "ins.xpm"
#include "line.xpm"
#include "load.xpm"
#include "lock.xpm"
#include "new.xpm"
#include "open.xpm"
#include "pan.xpm"
#include "poly.xpm"
#include "polyhole.xpm"
#include "print.xpm"
#include "rect.xpm"
#include "redo.xpm"
#include "reload.xpm"
#include "rot.xpm"
#include "save.xpm"
#include "sel.xpm"
#include "success.xpm"
#include "text.xpm"
#include "thrm.xpm"
#include "undo.xpm"
#include "via.xpm"
#include "warning.xpm"
#include "x-flip.xpm"
#include "y-flip.xpm"
#include "zoom-in.xpm"
#include "zoom-out.xpm"

#include "layer_empty.xpm"
#include "layer_on.xpm"
#include "layer_off.xpm"


static Fl_Pixmap BLANK_ICON(BLANK_XPM);

/* Toolbar button icons. */
static Fl_Pixmap NEW_ICON (new_xpm);
static Fl_Pixmap OPEN_ICON (open_xpm);
static Fl_Pixmap SAVE_ICON (save_xpm);
static Fl_Pixmap PRINT_ICON (print_xpm);

/* Traditional pcb icons. */
static Fl_Pixmap VIA_ICON (via_xpm);
static Fl_Pixmap LINE_ICON (line_xpm);
static Fl_Pixmap ARC_ICON (arc_xpm);
static Fl_Pixmap TEXT_ICON (text_xpm);
static Fl_Pixmap RECT_ICON (rect_xpm);
static Fl_Pixmap POLY_ICON (poly_xpm);
static Fl_Pixmap POLYHOLE_ICON (polyhole_xpm);
static Fl_Pixmap BUF_ICON (buf_xpm);
static Fl_Pixmap DEL_ICON (del_xpm);
static Fl_Pixmap ROT_ICON (rot_xpm);
static Fl_Pixmap INS_ICON (ins_xpm);
static Fl_Pixmap THRM_ICON (thrm_xpm);
static Fl_Pixmap SEL_ICON (sel_xpm);
static Fl_Pixmap LOCK_ICON (lock_xpm);
static Fl_Pixmap PAN_ICON (pan_xpm);

static Fl_Pixmap LOAD_ICON (load_xpm);
static Fl_Pixmap RELOAD_ICON (reload_xpm);
static Fl_Pixmap UNDO_ICON (undo_xpm);
static Fl_Pixmap REDO_ICON (redo_xpm);
static Fl_Pixmap ZOOM_IN_ICON (zoom_in_xpm);
static Fl_Pixmap ZOOM_OUT_ICON (zoom_out_xpm);
static Fl_Pixmap X_FLIP_ICON (x_flip_xpm);
static Fl_Pixmap Y_FLIP_ICON (y_flip_xpm);

static Fl_Pixmap LAYER_EMPTY_ICON (layer_empty_xpm);
static Fl_Pixmap LAYER_ON_ICON (layer_on_xpm);
static Fl_Pixmap LAYER_OFF_ICON (layer_off_xpm);


#endif /* PCB_SRC_HID_FLTK_ICONS_H */


/* EOF */
