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

  /* Main group. */

  /* Left group. */

  /* Dialogs. */
//  _about_dialog = new About_Dialog (this, "About " PROGRAM_NAME, Modal_Dialog::Icon::APP_ICON);

  /* Drag-and-drop receivers. */

  /* Configure window. */

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




  /* Configure containers. */

  /* Configure dialogs. */

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
Main_Window::undo_cb (Fl_Widget *, Main_Window *mw)
{
}


void
Main_Window::redo_cb (Fl_Widget *, Main_Window *mw)
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
}


void
Main_Window::about_cb (Fl_Widget *, Main_Window *mw)
{
//  mw->_about_dialog->show (mw);
}


#pragma warning(pop)
