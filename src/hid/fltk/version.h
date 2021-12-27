/*!
 * \file src/hid/fltk/version.h
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


#ifndef PCB_SRC_HID_FLTK_VERSION_H
#define PCB_SRC_HID_FLTK_VERSION_H


#define PROGRAM_VERSION 0,0,1


#ifdef _DEBUG
#define PROGRAM_VERSION_STRING "0.0.1 [DEBUG]"
#else
#define PROGRAM_VERSION_STRING "0.0.1"
#endif /* _DEBUG */


#define PROGRAM_EXE_NAME "pcb_fltk"


#ifdef _WIN32
#define PROGRAM_EXE PROGRAM_EXE_NAME ".exe"
#else
#define PROGRAM_EXE PROGRAM_EXE_NAME
#endif /* _WIN32 */


#define PROGRAM_NAME "pcb_fltk"
#define PROGRAM_AUTHOR "PCB Contributors"
#define CURRENT_YEAR "2021"


#endif /* PCB_SRC_HID_FLTK_VERSION_H */


/* EOF */
