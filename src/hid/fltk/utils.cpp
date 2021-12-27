/*!
 * \file src/hid/fltk/utils.cpp
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


#include "utils.h"


static bool
cmp_ignore_case (const char &a, const char &b)
{
  return tolower (a) == tolower (b);
}


bool
starts_with_ignore_case (std::string_view s, std::string_view p)
{
  if (s.size() < p.size())
  {
    return false;
  }

  std::string_view ss = s.substr (0, p.size());
  return std::equal (RANGE(ss), RANGE (p), cmp_ignore_case);
}


bool
ends_with_ignore_case (std::string_view s, std::string_view p)
{
  if (s.size () < p.size ())
  {
    return false;
  }

  std::string_view ss = s.substr (s.size () - p.size ());
  return std::equal (RANGE (ss), RANGE (p), cmp_ignore_case);
}


void
add_dot_ext (const char *f, const char *ext, char *s)
{
  strcpy (s, f);
  const char *e = fl_filename_ext (s);

  if (!e || !strlen(e))
  {
    strcat (s, ext);
  }
}


int
text_width (const char *l, int pad)
{
  int lw = 0;
  int lh = 0;

  fl_measure (l, lw, lh, 0);
  return lw + 2 * pad;
}


bool
file_exists (const char *f)
{
  return !fl_access (f, 4); // R_OK
}


size_t
file_size (const char *f)
{
  struct stat s;
  int r = fl_stat (f, &s);
  return r ? 0 : (size_t) s.st_size;
}


size_t
file_size (FILE *f)
{
#ifdef __CYGWIN__
#define stat64 stat
#define fstat64 fstat
#elif defined (_WIN32)
#define fileno _fileno
#define stat64 _stat32i64
#define fstat64 _fstat32i64
#endif /* __CYGWIN__ */

  struct stat64 s;
  int r = fstat64 (fileno (f), &s);
  return r ? 0 : (size_t) s.st_size;
}


void
open_ifstream (std::ifstream &ifs, const char *f)
{
#ifdef _WIN32
  wchar_t wf[FL_PATH_MAX] = {};
  fl_utf8towc (f, strlen (f), wf, sizeof (wf));
  ifs.open (wf);
#else
  ifs.open (f);
#endif
}


bool
check_read (FILE *file, uchar *expected, size_t n)
{
  std::vector<uchar> buffer(n);
  size_t r = fread (buffer.data (), 1, n, file);
  return r == n && (!expected || !memcmp (buffer.data (), expected, n));
}


uint16_t
read_uint16 (FILE *file)
{
  int lo = fgetc (file);
  int hi = fgetc (file);
  return (uint16_t) (((hi & 0xFF00) >> 8) | (lo & 0xFF));
}


/* EOF */
