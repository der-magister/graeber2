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

#ifndef _ENEMY_H_
#define _ENEMY_H_

#define ENEMY_SPRITE_ID1 5
#define ENEMY_SPRITE_ID2 6
#define ENEMY_SPRITE_ID3 7

#include "globals.h"

struct s_enemy_t {
	uint8_t v_xk;
	uint8_t v_yk;
	uint8_t v_mk;
	uint8_t v_direction;
	uint8_t v_lifepoints;
	uint8_t v_damage;
	uint8_t v_sprite;
	bool v_walk;
};

extern uint8_t v_enemy_timer;

extern struct s_enemy_t o_enemy [3];

void p_enemy_init (void) __nonbanked;
void p_enemy_set (uint8_t l_nr, uint8_t l_xk, uint8_t l_yk, uint8_t l_lp, uint8_t l_dmg, uint8_t l_direction, uint8_t l_sprite) __nonbanked;
void p_enemy_move_horizontal (void) __nonbanked;
void p_enemy_move_vertical (void) __nonbanked;
void p_enemy_disabled (void) __nonbanked;
void p_enemy_player_collision (void) __nonbanked;

#endif
