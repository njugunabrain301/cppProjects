#include "MapSize.h"
#include "Shape.h"

void mapInit (Shape map[][MAP_SIZE_EAST]);
void mapPrintMap (const Shape map[][MAP_SIZE_EAST]);
bool mapIsInMap (const Shape map[][MAP_SIZE_EAST], int south, int east);
bool mapIsTunnel (const Shape map[][MAP_SIZE_EAST], int south, int east);
void mapPrintDescription (const Shape map[][MAP_SIZE_EAST], int south, int east);
void mapSetAt (Shape map[][MAP_SIZE_EAST], int south, int east, Shape shape);
void mapSetRectangle (Shape map[][MAP_SIZE_EAST], int south_min, int east_min, int south_size, int east_size, Shape shape);

