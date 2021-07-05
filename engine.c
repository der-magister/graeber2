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

#include "engine.h"

#include "data/tilesets/font-81-127.h"
#include "data/tilesets/maintiles_81-0.h"
#include "data/spritesets/spriteset.h"

void p_engine_loadTileset (void) NONBANKED
{
	SWITCH_ROM_MBC5 (BANK_2);
	set_bkg_data (81, 127, font);
	set_bkg_data (0, 80, maintiles);
        SWITCH_ROM_MBC5 (BANK_0);
}

void p_engine_loadSpriteset (void) NONBANKED
{
	SWITCH_ROM_MBC5 (BANK_2);
	set_sprite_data (0, 127, sprites);
	SWITCH_ROM_MBC5 (BANK_0);
}
