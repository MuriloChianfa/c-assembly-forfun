#ifndef NAMED_POINT_H
#define NAMED_POINT_H

#define POINT_MAX_NAME_SZ 30

struct NamedPoint;
struct NamedPoint* makeNamedPoint(double x, double y, char* name);
void setName(struct NamedPoint* namedPoint, char* name);
char* getName(struct NamedPoint* namedPoint);

#endif
