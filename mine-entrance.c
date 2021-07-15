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

#include "mine-entrance.h"

#include "engine.h"

#include "data/level/lvldatmine-entrance.h"

///procedure for lvl0a
void p_lvl0a (void) __banked
{
	//lvl changes
	if (o_player.mk == 108) {
		p_engine_load_map (lvl0b, BANK_5, BANK_3);
		p_engine_change_lvl (-3, 152, o_player.yk);
	}
	else if (o_player.mk == 125) {
		p_engine_load_map (lvl0c, BANK_5, BANK_3);
		p_engine_change_lvl (-2, 16, o_player.yk);
	}
	else if (o_player.mk == 8) {
		p_engine_load_map (lvl0d, BANK_5, BANK_3);
		p_engine_change_lvl (-1, o_player.xk, 128);
	}

}

///procedure for lvl0b
void p_lvl0b (void) __banked
{       
	//level change
	if (o_player.mk == 125) {
		p_engine_load_map (lvl0a, BANK_5, BANK_3);
		p_engine_change_lvl (-4, 16, o_player.yk);
	}
}

///procedure for lvl0c
void p_lvl0c (void) __banked
{
	//lvl change
	if (o_player.mk == 108) {
		p_engine_load_map (lvl0a, BANK_5, BANK_3);
		p_engine_change_lvl (-4, 152, o_player.yk);
	}	
}

///procedure for lvl0d
void p_lvl0d (void) __banked
{
	//level change
	if (o_player.mk == 242) {
		p_engine_load_map (lvl0a, BANK_5, BANK_3);
		p_engine_change_lvl (-4, o_player.xk, 24);
	}
}
