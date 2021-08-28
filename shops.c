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
//   GNU General Public License For mor details.
//
//   You should have received a copy of the GNU General Public License along
//   With this program; if not, write to the Free Software Foundation, Inc.,
//   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//   Contact: projekte@kabelmail.net

#include "shops.h"

#include "text.h"

#include "data/text/npcs/healertxtA1.h"

void p_shop_healer (void) __banked
{
	if ((o_player.mk == 193) || (o_player.mk == 176)) {
		if (o_player.lifepoints != o_player.max_lifepoints) {
			p_set_txt (1, 1, healertxtA1);
			waitpad (J_A);
			p_hide_txt ();
			o_player.lifepoints = o_player.max_lifepoints; 
		}
	} 

}

void p_shop_food (void) __banked
{
	
}