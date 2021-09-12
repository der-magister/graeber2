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

#include "enemy.h"

#include "engine.h"
#include "values.h"
#include "player.h"
#include "hud.h"

struct s_enemy_t o_enemy [3];

uint8_t v_enemy_timer;

void p_enemy_init (void) __nonbanked
{
	v_enemy_timer = 255;

	for (v_i = 0; v_i != 3; ++v_i) o_enemy[v_i].v_direction = 255;
}

void p_enemy_set (uint8_t l_nr, uint8_t l_xk, uint8_t l_yk, uint8_t l_lp, uint8_t l_dmg, uint8_t l_direction, uint8_t l_sprite) __nonbanked
{
	o_enemy[l_nr].v_xk = l_xk;
	o_enemy[l_nr].v_yk = l_yk;
	o_enemy[l_nr].v_lifepoints = l_lp;
	o_enemy[l_nr].v_damage = l_dmg;
	o_enemy[l_nr].v_direction = l_direction;

	o_enemy[l_nr].v_walk = true; v_enemy_timer = 0;

	if (l_nr == 0) {
		set_sprite_tile (ENEMY_SPRITE_ID1, l_sprite);
		move_sprite (ENEMY_SPRITE_ID1, o_enemy[l_nr].v_xk, o_enemy[l_nr].v_yk);
	}
	else if (l_nr == 1) {
		set_sprite_tile (ENEMY_SPRITE_ID2, l_sprite);
		move_sprite (ENEMY_SPRITE_ID2, o_enemy[l_nr].v_xk, o_enemy[l_nr].v_yk);
	}
	else if (l_nr == 2) {
		set_sprite_tile (ENEMY_SPRITE_ID3, l_sprite);
		move_sprite (ENEMY_SPRITE_ID3, o_enemy[l_nr].v_xk, o_enemy[l_nr].v_yk);
	}

	o_enemy[l_nr].v_mk =  p_engine_calc_map (o_enemy[l_nr].v_xk, o_enemy[l_nr].v_yk);
}

bool p_enemy_collision_check (uint8_t l_nr) __nonbanked
{
	if (o_enemy[l_nr].v_direction == UP) {
		o_engine.v_tile [1] = p_engine_get_tile (o_enemy[l_nr].v_mk - 18);
	}
	else if (o_enemy[l_nr].v_direction == DOWN) {
		o_engine.v_tile [1] = p_engine_get_tile (o_enemy[l_nr].v_mk + 18);	
	}
	else if (o_enemy[l_nr].v_direction == LEFT) {
		o_engine.v_tile [1] = p_engine_get_tile (o_enemy[l_nr].v_mk - 1);	
	}
	else if (o_enemy[l_nr].v_direction == RIGHT) {
		o_engine.v_tile [1] = p_engine_get_tile (o_enemy[l_nr].v_mk + 1);	
	}


	for (v_a = 0; v_a != sizeof (c_collision_values_enemy) + 1; ++v_a) {
		SWITCH_ROM_MBC5 (BANK_4);

			if (c_collision_values_enemy [v_a] == o_engine.v_tile [1]) return false;

		SWITCH_ROM_MBC5 (BANK_0);
	}	
	return true;
}


///horizotal movement of the enemies
void p_enemy_move_horizontal (void) __nonbanked
{
	for (v_j = 0; v_j != 3; ++v_j) {
		o_enemy[v_j].v_walk = p_enemy_collision_check (v_j);

		if (o_enemy[v_j].v_walk == true) {

			if (o_enemy[v_j].v_direction == RIGHT) {
				o_enemy[v_j].v_xk +=8;
			}
			else if (o_enemy[v_j].v_direction == LEFT) {
				o_enemy[v_j].v_xk -=8;
			}
			if (o_enemy[v_j].v_direction != 255) {
				move_sprite (ENEMY_SPRITE_ID1 + v_j, o_enemy[v_j].v_xk, o_enemy[v_j].v_yk);
				o_enemy[v_j].v_mk =  p_engine_calc_map (o_enemy[v_j].v_xk, o_enemy[v_j].v_yk);
			}
		}
		else {
			if (o_enemy[v_j].v_direction == LEFT) o_enemy[v_j].v_direction = RIGHT;
			else if (o_enemy[v_j].v_direction == RIGHT) o_enemy[v_j].v_direction = LEFT;

		}
 	}
}

///vertical movement of the enemies
void p_enemy_move_vertical (void) __nonbanked
{
	for (v_j = 0; v_j != 3; ++v_j) {
		o_enemy[v_j].v_walk = p_enemy_collision_check (v_j);

		if (o_enemy[v_j].v_walk == true) {

			if (o_enemy[v_j].v_direction == DOWN) {
				o_enemy[v_j].v_yk +=8;
			}
			else if (o_enemy[v_j].v_direction == UP) {
				o_enemy[v_j].v_yk -=8;
			}
			if (o_enemy[v_j].v_direction != 255) {
				move_sprite (ENEMY_SPRITE_ID1 + v_j, o_enemy[v_j].v_xk, o_enemy[v_j].v_yk);
				o_enemy[v_j].v_mk =  p_engine_calc_map (o_enemy[v_j].v_xk, o_enemy[v_j].v_yk);
			}
		}
		else {
			if (o_enemy[v_j].v_direction == DOWN) o_enemy[v_j].v_direction = UP;
			else if (o_enemy[v_j].v_direction == UP) o_enemy[v_j].v_direction = DOWN;

		}
 	}
}

void p_enemy_player_collision (void) __nonbanked
{
	for (v_k = 0; v_k != 3; ++v_k) {
		if (o_player.mk == o_enemy[v_k].v_mk) {
			o_player.lifepoints -= o_enemy[v_k].v_damage;


			if (o_enemy[v_k].v_direction == UP) o_enemy[v_k].v_direction = DOWN;
			else if (o_enemy[v_k].v_direction == DOWN) o_enemy[v_k].v_direction = UP;
			else if (o_enemy[v_k].v_direction == LEFT) o_enemy[v_k].v_direction = RIGHT;
			else if (o_enemy[v_k].v_direction == RIGHT) o_enemy[v_k].v_direction = LEFT;

			p_player_set_sprite_nr (1);
			delay (300);
			p_player_set_sprite_nr (0);
			p_hud_show_lifepoints ();
		}
	}
}

void p_enemy_disabled (void) __nonbanked
{
	for (v_j = 0; v_j != 3; ++v_j) {
		o_enemy[v_j].v_direction = 255;
		move_sprite (ENEMY_SPRITE_ID1 + v_j, 0, 0);
	}
	v_enemy_timer = 255;
}