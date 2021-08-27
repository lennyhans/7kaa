
#include <ui/map.h>

namespace ui {

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


	ui::Map::Map(){
        MAX_MAP_WIDTH = 200;
        MAX_MAP_HEIGHT = 200;
    };

    ui::Map::~Map(){

    };

    int GetMapPositionX(int pos){
        int iPos = pos + MAP_X1;
        return iPos == MAP_WIDTH - 1 ? MAP_WIDTH - 2 : iPos;
    }

    int GetMapPositionY(int pos){
        int iPos = pos + MAP_Y1;
        return iPos == MAP_HEIGHT - 1 ? MAP_HEIGHT - 2 : iPos;
    }

    int Map::GetMapPosition(int position, int coordinate){
        return coordinate == 0 ? GetMapPositionX(position) : coordinate == 1 ? GetMapPositionY(position)
                                                                             : 0;
    }
}