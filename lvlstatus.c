//   Graeber2 - an digger adventure game
//
//   Copyright (C) 2021 Heiko Wolf
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License As published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY Or FITNESS For A PARTICULAR PURPOSE.  See the
//   GNU General Public License For more details.
//
//   You should have received a copy of the GNU General Public License along
//   With this program; if not, write to the Free Software Foundation, Inc.,
//   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//   Contact: projekte@kabelmail.net

#include "lvlstatus.h"

#include "mine-entrance.h"
#include "first-course.h"


void p_lvl_select (void) __nonbanked
{
	if (v_lvl == -4) p_lvl0a ();
	else if (v_lvl == -3) p_lvl0b ();
	else if (v_lvl == -2) p_lvl0c ();
	else if (v_lvl == -1) p_lvl0d ();
	else if (v_lvl == 1) p_lvl001 ();
	else if (v_lvl == 2) p_lvl002 ();
	else if (v_lvl == 3) p_lvl003 ();
	else if (v_lvl == 4) p_lvl004 ();
	else if (v_lvl == 5) p_lvl005 ();
	else if (v_lvl == 6) p_lvl006 ();
	else if (v_lvl == 7) p_lvl007 ();
	else if (v_lvl == 8) p_lvl008 ();
}
