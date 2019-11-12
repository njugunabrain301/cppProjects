#ifndef SHAPE
#define SHAPE

typedef struct Shape{
    unsigned int type;
}Shape;

const Shape SHAPE_BUBBLE  = {0};
const Shape SHAPE_N_DEAD_END  = {1};
const Shape SHAPE_S_DEAD_END = {2};
const Shape SHAPE_E_DEAD_END = {3};
const Shape SHAPE_W_DEAD_END = {4};
const Shape SHAPE_NS_STRAIGHT = {5};
const Shape SHAPE_EW_STRAIGHT = {6};
const Shape SHAPE_NE_CORNER = {7};
const Shape SHAPE_NW_CORNER = {8};
const Shape SHAPE_SE_CORNER = {9};
const Shape SHAPE_SW_CORNER = {10};
const Shape SHAPE_NSE_T_JUNCTION = {11};
const Shape SHAPE_NSW_T_JUNCTION = {12};
const Shape SHAPE_NEW_T_JUNCTION = {13};
const Shape SHAPE_SEW_T_JUNCTION = {14};
const Shape SHAPE_NSEW_CROSSROAD = {15};
const Shape SHAPE_SOLID = {16};

const int NUM_TUNNEL_SHAPES = 17;
const char CHARS[NUM_TUNNEL_SHAPES] = {'0','N','S','E','W','|','-','\\','/','/','\\','>','<','^','v','+',' ',};


bool shapeIsTunnel (Shape shape);
char shapeGetMapChar (Shape shape);
Shape shapeCalculate (bool is_open_north, bool is_open_south, bool is_open_east, bool is_open_west);


#endif // SHAPE
