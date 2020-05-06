/*
 * Seven Kingdoms 2: The Fryhtan War
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

// Filename    : OMODEID.H
// Description : DisplayModeInfo


#include <vga_ui.h>
#include <dbglog.h>
#include <cstdlib>

#define MAX_DISPLAY_MODE_ID 3


static VgaUI display_info_array[MAX_DISPLAY_MODE_ID] = 
{
	// 800x600x8
	{
		MODE_ID_800x600x8,						        // mode id
		800, 600, 8,						            // screen_width, height, bbp,
		0, 68-12, 575, 599, 576, 532+12,				// zoom_matrix_x1,y1,x2,y2,width,height
		588, 56, 588 + 200 -1, 56+ 200 -1, 200, 200,	// map_matrix_x1,y1,x2,y2,width,height
		4, 4, 576-2, 30,						        // top_menu_x1,y1,x2,y2
		586, 265, 790, 589,						        // info_x1,y1,x2,y2
		586, 589 -29, 790, 589,						    // msg_info_x1,y1,x2,y2
		580, 3, 40, 24,							        // map_mode_button_x1, y1, width, height
		720, 6,									        // menu_button_x1, y1
        // UNUSED
		486-30, 24,								        // repu_button_x1, y1
		480, 12-2, 105,							        // date_x1, y1, length
        378-20, 9+4, 67+100,						    // food_x1, y1, length
		376-20, 36+1, 69+100,							// cash_x1, y1, length
		0, 0, 331-19, 66-11,							// scroll_menu_x1, y1, x2, y2 
		577, 584, 799, 599, 							// help_short_x1, y1, x2, y2
		0, 0, 797, 598						            // mouse_x1,y1,x2,y2
	},

	// 1024x768x8
	{
		MODE_ID_1024x768x8,			    		        // mode id
		1024,768, 8,						            // screen_width, height, bbp
		0, 68-12, 799, 767, 800, 712,				    // zoom_matrix_x1,y1,x2,y2,width,height  {y1 must never 0, 64 must be a factor of y1 - y2}
		812, 56, 812+200 -1, 56 +200 -1, 200, 200,		// map_matrix_x1,y1,x2,y2,width,height
		4, 4, 798, 30,						            // top_menu_x1,y1,x2,y2
		812-2, 265, 1014, 757,					        // info_x1,y1,x2,y2
		812-2, 757 -29, 1014, 757,					    // msg_info_x1,y1,x2,y2
		812-2, 3, 40, 24,						        // map_mode_button_x1, y1, width, height
		950, 6,								            // menu_button_x1, y1
        // UNUSED
		814+155, 165-165,								// repu_button_x1, y1
		875, 150-90, 150,						    	// date_x1, y1, length
		947-120, 122-95, 72,							// food_x1, y1, length
		848+50, 122-95, 56,							    // cash_x1, y1, length
		801-2, 80-5, 1018, 168,						    // scroll_menu_x1, y1, x2, y2 
		801, 752, 1023, 767,						    // help_short_x1, y1, x2, y2
		0, 0, 1021, 766							        // mouse_x1,y1,x2,y2
	},
    // 1440x1080x8
	{
		MODE_ID_1440x1080x8,			    		    // mode id
		1440, 1080, 8,						            // screen_width, height, bbp
		0, 68-12, 1216, 1079, 1216, 1024,				    // zoom_matrix_x1,y1,x2,y2,width,height  {y1 must never 0, 64 must be a factor of y1 - y2}
		1228, 56, 1228+200 -1, 56 +200 -1, 200, 200,	// map_matrix_x1,y1,x2,y2,width,height
		4, 4, 798, 198,						            // top_menu_x1,y1,x2,y2
		1228-2, 256, 1430, 433,					        // info_x1,y1,x2,y2
		1228-2, 757 -29, 1430, 757,					    // msg_info_x1,y1,x2,y2
		1228-2, 3, 40, 24,						        // map_mode_button_x1, y1, width, height
		1228, 6,								            // menu_button_x1, y1
		814+155, 165-165,								// repu_button_x1, y1
		875, 150-90, 150,							    // date_x1, y1, length
		947-120, 122-95, 72,							// food_x1, y1, length
		848+50, 122-95, 56,							    // cash_x1, y1, length
		801-2, 80-5, 1018, 168,						    // scroll_menu_x1, y1, x2, y2 
		801, 752, 1023, 767,						    // help_short_x1, y1, x2, y2
		32, 2, 1018, 762							    // mouse_x1,y1,x2,y2
	}
};

void VgaUI::init(int modeId)
{
	if( modeId >= 0 && modeId < MAX_DISPLAY_MODE_ID )
	{
		 *this = display_info_array[modeId];
	}
	else
	{
		ERR("Unknown UI Mode: %s\n", modeId);
	}	
}

// return NULL for non-existing display mode
VgaUI *VgaUI::get_display_info(int modeId)
{
	if( modeId >= 0 && modeId < MAX_DISPLAY_MODE_ID )
		return display_info_array + modeId;
	else
		return NULL;
}


void VgaUI::set_current_display_mode(int modeId)
{
	if( modeId >= 0 && modeId < MAX_DISPLAY_MODE_ID )
	{
		current_display_mode = display_info_array[modeId];
	}
	else
	{
		ERR("Unknown UI Mode: %s\n", modeId);
	}	
}



