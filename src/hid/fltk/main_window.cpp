/*!
 * \file src/hid/fltk/main_window.cpp
 *
 * \author Bert Timmerman <bert.timmerman@xs4all.nl>
 *
 * \copyright (C) 2021, 2022 PCB Contributors.
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


/* Standard headers */
#include <cstdlib>
#include <cwctype>
#include <queue>
#include <utility>


#pragma warning (push, 0)


/* Fltk headers */
#include "FLTK_headers.h"


#pragma warning (pop)


#include "main_window.h"


#ifdef _WIN32
#include "resource.h"
#else
#include <unistd.h>
#include <X11/xpm.h>
//#include "app-icon.xpm"
#endif /* _WIN32 */


/* Avoid "warning C4458: declaration of 'i' hides class member"
 * due to Fl_Window's Fl_X *i . */
#pragma warning (push)
#pragma warning (disable : 4458)


Main_Window::Main_Window (int x, int y, int w, int h, const char *) : Fl_Overlay_Window (x, y, w, h, PROGRAM_NAME), _wx (x), _wy (y), _ww (w), _wh (h)
{
  int transparent = Preferences::get ("transparent", 0);
  int fullscreen = Preferences::get ("fullscreen", 0);

  /* Populate window. */
  int wx = 0;
  int wy = 0;
  int ww = w;
  int wh = h;

  /* Initialize menu bar. */
  _menu_bar = new Fl_Menu_Bar (wx, wy, ww, 21);
  wy += _menu_bar->h ();
  wh -= _menu_bar->h ();

  /* Initialize toolbar. */
  _toolbar = new Toolbar (wx, wy, w, 26);
  _new_tb = new Toolbar_Button (0, 0, 24, 24);
  _open_tb = new Toolbar_Button (0, 0, 24, 24);
  _save_tb = new Toolbar_Button (0, 0, 24, 24);
  _print_tb = new Toolbar_Button (0, 0, 24, 24);
  new Fl_Box (0, 0, 2, 24);
  new Spacer (0, 0, 2, 24);
  new Fl_Box (0, 0, 2, 24);
  _via_tb = new Toolbar_Button (0, 0, 24, 24);
  _line_tb = new Toolbar_Button (0, 0, 24, 24);
  _arc_tb = new Toolbar_Button (0, 0, 24, 24);
  _text_tb = new Toolbar_Button (0, 0, 24, 24);
  _rect_tb = new Toolbar_Button (0, 0, 24, 24);
  _poly_tb = new Toolbar_Button (0, 0, 24, 24);
  _polyhole_tb = new Toolbar_Button (0, 0, 24, 24);
  _buf_tb = new Toolbar_Button (0, 0, 24, 24);
  _del_tb = new Toolbar_Button (0, 0, 24, 24);
  _rot_tb = new Toolbar_Button (0, 0, 24, 24);
  _ins_tb = new Toolbar_Button (0, 0, 24, 24);
  _thrm_tb = new Toolbar_Button (0, 0, 24, 24);
  _sel_tb = new Toolbar_Button (0, 0, 24, 24);
  _lock_tb = new Toolbar_Button (0, 0, 24, 24);
  _pan_tb = new Toolbar_Button (0, 0, 24, 24);
  new Fl_Box (0, 0, 2, 24);
  new Spacer (0, 0, 2, 24);
  new Fl_Box (0, 0, 2, 24);
  _load_tb = new Toolbar_Button (0, 0, 24, 24);
  _reload_tb = new Toolbar_Button (0, 0, 24, 24);
  new Fl_Box (0, 0, 2, 24);
  new Spacer (0, 0, 2, 24);
  new Fl_Box (0, 0, 2, 24);
  _zoom_out_tb = new Toolbar_Button (0, 0, 24, 24);
  _zoom_in_tb = new Toolbar_Button (0, 0, 24, 24);
  /*! \todo _zoom_all_tb = new Toolbar_Button (0, 0, 24, 24); */
  /*! \todo _zoom_10mil_tb = new Toolbar_Button (0, 0, 24, 24); */
  /*! \todo _zoom_1mil_tb = new Toolbar_Button (0, 0, 24, 24); */
  /*! \todo _zoom_01mil_tb = new Toolbar_Button (0, 0, 24, 24); */
  /*! \todo _zoom_01mm_tb = new Toolbar_Button (0, 0, 24, 24); */
  /*! \todo _zoom_005mm_tb = new Toolbar_Button (0, 0, 24, 24); */
  /*! \todo _zoom_001mm_tb = new Toolbar_Button (0, 0, 24, 24); */
  /*! \todo _zoom_1mil_tb = new Toolbar_Button (0, 0, 24, 24); */
  new Fl_Box (0, 0, 2, 24);
  new Spacer (0, 0, 2, 24);
  new Fl_Box (0, 0, 2, 24);
  _x_flip_tb = new Toolbar_Button (0, 0, 24, 24);
  _y_flip_tb = new Toolbar_Button (0, 0, 24, 24);


  /*! \todo Add more Toolbar_Buttons here ... */

  _toolbar->end ();
  wy += _toolbar->h ();
  wh -= _toolbar->h ();
  begin ();

  /* Initialize status bar. */
  _status_bar = new Toolbar(wx, h-23, ww, 23);
  wh -= _status_bar->h();
  _view_side_label = new Label (0, 0, text_width ("View=top", 4), 21, "View=top");
  new Spacer(0, 0, 2, 21);
  _grid_size_label = new Label (0, 0, text_width ("Grid=10.00 mil", 4), 21, "Grid=10.00 mil");
  new Spacer(0, 0, 2, 21);
  _line_mode_label = new Label (0, 0, text_width ("Mode=45_/", 4), 21, "Mode=45_/");
  new Spacer(0, 0, 2, 21);
  _line_thickness_label = new Label (0, 0, text_width ("Line=10.00 mil", 4), 21, "Line=10.00 mil");
  new Spacer(0, 0, 2, 21);
  _via_thickness_label = new Label (0, 0, text_width ("Via=36.00 mil (20.00)", 4), 21, "Via=36.00 mil (20.00)");
  new Spacer(0, 0, 2, 21);
  _clearance_label = new Label (0, 0, text_width ("Clearance=10.00 mil", 4), 21, "Clearance=10.00 mil");
  new Spacer(0, 0, 2, 21);
  _text_size_label = new Label (0, 0, text_width ("Text=100 %", 4), 21, "Text=100 %");
  new Spacer(0, 0, 2, 21);
  _buffer_nr_label = new Label (0, 0, text_width ("Buffer=#1", 4), 21, "Buffer=#1");
  _status_bar->end();
  begin();

  /* Main group. */
  int wgt_h = 22;
  int win_m = 10;
  int wgt_m = 4;
  int tab_h = OS_TAB_HEIGHT;

  _main_group = new Fl_Group (wx, wy, ww, wh);
//  wx += win_m;
//  ww -= win_m * 2;
//  wy += win_m;
//  wh -= win_m * 2;

  /* Left group. */

  /* Initialize layer dialog. */
  _left_group = new Fl_Group (wx, wy, 256, wh);

  _left_group->begin ();

  _layer_group = new Fl_Group (wx, wy, 24 + 24 + 72, 14 * 24);

  _layer_group->begin ();

  _layer_1_rb = new Fl_Radio_Round_Button (6, wy, 24, 24, "");
  _layer_1_cb = new Fl_Check_Button (24, wy, 24, 24);
  _layer_1_lb = new Fl_Button (48, wy, 100, 24, "top");

  _layer_2_rb = new Fl_Radio_Round_Button (6, wy+24, 24, 24, "");
  _layer_2_cb = new Fl_Check_Button (24, wy+24, 24, 24);
  _layer_2_lb = new Fl_Button (48, wy+24, 100, 24, "ground");

  _layer_3_rb = new Fl_Radio_Round_Button (6, wy+48, 24, 24, "");
  _layer_3_cb = new Fl_Check_Button (24, wy+48, 24, 24);
  _layer_3_lb = new Fl_Button (48, wy+48, 100, 24, "signal2");

  _layer_4_rb = new Fl_Radio_Round_Button (6, wy+72, 24, 24, "");
  _layer_4_cb = new Fl_Check_Button (24, wy+72, 24, 24);
  _layer_4_lb = new Fl_Button (wx+48, wy+72, 100, 24, "signal3");

  _layer_5_rb = new Fl_Radio_Round_Button (6, wy+96, 24, 24, "");
  _layer_5_cb = new Fl_Check_Button (24, wy+96, 24, 24);
  _layer_5_lb = new Fl_Button (48, wy+96, 100, 24, "power");

  _layer_6_rb = new Fl_Radio_Round_Button (6, wy+120, 24, 24, "");
  _layer_6_cb = new Fl_Check_Button (24, wy+120, 24, 24);
  _layer_6_lb = new Fl_Button (48, wy+120, 100, 24, "bottom");

  _layer_7_rb = new Fl_Radio_Round_Button (6, wy+144, 24, 24, "");
  _layer_7_cb = new Fl_Check_Button (24, wy+144, 24, 24);
  _layer_7_lb = new Fl_Button (48, wy+144, 100, 24, "outline");

  _layer_8_rb = new Fl_Radio_Round_Button (6, wy+168, 24, 24, "");
  _layer_8_cb = new Fl_Check_Button (24, wy+168, 24, 24);
  _layer_8_lb = new Fl_Button (48, wy+168, 100, 24, "spare");

  _layer_9_rb = new Fl_Radio_Round_Button (6, wy+192, 24, 24, "");
  _layer_9_cb = new Fl_Check_Button (24, wy+192, 24, 24);
  _layer_9_lb = new Fl_Button (48, wy+192, 100, 24, "top silk");

  _layer_10_rb = new Fl_Radio_Round_Button (6, wy+216, 24, 24, "");
  _layer_10_cb = new Fl_Check_Button (24, wy+216, 24, 24);
  _layer_10_lb = new Fl_Button (48, wy+216, 100, 24, "rat lines");

  new Spacer (10, wy+240, 24 + 24 + 82, 2);

  _layer_11_rb = new Fl_Radio_Round_Button (6, wy+242, 24, 24, "");
  _layer_11_cb = new Fl_Check_Button (24, wy+242, 24, 24);
  _layer_11_lb = new Fl_Button (48, wy+242, 100, 24, "pins/pads");

  _layer_12_rb = new Fl_Radio_Round_Button (6, wy+266, 24, 24, "");
  _layer_12_cb = new Fl_Check_Button (24, wy+266, 24, 24);
  _layer_12_lb = new Fl_Button (48, wy+266, 100, 24, "vias");

  _layer_13_rb = new Fl_Radio_Round_Button (6, wy+290, 24, 24, "");
  _layer_13_cb = new Fl_Check_Button (24, wy+290, 24, 24);
  _layer_13_lb = new Fl_Button (48, wy+290, 100, 24, "far side");

  _layer_14_rb = new Fl_Radio_Round_Button (6, wy+314, 24, 24, "");
  _layer_14_cb = new Fl_Check_Button (24, wy+314, 24, 24);
  _layer_14_lb = new Fl_Button (48, wy+314, 100, 24, "solder mask");

  _layer_group->end ();
  _layer_group->resizable (NULL);

  _trackball = new Fl_Button (0, wy+338, 148, 148, "Trackball");

  _route_style_group = new Fl_Group (6, wy+486, 124, 4 * 24);
  _route_style_group->begin ();

  _route_style_1_rb = new Fl_Radio_Round_Button (6, wy+486, 24, 24, "");
  _route_style_1_lb = new Fl_Button (24, wy+486, 124, 24, "Signal");
  _route_style_2_rb = new Fl_Radio_Round_Button (6, wy+510, 24, 24, "");
  _route_style_2_lb = new Fl_Button (24, wy+510, 124, 24, "Power");
  _route_style_3_rb = new Fl_Radio_Round_Button (6, wy+534, 24, 24, "");
  _route_style_3_lb = new Fl_Button (24, wy+534, 124, 24, "Fat");
  _route_style_4_rb = new Fl_Radio_Round_Button (6, wy+558, 24, 24, "");
  _route_style_4_lb = new Fl_Button (24, wy+558, 124, 24, "Skinny");

  _route_style_group->end ();
  _route_style_group->resizable (NULL);

  _left_group->end ();
  _left_group->resizable (NULL);

  int lgx = _left_group->x();
  int lgy = _left_group->y();
  int lgw = _left_group->w();
  int lgh = _left_group->h();

  begin ();

  /* Dialogs. */
  _help_dialog = new Help_Window (48, 48, 700, 500, PROGRAM_NAME " Help");
//  _about_dialog = new About_Dialog (this, "About " PROGRAM_NAME, Modal_Dialog::Icon::APP_ICON);

  /* Drag-and-drop receivers. */

  /* Configure window. */
  box (OS_BG_BOX);
  size_range (647, 406);
  resizable (_main_group);
  callback ((Fl_Callback *) exit_cb, this);
  xclass (PROGRAM_NAME);


  /* Configure window icon. */

  /* Configure workspaces. */

  /* Configure menu bar. */
  _menu_bar->box (OS_PANEL_THIN_UP_BOX);
  _menu_bar->down_box (FL_FLAT_BOX);

  /* Configure menu bar items. */

  Fl_Menu_Item menu_items[] =
  {
#include "res/fpcb-menu.res"
  };

  _menu_bar->copy (menu_items);

  /* Initialize menu bar items. */
  for (int i = 0, md = 0; i < _menu_bar->size (); i++)
  {
    Fl_Menu_Item *mi = (Fl_Menu_Item *) &_menu_bar->menu ()[i];

    if (md > 0 && mi->label () && !mi->checkbox () && !mi->radio ())
    {
      Fl_Pixmap *icon = &BLANK_ICON;
      Fl_Multi_Label *ml = new Fl_Multi_Label ();
      ml->typea = _FL_IMAGE_LABEL;
      ml->labela = (const char *) icon;
      ml->typeb = FL_NORMAL_LABEL;
      ml->labelb = mi->text;
      mi->image (icon);
      ml->label (mi);
    }

    if (mi->submenu ())
    {
      md++;
    }
    else if (!mi->label ())
    {
      md--;
    }
  }

  /* Configure toolbar buttons. */
  _new_tb->tooltip ("New pcb layout (Ctrl+N)");
  _new_tb->callback ((Fl_Callback *) new_cb, this);
  _new_tb->image (NEW_ICON);
  _new_tb->take_focus ();

  _open_tb->tooltip ("Open pcb layout (Ctrl+O)");
  _open_tb->callback ((Fl_Callback *) open_cb, this);
  _open_tb->image (OPEN_ICON);

  _save_tb->tooltip ("Save pcb layout (Ctrl+S)");
  _save_tb->callback ((Fl_Callback *) save_cb, this);
  _save_tb->image (SAVE_ICON);

  _print_tb->tooltip ("Print pcb layout (Ctrl+P)");
  _print_tb->callback ((Fl_Callback *) print_cb, this);
  _print_tb->image (PRINT_ICON);

  _via_tb->tooltip ("Via tool");
  _via_tb->callback ((Fl_Callback *) via_cb, this);
  _via_tb->image (VIA_ICON);

  _line_tb->tooltip ("Line tool");
  _line_tb->callback ((Fl_Callback *) line_cb, this);
  _line_tb->image (LINE_ICON);

  _arc_tb->tooltip ("Arc tool");
  _arc_tb->callback ((Fl_Callback *) arc_cb, this);
  _arc_tb->image (ARC_ICON);

  _text_tb->tooltip ("Text tool");
  _text_tb->callback ((Fl_Callback *) text_cb, this);
  _text_tb->image (TEXT_ICON);

  _rect_tb->tooltip ("Rectangle tool");
  _rect_tb->callback ((Fl_Callback *) rect_cb, this);
  _rect_tb->image (RECT_ICON);

  _poly_tb->tooltip ("Polygon tool");
  _poly_tb->callback ((Fl_Callback *) poly_cb, this);
  _poly_tb->image (POLY_ICON);

  _polyhole_tb->tooltip ("Polygon hole tool");
  _polyhole_tb->callback ((Fl_Callback *) polyhole_cb, this);
  _polyhole_tb->image (POLYHOLE_ICON);

  _buf_tb->tooltip ("Buffer tool");
  _buf_tb->callback ((Fl_Callback *) buf_cb, this);
  _buf_tb->image (BUF_ICON);

  _del_tb->tooltip ("Delete tool");
  _del_tb->callback ((Fl_Callback *) del_cb, this);
  _del_tb->image (DEL_ICON);

  _rot_tb->tooltip ("Rotate tool");
  _rot_tb->callback ((Fl_Callback *) rot_cb, this);
  _rot_tb->image (ROT_ICON);

  _ins_tb->tooltip ("Insert tool");
  _ins_tb->callback ((Fl_Callback *) ins_cb, this);
  _ins_tb->image (INS_ICON);

  _thrm_tb->tooltip ("Thermal tool");
  _thrm_tb->callback ((Fl_Callback *) thrm_cb, this);
  _thrm_tb->image (THRM_ICON);

  _sel_tb->tooltip ("Selection tool");
  _sel_tb->callback ((Fl_Callback *) sel_cb, this);
  _sel_tb->image (SEL_ICON);

  _lock_tb->tooltip ("Lock tool");
  _lock_tb->callback ((Fl_Callback *) lock_cb, this);
  _lock_tb->image (LOCK_ICON);

  _pan_tb->tooltip ("Pan tool");
  _pan_tb->callback ((Fl_Callback *) pan_cb, this);
  _pan_tb->image (PAN_ICON);

  _load_tb->tooltip ("Load footprint");
  _load_tb->callback ((Fl_Callback *) load_cb, this);
  _load_tb->image (LOAD_ICON);

  _reload_tb->tooltip ("Reload pcb layout");
  _reload_tb->callback ((Fl_Callback *) reload_cb, this);
  _reload_tb->image (RELOAD_ICON);

  _zoom_in_tb->tooltip ("Zoom In (Ctrl+=)");
  _zoom_in_tb->callback ((Fl_Callback *) zoom_in_cb, this);
  _zoom_in_tb->image (ZOOM_IN_ICON);

  _zoom_out_tb->tooltip ("Zoom Out (Ctrl+-)");
  _zoom_out_tb->callback ((Fl_Callback *) zoom_out_cb, this);
  _zoom_out_tb->image (ZOOM_OUT_ICON);

  _x_flip_tb->tooltip ("X-flip (Shift+Tab)");
  _x_flip_tb->callback ((Fl_Callback *) x_flip_cb, this);
  _x_flip_tb->image (X_FLIP_ICON);

  _y_flip_tb->tooltip ("Y-flip (Tab)");
  _y_flip_tb->callback ((Fl_Callback *) y_flip_cb, this);
  _y_flip_tb->image (Y_FLIP_ICON);

  /* Configure left group. */

  /*! todo This is a mock up (kludge) of the left group - layer dialog.
   * This requires a proper implementation. */

  _layer_1_rb->callback ((Fl_Callback *) layer_1_rb_cb, this);
  _layer_1_rb->tooltip ("Set active layer");
  _layer_1_rb->setonly ();
  _layer_1_cb->callback ((Fl_Callback *) layer_1_cb_cb, this);
  _layer_1_cb->tooltip ("Toggle visibility");
  _layer_1_cb->set ();
  _layer_1_lb->callback ((Fl_Callback *) layer_1_label_cb, this);
  _layer_1_lb->tooltip ("Change layer properties");
  _layer_1_lb->box (FL_DOWN_BOX);
  _layer_1_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_1_lb->color (0x8B2323);

  _layer_2_rb->callback ((Fl_Callback *) layer_2_rb_cb, this);
  _layer_2_rb->tooltip ("Set active layer");
  _layer_2_cb->callback ((Fl_Callback *) layer_2_cb_cb, this);
  _layer_2_cb->tooltip ("Toggle visibility");
  _layer_2_cb->set ();
  _layer_2_lb->callback ((Fl_Callback *) layer_2_label_cb, this);
  _layer_2_lb->tooltip ("Change layer properties");
  _layer_2_lb->box (FL_DOWN_BOX);
  _layer_2_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_2_lb->color (0x3A5FCD);

  _layer_3_rb->callback ((Fl_Callback *) layer_3_rb_cb, this);
  _layer_3_rb->tooltip ("Set active layer");
  _layer_3_cb->callback ((Fl_Callback *) layer_3_cb_cb, this);
  _layer_3_cb->tooltip ("Toggle visibility");
  _layer_3_cb->set ();
  _layer_3_lb->callback ((Fl_Callback *) layer_3_label_cb, this);
  _layer_3_lb->tooltip ("Change layer properties");
  _layer_3_lb->box (FL_DOWN_BOX);
  _layer_3_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_3_lb->color (0x104E8B);

  _layer_4_rb->callback ((Fl_Callback *) layer_4_rb_cb, this);
  _layer_4_rb->tooltip ("Set active layer");
  _layer_4_cb->callback ((Fl_Callback *) layer_4_cb_cb, this);
  _layer_4_cb->tooltip ("Toggle visibility");
  _layer_4_cb->set ();
  _layer_4_lb->callback ((Fl_Callback *) layer_4_label_cb, this);
  _layer_4_lb->tooltip ("Change layer properties");
  _layer_4_lb->box (FL_DOWN_BOX);
  _layer_4_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_4_lb->color (0xCD3700);

  _layer_5_rb->callback ((Fl_Callback *) layer_5_rb_cb, this);
  _layer_5_rb->tooltip ("Set active layer");
  _layer_5_cb->callback ((Fl_Callback *) layer_5_cb_cb, this);
  _layer_5_cb->tooltip ("Toggle visibility");
  _layer_5_cb->set ();
  _layer_5_lb->callback ((Fl_Callback *) layer_5_label_cb, this);
  _layer_5_lb->tooltip ("Change layer properties");
  _layer_5_lb->box (FL_DOWN_BOX);
  _layer_5_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_5_lb->color (0x548B54);

  _layer_6_rb->callback ((Fl_Callback *) layer_6_rb_cb, this);
  _layer_6_rb->tooltip ("Set active layer");
  _layer_6_cb->callback ((Fl_Callback *) layer_6_cb_cb, this);
  _layer_6_cb->tooltip ("Toggle visibility");
  _layer_6_cb->set ();
  _layer_6_lb->callback ((Fl_Callback *) layer_6_label_cb, this);
  _layer_6_lb->tooltip ("Change layer properties");
  _layer_6_lb->box (FL_DOWN_BOX);
  _layer_6_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_6_lb->color (0x8B7355);

  _layer_7_rb->callback ((Fl_Callback *) layer_7_rb_cb, this);
  _layer_7_rb->tooltip ("Set active layer");
  _layer_7_cb->callback ((Fl_Callback *) layer_7_cb_cb, this);
  _layer_7_cb->tooltip ("Toggle visibility");
  _layer_7_cb->set ();
  _layer_7_lb->callback ((Fl_Callback *) layer_7_label_cb, this);
  _layer_7_lb->tooltip ("Change layer properties");
  _layer_7_lb->box (FL_DOWN_BOX);
  _layer_7_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_7_lb->color (0x00868B);

  _layer_8_rb->callback ((Fl_Callback *) layer_8_rb_cb, this);
  _layer_8_rb->tooltip ("Set active layer");
  _layer_8_cb->callback ((Fl_Callback *) layer_8_cb_cb, this);
  _layer_8_cb->tooltip ("Toggle visibility");
  _layer_8_cb->set ();
  _layer_8_lb->callback ((Fl_Callback *) layer_8_label_cb, this);
  _layer_8_lb->tooltip ("Change layer properties");
  _layer_8_lb->box (FL_DOWN_BOX);
  _layer_8_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_8_lb->color (0x228B22);

  _layer_9_rb->callback ((Fl_Callback *) layer_9_rb_cb, this);
  _layer_9_rb->tooltip ("Set active layer");
  _layer_9_cb->callback ((Fl_Callback *) layer_9_cb_cb, this);
  _layer_9_cb->tooltip ("Toggle visibility");
  _layer_9_cb->set ();
  _layer_9_lb->callback ((Fl_Callback *) layer_9_label_cb, this);
  _layer_9_lb->tooltip ("Change layer properties");
  _layer_9_lb->box (FL_DOWN_BOX);
  _layer_9_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_9_lb->color (0x8B2323);

  _layer_10_rb->callback ((Fl_Callback *) layer_10_rb_cb, this);
  _layer_10_rb->tooltip ("Set active layer");
  _layer_10_cb->callback ((Fl_Callback *) layer_10_cb_cb, this);
  _layer_10_cb->tooltip ("Toggle visibility");
  _layer_10_cb->set ();
  _layer_10_lb->callback ((Fl_Callback *) layer_10_label_cb, this);
  _layer_10_lb->tooltip ("Change layer properties");
  _layer_10_lb->box (FL_DOWN_BOX);
  _layer_10_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_10_lb->color (0x3A5FCD);

  _layer_11_rb->callback ((Fl_Callback *) layer_11_rb_cb, this);
  _layer_11_rb->tooltip ("Set active layer");
  _layer_11_cb->callback ((Fl_Callback *) layer_11_cb_cb, this);
  _layer_11_cb->tooltip ("Toggle visibility");
  _layer_11_cb->set ();
  _layer_11_lb->callback ((Fl_Callback *) layer_11_label_cb, this);
  _layer_11_lb->tooltip ("Change layer properties");
  _layer_11_lb->box (FL_DOWN_BOX);
  _layer_11_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_11_lb->color (0x104E8B);

  _layer_12_rb->callback ((Fl_Callback *) layer_12_rb_cb, this);
  _layer_12_rb->tooltip ("Set active layer");
  _layer_12_cb->callback ((Fl_Callback *) layer_12_cb_cb, this);
  _layer_12_cb->tooltip ("Toggle visibility");
  _layer_12_cb->set ();
  _layer_12_lb->callback ((Fl_Callback *) layer_12_label_cb, this);
  _layer_12_lb->tooltip ("Change layer properties");
  _layer_12_lb->box (FL_DOWN_BOX);
  _layer_12_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_12_lb->color (0xCD3700);

  _layer_13_rb->callback ((Fl_Callback *) layer_13_rb_cb, this);
  _layer_13_rb->tooltip ("Set active layer");
  _layer_13_cb->callback ((Fl_Callback *) layer_13_cb_cb, this);
  _layer_13_cb->tooltip ("Toggle visibility");
  _layer_13_cb->set ();
  _layer_13_lb->callback ((Fl_Callback *) layer_13_label_cb, this);
  _layer_13_lb->tooltip ("Change layer properties");
  _layer_13_lb->box (FL_DOWN_BOX);
  _layer_13_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_13_lb->color (0x548B54);

  _layer_14_rb->callback ((Fl_Callback *) layer_14_rb_cb, this);
  _layer_14_rb->tooltip ("Set active layer");
  _layer_14_cb->callback ((Fl_Callback *) layer_14_cb_cb, this);
  _layer_14_cb->tooltip ("Toggle visibility");
  _layer_14_lb->callback ((Fl_Callback *) layer_14_label_cb, this);
  _layer_14_lb->tooltip ("Change layer properties");
  _layer_14_lb->box (FL_DOWN_BOX);
  _layer_14_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _layer_14_lb->color (0x670183);

  _trackball->box (FL_DOWN_BOX);

  _route_style_1_rb->tooltip ("Set active route style");
  _route_style_1_rb->setonly ();
  _route_style_1_lb->tooltip ("Change route style properties");
  _route_style_1_lb->box (FL_DOWN_BOX);
  _route_style_1_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _route_style_2_rb->tooltip ("Set active route style");
  _route_style_2_lb->tooltip ("Change route style properties");
  _route_style_2_lb->box (FL_DOWN_BOX);
  _route_style_2_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _route_style_3_rb->tooltip ("Set active route style");
  _route_style_3_lb->tooltip ("Change route style properties");
  _route_style_3_lb->box (FL_DOWN_BOX);
  _route_style_3_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _route_style_4_rb->tooltip ("Set active route style");
  _route_style_4_lb->tooltip ("Change route style properties");
  _route_style_4_lb->box (FL_DOWN_BOX);
  _route_style_4_lb->align (FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

  /* Configure containers. */

  /* Configure dialogs. */
  _help_dialog->content
  (
#include "help/pcb.html" /* a C++11 raw string literal. */
  );

}

Main_Window::~Main_Window ()
{
  delete _menu_bar; /* Includes menu items. */
  delete _about_dialog;
}

void
Main_Window::show ()
{
  Fl_Overlay_Window::show ();
#ifdef _WIN32
  /* Fix for 16x16 icon from <http://www.fltk.org/str.php?L925>. */
  HWND hwnd = fl_xid (this);

  HANDLE big_icon = LoadImage (GetModuleHandle (0),
                               MAKEINTRESOURCE (IDI_ICON1),
                               IMAGE_ICON,
                               GetSystemMetrics (SM_CXICON),
                               GetSystemMetrics (SM_CXICON),
                               0);

  SendMessage (hwnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(big_icon));

  HANDLE small_icon = LoadImage (GetModuleHandle (0),
                                 MAKEINTRESOURCE (IDI_ICON1),
                                 IMAGE_ICON,
                                 GetSystemMetrics (SM_CXSMICON),
                                 GetSystemMetrics (SM_CXSMICON),
                                 0);

  SendMessage (hwnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(small_icon));
#else
  /* Fix for X11 icon alpha mask <https://www.mail-archive.com/fltk@easysw.com/msg02863.html>. */
  XWMHints *hints = XGetWMHints (fl_display, fl_xid (this));
  hints->flags |= IconMaskHint;
//  hints->icon_mask = _icon_mask;
  XSetWMHints (fl_display, fl_xid (this), hints);
  XFree (hints);
#endif /* _WIN32 */
}


bool
Main_Window::maximized () const
{
#ifdef _WIN32

  WINDOWPLACEMENT wp;
  wp.length = sizeof (wp);

  if (!GetWindowPlacement (fl_xid (this), &wp))
  {
    return false;
  }

  return wp.showCmd == SW_MAXIMIZE;

#else

  Atom wmState = XInternAtom (fl_display, "_NET_WM_STATE", True);
  Atom actual;
  int format;
  unsigned long numItems, bytesAfter;
  unsigned char *properties = NULL;
  int result = XGetWindowProperty (fl_display,
                                   fl_xid (this),
                                   wmState,
                                   0,
                                   1024,
                                   False,
                                   AnyPropertyType,
                                   &actual,
                                   &format,
                                   &numItems,
                                   &bytesAfter,
                                   &properties);

  int numMax = 0;

  if (result == Success && format == 32 && properties)
  {
    Atom maxVert = XInternAtom (fl_display, "_NET_WM_STATE_MAXIMIZED_VERT", False);
    Atom maxHorz = XInternAtom (fl_display, "_NET_WM_STATE_MAXIMIZED_HORZ", False);

    for (unsigned long i = 0; i < numItems; i++)
    {
      Atom property = ((Atom *) properties)[i];

      if (property == maxVert || property == maxHorz)
      {
        numMax++;
      }

    }

    XFree (properties);
  }

  return numMax == 2;
#endif /* _WIN32 */
}


void
Main_Window::maximize ()
{
#ifdef _WIN32
  ShowWindow (fl_xid (this), SW_MAXIMIZE);
#else
  XEvent event;
  memset(&event, 0, sizeof (event));
  event.xclient.type = ClientMessage;
  event.xclient.window = fl_xid (this);
  event.xclient.message_type = XInternAtom (fl_display, "_NET_WM_STATE", False);
  event.xclient.format = 32;
  event.xclient.data.l[0] = 1;
  event.xclient.data.l[1] = XInternAtom (fl_display, "_NET_WM_STATE_MAXIMIZED_HORZ", False);
  event.xclient.data.l[2] = XInternAtom (fl_display, "_NET_WM_STATE_MAXIMIZED_VERT", False);
  event.xclient.data.l[3] = 1;
  XSendEvent (fl_display, DefaultRootWindow (fl_display), False, SubstructureNotifyMask | SubstructureNotifyMask, &event);
#endif /* _WIN32 */
}


void
Main_Window::apply_transparency ()
{
  double alpha = transparent () ? 0.75 : 1.0;
#ifdef _WIN32
  HWND hwnd = fl_xid (this);
  LONG_PTR exstyle = GetWindowLongPtr (hwnd, GWL_EXSTYLE);

  if (!(exstyle & WS_EX_LAYERED))
  {
    SetWindowLongPtr (hwnd, GWL_EXSTYLE, exstyle | WS_EX_LAYERED);
  }

  SetLayeredWindowAttributes (hwnd, 0, (BYTE)(alpha * 0xFF), LWA_ALPHA);
#else
  Atom atom = XInternAtom (fl_display, "_NET_WM_WINDOW_OPACITY", False);
  uint32_t opacity = (uint32_t) (UINT32_MAX * alpha);
  XChangeProperty (fl_display, fl_xid (this), atom, XA_CARDINAL, 32, PropModeReplace, (unsigned char *) &opacity, 1);
#endif
}

void Main_Window::draw_overlay ()
{
}

int
Main_Window::handle (int event)
{
  switch (event)
  {
    case FL_FOCUS:
      return 1;

    case FL_UNFOCUS:
      return 1;

    default:
      return Fl_Overlay_Window::handle (event);
  }
}


void
Main_Window::exit_cb (Fl_Widget *, Main_Window *mw)
{
  Preferences::close ();
  exit (EXIT_SUCCESS);
}


void
Main_Window::full_screen_cb (Fl_Menu_ *m, Main_Window *mw)
{
  if (m->mvalue ()->value ())
  {
    mw->_wx = mw->x ();
    mw->_wy = mw->y ();
    mw->_ww = mw->w ();
    mw->_wh = mw->h ();
    mw->fullscreen ();
  }
  else
  {
    mw->fullscreen_off (mw->_wx, mw->_wy, mw->_ww, mw->_wh);
  }
}


/*!
 * \todo Remove me when it is time to do so.
 */
void
Main_Window::dummy_cb (Fl_Widget *, Main_Window *mw)
{
}

/* File menu item callbacks. */

void
Main_Window::new_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::open_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::save_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::save_as_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::revert_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::gschem_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::tinycad_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::load_element_to_buffer_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::load_layout_to_buffer_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::load_netlist_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::load_vendor_resource_file_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::save_conn_data_1_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::save_conn_data_all_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::save_conn_data_u_pins_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::export_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::calibrate_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::print_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::preferences_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::quit_cb (Fl_Widget *, Main_Window *mw)
{
}


/* Edit menu item callbacks. */


void
Main_Window::undo_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::redo_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::clear_undo_buffer_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::cut_to_buffer_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::copy_to_buffer_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::paste_from_buffer_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::unselect_all_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::select_all_visible_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::edit_name_of_text_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::edit_name_of_layout_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::edit_name_of_active_layer_cb (Fl_Widget *, Main_Window *mw)
{
}


/* Tool button callbacks.
 * Some of the toolbutton callbacks are identical to menu item callbacks. */


void
Main_Window::via_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::line_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::arc_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::text_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::rect_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::poly_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::polyhole_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::buf_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::del_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::rot_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::ins_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::thrm_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::sel_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::lock_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::pan_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::load_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::reload_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::zoom_in_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::zoom_out_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::x_flip_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::y_flip_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::help_cb (Fl_Widget *, Main_Window *mw)
{
  mw->_help_dialog->show (mw);
}


void
Main_Window::about_cb (Fl_Widget *, Main_Window *mw)
{
//  mw->_about_dialog->show (mw);
}


void
Main_Window::layer_1_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_2_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_3_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_4_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_5_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_6_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_7_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_8_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_9_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_10_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_11_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_12_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_13_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_14_rb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, the active layer name needs to be passed to the
   * pcb data structs. */
}


void
Main_Window::layer_1_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_2_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_3_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_4_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_5_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_6_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_7_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_8_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_9_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_10_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_11_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_12_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_13_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_14_cb_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If toggled, update the icon.
   * The layer state (on/off) needs to be passed to the pcb data structs
   * as well. */
}


void
Main_Window::layer_1_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_2_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_3_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_4_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_5_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_6_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_7_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_8_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_9_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_10_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_11_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_12_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_13_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


void
Main_Window::layer_14_label_cb (Fl_Widget *, Main_Window *mw)
{
  /*! \todo If clicked, let the user alter the name of the layer.
   * The new layer name needs to be passed to the pcb data structs as
   * well. */
}


#pragma warning(pop)
