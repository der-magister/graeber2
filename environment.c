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
#include "text.h"
#include "player.h"

#include "data/text/chest/chesttxt.h"

const uint8_t c_switches_values [2][2] = {
						
						
						{8, 0}


};

///changes after an event
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

///
void p_environment_use_switch (void) __banked
{

	p_environment_changes (TILE_SWITCH_ON);
	//o_engine.v_tile [0] = TILE_DOOR_OPEN;
	//set_bkg_tiles (c_switches_values [v_lvl][0] + 1, c_switches_values [v_lvl][1] + 1 , 1, 1, o_engine.v_tile);
	if (v_lvl == 8) {
		p_engine_set_tile (c_switches_values [0][0], c_switches_values [0][1], TILE_DOOR_OPEN);
	}
}

void p_environment_use_chest (void) __banked
{
	p_environment_changes (TILE_OPEN_CHEST);

	if (v_lvl == 1) {
		o_player.inventory.pickaxe = true;
		p_player_set_weapon_sprite ();
		p_set_txt (1, 1, pickaxetxt);
	}
}

///trigger an event 
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
	else if (o_engine.v_tile [1] == TILE_SWITCH_OFF)  p_environment_use_switch ();
	else if (o_engine.v_tile [1] == TILE_CHEST) p_environment_use_chest ();
}

///clear screen from collected item
void p_environment_clean_item (void) __banked
{
	o_engine.v_tile [0] = TILE_PATH;
	o_engine.v_leveldata [o_player.mk] = TILE_PATH;
	set_bkg_tiles (o_player.xk / 8 - 1, o_player.yk / 8 - 2, 1, 1, o_engine.v_tile);
}

///collect gold 
void p_environment_collect_gold (void) __banked
{
	if (o_player.inventory.gold != 255) {
		o_player.inventory.gold += 1;
		p_environment_clean_item ();
	}
}

///collect crystal
void p_environment_collect_crystal (void) __banked
{
	if (o_player.inventory.crystals != 255) {
		o_player.inventory.crystals += 1;
		p_environment_clean_item ();
	}
}


///collect beer and increase lifepoints + 3
void p_environment_collect_beer (void) __banked
{
	if (o_player.lifepoints != o_player.max_lifepoints - 3) {
		o_player.lifepoints += 3;
	}
	else {
		o_player.lifepoints = o_player.max_lifepoints;
	}
	p_environment_clean_item ();
}

///collect key
void p_environment_collect_key (void) __banked
{
	if (o_player.inventory.v_keys != o_player.inventory.v_max_keys) {
		o_player.inventory.v_keys += 1;
		p_environment_clean_item ();
	}	
}

///collect big clock and increase dungeontime + 50
void p_environment_collect_big_clock (void) __banked
{
	p_environment_clean_item ();
}

///collect tiny clock and increase dungeontime + 25
void p_environment_collect_tiny_clock (void) __banked
{
	if (o_engine.v_dungeontimer <= o_engine.v_dungeontimer - 25) {
		p_environment_clean_item ();
		o_engine.v_dungeontimer += 25;
	}
}

///collect items
void p_environment_collect_item (void) __banked
{
	o_engine.v_tile  [1] = p_engine_get_tile (o_player.mk);

	if (o_engine.v_tile [1] == TILE_GOLD) p_environment_collect_gold ();
	else if (o_engine.v_tile [1] == TILE_CRYSTAL) p_environment_collect_crystal ();
	else if (o_engine.v_tile [1] == TILE_BEER) p_environment_collect_beer ();
	else if (o_engine.v_tile [1] == TILE_KEY) p_environment_collect_key ();
	else if (o_engine.v_tile [1] == TILE_BIG_CLOCK) p_environment_collect_big_clock ();
	else if (o_engine.v_tile [1] == TILE_TINY_CLOCK) p_environment_collect_tiny_clock ();
}

void  p_environment_shield (uint8_t l_mk, unsigned char l_txt[]) __banked
{
	if (l_mk == o_player.mk) {
		p_set_txt (1, 1, l_txt);
	}
}

