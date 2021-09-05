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

#include "first-course.h"
#include "engine.h"
#include "hud.h"
#include "text.h"

#include "data/level/lvldatfirstcourse.h"
#include "data/level/lvldatmine-entrance.h"

#include "data/text/locations/locations.h"

///procedure first course room 1
void p_lvl001 (void) __banked
{
	if (o_player.mk == 8) {
		p_engine_load_map (lvl002, BANK_5, BANK_3);
		p_engine_change_lvl (2, o_player.xk, 128);
	}
} 

///procedure first course room 2
void p_lvl002 (void) __banked
{
	if (o_player.mk == 125) {
		p_engine_load_map (lvl003, BANK_5, BANK_3);
		p_engine_change_lvl (3, 16, o_player.yk);
	}
}

///procedure first course room 3
void p_lvl003 (void) __banked
{
	if (o_player.mk == 125) {
		p_engine_load_map (lvl004, BANK_5, BANK_3);
		p_engine_change_lvl (4, 16, o_player.yk);
	}	
}

///procedure first course room 4
void p_lvl004 (void) __banked
{
	if (o_player.mk == 242) {
		p_engine_load_map (lvl005, BANK_5, BANK_3);
		p_engine_change_lvl (5, o_player.xk, 24);
	}	
}

///procedure first course room 5
void p_lvl005 (void) __banked
{
	if (o_player.mk == 125) {
		p_engine_load_map (lvl006, BANK_5, BANK_3);
		p_engine_change_lvl (6, 16, o_player.yk);
	}	
}

///procedure first course room 6
void p_lvl006 (void) __banked
{
	if (o_player.mk == 8) {
		p_engine_load_map (lvl007, BANK_5, BANK_3);
		p_engine_change_lvl (7, o_player.xk, 128);
	}

}

///procedure first course room 7
void p_lvl007 (void) __banked
{
	if (o_player.mk == 8) {
		p_engine_load_map (lvl008, BANK_5, BANK_3);
		p_engine_change_lvl (8, o_player.xk, 128);

	}
}

///procedure first course room 8
void p_lvl008 (void) __banked
{
	if (o_player.mk == 8) {
		p_hud_show_clean_course ();
		p_engine_load_map (lvl0d, BANK_5, BANK_3);
		p_engine_change_lvl (-1, o_player.xk, 72);
		p_show_location (mineentrancetxt);
	}
}
