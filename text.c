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

#include "text.h"
#include "engine.h"
#include "player.h"

void p_hide_txt (void) __banked
{
	o_engine.v_movetimer = 5;
	delay (160);
	HIDE_WIN;
	p_player_set_sprite_xy (o_player.xk, o_player.yk);
}

void p_set_txt (uint8_t l_xpos, uint8_t l_ypos, unsigned char l_text []) __banked
{
	if (o_player.yk > 104) hide_sprite (PLAYER_SPRITE_ID);
	move_win (7, 96);
	set_win_tiles (l_xpos, l_ypos, 18, 4, l_text);
	SHOW_WIN;
	delay (160);
	waitpad (J_A);
	p_hide_txt ();
}
