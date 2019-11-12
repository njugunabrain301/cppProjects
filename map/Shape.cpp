#include "Shape.h"
#include "RawMap.h"

bool shapeIsTunnel (Shape shape){
    if(shape.type < SHAPE_SOLID.type){
        return true;
    }
    return false;
}

char shapeGetMapChar (Shape shape){
    if(shapeIsTunnel(shape))
        return CHARS[shape.type];
    return NULL;
}

Shape shapeCalculate (bool is_open_north, bool is_open_south, bool is_open_east, bool is_open_west){
    if(!is_open_north && !is_open_south && !is_open_east && !is_open_west)
        return SHAPE_BUBBLE;
    if(is_open_north && !is_open_south && !is_open_east && !is_open_west)
        return SHAPE_N_DEAD_END;
    if(!is_open_north && is_open_south && !is_open_east && !is_open_west)
        return SHAPE_S_DEAD_END;
    if(!is_open_north && !is_open_south && is_open_east && !is_open_west)
        return SHAPE_E_DEAD_END;
    if(!is_open_north && !is_open_south && !is_open_east && is_open_west)
        return SHAPE_W_DEAD_END;
    if(is_open_north && is_open_south && !is_open_east && !is_open_west)
        return SHAPE_NS_STRAIGHT;
    if(!is_open_north && !is_open_south && is_open_east && is_open_west)
        return SHAPE_EW_STRAIGHT;
    if(is_open_north && is_open_south && !is_open_east && !is_open_west)
        return SHAPE_NE_CORNER;
    if(!is_open_north && !is_open_south && !is_open_east && !is_open_west)
        return SHAPE_NW_CORNER;
    if(!is_open_north && is_open_south && is_open_east && !is_open_west)
        return SHAPE_SE_CORNER;
    if(!is_open_north && is_open_south && !is_open_east && is_open_west)
        return SHAPE_SW_CORNER;
    if(is_open_north && is_open_south && is_open_east && !is_open_west)
        return SHAPE_NSE_T_JUNCTION;
    if(is_open_north && is_open_south && !is_open_east && is_open_west)
        return SHAPE_NSW_T_JUNCTION;
    if(is_open_north && !is_open_south && is_open_east && is_open_west)
        return SHAPE_NEW_T_JUNCTION;
    if(!is_open_north && is_open_south && is_open_east && is_open_west)
        return SHAPE_SEW_T_JUNCTION;

    return SHAPE_NSEW_CROSSROAD;
}

