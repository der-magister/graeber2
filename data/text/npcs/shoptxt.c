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

const unsigned char healertxtA1 [72] =
{
  0x6B,0x77,0x7A,0x7F,0x77,0x7A,0x7E,0x73,0x7A,0x6D,
  0x7F,0x6B,0x7E,0x74,0x7A,0x6C,0x7F,0x7F,0x70,0x79,
  0x7F,0x66,0x70,0x6A,0x6D,0x7F,0x68,0x70,0x6A,0x71,
  0x7B,0x6C,0x59,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x50
};

const unsigned char shopfoodtxtA1 [72] =
{
  0x7D,0x66,0x7A,0x7F,0x64,0x7F,0x79,0x70,0x70,0x7B,
  0x7F,0x79,0x70,0x6D,0x7F,0x64,0x7F,0x7F,0x78,0x70,
  0x73,0x7B,0x57,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x4F,0x52,0x66,0x7A,0x6C,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x50,0x52,
  0x71,0x70
};

const unsigned char shopfoodtxtA2 [72] =
{
  0x66,0x70,0x6A,0x7F,0x7D,0x6A,0x66,0x7F,0x64,0x7F,
  0x79,0x70,0x70,0x7B,0x59,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x50
};

const unsigned char nogoldtxt [72] =
{
  0x71,0x70,0x6B,0x7F,0x7A,0x71,0x70,0x6A,0x78,0x77,
  0x7F,0x78,0x70,0x73,0x7B,0x5A,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x50
};

const unsigned char shopbeertxtA1 [72] =
{
  0x7D,0x66,0x7A,0x7F,0x64,0x7F,0x7D,0x7A,0x7A,0x6D,
  0x7F,0x79,0x70,0x6D,0x7F,0x62,0x7F,0x7F,0x78,0x70,
  0x73,0x7B,0x57,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x4F,0x52,0x66,0x7A,0x6C,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x50,0x52,
  0x71,0x70
};

const unsigned char shopbeertxtA2 [72] =
{
  0x66,0x70,0x6A,0x7F,0x7D,0x6A,0x66,0x7F,0x64,0x7F,
  0x7D,0x7A,0x7A,0x6D,0x59,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x50
};

const unsigned char shopwhetstonetxtA1 [72] =
{
  0x7D,0x66,0x7A,0x7F,0x64,0x7F,0x68,0x77,0x7A,0x6B,
  0x6C,0x6B,0x70,0x71,0x7A,0x7F,0x7F,0x7F,0x79,0x70,
  0x6D,0x00,0x5D,0x7F,0x78,0x70,0x73,0x7B,0x57,0x00,
  0x00,0x00,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x4F,0x52,0x66,0x7A,0x6C,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x50,0x52,
  0x71,0x70
};

const unsigned char shopwhetstonetxtA2 [72] =
{
  0x66,0x70,0x6A,0x7F,0x7D,0x6A,0x66,0x7F,0x64,0x7F,
  0x68,0x77,0x7A,0x6B,0x53,0x7F,0x7F,0x7F,0x6C,0x6B,
  0x70,0x71,0x7A,0x59,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x7F,0x50
};