#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "GameObject.h"

class View{
private:
static const int view_maxsize = 20;
int size;
double scale;
Point2D origin;
char grid[20][20][2];
bool GetSubscripts(int &out_x, int &out_y, Point2D location);
public:
View();
void Clear();
void Plot(GameObject * ptr);
void Draw();
};
#endif
