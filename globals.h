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

#ifndef _globals_h_
#define _globals_h_

#include "/opt/gbdk/include/asm/gbz80/types.h"
#include "/opt/gbdk/include/gb/gb.h"

///actual livepoints 
extern INT8 v_lifepoints;

///maximal livepoints
extern INT8 v_max_lifepoints;

///Value of the amor 
extern INT8 v_amorvalue;

///number of gold
extern INT8 v_gold;

///
extern BOOLEAN v_pickaxe;


///actual dungeon time
extern INT8 v_time;

#endif