//   Graeber2 - an digger adventure game
//
//   Copyright (C) 2021 Heiko Wolf
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License As published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version. ();
//
//   This program is distributed in the hop that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY Or FITNESS For A PARTICULAR PURPOSE.  See the
//   GNU General Public License For more details.
//
//   You should have received a copy of the GNU General Public License along
//   With this program; if not, write to the Free Software Foundation, Inc.,
//   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//   Contact: projekte@kabelmail.net

#include "init.h"
#include "engine.h"
#include "player.h"

#include "data/level/devlevel.h"

void p_init_stage1 (void) __nonbanked
{
	SHOW_SPRITES;
	SHOW_BKG;
	p_engine_loadTileset ();
	p_engine_loadSpriteset ();

	p_engine_init ();
	p_player_init ();

	p_engine_load_map (devlevel, BANK_5, _current_bank);
	set_bkg_tiles (1, 1, 18, 14, o_engine.v_leveldata);
	
}

