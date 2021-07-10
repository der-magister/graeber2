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

#include "environment.h"
#include "engine.h"
#include <gb/bgb_emu.h>

#include <stdio.h>

void p_environment_changes (unsigned char l_tile) __banked
{
	o_engine.v_tile [0] = l_tile;

	if (o_player.direction == UP) {
		o_engine.v_leveldata [o_player.mk - 18] = l_tile;
		set_bkg_tiles (o_player.xk / 8 - 1, o_player.yk / 8 - 3, 1, 1, o_engine.v_tile);
	}
	else if (o_player.direction == DOWN) {
		o_engine.v_leveldata [o_player.mk + 18] = l_tile;
		set_bkg_tiles (o_player.xk / 8 - 1, o_player.yk / 8 - 1, 1, 1, o_engine.v_tile);	
	}
	else if (o_player.direction == LEFT) {
		o_engine.v_leveldata [o_player.mk - 1] = l_tile;
		set_bkg_tiles (o_player.xk / 8 - 2, o_player.yk / 8 - 2, 1, 1, o_engine.v_tile);	
	}
	else if (o_player.direction == RIGHT) {
		o_engine.v_leveldata [o_player.mk + 1] = l_tile;
		set_bkg_tiles (o_player.xk / 8, o_player.yk / 8 - 2, 1, 1, o_engine.v_tile);	
	}
}

void p_environment_get_ev (void) __banked
{
	if (o_player.direction == UP) o_engine.v_tile [1] = p_engine_get_tile (o_player.mk - 18);
	else if (o_player.direction == DOWN) o_engine.v_tile [1] = p_engine_get_tile (o_player.mk + 18);
	else if (o_player.direction == LEFT) o_engine.v_tile [1] = p_engine_get_tile (o_player.mk - 1);
	else if (o_player.direction == RIGHT) o_engine.v_tile [1] = p_engine_get_tile (o_player.mk + 1);

	if (o_engine.v_tile [1] == TILE_SAND)  p_environment_changes (TILE_PATH);
	else if (o_engine.v_tile [1] == TILE_STONE)  p_environment_changes (TILE_STONE_PHASE2);
	else if (o_engine.v_tile [1] == TILE_STONE_PHASE2)  p_environment_changes (TILE_PATH);
	else if (o_engine.v_tile [1] == TILE_BLACK_STONE)  p_environment_changes (TILE_BLACK_STONE_PHASE1);
	else if (o_engine.v_tile [1] == TILE_BLACK_STONE_PHASE1)  p_environment_changes (TILE_BLACK_STONE_PHASE2);
	else if (o_engine.v_tile [1] == TILE_BLACK_STONE_PHASE2)  p_environment_changes (TILE_PATH);
}
