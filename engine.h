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

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "globals.h"

struct s_engine_t
{
	unsigned char v_leveldata [252]; 	///actual level map data
	uint8_t v_movetimer;			///timer for player movements
	unsigned char v_tile [2];               ///tilenumber of an selected tile         
};

extern struct s_engine_t o_engine;		///"object" engine

void p_engine_loadTileset (void) __nonbanked;
void p_engine_loadSpriteset (void) __nonbanked;
void p_engine_load_map (unsigned char l_lvldat [252], uint8_t l_databank, uint8_t l_curbank) __nonbanked;

uint8_t p_engine_calc_map (uint8_t l_xk, uint8_t l_yk) __nonbanked;
void p_engine_init (void) __nonbanked;
unsigned char p_engine_get_tile (uint8_t l_mk) __nonbanked;
void p_engine_set_tile (uint8_t l_xk, uint8_t l_yk, unsigned char l_tile) __nonbanked;
void p_engine_change_lvl (int8_t l_lvl, uint8_t l_xk, uint8_t l_yk) __nonbanked;

#endif
