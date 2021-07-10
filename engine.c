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

#include "engine.h"
#include <stdio.h>

#include "data/tilesets/font-81-127.h"
#include "data/tilesets/maintiles_81-0.h"
#include "data/spritesets/spriteset.h"

struct s_engine o_engine;

///load the game tileset
void p_engine_loadTileset (void) __nonbanked
{
	SWITCH_ROM_MBC5 (BANK_2);
	set_bkg_data (81, 127, font);
	set_bkg_data (0, 80, maintiles);
        SWITCH_ROM_MBC5 (BANK_0);
}

///load the game sprite set
void p_engine_loadSpriteset (void) __nonbanked
{
	SWITCH_ROM_MBC5 (BANK_2);
	set_sprite_data (0, 127, sprites);
	SWITCH_ROM_MBC5 (BANK_0);
}

void p_engine_load_map (unsigned char l_lvldat [252], uint8_t l_databank, uint8_t l_curbank) __nonbanked
{
	DISPLAY_OFF;
	SWITCH_ROM_MBC5 (l_databank);

	for (v_i = 0; v_i != 253; ++v_i) o_engine.v_leveldata [v_i] = l_lvldat [v_i];

	SWITCH_ROM_MBC5 (l_curbank);
	DISPLAY_ON;
}

///calculate the cell on the screen
uint8_t p_engine_calc_map (uint8_t l_xk, uint8_t l_yk) __nonbanked
{
        return ((l_xk - 16) / 8) + 18 * ((l_yk - 24) / 8);
}

void p_engine_init (void) __nonbanked
{
	o_engine.v_movetimer = 0; o_engine.v_attacktimer = 0;
}

unsigned char p_engine_get_tile (uint8_t l_mk) __nonbanked
{
	//printf ("wert: %u", o_engine.v_leveldata [l_mk]);

	return (o_engine.v_leveldata [l_mk]);
}

void p_engine_set_tile (UINT8 l_xk, UINT8 l_yk, unsigned char l_tile) __nonbanked
{
	o_engine.v_tile [0] = l_tile;
        set_bkg_tiles (l_xk + 1, l_yk + 1, 1, 1, o_engine.v_tile);
        o_engine.v_leveldata [l_xk + 18 * l_yk] = o_engine.v_tile [0];
}
