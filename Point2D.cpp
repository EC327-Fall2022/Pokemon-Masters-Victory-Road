
#include "Point2D.h"
#include <cmath>
#include "Vector2D.h"

Point2D::Point2D()
{
    this->x = 0.0;
    this->y = 0.0;
}
Point2D::Point2D(double in_x, double in_y)
{
    this->x = in_x;
    this->y = in_y;
}
double GetDistanceBetween(Point2D p1, Point2D p2){
    double distance = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y- p1.y) * (p2.y - p1.y));
    return distance;
}
ostream& operator<<(ostream& output,Point2D& p1)

{
    output << "("  << p1.x <<","<< p1.y << ")";
    return output;

}
Point2D operator+(Point2D p1,Point2D p2)
{
    return Point2D (p1.x+ p2.x,p1.y+ p2.y);
}
Vector2D operator-(Point2D p1,Point2D p2)
{
    return Vector2D(p1.x-p2.x ,p1.y- p2.y);
}


