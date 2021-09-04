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
#include "environment.h"
#include "hud.h"
#include "text.h"
#include "items.h"
#include "player.h"
#include "shops.h"

#include "data/level/lvldatmine-entrance.h"
#include "data/level/lvldatfirstcourse.h"

#include "data/text/shields/shieldtxt.h"
#include "data/text/npcs/bosstxt.h"

#include "data/text/locations/locations.h"

///procedure for lvl0a
void p_lvl0a (void) __banked
{
	//shield
	p_environment_shield (191, shieldhealertxt);

	p_shop_healer ();

	//npcs
	if ((o_player.mk == 134) || (o_player.mk == 117) ||
	    (o_player.mk == 98)  || (o_player.mk == 115)) 
	{
		if (v_lvldat [0] == 0) {
			p_set_txt (1, 1, bosstxtA1);
			waitpad (J_DOWN);
			p_set_txt (1, 1, bosstxtA2);
			waitpad (J_DOWN);
			p_set_txt (1, 1, bosstxtA3);
			o_pickaxe.v_active = true;
			o_player.inventory.pickaxe = true;
			waitpad (J_A);
			p_hide_txt ();
			v_lvlmodi [0] = 1; v_lvldat [0] = 1;
			p_player_set_weapon_sprite ();
			p_hud_show_tool_status ();
		}
	}

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
	//npcs
	p_shop_food ();

	//shields
	p_environment_shield (133, shieldfoodtxt);
	p_environment_shield (123, shieldbombstxt);

	//level change
	if (o_player.mk == 125) {
		p_engine_load_map (lvl0a, BANK_5, BANK_3);
		p_engine_change_lvl (-4, 16, o_player.yk);
	}
}

///procedure for lvl0c
void p_lvl0c (void) __banked
{
	//npc
	p_shop_beer ();
	p_shop_whetstone ();

	//shields
	p_environment_shield (136, forgetxt);
	p_environment_shield (110, shieldpubtxt);
	p_environment_shield (228, shieldoiltxt);

	//lvl change
	if (o_player.mk == 108) {
		p_engine_load_map (lvl0a, BANK_5, BANK_3);
		p_engine_change_lvl (-4, 152, o_player.yk);
	}	
}

///procedure for lvl0d
void p_lvl0d (void) __banked
{
	//shields
	p_environment_shield (45, shieldfirstcoursetxt);
	p_environment_shield (50, shieldsecondcoursetxt);
	p_environment_shield (41, shieldthirdcoursetxt);
	p_environment_shield (160, shieldfourthcoursetxt);
	p_environment_shield (109, shieldfifthcoursetxt);


	//level change
	if (o_player.mk == 242) {
		p_engine_load_map (lvl0a, BANK_5, BANK_3);
		p_engine_change_lvl (-4, o_player.xk, 24);
	}
	else if (o_player.mk == 8) {
		p_engine_load_map (lvl001, BANK_5, BANK_3);
		p_engine_change_lvl (1, o_player.xk, 128);
		o_engine.v_dungeontimer = 125;
		p_hud_show_dungeontimer ();
		p_show_location (firstcoursetxt);
	}
}
