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


///calculate the amor value
UINT8 p_player_calc_amor (void) NONBANKED
{
	UINT8 l_value;

	l_value = c_amor_values [0];

	if (o_player.inventory.workwear == true) l_value = c_amor_values [1];
        else if (o_player.inventory.tabard == true) l_value = c_amor_values [2];
        else if (o_player.inventory.leather_amor == true) l_value = c_amor_values [3];

        if (o_player.inventory.helmet == true) l_value += c_amor_values [4];
        else if (o_player.inventory.helmet_with_kandle == true) l_value += c_amor_values [4];

        return (l_value);
}

///init basic stats
void p_player_init_basic_stats (void) NONBANKED
{	
	o_player.lifepoints = 3;
	o_player.max_lifepoints = 3;
	o_player.amorvalue = c_amor_values [0];
}	

///init inventory
void p_player_init_inventory (void) NONBANKED
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

void p_player_init (void) NONBANKED
{
	p_player_init_basic_stats ();
	p_player_init_inventory ();
}