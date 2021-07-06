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

#define BANK_0 0
#define BANK_2 2
#define false FALSE
#define true TRUE

struct s_inventory {
	UINT8 food;			///actual food
	UINT8 max_food;                 ///maximal food
	UINT8 gold;                   	///actual gold pieces
	UINT8 max_gold;                 ///maximal gold
	UINT8 crystals;			///actual crystals
	UINT8 max_crystals;             ///maximal crystals  
	UINT8 beer;                     ///actual beer
	UINT8 max_beer;                 ///maximal beer

	BOOLEAN pickaxe;                ///have player the pickaxe - true = yes, false = no
	BOOLEAN steel_pickaxe;          ///have player the steel pickaxe - true = yes, false = no
	BOOLEAN workwear;               ///have player the workwear - true = yes, false = no
	BOOLEAN tabard;                 ///have player the tabard - true = yes, false = no
	BOOLEAN leather_amor;           ///have player the leather_amor - true = yes, false = no
	BOOLEAN helmet;                 ///have player the helmet - true = yes, false = no
	BOOLEAN helmet_with_kandle; 	///have player the helmet with kandle - true = yes, false = no
	BOOLEAN glove;                  ///have player the glove - true = yes, false = no

	BOOLEAN barrel;                 ///have player the barrel - true = yes, false = no
	BOOLEAN bread_can;		///have player the bread can - true = yes, false = no
	BOOLEAN oil_canister;           ///have player the oil canister - true = yes, false = no 

	UINT8 bombs;                     ///actual bombs
	UINT8 max_bombs;                ///maximal bombs

	UINT8 oil;                      ///actual oil
	UINT8 max_oil;                  ///maximal oil  
};

struct s_player {
	INT8 lifepoints;		///actual lifepoints    
	UINT8 max_lifepoints;		///maximal lifepoints
	UINT8 amorvalue;		///Value of the amor
	struct s_inventory inventory;   ///values of the inventory
	UINT8 xk;                       ///XK-coordinate on the screen
	UINT8 yk;                       ///YK-coordinate on the screen
	UINT8 mk;			///Map-coordinate
};

extern struct s_player o_player;

#endif