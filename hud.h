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

#ifndef _HUD_H_
#define _HUD_H_

#include "globals.h"

void p_hud_show_value (uint8_t l_value, uint8_t l_xk, uint8_t l_yk) __banked;
void p_hud_show_players_mapK (void) __banked;

void p_hud_show_food (void) __banked;
void p_hud_show_lifepoints () __banked;

void p_hud_show_dungeontimer (void) __banked;
void p_hud_show_frame (void) __banked;
void p_hud_show_tiny_hud (void) __banked;
void p_hud_show_tool_status (void) __banked;
void p_hud_show_clean_course (void) __banked;
void p_hud_show_big_frame (void) __banked;

#endif
