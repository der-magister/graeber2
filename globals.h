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

#ifndef _GLOBALS_H_
#define _GLOBALS_H_


#include "/opt/gbdk/include/gb/gb.h"
#include "defines.h"

#define PLAYER_SPRITE_ID 0
#define PLAYER_WEAPON_SPRITE_ID 1
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


///inventory struct
struct s_inventory {
	uint8_t food;			///actual food
	uint8_t max_food;               ///maximal food
	uint8_t gold;                  	///actual gold pieces
	uint8_t max_gold;               ///maximal gold
	uint8_t crystals;		///actual crystals
	uint8_t max_crystals;           ///maximal crystals  
	uint8_t beer;                   ///actual beer
	uint8_t max_beer;               ///maximal beer
	bool v_keys;                  	///player have a key?

	bool pickaxe;                   ///have player the pickaxe - true = yes, false = no
	bool steel_pickaxe;          	///have player the steel pickaxe - true = yes, false = no
	bool workwear;               	///have player the workwear - true = yes, false = no
	bool tabard;                 	///have player the tabard - true = yes, false = no

	bool barrel;                 	///have player the barrel - true = yes, false = no
	bool bomb_bag;			///have player the bomb bag - true = yes, false = no
	
	uint8_t bombs;                  ///actual bombs
	uint8_t max_bombs;              ///maximal bombs

	uint8_t whetstone;              ///actual whetstone
	uint8_t max_whetstone;          ///maximal whetstone
};

///player struct
struct s_player_t {
	int8_t lifepoints;		///actual lifepoints    
	int8_t max_lifepoints;		///maximal lifepoints
	uint8_t amorvalue;		///value of the amor
	struct s_inventory inventory;   ///values of the inventory
	uint8_t xk;                     ///XK-coordinate on the screen
	uint8_t yk;                     ///YK-coordinate on the screen
	uint8_t mk;			///map-coordinates
	uint8_t direction;		///movement direction 
	bool walk;			///can player move? collision
	uint8_t v_attacktimer;		///timer for showing the pickaxe on the screen
	bool v_attack;
	uint8_t v_hitcounter;           ///counter for hits with the pickaxe
	uint8_t v_steps;                ///counter for player steps
	uint8_t v_active_item;          ///selected item
	bool v_move;                    ///player actual moves?
};

extern struct s_player_t o_player;	///player "object"

extern volatile uint8_t v_i;
extern volatile uint8_t v_j;
extern volatile uint8_t v_a;
extern volatile uint8_t v_k;
extern volatile int8_t v_lvl;
extern uint8_t v_lvlmodi [10];
extern uint8_t v_lvldat [10];

#endif
