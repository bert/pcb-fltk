/*!
 * \file src/hid/fltk/res/fpcb-menu.res
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


/* Format: label, shortcut, callback, data, flags. */

/*
 * File menu items.
 */
{"File", 0, nullptr, nullptr, FL_SUBMENU},
  {"New", FL_COMMAND + 'n', (Fl_Callback *) new_CB, this},
  {"Open", FL_COMMAND + 'o', (Fl_Callback *) open_CB, this, FL_MENU_DIVIDER},
  {"Save", FL_COMMAND + 's', (Fl_Callback *) save_CB, this},
  {"Save as...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback *) save_as_CB, this},
  {"Revert", 0, (Fl_Callback *) revert_CB, this, FL_MENU_DIVIDER},
  {"Import Schematics", 0, nullptr, nullptr, FL_SUBMENU},
    {"gschem", 0, (Fl_Callback *) gschem_CB, this},
    {"TinyCAD", 0, (Fl_Callback *) tinycad_CB, this},
    {0},
  {"Load element to buffer", 0, (Fl_Callback *) load_element_to_buffer_CB, this},
  {"Load layout to buffer", 0, (Fl_Callback *) load_layout_to_buffer_CB, this},
  {"Load netlist", 0, (Fl_Callback *) load_netlist_CB, this},
  {"Load vendor resource file", 0, (Fl_Callback *) load_vendor_resource_file_CB, this, FL_MENU_DIVIDER},
  {"Save connection data of", 0, nullptr, nullptr, FL_SUBMENU},
    {"a single element", 0, (Fl_Callback *) save_conn_data_1_CB, this},
    {"all elements", 0, (Fl_Callback *) save_conn_data_all_CB, this},
    {"unused pins", 0, (Fl_Callback *) save_conn_data_u_pins_CB, this},
    {0},
  {"Export", 0, (Fl_Callback *) export_CB, this, FL_MENU_DIVIDER},
  {"Calibrate printer", 0, (Fl_Callback *) calibrate_CB, this},
  {"Print", FL_COMMAND + 'p', (Fl_Callback *) print_CB, this, FL_MENU_DIVIDER},
  {"Preferences", 0, (Fl_Callback *) preferences_CB, this, FL_MENU_DIVIDER},
  {"Quit", FL_COMMAND + 'q', (Fl_Callback *) quit_CB, this},
  {0},

/*
 * Edit menu items.
 */
{"Edit", 0, nullptr, nullptr, FL_SUBMENU},
  {"Undo", FL_COMMAND + 'z', (Fl_Callback *) undo_CB, this},
  {"Redo", FL_COMMAND + FL_SHIFT + 'z', (Fl_Callback *) redo_CB, this},
  {"Clear undo-buffer", 0, (Fl_Callback *) clear_undo_buffer_CB, this, FL_MENU_DIVIDER},
  {"Cut to buffer", FL_COMMAND + 'x', (Fl_Callback *) cut_to_buffer_CB, this},
  {"Copy to buffer", FL_COMMAND + 'c', (Fl_Callback *) copy_to_buffer_CB, this},
  {"Paste from buffer", FL_COMMAND + 'v', (Fl_Callback *) paste_from_buffer_CB, this, FL_MENU_DIVIDER},
  {"Unselect all", FL_COMMAND + FL_SHIFT + 'a', (Fl_Callback *) unselect_all_CB, this},
  {"Select all visible", FL_COMMAND + 'a', (Fl_Callback *) select_all_visible_CB, this, FL_MENU_DIVIDER},
  {"Edit name of", 0, nullptr, nullptr, FL_SUBMENU},
    {"text on layout", FL_SHIFT + 'n', (Fl_Callback *) edit_name_of_text_CB, this},
    {"layout", 0, (Fl_Callback *) edit_name_of_layout_CB, this},
    {"active layer", 0, (Fl_Callback *) edit_name_of_active_layer_CB, this},
    {0},
  {"Edit attributes of", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Layout", FL_SHIFT + 'n', (Fl_Callback *) dummy_CB, this},
    {"Current layer", 0, (Fl_Callback *) dummy_CB, this},
    {"Element", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Route style", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Signal", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_CHECK},
    {"Power", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"Fat", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"Skinny", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_DIVIDER},
    {0},
  {"Via type", 0, nullptr, nullptr, FL_SUBMENU},
    {"Through-hole", FL_COMMAND + FL_SHIFT + 'p', (Fl_Callback *) dummy_CB, this},
    {"Buried from", FL_COMMAND + FL_SHIFT + 'f', (Fl_Callback *) dummy_CB, this},
    {"Buried to", FL_COMMAND + FL_SHIFT + 't', (Fl_Callback *) dummy_CB, this},
    {0},
  {0},

/*
 * View menu items.
 */
{"View", 0, nullptr, nullptr, FL_SUBMENU},
  {"Enable visible grid", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
  {"Grid units", 0, nullptr, nullptr, FL_SUBMENU},
    {"mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_CHECK},
    {"mm", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {0},
  {"Grid size", 0, nullptr, nullptr, FL_SUBMENU},
    {"No Grid", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"0.1 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"1 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"2 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"5 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"10 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_CHECK},
    {"25 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"50 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"100 mil", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"0.01 mm", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"0.05 mm", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"0.1 mm", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"0.25 mm", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"0.5 mm", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"1 mm", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_DIVIDER},
    {"Grid -", FL_SHIFT + 'g', (Fl_Callback *) dummy_CB, this},
    {"Grid +", 'g', (Fl_Callback *) dummy_CB, this},
    {0},
  {"Realign grid", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Displayed element name", 0, nullptr, nullptr, FL_SUBMENU},
    {"Description", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"Reference Designator", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_CHECK},
    {"Value", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {0},
  {"Enable Pinout shows number", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
  {"Pins/Via show Name/Number", 'd', (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Zoom in 20%", 'z', (Fl_Callback *) zoom_in_CB, this,},
  {"Zoom out 20%", FL_SHIFT + 'd', (Fl_Callback *) zoom_out_CB, this},
  {"More zooms and view changes", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Zoom Max", 'v', (Fl_Callback *) dummy_CB, this},
    {"Zoom in 2X", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom out 2X", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 10 mil/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 2.5 mil/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 1 mil/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 0.1 mil/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 0.01 mil/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 0.25 mm/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 0.1 mm/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 0.05 mm/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom to 0.01 mm/px", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom in 20% and center", 0, (Fl_Callback *) dummy_CB, this},
    {"Zoom out 20% and center", 0, (Fl_Callback *) dummy_CB, this},
    {"Flip up/down", FL_Tab, (Fl_Callback *) y_flip_CB, this},
    {"Flip left/right", FL_SHIFT + FL_Tab, (Fl_Callback *) x_flip_CB, this},
    {"Spin 180 degrees", FL_COMMAND + FL_Tab, (Fl_Callback *) dummy_CB, this},
    {"Swap Sides", FL_COMMAND + FL_SHIFT + FL_Tab, (Fl_Callback *) dummy_CB, this},
    {"Center cursor", 'c', (Fl_Callback *) dummy_CB, this},
    {0},
  {"Shown layers", 0, nullptr, nullptr, FL_SUBMENU},
    {"top", FL_COMMAND + '1', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"ground", FL_COMMAND + '2', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"signal2", FL_COMMAND + '3', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"signal3", FL_COMMAND + '4', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"power", FL_COMMAND + '5', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"bottom", FL_COMMAND + '6', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"outline", FL_COMMAND + '7', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"spare", FL_COMMAND + '8', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"top silk", FL_COMMAND + '9', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"rat lines", FL_COMMAND + '0', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"pins/pads", FL_COMMAND + FL_ALT + '1', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"vias", FL_COMMAND + FL_ALT + '2', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"far side", FL_COMMAND + FL_ALT + '3', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
    {"soldermask", FL_COMMAND + FL_ALT + '4', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_DIVIDER},
    {"Edit Layer Groups", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Current layer", 0, nullptr, nullptr, FL_SUBMENU},
    {"top", '1', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_CHECK},
    {"ground", '2', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"signal2", '3', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"signal3", '4', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"power", '5', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"bottom", '6', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"outline", '7', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"spare", '8', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"top silk", '9', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO},
    {"rat lines", '0', (Fl_Callback *) dummy_CB, this, FL_MENU_RADIO + FL_MENU_DIVIDER},
    {"Delete current layer", 0, (Fl_Callback *) dummy_CB, this},
    {"Add new layer", 0, (Fl_Callback *) dummy_CB, this},
    {"Move current layer up", 0, (Fl_Callback *) dummy_CB, this},
    {"Move current layer down", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {0},

/*
 * Settings menu items.
 */
{"Settings", 0, nullptr, nullptr, FL_SUBMENU},
  {"'All-direction' lines", '.', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Auto swap line start angle", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Orthogonal moves", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Crosshair snaps to pins and pads", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Crosshair shows DRC clearance", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Auto enforce DRC clearance", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Lock Names", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Only Names", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Hide Names", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE + FL_MENU_DIVIDER},
  {"Rubber band mode", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Require unique element names", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Auto-zero delta measurements", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"New lines, arcs clear polygons", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"New polygons are full ones", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Show autorouter trials", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Thin draw", '|', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Thin draw poly", FL_COMMAND + FL_SHIFT + 'p', (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Auto buried vias", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Vendor drill mapping", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_TOGGLE},
  {"Import New Elements at", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Center", 0, (Fl_Callback *) dummy_CB, this},
    {"Mark", 0, (Fl_Callback *) dummy_CB, this},
    {"Crosshair", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Set Dispersion", 0, (Fl_Callback *) dummy_CB, this},
  {0},

/*
 * Select menu items.
 */
{"Select", 0, nullptr, nullptr, FL_SUBMENU},
  {"Select all visible", 0, (Fl_Callback *) dummy_CB, this},
  {"Select all found", 0, (Fl_Callback *) dummy_CB, this},
  {"Select all connected", 0, (Fl_Callback *) dummy_CB, this},
  {"Select all buried vias", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Unselect all", 0, (Fl_Callback *) dummy_CB, this},
  {"Unselect all found", 0, (Fl_Callback *) dummy_CB, this},
  {"Unselect all connected", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Select by name", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"All objects", 0, (Fl_Callback *) dummy_CB, this},
    {"Elements", 0, (Fl_Callback *) dummy_CB, this},
    {"Pads", 0, (Fl_Callback *) dummy_CB, this},
    {"Pins", 0, (Fl_Callback *) dummy_CB, this},
    {"Texts", 0, (Fl_Callback *) dummy_CB, this},
    {"Vias", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Auto-place selected elements", FL_COMMAND + 'p', (Fl_Callback *) dummy_CB, this},
  {"Disperse all elements", 0, (Fl_Callback *) dummy_CB, this},
  {"Disperse selected elements", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Move selected elements to other side", FL_SHIFT + 'b', (Fl_Callback *) dummy_CB, this},
  {"Move selected to current layer", FL_SHIFT + 'm', (Fl_Callback *) dummy_CB, this},
  {"Remove selected objects", FL_SHIFT + FL_Delete, (Fl_Callback *) dummy_CB, this},
  {"Convert selection to element", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Optimize selected rats", 0, (Fl_Callback *) dummy_CB, this},
  {"Auto-route selected rats", FL_ALT + 'r', (Fl_Callback *) dummy_CB, this},
  {"Rip up selected auto-routed tracks", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Change size of selected objects", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Lines -10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Lines +10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Pads -10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Pads +10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Pins -10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Pins +10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Texts -10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Texts +10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Vias -10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Vias +10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Change drilling hole of selected objects", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Vias -10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Vias +10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Pins -10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {"Pins +10 mil", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Change square-flag of selected objects", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Elements", 0, (Fl_Callback *) dummy_CB, this},
    {"Pins", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Change type of selected vias", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Through-hole", 0, (Fl_Callback *) dummy_CB, this},
    {"Buried from current layer", 0, (Fl_Callback *) dummy_CB, this},
    {"Buried to current layer", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {0},

/*
 * Buffer menu items.
 */
{"Buffer", 0, nullptr, nullptr, FL_SUBMENU},
  {"Cut to buffer", 0, (Fl_Callback *) dummy_CB, this},
  {"Paste buffer", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Rotate buffer 90 deg CCW", FL_SHIFT + FL_F + 7, (Fl_Callback *) dummy_CB, this},
  {"Rotate buffer 90 deg CW", 0, (Fl_Callback *) dummy_CB, this},
  {"Arbitrarily Rotate Buffer", 0, (Fl_Callback *) dummy_CB, this},
  {"Mirror buffer (up/down)", 0, (Fl_Callback *) dummy_CB, this},
  {"Mirror buffer (left/right)", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Clear buffer", 0, (Fl_Callback *) dummy_CB, this},
  {"Convert buffer to element", 0, (Fl_Callback *) dummy_CB, this},
  {"Break buffer elements to pieces", 0, (Fl_Callback *) dummy_CB, this},
  {"Save buffer elements to file", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Select Buffer #1", FL_SHIFT + '1', (Fl_Callback *) dummy_CB, this},
  {"Select Buffer #2", FL_SHIFT + '2', (Fl_Callback *) dummy_CB, this},
  {"Select Buffer #3", FL_SHIFT + '3', (Fl_Callback *) dummy_CB, this},
  {"Select Buffer #4", FL_SHIFT + '4', (Fl_Callback *) dummy_CB, this},
  {"Select Buffer #5", FL_SHIFT + '5', (Fl_Callback *) dummy_CB, this},
  {0},

/*
 * Connects menu items.
 */ 
{"Connects", 0, nullptr, nullptr, FL_SUBMENU},
  {"Lookup connection", FL_COMMAND + 'f', (Fl_Callback *) dummy_CB, this},
  {"Reset scanned pads/pins/vias", 0, (Fl_Callback *) dummy_CB, this},
  {"Reset scanned lines/polygons", 0, (Fl_Callback *) dummy_CB, this},
  {"Reset all connections", FL_SHIFT + 'f', (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Optimize rats nest", 'o', (Fl_Callback *) dummy_CB, this},
  {"Erase rats nest", 'e', (Fl_Callback *) dummy_CB, this},
  {"Erase selected rats", FL_SHIFT + 'e', (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Auto-route selected rats", 0, (Fl_Callback *) dummy_CB, this},
  {"Auto-route all rats", 0, (Fl_Callback *) dummy_CB, this},
  {"Toporouter", 0, (Fl_Callback *) dummy_CB, this},
  {"Rip up all auto-routed tracks", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Buffer", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
    {"Auto-Optimize", FL_SHIFT + '=', (Fl_Callback *) dummy_CB, this},
    {"Debumpify", 0, (Fl_Callback *) dummy_CB, this},
    {"Unjaggy", 0, (Fl_Callback *) dummy_CB, this},
    {"Vianudge", 0, (Fl_Callback *) dummy_CB, this},
    {"Viatrim", 0, (Fl_Callback *) dummy_CB, this},
    {"Ortho pull", 0, (Fl_Callback *) dummy_CB, this},
    {"Simple optimization", '=', (Fl_Callback *) dummy_CB, this},
    {"Miter", 0, (Fl_Callback *) dummy_CB, this},
    {"Puller", 'y', (Fl_Callback *) dummy_CB, this},
    {"Global Puller", 0, nullptr, nullptr, FL_SUBMENU + FL_MENU_DIVIDER},
      {"Selected", 0, (Fl_Callback *) dummy_CB, this},
      {"Found", 0, (Fl_Callback *) dummy_CB, this},
      {"All", 0, (Fl_Callback *) dummy_CB, this},
      {0},
    {"Only autorouted nets", 0, (Fl_Callback *) dummy_CB, this},
    {0},
  {"Design Rule Checker", 0, (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Apply vendor drill mapping", 0, (Fl_Callback *) dummy_CB, this},
  {0},

/*
 * Info menu items.
 */
{"Info", 0, nullptr, nullptr, FL_SUBMENU},
  {"Generate object report", FL_COMMAND + 'r', (Fl_Callback *) dummy_CB, this},
  {"Generate drill summary", 0, (Fl_Callback *) dummy_CB, this},
  {"Report found pins/pads", 0, (Fl_Callback *) dummy_CB, this},
  {"Report net length", 0, (Fl_Callback *) dummy_CB, this},
  {"Key Bindings", 0, nullptr, nullptr, FL_SUBMENU},
    {"Remove", FL_Delete, (Fl_Callback *) dummy_CB, this},
    {"Remove Selected", FL_BackSpace, (Fl_Callback *) dummy_CB, this},
    {"Remove Connected", FL_SHIFT + FL_BackSpace, (Fl_Callback *) dummy_CB, this},
    {"Set Same", 'a', (Fl_Callback *) dummy_CB, this},
    {"Flip Object", 'b', (Fl_Callback *) dummy_CB, this},
    {"Find Connections", 'f', (Fl_Callback *) dummy_CB, this},
    {"Toggle Hide Name Object", 'h', (Fl_Callback *) dummy_CB, this},
    {"Toggle Hide Name Selected Element", FL_SHIFT + 'h', (Fl_Callback *) dummy_CB, this},
    {"Change Hole Object", FL_COMMAND + 'h', (Fl_Callback *) dummy_CB, this},
    {"Change Join Object", 'j', (Fl_Callback *) dummy_CB, this},
    {"Change Join Selected Object", FL_SHIFT + 'j', (Fl_Callback *) dummy_CB, this},
    {"Clear Object +", 'k', (Fl_Callback *) dummy_CB, this},
    {"Clear Object -", FL_SHIFT + 'k', (Fl_Callback *) dummy_CB, this},
    {"Clear Selected +", FL_COMMAND + 'k', (Fl_Callback *) dummy_CB, this},
    {"Clear Selected -", FL_COMMAND + FL_SHIFT + 'k', (Fl_Callback *) dummy_CB, this},
    {"Line Tool size +", 'l', (Fl_Callback *) dummy_CB, this},
    {"Line Tool size -", FL_SHIFT + 'l', (Fl_Callback *) dummy_CB, this},
    {"Move Object to current layer", 'm', (Fl_Callback *) dummy_CB, this},
    {"Mark Crosshair", FL_COMMAND + 'm', (Fl_Callback *) dummy_CB, this},
    {"Select shortest rat", FL_SHIFT + 'n', (Fl_Callback *) dummy_CB, this},
    {"Add Rats to selected pins", FL_SHIFT + 'o', (Fl_Callback *) dummy_CB, this},
    {"Change Octagon Object", FL_COMMAND + 'o', (Fl_Callback *) dummy_CB, this},
    {"Polygon Previous Point", 'p', (Fl_Callback *) dummy_CB, this},
    {"Polygon Close", FL_SHIFT + 'p', (Fl_Callback *) dummy_CB, this},
    {"Change Square Object", 'q', (Fl_Callback *) dummy_CB, this},
    {"Change Size +", 's', (Fl_Callback *) dummy_CB, this},
    {"Change Size -", FL_SHIFT + 's', (Fl_Callback *) dummy_CB, this},
    {"Change Drill +5 mil", FL_COMMAND + 'd', (Fl_Callback *) dummy_CB, this},
    {"Change Drill -5 mil", FL_COMMAND + FL_SHIFT + 'd', (Fl_Callback *) dummy_CB, this},
    {"Text Tool scale +10 mil", 't', (Fl_Callback *) dummy_CB, this},
    {"Text Tool scale -10 mil", FL_SHIFT + 't', (Fl_Callback *) dummy_CB, this},
    {"Via Tool size +5 mil", FL_SHIFT + 'v', (Fl_Callback *) dummy_CB, this},
    {"Via Tool size -5 mil", FL_COMMAND + FL_SHIFT + 'v', (Fl_Callback *) dummy_CB, this},
    {"Via Tool drill +5 mil", FL_COMMAND + 'l', (Fl_Callback *) dummy_CB, this},
    {"Via Tool drill -5 mil", FL_COMMAND + FL_SHIFT + 'l', (Fl_Callback *) dummy_CB, this},
    {"Add Selected Rats", FL_SHIFT + 'w', (Fl_Callback *) dummy_CB, this},
    {"Add All Rats", 'w', (Fl_Callback *) dummy_CB, this},
    {"Cycle Clip", '/', (Fl_Callback *) dummy_CB, this},
    {"Arrow Mode", ' ', (Fl_Callback *) dummy_CB, this},
    {"Temp Arrow ON", '[', (Fl_Callback *) dummy_CB, this},
    {"Temp Arrow OFF", ']', (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
    {"Step Up", FL_Up, (Fl_Callback *) dummy_CB, this},
    {"Step Down", FL_Down, (Fl_Callback *) dummy_CB, this},
    {"Step Left", FL_Left, (Fl_Callback *) dummy_CB, this},
    {"Step Right", FL_Right, (Fl_Callback *) dummy_CB, this},
    {"Step +Up", FL_SHIFT + FL_Up, (Fl_Callback *) dummy_CB, this},
    {"Step +Down", FL_SHIFT + FL_Down, (Fl_Callback *) dummy_CB, this},
    {"Step +Left", FL_SHIFT + FL_Left, (Fl_Callback *) dummy_CB, this},
    {"Step +Right", FL_SHIFT + FL_Right, (Fl_Callback *) dummy_CB, this},
    {"\"Click\"", FL_Enter, (Fl_Callback *) dummy_CB, this},
    {0},
  {0},

/*
 * Window menu items.
 */
{"Window", 0, nullptr, nullptr, FL_SUBMENU},
  {"Library", 'i', (Fl_Callback *) dummy_CB, this},
  {"Message Log", 0, (Fl_Callback *) dummy_CB, this},
  {"DRC Check", 0, (Fl_Callback *) dummy_CB, this},
  {"Netlist", 0, (Fl_Callback *) dummy_CB, this},
  {"Command Entry", ':', (Fl_Callback *) dummy_CB, this},
  {"Pinout", FL_SHIFT + 'd', (Fl_Callback *) dummy_CB, this, FL_MENU_DIVIDER},
  {"Help...", 0, (Fl_Callback *) help_CB, this},
  {"About...", 0, (Fl_Callback *) about_CB, this},
  {0},

/*
 * End of menu items.
 */
{0}

/* EOF */
