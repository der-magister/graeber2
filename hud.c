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

#include "hud.h"
#include "engine.h"
#include "player.h"

#include "data/hud/tinyhud.h"

void p_hud_convert_value (uint8_t l_value, uint8_t l_xk, uint8_t l_yk, uint8_t l_layer) __nonbanked
{ 
        if (l_value == 0) o_engine.v_tile [0] = 91;
  
        for (v_i = 0x01; v_i != 0x0A; ++v_i) {
                if (l_value == v_i) o_engine.v_tile [0] = 0x65 - v_i;
        }
        if (l_layer == LAYER_BKG) set_bkg_tiles (l_xk, l_yk, 1, 1, o_engine.v_tile); 
        else if (l_layer == LAYER_WIN) set_win_tiles (l_xk, l_yk, 1, 1, o_engine.v_tile);
}

void p_hud_show_value (uint8_t l_value, uint8_t l_xk, uint8_t l_yk) __nonbanked
{
        p_hud_convert_value (l_value % 10, l_xk, l_yk, LAYER_BKG);
        p_hud_convert_value ((l_value / 10) % 10, l_xk - 1, l_yk, LAYER_BKG);
        p_hud_convert_value (((l_value / 10) / 10) % 10, l_xk - 2, l_yk, LAYER_BKG);       
}

void p_hud_show_players_xk (void) __nonbanked
{
       p_hud_show_value (o_player.xk, 8, 16);
}

void p_hud_show_players_yk (void) __nonbanked
{
        p_hud_show_value (o_player.yk, 12, 16);
}

///show the map coordinate of the player on the screen
void p_hud_show_players_mapK (void) __nonbanked
{
        p_hud_show_value (o_player.mk, 10, 17);
}

///show the dungeon timer
void p_hud_show_dungeontimer (void) __nonbanked
{
        p_hud_show_value (o_engine.v_dungeontimer, 18, 17);
}

void p_hud_show_lifepoints (void) __nonbanked
{
        p_hud_convert_value (o_player.lifepoints % 10, 3, 15, LAYER_BKG);
}

///show timy hud on the game screen
void p_hud_show_tiny_hud (void) __nonbanked
{

        SWITCH_ROM_MBC5 (BANK_8);
                set_bkg_tiles (1, 15, 18, 3, tinyhud);
        SWITCH_ROM_MBC5 (BANK_0);

        p_hud_show_lifepoints ();

        p_hud_show_value (o_player.inventory.crystals, 18, 15);
        p_hud_show_value (o_player.inventory.gold, 18, 16);

        p_hud_show_dungeontimer ();
}
