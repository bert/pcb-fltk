/*!
 * \file src/hid/fltk/main.cpp
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
 * Copyright (C) 1994, 1995, 1996, 2004 Thomas Nau
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


#include <iostream>


#pragma warning (push, 0)


#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>


#pragma warning (pop)


#include "event_handlers.h"
#include "version.h"
#include "preferences.h"
#include "themes.h"
#include "main_window.h"


#ifdef _WIN32
#include <shlobj.h>
#include <tchar.h>
#define MAKE_WSTR_HELPER(x) L ## x
#define MAKE_WSTR(x) MAKE_WSTR_HELPER(x)
#endif /* _WIN32 */


#define VERSION "0.0.1"


static void copyright (void);
static void usage (void);
static void use_theme (OS::Theme theme);

char *Progname;


int
main (int argc, char **argv)
{
  Progname = argv[0];

  Preferences::initialize (argv[0]);
  std::ios::sync_with_stdio (false);

#ifdef _WIN32
  SetCurrentProcessExplicitAppUserModelID (MAKE_WSTR (PROGRAM_AUTHOR) L"." MAKE_WSTR (PROGRAM_NAME));
#endif /* _WIN32 */

  Fl::visual(FL_DOUBLE | FL_RGB);

#ifdef _WIN32
  OS::Theme default_theme = OS::Theme::BLUE;
  DWORD reg_value = 1, reg_size = sizeof(reg_value);

  if (!RegGetValue (HKEY_CURRENT_USER,
                   _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"),
                   _T("AppsUseLightTheme"),
                   RRF_RT_REG_DWORD,
                   NULL,
                   &reg_value,
                   &reg_size)
    && reg_value == 0)
  {
    default_theme = OS::Theme::DARK;
  }

  OS::Theme theme = (OS::Theme) Preferences::get ("theme", (int) default_theme);
#else
  OS::Theme theme = (OS::Theme) Preferences::get ("theme", (int) OS::Theme::GREYBIRD);
#endif /* _WIN32 */

  use_theme (theme);

#ifdef _WIN32
  int x = Preferences::get ("x", 48), y = Preferences::get ("y", 48 + GetSystemMetrics (SM_CYCAPTION));
#else
  int x = Preferences::get ("x", 48), y = Preferences::get ("y", 48);
#endif /* _WIN32 */

  int w = Preferences::get("w", 647), h = Preferences::get ("h", 406);

  Main_Window window (x, y, w, h);
  window.show ();
//  Fl::add_handler (escape_handler);

  if (window.transparent ())
  {
    window.apply_transparency ();
  }

  if (window.full_screen ())
  {
    window.fullscreen ();
  }
  else if (Preferences::get ("maximized"))
  {
    window.maximize ();
  }

  if (argc > 2)
  {
//    window.open_pcb_file (argv[1]);
//    window.load_netlist (argv[2]);
  }
  else if (argc < 1)
  {
    usage ();
  }

  return Fl::run ();
}


/*!
 * \brief Print the copyright notice.
 */
static void
copyright (void)
{
  printf ("\n"
          "            COPYRIGHT for %s version %s\n\n"
          "PCB, interactive printed circuit board design\n"
          "Copyright (C) 1994,1995,1996,1997 Thomas Nau\n"
          "Copyright (C) 1998, 1999, 2000 Harry Eaton\n\n"
          "This program is free software; you can redistribute it and/or modify\n"
          "it under the terms of the GNU General Public License as published by\n"
          "the Free Software Foundation; either version 2 of the License, or\n"
          "(at your option) any later version.\n\n"
          "This program is distributed in the hope that it will be useful,\n"
          "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
          "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
          "GNU General Public License for more details.\n\n"
          "You should have received a copy of the GNU General Public License along\n"
          "with this program; if not, write to the Free Software Foundation, Inc.,\n"
          "51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.\n\n",
          Progname, VERSION);

  exit (0);
}


static void
usage ()
{
}


static void
use_theme (OS::Theme theme)
{
  OS::use_native_fonts ();

  switch (theme)
  {
    case OS::Theme::CLASSIC:
      OS::use_classic_theme ();
      return;

    case OS::Theme::AERO:
      OS::use_aero_theme ();
      return;

    case OS::Theme::METRO:
      OS::use_metro_theme ();
      return;

    case OS::Theme::AQUA:
      OS::use_aqua_theme ();
      return;

    case OS::Theme::GREYBIRD:
      OS::use_greybird_theme ();
      return;

    case OS::Theme::OCEAN:
      OS::use_ocean_theme ();
      return;

    case OS::Theme::BLUE:
      OS::use_blue_theme ();
      return;

    case OS::Theme::OLIVE:
      OS::use_olive_theme ();
      return;

    case OS::Theme::ROSE_GOLD:
      OS::use_rose_gold_theme ();
      return;

    case OS::Theme::DARK:
      OS::use_dark_theme ();
      return;

    case OS::Theme::BRUSHED_METAL:
      OS::use_brushed_metal_theme ();
      return;

    case OS::Theme::HIGH_CONTRAST:
      OS::use_high_contrast_theme ();
  }
}


/* EOF */
