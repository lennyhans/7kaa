/*
 * Seven Kingdoms: Ancient Adversaries
 *
 * Copyright 1997,1998 Enlight Software Ltd.
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
 *
 *Filename    : IC_R.ASM
 *Description : Remap a display surface to another display
 *              surface on the same place
 *
 * converted to C++
 */

#include <IMGFUN.h>


//--------- BEGIN OF FUNCTION IMGcopyRemap -----------
//
// Remap a rectangle of a display surface, but the result is
// put into another display surface
//
// Note : No border checking is made in this function.
//	 Placing an icon outside image buffer will cause serious BUG.
//
// char *imageBuf   - the pointer to the display surface buffer
// int imgPitch     - pitch of the destination display surface buffer
// char *backBuf    - the pointer to the back buffer
// int backPitch    - pitch of the back buffer
// int  x1,y1       - the top left vertex of the bar
// int  x2,y2       - the bottom right vertex of the bar
// char *colorTable - the pointer to the remap table
//
void IMGcall IMGcopyRemap(char* imageBuf, int imgPitch, char* backBuf, int backPitch, int x1, int y1, int x2, int y2, unsigned char* colorTable)
{
	int width = x2 - x1 + 1;
	int height = y2 - y1 + 1;
	int dest = y1*imgPitch + x1;
	int src = y1*backPitch + x1;
	for (int j=0; j<height; ++j, dest+=imgPitch, src+=backPitch)
	{
		for (int i=0; i<width; ++i)
		{
			imageBuf[ dest + i ] = colorTable[ backBuf[src + i] ];
		}
	}
}


//---------- END OF FUNCTION IMGcopyRemap ------------
