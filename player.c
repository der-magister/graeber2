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

#include "player.h"
#include "values.h"
#include "engine.h"


///calculate the amor value
UINT8 p_player_calc_amor (void) __nonbanked
{
	static UINT8 l_value;

	l_value = c_amor_values [0];

	if (o_player.inventory.workwear == true) l_value = c_amor_values [1];
        else if (o_player.inventory.tabard == true) l_value = c_amor_values [2];
        else if (o_player.inventory.leather_amor == true) l_value = c_amor_values [3];

        if (o_player.inventory.helmet == true) l_value += c_amor_values [4];
        else if (o_player.inventory.helmet_with_kandle == true) l_value += c_amor_values [4];

        return (l_value);
}

///init basic stats
void p_player_init_basic_stats (void) __nonbanked
{	
	o_player.lifepoints = 3;
	o_player.max_lifepoints = 3;
	o_player.amorvalue = c_amor_values [0];
}	

///init inventory
void p_player_init_inventory (void) __nonbanked
{
	o_player.inventory.food = 1;
	o_player.inventory.max_food = 6;
	o_player.inventory.gold = 0;
	o_player.inventory.max_gold = 25;
	o_player.inventory.crystals = 0;
	o_player.inventory.max_crystals = 255;
	o_player.inventory.beer = 0;
	o_player.inventory.max_beer = 2;
	
	o_player.inventory.pickaxe = false;
	o_player.inventory.steel_pickaxe = false;
	o_player.inventory.workwear = false;
	o_player.inventory.tabard = false;
	o_player.inventory.leather_amor = false;
	o_player.inventory.helmet = false;
	o_player.inventory.helmet_with_kandle = false;
	o_player.inventory.glove = false;

	o_player.inventory.barrel = false;
	o_player.inventory.bread_can = false;
	o_player.inventory.oil_canister = false;

	o_player.inventory.bombs = 0;
	o_player.inventory.max_bombs = 3;
	o_player.inventory.oil = 0;
	o_player.inventory.max_oil = 5;
}

///init other player values
void p_player_init_others (void) __nonbanked
{
	o_player.xk = 0;
	o_player.yk = 0;
	o_player.mk = p_engine_calcMap (o_player.xk, o_player.yk);
}

///set player sprite
void p_player_set_sprite_nr (uint8_t l_nr) __nonbanked
{
	set_sprite_tile (PLAYER_SPRITE_ID, l_nr);
}

///set player sprite to x and y on the screen
void p_player_set_sprite_xy (uint8_t l_xk, uint8_t l_yk) __nonbanked
{
	o_player.xk = l_xk;
	o_player.yk = l_yk;
	o_player.mk = p_engine_calcMap (l_xk, l_yk);
	move_sprite (PLAYER_SPRITE_ID, l_xk, l_yk);
} 

///player main init
void p_player_init (void) __nonbanked
{
	p_player_init_basic_stats ();
	p_player_init_inventory ();
	p_player_init_others ();
	p_player_set_sprite_nr (0);
	p_player_set_sprite_xy (40, 112);
}

void p_player_move_up (void) __nonbanked
{
	o_player.yk -= 8; o_player.direction = UP;
	p_player_set_sprite_xy (o_player.xk, o_player.yk);
}

void p_player_move_down (void) __nonbanked
{
	o_player.yk += 8; o_player.direction = DOWN;
	p_player_set_sprite_xy (o_player.xk, o_player.yk);	
}

void p_player_move_left (void)  __nonbanked
{
	o_player.xk -= 8; o_player.direction = LEFT;
	p_player_set_sprite_xy (o_player.xk, o_player.yk);
}

void p_player_move_right (void)  __nonbanked
{
	o_player.xk += 8; o_player.direction = RIGHT;
	p_player_set_sprite_xy (o_player.xk, o_player.yk);
}

