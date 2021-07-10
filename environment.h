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

#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include "globals.h"

#define TILE_PATH 1
#define TILE_SAND 2
#define TILE_STONE 3
#define TILE_STONE_PHASE2 4
#define TILE_BLACK_STONE 5
#define TILE_BLACK_STONE_PHASE1 6
#define TILE_BLACK_STONE_PHASE2 7
#define TILE_GOLD 74
#define TILE_CRYSTAL 70 
#define TILE_BEER 75
#define TILE_SWITCH_OFF 15
#define TILE_SWITCH_ON 16
#define TILE_DOOR_OPEN 9
#define TILE_KEY 72
#define TILE_CHEST 11
#define TILE_OPEN_CHEST 12
#define TILE_BIG_CLOCK 71

void p_environment_get_ev (void) __banked;
void p_environment_collect_item (void) __banked;

#endif
