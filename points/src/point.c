/*
 * Declare structs and functions of point header file
 *
 * point.c
 *
 * Author:     Murilo Chianfa <github.com/MuriloChianfa>
 * release:    1.0.0
 */

#include"point.h"

#include<stdlib.h>
#include<math.h>

struct Point {
    double x, y;
};

/*
 * Function: makePoint
 * ----------------
 *   Alloc and create a new point and return then
 *
 *   x: the x-axis of a point
 *   y: the y-axis of a point
 *
 *   returns: struct Point*
 */
struct Point* makePoint(double x, double y)
{
    struct Point* point = malloc(sizeof(struct Point));

    point->x = x;
    point->y = y;

    return point;
}

/*
 * Function: distance
 * ----------------
 *   Calculate the distance between two points
 *
 *   point1: one pointer to struct Point
 *   point1: other pointer to struct Point
 *
 *   returns: double
 */
double distance(struct Point* point1, struct Point* point2)
{
    double distanceX = point1->x - point2->x;
    double distanceY = point1->y - point2->y;

    return sqrt((distanceX * distanceX) + (distanceY * distanceY));
}

