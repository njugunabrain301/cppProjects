#include "MapSize.h"
#include "RawMap.h"
#include "Shape.h"
#include "Map.h"

int main(){

    char map[MAP_SIZE_SOUTH][MAP_SIZE_EAST];
    rawMapLoad(map, "map1.txt");
    Shape processed_map[MAP_SIZE_SOUTH][MAP_SIZE_EAST];
    rawMapPrint(map);

    mapInit(processed_map);
    mapPrintMap(processed_map);
    for(int i = 0; i < MAP_SIZE_SOUTH; i++){
        for(int j = 0; j < MAP_SIZE_EAST; j++){
            Shape s = rawMapCalculateShape(map, i, j);
            processed_map[i][j] = s;
        }
    }
    mapPrintMap(processed_map);

    cout << "Enter the south position of the location to be checked" << endl;
    int south;
    cin >> south;
    //cin.ignore(1000, "\n");
    cout << "Enter the east position of the location to be checked" << endl;
    int east;
    cin >> east;
    //cin.getline();
    if(mapIsInMap(processed_map, south, east))
        mapPrintDescription(processed_map, south, east);
    else
        cout << "You are somewhere outside the map" << endl;
}
