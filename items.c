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

#define TILE_BEER 75
#define TILE_WHETSTONE 39
#define TILE_BOMB 73

#define BEER 1
#define WHETSTONE 2
#define BOMB 3

#include "items.h"

#include "player.h"
#include "hud.h"
#include "engine.h"

struct s_tools_t o_pickaxe;
struct s_tools_t o_steel_pickaxe;

///init
void p_items_init (void) __nonbanked
{
	o_pickaxe.v_status = 5; o_pickaxe.v_max_status = 5;

	o_steel_pickaxe.v_status = 8; o_steel_pickaxe.v_max_status = 8;
}

///use food
void p_items_use_proviant (void) __nonbanked
{
	if (o_player.v_steps == 255) {
		o_player.v_steps = 0;

		if (o_player.inventory.food != 0) {
			--o_player.inventory.food;
			p_hud_show_food ();
		}
		else if (o_player.inventory.food == 0) {
			--o_player.lifepoints;
			p_hud_show_lifepoints ();
		}


	}
}

///
void p_items_use_tool (void) __nonbanked
{
	if (o_player.v_hitcounter == 80) {
		o_player.v_hitcounter = 0;

		if (o_pickaxe.v_status != 0) {
			--o_pickaxe.v_status;
			p_hud_show_tool_status ();
		}
	}
}

///use whetstone
void p_items_use_whetstone (void) __nonbanked
{
	if ((o_player.inventory.whetstone != 0) && (o_pickaxe.v_status != o_pickaxe.v_max_status)) {
		--o_player.inventory.whetstone;
		o_pickaxe.v_status = o_pickaxe.v_max_status;
		p_hud_show_tool_status ();
		if (o_player.inventory.whetstone == 0) p_engine_set_tile (8, 14, 40); 
	}
}

///use beer
void p_items_use_beer (void) __nonbanked
{
	if (o_player.lifepoints <= o_player.max_lifepoints - 3) {
		o_player.lifepoints += 3;
	}
	else {
		o_player.lifepoints = o_player.max_lifepoints;
	}
	p_hud_show_lifepoints ();
	--o_player.inventory.beer;
	if (o_player.inventory.beer == 0) p_engine_set_tile (8, 14, 41);
}

///use items
void p_items_use (void) __nonbanked
{
	if (o_player.v_active_item == WHETSTONE) p_items_use_whetstone ();
	else if (o_player.v_active_item == BEER) p_items_use_beer ();

}

///select an items
void p_items_select (void) __nonbanked
{
	if (o_player.v_active_item == 0) {
		p_engine_set_tile (8, 14, 41);
		if (o_player.inventory.beer != 0) p_engine_set_tile (8, 14, TILE_BEER);
		o_player.v_active_item = BEER;
	}
	else if (o_player.v_active_item == BEER) {
		p_engine_set_tile (8, 14, 40);
		if (o_player.inventory.whetstone != 0) p_engine_set_tile (8, 14, TILE_WHETSTONE);
		o_player.v_active_item = WHETSTONE;
	}
	else if (o_player.v_active_item == WHETSTONE) {
		p_engine_set_tile (8, 14, 42);
		if (o_player.inventory.bombs != 0) p_engine_set_tile (8, 14, TILE_BOMB);
		o_player.v_active_item = BOMB;
	}
	else if (o_player.v_active_item == BOMB) {
		p_engine_set_tile (8, 14, TILE_CLEAN);
		o_player.v_active_item = 0;	
	}
	delay (200);
}
