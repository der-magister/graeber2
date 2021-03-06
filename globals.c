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

#include "globals.h"

//playervariables
struct s_player_t o_player;

///actual dungeon time
volatile uint8_t v_i;
volatile uint8_t v_j;
volatile uint8_t v_a;
volatile uint8_t v_k;
volatile int8_t v_lvl;				///actual level
uint8_t v_lvlmodi [10];
uint8_t v_lvldat [10];

