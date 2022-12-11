#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
using namespace std;
class Vector2D
{
public:
    double x;
    double y;
    Vector2D();
    Vector2D(double in_x, double in_y);
};
ostream& operator<< (ostream& output,Vector2D& v1);
Vector2D operator*(Vector2D v1, double d);
Vector2D operator/(Vector2D v1, double d);
#endif
