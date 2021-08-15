#include "namedPoint.h"

#include<stdlib.h>
#include<string.h>

struct NamedPoint {
    double x, y;
    char* name;
};

/*
 * Function: makeNamedPoint
 * ----------------
 *   Alloc and create a new point with one name and return then
 *
 *   x: the x-axis of a point
 *   y: the y-axis of a point
 *   name: char pointer to a new name
 *
 *   returns: struct NamedPoint*
 */
struct NamedPoint* makeNamedPoint(double x, double y, char* name)
{
    struct NamedPoint* namedPoint = malloc(sizeof(struct NamedPoint));

    namedPoint->x = x;
    namedPoint->y = y;
    namedPoint->name = name;

    return namedPoint;
}

/*
 * Function: setName
 * ----------------
 *   Assign the name with a namedPoint
 *
 *   namedPoint: a pointer to NamedPoint struct
 *
 *   returns: void
 */
void setName(struct NamedPoint* namedPoint, char* name)
{
    namedPoint->name = name;
}

/*
 * Function: getName
 * ----------------
 *   Returns the name of one NamedPoint
 *
 *   namedPoint: a pointer to NamedPoint struct
 *
 *   returns: char*
 */
char* getName(struct NamedPoint* namedPoint)
{
    namedPoint->name[strcspn(namedPoint->name, "(\n|\r\n|\r)$")] = (char) '\x00'; /* Switching EOL by null in name */

    return namedPoint->name;
}

