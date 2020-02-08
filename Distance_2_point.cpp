#include <iostream>
#include <stdio.h>
#include <math.h>
struct Point
	{
		float x;
		float y;
	}; 
int main()
{
	struct Point point1,point2;
	float distance,x_component,y_component;
	printf("Enter x and y part for point 1 "); scanf("%f %f",&point1.x,&point1.y);
	printf("Enter x and y part for point 2 "); scanf("%f %f",&point2.x,&point2.y);
	x_component=(point2.x-point1.x)*(point2.x-point1.x);
	y_component=(point2.y-point1.y)*(point2.y-point1.y);
	distance=sqrt(x_component+y_component);
	printf("Distance is %f",distance);
	return 0;
}
