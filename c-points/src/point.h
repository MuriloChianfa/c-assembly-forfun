#ifndef POINT_H
#define POINT_H

struct Point;
struct Point* makePoint(double x, double y);
double distance (struct Point *point1, struct Point *point2);

#endif
