#include "MapSize.h"
#include "Map.h"
#include "Shape.h"
#include "RawMap.h"

void mapSetAt (Shape map[][MAP_SIZE_EAST], int south, int east, Shape shape){
    map[south][east] = shape;
}
void mapSetAt (Shape map[][MAP_SIZE_EAST], int south, int east, Shape shape);

void mapSetRectangle (Shape map[][MAP_SIZE_EAST], int south_min, int east_min, int south_size, int east_size, Shape shape){
    for(; south_min < south_size; south_min++){
        for(; east_min < east_size; east_min++){
            mapSetAt(map, south_min, east_min, shape);
        }
    }
}

void mapInit (Shape map[][MAP_SIZE_EAST]){
    for(int i = 0; i < MAP_SIZE_SOUTH; i++){
        for(int j = 0; j < MAP_SIZE_EAST; j++){
            mapSetAt(map,i,j, SHAPE_SOLID);
        }
    }
}

void mapPrintMap (const Shape map[][MAP_SIZE_EAST]){
    for(int i = 0; i < MAP_SIZE_SOUTH; i++){
        for(int j = 0; j < MAP_SIZE_EAST; j++){
            char c = shapeGetMapChar(map[i][j]);
            cout << c;
        }
        cout << endl;
    }
}

bool mapIsInMap (const Shape map[][MAP_SIZE_EAST], int south, int east){
    if(south < 0 || south >= MAP_SIZE_SOUTH || east < 0 || east >= MAP_SIZE_EAST)
        return false;
    return true;
}

bool mapIsTunnel (const Shape map[][MAP_SIZE_EAST], int south, int east){
    return shapeIsTunnel(map[south][east]);
}

void mapPrintDescription (const Shape map[][MAP_SIZE_EAST], int south, int east){
    if(mapIsTunnel(map, south, east))
        cout << "You are in a tunnel" << endl;
    else
        cout << "You are in solid rock" << endl;
}

