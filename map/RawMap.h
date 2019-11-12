#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include "MapSize.h"
#include "Shape.h"

using namespace std;

void rawMapLoad (char raw[][MAP_SIZE_EAST], const std::string& filename);
void rawMapPrint (const char raw[][MAP_SIZE_EAST]);
bool rawMapIsOpen (const char raw[][MAP_SIZE_EAST], int south, int east);

Shape rawMapCalculateShape (const char raw[][MAP_SIZE_EAST], int south, int east);
