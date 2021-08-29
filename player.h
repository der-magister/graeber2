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

#ifndef _player_h_
#define _player_h_

#include "globals.h"

void p_player_init (void) __nonbanked;
void p_player_move_up (void) __nonbanked; 
void p_player_move_down (void) __nonbanked;
void p_player_move_left (void) __nonbanked;
void p_player_move_right (void) __nonbanked;
void p_player_set_weapon_sprite (void) __nonbanked;
void p_player_attack (void) __nonbanked;
//void p_player_hide_weapon_sprite (void) __nonbanked;
void p_player_set_sprite_xy (uint8_t l_xk, uint8_t l_yk) __nonbanked;
void p_hud_show_players_xk (void) __nonbanked;
void p_hud_show_players_yk (void) __nonbanked;
void p_player_hide_weapon_sprite (void) __nonbanked;

#endif
