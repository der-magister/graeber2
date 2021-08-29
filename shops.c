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
#include "hud.h"

#include "data/text/npcs/shoptxt.h"

void p_shop_healer (void) __banked
{
	if ((o_player.mk == 193) || (o_player.mk == 176)) {
		if (o_player.lifepoints != o_player.max_lifepoints) {
			p_set_txt (1, 1, healertxtA1);
			waitpad (J_A);
			p_hide_txt ();
			o_player.lifepoints = o_player.max_lifepoints; 
			p_hud_show_lifepoints ();
		}
	} 

}

///food shop
void p_shop_food (void) __banked
{
	uint8_t l_quit;

	l_quit = false;

	if ((o_player.mk == 165) || (o_player.mk == 148) || (o_player.mk == 167)) {
		if (o_player.inventory.food != o_player.inventory.max_food) {
			p_set_txt (1, 1, shopfoodtxtA1);

			while (l_quit == false) {
				if (joypad () & J_A) { l_quit = true; }
				else if (joypad () & J_DOWN) {
					if (o_player.inventory.gold > 0) {

						++o_player.inventory.food;
						--o_player.inventory.gold;
						p_set_txt (1, 1, shopfoodtxtA2);
						p_hud_show_food ();	
					}
					else {
						p_set_txt (1, 1, nogoldtxt);
					}
					delay (200);
					waitpad (J_A);
					l_quit = true;
				}
			}
			p_hide_txt ();
		}
	}
}

///pub
void p_shop_beer (void) __banked
{
	uint8_t l_quit;

	l_quit = false;

	if ((o_player.mk == 184) || (o_player.mk == 167)) {
		if (o_player.inventory.beer != o_player.inventory.max_beer) {
			p_set_txt (1, 1, shopbeertxtA1);

			while (l_quit == false) {
				if (joypad () & J_A) { l_quit = true; }
				else if (joypad () & J_DOWN) {
					if (o_player.inventory.gold > 3) {

						++o_player.inventory.beer;
						o_player.inventory.gold -= 3;
						p_set_txt (1, 1, shopbeertxtA2);	
					}
					else {
						p_set_txt (1, 1, nogoldtxt);
					}
					delay (200);
					waitpad (J_A);
					l_quit = true;
				}
			}
			p_hide_txt ();
		}
	}
}

///whetstone
void p_shop_whetstone (void) __banked
{
	uint8_t l_quit;

	l_quit = false;

	if ((o_player.mk == 194) || (o_player.mk == 175)) {
		if (o_player.inventory.whetstone != o_player.inventory.max_whetstone) {
			p_set_txt (1, 1, shopwhetstonetxtA1);

			while (l_quit == false) {
				if (joypad () & J_A) { l_quit = true; }
				else if (joypad () & J_DOWN) {
					if (o_player.inventory.gold > 8) {

						++o_player.inventory.whetstone;
						o_player.inventory.gold -= 8;
						p_set_txt (1, 1, shopwhetstonetxtA2);	
					}
					else {
						p_set_txt (1, 1, nogoldtxt);
					}
					delay (200);
					waitpad (J_A);
					l_quit = true;
				}
			}
			p_hide_txt ();
		}
	}
}
