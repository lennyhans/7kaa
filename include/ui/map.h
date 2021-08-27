
#ifndef __UI_MAP_H
#define __UI_MAP_H
#include <stdint.h>

namespace ui {

class Map
{
public:
	int MAX_WORLD_X_LOC;
	int	MAX_WORLD_Y_LOC;
	int MAP_WIDTH;
    int MAP_HEIGHT;
    int MAX_MAP_WIDTH;
    int MAX_MAP_HEIGHT;
    int MAP_X1;
    int MAP_Y1;
    int MAP_X2;
    int MAP_Y2;
    int MAP_LOC_HEIGHT;
    int MAP_LOC_WIDTH;
    int MAP2_LOC_HEIGHT;
    int MAP2_LOC_WIDTH;
    int ZOOM_X1;
    int ZOOM_Y1;
    int ZOOM_X2;
    int ZOOM_Y2;
    int ZOOM_WIDTH;
    int ZOOM_HEIGHT;
    int ZOOM_LOC_HEIGHT;
    int ZOOM_LOC_WIDTH;
    int ZOOM_X_SHIFT_COUNT;
    int ZOOM_Y_SHIFT_COUNT;
    int ZOOM_X_PIXELS;
    int ZOOM_Y_PIXELS;

public:
	Map();
   ~Map();
   int GetMapPosition( int position, int coordinate);
};

}

#endif