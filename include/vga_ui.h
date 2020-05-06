/*
 * Seven Kingdoms: Ancient Adversaries
 *
 * Copyright 1999 Enlight Software Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// Filename    : vga_ui.h
// Description : header file of VGA UI


#ifndef __VGA_UI_H
#define __VGA_UI_H


// -------- define constant for existing modeId ---------//

#define MODE_ID_DEFAULT			0
#define MODE_ID_800x600x8		0	
#define MODE_ID_1024x768x8	    1
#define MODE_ID_1440x1080x8     2


// -------- define struct DisplayModeInfo --------------//

struct VgaUI
{
	int	mode_id;

	// vga class constant

	int	screen_width;
	int	screen_height;
	int	screen_bpp;			// bit per plane

	// world.zoom_matrix constant

	int	zoom_matrix_x1;
	int	zoom_matrix_y1;
	int	zoom_matrix_x2;
	int	zoom_matrix_y2;
	int	zoom_matrix_width;
	int	zoom_matrix_height;

	// world.map_matrix constant

	int	map_matrix_x1;
	int	map_matrix_y1;
	int	map_matrix_x2;
	int	map_matrix_y2;
	int	map_matrix_width;
	int	map_matrix_height;

	// class Info constant

	int	top_menu_x1;
	int	top_menu_y1;
	int	top_menu_x2;
	int	top_menu_y2;

	int	info_x1;
	int	info_y1;
	int	info_x2;
	int	info_y2;

	int	info_msg_x1;
	int	info_msg_y1;
	int	info_msg_x2;
	int	info_msg_y2;

	// reserved for expansion

	int	map_mode_button_x1;
	int	map_mode_button_y1;
	int	map_mode_button_width;
	int	map_mode_button_height;
	
	int	menu_button_x1;
	int	menu_button_y1;

	int	repu_button_x1;
	int	repu_button_y1;
	
	int	date_x1;
	int	date_y1;
	int	date_length;

	int	food_x1;
	int	food_y1;
	int	food_length;

	int	cash_x1;
	int	cash_y1;
	int	cash_length;

	int	scroll_menu_x1;
	int	scroll_menu_y1;
	int	scroll_menu_x2;
	int	scroll_menu_y2;

	int	help_short_x1;
	int	help_short_y1;
	int	help_short_x2;
	int	help_short_y2;

	int	mouse_x1;
	int	mouse_y1;
	int	mouse_x2;
	int	mouse_y2;

	// ------------------------------ //

	void	init(int modeId = MODE_ID_DEFAULT);

	static VgaUI *get_display_info(int modeId);		// return NULL for non-existing display mode
	static void	set_current_display_mode(int modeId);
};

extern VgaUI current_display_mode;


// -------- replace respective constant ---------- //

#define VGA_WIDTH    current_display_mode.screen_width
#define VGA_HEIGHT   current_display_mode.screen_height
#define VGA_BPP      current_display_mode.screen_bpp
// #define VGA_PALETTE_SIZE current_display_mode.screen_palette

#define ZOOM_X1      current_display_mode.zoom_matrix_x1
#define ZOOM_Y1      current_display_mode.zoom_matrix_y1
#define ZOOM_X2      current_display_mode.zoom_matrix_x2
#define ZOOM_Y2      current_display_mode.zoom_matrix_y2
#define ZOOM_WIDTH   current_display_mode.zoom_matrix_width
#define ZOOM_HEIGHT  current_display_mode.zoom_matrix_height

#define MAP_X1       current_display_mode.map_matrix_x1
#define MAP_Y1       current_display_mode.map_matrix_y1
#define MAP_X2       current_display_mode.map_matrix_x2
#define MAP_Y2       current_display_mode.map_matrix_y2
#define MAP_WIDTH    current_display_mode.map_matrix_width
#define MAP_HEIGHT   current_display_mode.map_matrix_height

#define TOP_MENU_X1  current_display_mode.top_menu_x1
#define TOP_MENU_Y1  current_display_mode.top_menu_y1
#define TOP_MENU_X2  current_display_mode.top_menu_x2
#define TOP_MENU_Y2  current_display_mode.top_menu_y2
	
#define INFO_X1      current_display_mode.info_x1
#define INFO_Y1      current_display_mode.info_y1
#define INFO_X2      current_display_mode.info_x2
#define INFO_Y2      current_display_mode.info_y2

#define MSG_X1       current_display_mode.info_msg_x1
#define MSG_Y1       current_display_mode.info_msg_y1
#define MSG_X2       current_display_mode.info_msg_x2
#define MSG_Y2       current_display_mode.info_msg_y2

#define MAP_MODE_BUTTON_X1      current_display_mode.map_mode_button_x1
#define MAP_MODE_BUTTON_Y1      current_display_mode.map_mode_button_y1
#define MAP_MODE_BUTTON_WIDTH   current_display_mode.map_mode_button_width
#define MAP_MODE_BUTTON_HEIGHT  current_display_mode.map_mode_button_height

#define MENU_BUTTON_X1  current_display_mode.menu_button_x1
#define MENU_BUTTON_Y1  current_display_mode.menu_button_y1

#define REPU_BUTTON_X1  current_display_mode.repu_button_x1
#define REPU_BUTTON_Y1  current_display_mode.repu_button_y1

#define DATE_X1         current_display_mode.date_x1
#define DATE_Y1         current_display_mode.date_y1
#define DATE_LENGTH     current_display_mode.date_length

#define FOOD_X1         current_display_mode.food_x1
#define FOOD_Y1         current_display_mode.food_y1
#define FOOD_LENGTH     current_display_mode.food_length

#define CASH_X1         current_display_mode.cash_x1
#define CASH_Y1         current_display_mode.cash_y1
#define CASH_LENGTH     current_display_mode.cash_length

#define SCROLL_MENU_X1  current_display_mode.scroll_menu_x1
#define SCROLL_MENU_Y1  current_display_mode.scroll_menu_y1
#define SCROLL_MENU_X2  current_display_mode.scroll_menu_x2
#define SCROLL_MENU_Y2  current_display_mode.scroll_menu_y2

#define HELP_SHORT_X1   current_display_mode.help_short_x1
#define HELP_SHORT_Y1   current_display_mode.help_short_y1
#define HELP_SHORT_X2   current_display_mode.help_short_x2
#define HELP_SHORT_Y2   current_display_mode.help_short_y2

#define MOUSE_X1   current_display_mode.mouse_x1
#define MOUSE_Y1   current_display_mode.mouse_y1
#define MOUSE_X2   current_display_mode.mouse_x2
#define MOUSE_Y2   current_display_mode.mouse_y2

//------------- Common units used ------------------------//
// Inner element padding
#define IE_PADDING 6

//------------- Define coordinations OR_AI.cpp -----------//

#define ACTION_BROWSE_X1 ZOOM_X1+IE_PADDING
#define ACTION_BROWSE_Y1 ZOOM_Y1+IE_PADDING
#define ACTION_BROWSE_X2 ZOOM_X2-IE_PADDING
#define ACTION_BROWSE_Y2  ACTION_BROWSE_Y1+200

#define ATTACK_BROWSE_X1 ZOOM_X1+IE_PADDING
#define ATTACK_BROWSE_Y1 ACTION_BROWSE_Y2+IE_PADDING
#define ATTACK_BROWSE_X2 ZOOM_X2-IE_PADDING
#define ATTACK_BROWSE_Y2 ATTACK_BROWSE_Y1+160

#define OTHER_INFO_X1 ZOOM_X1+IE_PADDING
#define OTHER_INFO_Y1 ATTACK_BROWSE_Y2+IE_PADDING
#define OTHER_INFO_X2 ZOOM_X2-IE_PADDING
#define OTHER_INFO_Y2 ZOOM_Y2-IE_PADDING


//------------- Define coordinations  OR_NAT.cpp -----------//

#define REPORT_BROWSE_X1 ZOOM_X1+IE_PADDING
#define  REPORT_BROWSE_Y1 ZOOM_Y1+IE_PADDING
#define  REPORT_BROWSE_X2 ZOOM_X2-IE_PADDING
#define  REPORT_BROWSE_Y2 REPORT_BROWSE_Y1+206

#define  REPORT_BUTTON_X1 ZOOM_X1+8
#define  REPORT_BUTTON_Y1 REPORT_BROWSE_Y2+IE_PADDING
#define  REPORT_BUTTON_WIDTH 135
#define  REPORT_BUTTON_Y2 REPORT_BUTTON_Y1+20
#define  REPORT_BUTTON_X_SPACE 130

#define  REPORT_DET_X1 ZOOM_X1+IE_PADDING
#define  REPORT_DET_Y1 REPORT_BUTTON_Y2+4
#define  REPORT_DET_X2 ZOOM_X2-IE_PADDING
#define  REPORT_DET_Y2 ZOOM_Y2-IE_PADDING
#define  REPORT_TALK_Y2 ZOOM_Y2-86	// use a shorter height for the diplomacy menu as it needs to let the player looks at the messages received.

#endif
