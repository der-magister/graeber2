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


extern void p_environment_get_ev (void) __banked;

#endif
