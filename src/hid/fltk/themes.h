/*!
 * \file src/hid/fltk/themes.h
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


#ifndef PCB_SRC_HID_FLTK_THEMES_H
#define PCB_SRC_HID_FLTK_THEMES_H


#include "FLTK_headers.h"
#include "utils.h"


#define OS_FONT FL_FREE_FONT


#ifdef _WIN32
#define OS_FONT_SIZE 12
#else
#define OS_FONT_SIZE 13
#endif /* _WIN32 */


#define OS_BUTTON_UP_BOX              FL_GTK_UP_BOX
#define OS_CHECK_DOWN_BOX             FL_GTK_DOWN_BOX
#define OS_BUTTON_UP_FRAME            FL_GTK_UP_FRAME
#define OS_CHECK_DOWN_FRAME           FL_GTK_DOWN_FRAME
#define OS_PANEL_THIN_UP_BOX          FL_GTK_THIN_UP_BOX
#define OS_SPACER_THIN_DOWN_BOX       FL_GTK_THIN_DOWN_BOX
#define OS_PANEL_THIN_UP_FRAME        FL_GTK_THIN_UP_FRAME
#define OS_SPACER_THIN_DOWN_FRAME     FL_GTK_THIN_DOWN_FRAME
#define OS_RADIO_ROUND_DOWN_BOX       FL_GTK_ROUND_DOWN_BOX
#define OS_HOVERED_UP_BOX             FL_PLASTIC_UP_BOX
#define OS_DEPRESSED_DOWN_BOX         FL_PLASTIC_DOWN_BOX
#define OS_HOVERED_UP_FRAME           FL_PLASTIC_UP_FRAME
#define OS_DEPRESSED_DOWN_FRAME       FL_PLASTIC_DOWN_FRAME
#define OS_INPUT_THIN_DOWN_BOX        FL_PLASTIC_THIN_DOWN_BOX
#define OS_INPUT_THIN_DOWN_FRAME      FL_PLASTIC_ROUND_DOWN_BOX
#define OS_MINI_BUTTON_UP_BOX         FL_GLEAM_UP_BOX
#define OS_MINI_DEPRESSED_DOWN_BOX    FL_GLEAM_DOWN_BOX
#define OS_MINI_BUTTON_UP_FRAME       FL_GLEAM_UP_FRAME
#define OS_MINI_DEPRESSED_DOWN_FRAME  FL_GLEAM_DOWN_FRAME
#define OS_DEFAULT_BUTTON_UP_BOX      FL_DIAMOND_UP_BOX
#define OS_DEFAULT_HOVERED_UP_BOX     FL_PLASTIC_THIN_UP_BOX
#define OS_DEFAULT_DEPRESSED_DOWN_BOX FL_DIAMOND_DOWN_BOX
#define OS_TOOLBAR_BUTTON_HOVER_BOX   FL_GLEAM_ROUND_UP_BOX
#define OS_TABS_BOX                   FL_EMBOSSED_BOX
#define OS_SWATCH_BOX                 FL_ENGRAVED_BOX
#define OS_SWATCH_FRAME               FL_ENGRAVED_FRAME
#define OS_BG_BOX                     FL_FREE_BOXTYPE
#define OS_BG_DOWN_BOX                (Fl_Boxtype)(FL_FREE_BOXTYPE+1)
#define OS_TOOLBAR_FRAME              (Fl_Boxtype)(FL_FREE_BOXTYPE+2)
#define OS_TAB_COLOR FL_FREE_COLOR


class OS
{
  public:
    enum class Theme {CLASSIC, AERO, METRO, AQUA, GREYBIRD, OCEAN, BLUE, OLIVE, ROSE_GOLD, DARK, BRUSHED_METAL, HIGH_CONTRAST};

  private:
    static Theme _current_theme;
    static bool _is_consolas;

  public:
#ifdef _WIN32
    static bool is_classic_windows (void);
    static bool is_modern_windows (void);
#endif /* _WIN32 */

    inline static Theme current_theme (void)
    {
      return _current_theme;
    }

    inline static constexpr bool is_dark_theme (Theme t)
    {
      return t == Theme::DARK || t == Theme::HIGH_CONTRAST;
    }

    inline static bool is_consolas (void)
    {
      return _is_consolas;
    }

    static void use_native_fonts (void);
    static void use_native_settings (void);
    static void use_classic_theme (void);
    static void use_aero_theme (void);
    static void use_metro_theme (void);
    static void use_aqua_theme (void);
    static void use_greybird_theme (void);
    static void use_ocean_theme (void);
    static void use_blue_theme (void);
    static void use_olive_theme (void);
    static void use_rose_gold_theme (void);
    static void use_dark_theme (void);
    static void use_brushed_metal_theme (void);
    static void use_high_contrast_theme (void);
};

#endif /* PCB_SRC_HID_FLTK_THEMES_H */


/* EOF */
