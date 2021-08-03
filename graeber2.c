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
#include "init.h"
#include "player.h"
#include "engine.h"
#include "lvlstatus.h"
#include "hud.h"

void main (void)
{
	uint8_t v_tick = 60;

	p_init_stage1 ();

	//gameloop
	while (1)
	{

		//p_hud_show_value (o_engine.v_movetimer);

		if ((o_engine.v_movetimer == 6) && (o_player.v_attack == false)) 
		{
			if ((joypad () & J_UP)) p_player_move_up ();
			else if ((joypad () & J_DOWN)) p_player_move_down ();
			else if ((joypad () & J_LEFT)) p_player_move_left ();
                        else if ((joypad () & J_RIGHT)) p_player_move_right ();

			o_engine.v_movetimer = 0;
		}

		if ((joypad () & J_A) && (o_player.v_attack == false)) {
			p_lvl_select ();
			p_player_attack ();
		}

		if (o_player.v_attacktimer == 15) { //p_player_hide_weapon_sprite;
			move_sprite (PLAYER_WEAPON_SPRITE_ID, 0, 0);
			o_player.v_attacktimer = 255; o_player.v_attack = false; o_engine.v_movetimer=5; 

		}

		++o_engine.v_movetimer;
		--v_tick;

		if (o_player.v_attacktimer != 255) ++o_player.v_attacktimer;

		if ((v_tick == 0) && (o_engine.v_dungeontimer != 255)) {
			--o_engine.v_dungeontimer;
			p_hud_show_dungeontimer ();
			v_tick = 60;
		}

		wait_vbl_done ();
	}

}

