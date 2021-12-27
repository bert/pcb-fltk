/*!
 * \file src/hid/fltk/toolbar.cpp
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


#include "toolbar.h"


Toolbar::Toolbar (int x, int y, int w, int h, const char *l) : Fl_Group (x, y, w, h, l), _spacer (0, 0, 0, 0)
{
  labeltype (FL_NO_LABEL);
  box (OS_TOOLBAR_FRAME);
  resizable (_spacer);
  clip_children (1);
  begin ();
}


void
Toolbar::resize (int x, int y, int w, int h)
{
  add (_spacer); /* Keep the resizable spacer as the last child. */
  resizable (_spacer);
  Fl_Group::resize (x, y, w, h);
}


void
Toolbar::draw ()
{
  /* Based on Fl_Pack::draw(). */
  int tx = x () + Fl::box_dx (box());
  int ty = y () + Fl::box_dy (box());
  int tw = w () - Fl::box_dw (box());
  int th = h () - Fl::box_dh (box());
  int cur_x = tx;
  int max_x = tx;
  uchar d = damage ();
  Fl_Widget * const *a = array ();
  int rw = 0;

  for (int i = children (); i--;)
  {
    if (child(i)->visible ())
    {
      if (child (i) != this->resizable ())
      {
        rw += child (i)->w();
      }
    }
  }

  for (int i = children (); i--;)
  {
    Fl_Widget* o = *a++;

    if (!o->visible ())
    {
      continue;
    }

    int X = cur_x;
    int Y = ty + (th - o->h ()) / 2;
    int W = o->w ();

    if (i == 0 && o == this->resizable ())
    {
      W = tw - rw; } /* Last child, if resizable, takes all remaining room. */

      if (X != o->x () || Y != o->y () || W != o->w ())
      {
        o->resize (X, Y, W, o->h ());
        o->clear_damage (FL_DAMAGE_ALL);
      }

      if (d & FL_DAMAGE_ALL)
      {
        draw_child (*o);
        draw_outside_label (*o);
      }
      else
      {
        update_child (*o);
      }

      cur_x += o->w(); /* Child's draw() can change it's size, so use new size. */

      if (cur_x > max_x)
      {
        max_x = cur_x;
      }
  }

  if (max_x < tx + tw && box ())
  {
    fl_color (color());
    fl_rectf (max_x, ty, tx+tw-max_x, th);
  }

  tw = max_x - tx;
  tw += Fl::box_dw (box ());

  if (tw <= 0)
  {
    tw = 1;
  }

  th += Fl::box_dh (box ());

  if (th <= 0)
  {
    th = 1;
  }

  if (tw != w () || th != h ())
  {
    Fl_Widget::resize (x (), y (), tw, th);
    d = FL_DAMAGE_ALL;
  }

  if (d & FL_DAMAGE_ALL)
  {
    draw_box ();
    draw_label ();
  }
}


Toolbar_Button::Toolbar_Button (int x, int y, int w, int h, const char *l) : Fl_Button (x, y, w, h, l)
{
  box (OS_BG_BOX);
  color (FL_BACKGROUND_COLOR);
  down_box (OS_MINI_DEPRESSED_DOWN_BOX);
  down_color (FL_SELECTION_COLOR);
  labelfont (OS_FONT);
  labelsize (OS_FONT_SIZE);
  align (FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
}


void
Toolbar_Button::draw ()
{
  /* Based on Fl_Button::draw(). */
  Fl_Color col = value () ? (OS::current_theme () == OS::Theme::CLASSIC ? fl_lighter (color()) : selection_color ()) : color ();
  draw_box (value() ? OS::current_theme () == OS::Theme::OLIVE ? OS_MINI_BUTTON_UP_BOX : down_box () ? down_box () : fl_down (box()) : box (), col);
  draw_backdrop ();

  if (labeltype () == FL_NORMAL_LABEL && value ())
  {
    Fl_Color c = labelcolor ();
    labelcolor (fl_contrast (c, col));
    draw_label ();
    labelcolor (c);
  }
  else
  {
    draw_label ();
  }

  if (Fl::focus () == this)
  {
    draw_focus ();
  }
}


int
Toolbar_Button::handle (int event)
{
  switch (event)
  {
    case FL_ENTER:
      if (active_r ())
      {
        color (FL_LIGHT3);
        box (OS_TOOLBAR_BUTTON_HOVER_BOX);
        redraw ();
        return 1;
      }

      return 0;

    case FL_LEAVE:
      color (FL_BACKGROUND_COLOR);
      box (OS_BG_BOX);
      redraw ();
      return 1;

    case FL_PUSH:
      Fl::focus (this);
  }

  return Fl_Button::handle (event);
}


Toolbar_Toggle_Button::Toolbar_Toggle_Button (int x, int y, int w, int h, const char *l) : Toolbar_Button(x, y, w, h, l)
{
  type (FL_TOGGLE_BUTTON);
}


Toolbar_Radio_Button::Toolbar_Radio_Button (int x, int y, int w, int h, const char *l) : Toolbar_Button(x, y, w, h, l)
{
  type(FL_RADIO_BUTTON);
}
