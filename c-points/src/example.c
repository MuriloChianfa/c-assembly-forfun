/*
 * Example of usage of points
 *
 * example.c
 *
 * Author:     Murilo Chianfa <github.com/MuriloChianfa>
 * release:    1.0.0
 */

#include"point.h"
#include"namedPoint.h"

#include<stdio.h>
#include<stdlib.h>

/*
 * Function: main
 * ----------------
 *   Create two NamedPoint* and calculate the distance between them
 *
 *   argc: numbers of enters arguments
 *   argv: these arguments
 *
 *   returns: int
 */
int main(int argc, char** argv)
{
    system("clear");
    
    puts("Welcome to usage example of points...\n");

    int xAxis, yAxis;
    
    char* firstPointName = (char*) malloc(POINT_MAX_NAME_SZ * sizeof(char));
    printf("Type the name of first point: ");
    setbuf(stdin, NULL);
    fgets(firstPointName, POINT_MAX_NAME_SZ, stdin);

    printf("Type the X-Axis of first point: ");
    scanf("%d", &xAxis);

    printf("Type the Y-Axis of first point: ");
    scanf("%d", &yAxis);

    struct NamedPoint* origin = makeNamedPoint(xAxis, yAxis, firstPointName);
    
    puts("");

    char* secondPointName = (char*) malloc(POINT_MAX_NAME_SZ * sizeof(char));
    printf("Write the name of second point: ");
    setbuf(stdin, NULL);
    fgets(secondPointName, POINT_MAX_NAME_SZ, stdin);

    printf("Type the X-Axis of second point: ");
    scanf("%d", &xAxis);

    printf("Type the Y-Axis of second point: ");
    scanf("%d", &yAxis);

    struct NamedPoint* destination = makeNamedPoint(xAxis, yAxis, secondPointName);

    printf("\nThe Distance between %s and %s is: %f\n", getName(origin), getName(destination), distance((struct Point*) origin, (struct Point*) destination));

	return 0;
}

