/*!
 * \file src/hid/fltk/main_window.h
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


#ifndef PCB_SRC_HID_FLTK_MAIN_WINDOW_H
#define PCB_SRC_HID_FLTK_MAIN_WINDOW_H


/* Standard headers */
#include <vector>


#include "FLTK_headers.h"
#include "utils.h"
#include "themes.h"
#include "icons.h"
#include "version.h"
#include "preferences.h"
#include "spacer.h"
#include "toolbar.h"
#include "modal_dialog.h"
#include "about_dialog.h"
#include "help_window.h"
#include "label_button.h"


#ifndef NUM_RECENT
#define NUM_RECENT 10
#endif

#ifndef OS_TAB_HEIGHT
#define OS_TAB_HEIGHT 20
#endif


class Main_Window : public Fl_Overlay_Window
{
  private:
    /* GUI containers. */
    Fl_Menu_Bar *_menu_bar;
    Toolbar *_toolbar;
    Fl_Group *_main_group;
    Fl_Group *_left_group;
    Fl_Group *_layer_group;
    Fl_Group *_route_style_group;

    Toolbar *_status_bar;

    /* GUI inputs. */
    Fl_Menu_Item *_transparent_mi = NULL;
    Fl_Menu_Item *_full_screen_mi = NULL;

    /* Toolbar menu buttons. */
    Toolbar_Button *_new_tb;
    Toolbar_Button *_open_tb;
    Toolbar_Button *_save_tb;
    Toolbar_Button *_print_tb;

    Toolbar_Button *_via_tb;
    Toolbar_Button *_line_tb;
    Toolbar_Button *_arc_tb;
    Toolbar_Button *_text_tb;
    Toolbar_Button *_rect_tb;
    Toolbar_Button *_poly_tb;
    Toolbar_Button *_polyhole_tb;
    Toolbar_Button *_buf_tb;
    Toolbar_Button *_del_tb;
    Toolbar_Button *_rot_tb;
    Toolbar_Button *_ins_tb;
    Toolbar_Button *_thrm_tb;
    Toolbar_Button *_sel_tb;
    Toolbar_Button *_lock_tb;
    Toolbar_Button *_pan_tb;

    Toolbar_Button *_load_tb;
    Toolbar_Button *_reload_tb;

    Toolbar_Button *_zoom_in_tb;
    Toolbar_Button *_zoom_out_tb;

    Toolbar_Button *_x_flip_tb;
    Toolbar_Button *_y_flip_tb;

    /* Layer dialog: toggle buttons. */
    Fl_Radio_Round_Button *_layer_1_rb;
    Fl_Radio_Round_Button *_layer_2_rb;
    Fl_Radio_Round_Button *_layer_3_rb;
    Fl_Radio_Round_Button *_layer_4_rb;
    Fl_Radio_Round_Button *_layer_5_rb;
    Fl_Radio_Round_Button *_layer_6_rb;
    Fl_Radio_Round_Button *_layer_7_rb;
    Fl_Radio_Round_Button *_layer_8_rb;
    Fl_Radio_Round_Button *_layer_9_rb;
    Fl_Radio_Round_Button *_layer_10_rb;
    Fl_Radio_Round_Button *_layer_11_rb;
    Fl_Radio_Round_Button *_layer_12_rb;
    Fl_Radio_Round_Button *_layer_13_rb;
    Fl_Radio_Round_Button *_layer_14_rb;

    /* Layer dialog: check buttons. */
    Fl_Check_Button *_layer_1_cb;
    Fl_Check_Button *_layer_2_cb;
    Fl_Check_Button *_layer_3_cb;
    Fl_Check_Button *_layer_4_cb;
    Fl_Check_Button *_layer_5_cb;
    Fl_Check_Button *_layer_6_cb;
    Fl_Check_Button *_layer_7_cb;
    Fl_Check_Button *_layer_8_cb;
    Fl_Check_Button *_layer_9_cb;
    Fl_Check_Button *_layer_10_cb;
    Fl_Check_Button *_layer_11_cb;
    Fl_Check_Button *_layer_12_cb;
    Fl_Check_Button *_layer_13_cb;
    Fl_Check_Button *_layer_14_cb;

    /* Layer dialog: layer change properties buttons. */
    Fl_Button *_layer_1_lb;
    Fl_Button *_layer_2_lb;
    Fl_Button *_layer_3_lb;
    Fl_Button *_layer_4_lb;
    Fl_Button *_layer_5_lb;
    Fl_Button *_layer_6_lb;
    Fl_Button *_layer_7_lb;
    Fl_Button *_layer_8_lb;
    Fl_Button *_layer_9_lb;
    Fl_Button *_layer_10_lb;
    Fl_Button *_layer_11_lb;
    Fl_Button *_layer_12_lb;
    Fl_Button *_layer_13_lb;
    Fl_Button *_layer_14_lb;

    /* Trackball (place holder).*/
    Fl_Button *_trackball;

    /* Route style dialog: radio buttons.*/
    Fl_Radio_Round_Button *_route_style_1_rb;
    Fl_Radio_Round_Button *_route_style_2_rb;
    Fl_Radio_Round_Button *_route_style_3_rb;
    Fl_Radio_Round_Button *_route_style_4_rb;

    /* Route style dialog: route style change properties label buttons. */
    Fl_Button *_route_style_1_lb;
    Fl_Button *_route_style_2_lb;
    Fl_Button *_route_style_3_lb;
    Fl_Button *_route_style_4_lb;

    /* GUI outputs. */
    Label *_view_side_label;
    Label *_grid_size_label;
    Label *_line_mode_label;
    Label *_line_thickness_label;
    Label *_via_thickness_label;
    Label *_clearance_label;
    Label *_text_size_label;
    Label *_buffer_nr_label;

    /* Conditional menu items. */

    /* Dialogs. */
    Help_Window *_help_dialog;
    About_Dialog *_about_dialog;

    /* Data. */

    /* Work properties. */

    /* Window size cache. */
    int _wx;
    int _wy;
    int _ww;
    int _wh;

#ifndef _WIN32
  /* Window icons. */
  static Fl_Pixmap _icon_pixmap;
  static Fl_Pixmap _icon_mask;
#endif


  public:
    Main_Window (int x, int y, int w, int h, const char *l = NULL);

    ~Main_Window ();

    void show (void);

    bool maximized (void) const;

    void maximize (void);

    void apply_transparency (void);

    inline bool transparent (void) const
    {
      return _transparent_mi && !!_transparent_mi->value ();
    }

    inline bool full_screen (void) const
    {
      return _full_screen_mi && !!_full_screen_mi->value ();
    }

    void draw_overlay (void);

    int handle (int event);

  private:

    /* Drag-and-drop. */

    /* Window callbacks. */
    static void exit_cb (Fl_Widget *w, Main_Window *mw);
    static void full_screen_cb (Fl_Menu_ *m, Main_Window *mw);

    /* Menu bar callbacks.*/
    static void dummy_cb (Fl_Widget *w, Main_Window *mw);

    /* File menu item callbacks. */
    static void new_cb (Fl_Widget *w, Main_Window *mw);
    static void open_cb (Fl_Widget *w, Main_Window *mw);
    static void save_cb (Fl_Widget *w, Main_Window *mw);
    static void save_as_cb (Fl_Widget *w, Main_Window *mw);
    static void revert_cb (Fl_Widget *w, Main_Window *mw);
    static void gschem_cb (Fl_Widget *w, Main_Window *mw);
    static void tinycad_cb (Fl_Widget *w, Main_Window *mw);
    static void load_element_to_buffer_cb (Fl_Widget *w, Main_Window *mw);
    static void load_layout_to_buffer_cb (Fl_Widget *w, Main_Window *mw);
    static void load_netlist_cb (Fl_Widget *w, Main_Window *mw);
    static void load_vendor_resource_file_cb (Fl_Widget *w, Main_Window *mw);
    static void save_conn_data_1_cb (Fl_Widget *w, Main_Window *mw);
    static void save_conn_data_all_cb (Fl_Widget *w, Main_Window *mw);
    static void save_conn_data_u_pins_cb (Fl_Widget *w, Main_Window *mw);
    static void export_cb (Fl_Widget *w, Main_Window *mw);
    static void calibrate_cb (Fl_Widget *w, Main_Window *mw);
    static void print_cb (Fl_Widget *w, Main_Window *mw);
    static void preferences_cb (Fl_Widget *w, Main_Window *mw);
    static void quit_cb (Fl_Widget *w, Main_Window *mw);

    /* Edit menu item callbacks. */

    static void undo_cb (Fl_Widget *w, Main_Window *mw);
    static void redo_cb (Fl_Widget *w, Main_Window *mw);
    static void clear_undo_buffer_cb (Fl_Widget *w, Main_Window *mw);
    static void cut_to_buffer_cb (Fl_Widget *w, Main_Window *mw);
    static void copy_to_buffer_cb (Fl_Widget *w, Main_Window *mw);
    static void paste_from_buffer_cb (Fl_Widget *w, Main_Window *mw);
    static void unselect_all_cb (Fl_Widget *w, Main_Window *mw);
    static void select_all_visible_cb (Fl_Widget *w, Main_Window *mw);
    static void edit_name_of_text_cb (Fl_Widget *w, Main_Window *mw);
    static void edit_name_of_layout_cb (Fl_Widget *w, Main_Window *mw);
    static void edit_name_of_active_layer_cb (Fl_Widget *w, Main_Window *mw);

    /* View menu item callbacks. */

    /* Settings menu item callbacks. */

    /* Tools menu item callbacks. */

    /* Help menu item callbacks. */
    static void help_cb (Fl_Widget *w, Main_Window *mw);
    static void about_cb (Fl_Widget *w, Main_Window *mw);

    /* Toolbar button callbacks. */
    static void via_cb (Fl_Widget *w, Main_Window *mw);
    static void line_cb (Fl_Widget *w, Main_Window *mw);
    static void arc_cb (Fl_Widget *w, Main_Window *mw);
    static void text_cb (Fl_Widget *w, Main_Window *mw);
    static void rect_cb (Fl_Widget *w, Main_Window *mw);
    static void poly_cb (Fl_Widget *w, Main_Window *mw);
    static void polyhole_cb (Fl_Widget *w, Main_Window *mw);
    static void buf_cb (Fl_Widget *w, Main_Window *mw);
    static void del_cb (Fl_Widget *w, Main_Window *mw);
    static void rot_cb (Fl_Widget *w, Main_Window *mw);
    static void ins_cb (Fl_Widget *w, Main_Window *mw);
    static void thrm_cb (Fl_Widget *w, Main_Window *mw);
    static void sel_cb (Fl_Widget *w, Main_Window *mw);
    static void lock_cb (Fl_Widget *w, Main_Window *mw);
    static void pan_cb (Fl_Widget *w, Main_Window *mw);

    static void load_cb (Fl_Widget *w, Main_Window *mw);
    static void reload_cb (Fl_Widget *w, Main_Window *mw);

    static void zoom_in_cb (Fl_Widget *w, Main_Window *mw);
    static void zoom_out_cb (Fl_Widget *w, Main_Window *mw);

    static void x_flip_cb (Fl_Widget *w, Main_Window *mw);
    static void y_flip_cb (Fl_Widget *w, Main_Window *mw);

    /* Layer dialog - radio button callbacks. */
    static void layer_1_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_2_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_3_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_4_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_5_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_6_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_7_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_8_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_9_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_10_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_11_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_12_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_13_rb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_14_rb_cb (Fl_Widget *w, Main_Window *mw);

    /* Layer dialog - layer toggle button callbacks. */
    static void layer_1_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_2_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_3_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_4_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_5_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_6_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_7_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_8_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_9_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_10_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_11_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_12_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_13_cb_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_14_cb_cb (Fl_Widget *w, Main_Window *mw);

    /* Layer dialog - label button callbacks. */
    static void layer_1_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_2_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_3_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_4_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_5_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_6_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_7_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_8_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_9_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_10_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_11_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_12_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_13_label_cb (Fl_Widget *w, Main_Window *mw);
    static void layer_14_label_cb (Fl_Widget *w, Main_Window *mw);
};


#endif /* PCB_SRC_HID_FLTK_MAIN_WINDOW_H */


/* EOF */
