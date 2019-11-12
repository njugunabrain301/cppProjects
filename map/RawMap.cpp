#include "MapSize.h"
#include "Shape.h"
#include "RawMap.h"


void rawMapLoad (char raw[][MAP_SIZE_EAST], const std::string& filename){
    fstream file;
    file.open("map1.txt");

    string line;
    int row = 0;
    while(getline(file, line)){
        char array[50];
        strcpy(array, line.c_str());
        for(int i = 0; i < MAP_SIZE_EAST; i++){
            raw[row][i] = array[i];
        }
        row++;
    }
}

void rawMapPrint (const char raw[][MAP_SIZE_EAST]){
    for(int i = 0; i < MAP_SIZE_SOUTH; i++){
        for(int j = 0; j < MAP_SIZE_EAST; j++){
            cout <<raw[i][j];
        }
        cout << endl;
    }
}

bool rawMapIsOpen (const char raw[][MAP_SIZE_EAST], int south, int east){
    if(south < 0 || south >= MAP_SIZE_SOUTH || east < 0 || east >= MAP_SIZE_EAST)
        return false;
    if(raw[south][east] == '#')
        return false;
    return true;
}

Shape rawMapCalculateShape (const char raw[][MAP_SIZE_EAST], int south, int east){
    if(!rawMapIsOpen(raw, south, east))
       return SHAPE_SOLID;
    bool northB = rawMapIsOpen(raw, south-1, east);
    bool southB = rawMapIsOpen(raw, south+1, east);
    bool eastB = rawMapIsOpen(raw, south, east+1);
    bool westB = rawMapIsOpen(raw, south, east-1);
    return shapeCalculate(northB, southB, eastB, westB);
}
