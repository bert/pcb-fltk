/*!
 * \file src/hid/fltk/utils.h
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


#ifndef PCB_SRC_HID_FLTK_UTILS_H
#define PCB_SRC_HID_FLTK_UTILS_H


/* Standard headers */
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdint.h>
#include <limits>
#include <cmath>
#include <string>
#include <string_view>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sys/stat.h>


/* Fltk headers */
#include "FLTK_headers.h"


#ifdef _WIN32
#define DIR_SEP "\\"
#else
#define DIR_SEP "/"
#endif /* _WIN32 */


#define STRINGIFY(x) _STRINGIFY_HELPER(x)
#define _STRINGIFY_HELPER(x) #x


#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(a[0]))
#endif /* _countof */


#define RANGE(x) std::begin(x), std::end(x)
#define HI_NYB(n) (uchar)(((n) & 0xF0) >> 4)
#define LO_NYB(n) (uchar)((n) & 0x0F)
#define LE16(n) (uchar)((n) & 0xFFUL), (uchar)(((n) & 0xFF00UL) >> 8)
#define LE32(n) (uchar)((n) & 0xFFUL), (uchar)(((n) & 0xFF00UL) >> 8), (uchar)(((n) & 0xFF0000UL) >> 16), (uchar)(((n) & 0xFF000000UL) >> 24)
#define BE16(n) (uchar)(((n) & 0xFF00UL) >> 8), (uchar)((n) & 0xFFUL)
#define BE32(n) (uchar)(((n) & 0xFF000000UL) >> 24), (uchar)(((n) & 0xFF0000UL) >> 16), (uchar)(((n) & 0xFF00UL) >> 8), (uchar)((n) & 0xFFUL)


typedef uint8_t size8_t;
typedef uint16_t size16_t;
typedef uint32_t size32_t;
typedef uint64_t size64_t;


bool starts_with_ignore_case (std::string_view s, std::string_view p);
bool ends_with_ignore_case (std::string_view s, std::string_view p);
void add_dot_ext (const char *f, const char *ext, char *s);
int text_width (const char *l, int pad = 0);
bool file_exists (const char *f);
size_t file_size (const char *f);
size_t file_size (FILE *f);
void open_ifstream (std::ifstream &ifs, const char *f);
bool check_read (FILE *file, uchar *expected, size_t n);
uint16_t read_uint16 (FILE *file);


#endif /* PCB_SRC_HID_FLTK_UTILS_H */


/* EOF */
