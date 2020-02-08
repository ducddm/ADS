#include <iostream>
#include <stdio.h>
#include <math.h>
struct P
	{
		float x;
		float y;
	};
int check(float a1,float a2, float x1, float x2, float y1, float y2);
int rectangle(float c, float d, float e, float f);
int main()
{
	struct P p1,p2,pA; 
	float area,x_component,y_component;
	printf("Enter x and y part for point 1 "); scanf("%f %f",&p1.x,&p1.y);
	printf("Enter x and y part for point 2 "); scanf("%f %f",&p2.x,&p2.y);
	while (rectangle(p1.x,p1.y,p2.x,p2.y)==0)
	{	
		printf("Please re-enter 2 points !");
		printf("\nEnter x and y part for point 1 "); scanf("%f %f",&p1.x,&p1.y);
		printf("Enter x and y part for point 2 "); scanf("%f %f",&p2.x,&p2.y);
	}
	if (p1.x>p2.x) x_component=p1.x-p2.x; else x_component=p2.x-p1.x;
	if (p1.y>p2.y) y_component=p1.y-p2.y; else y_component=p2.y-p1.y;
	area=x_component*y_component;
	printf("\nThe area of rectangle is %f",area);
	printf("\n------------------------------------------");
	printf("\nEnter x and y part for point A "); scanf("%f %f",&pA.x,&pA.y);
	if (check(pA.x,pA.y,p1.x,p1.y,p2.x,p2.y)) printf("A is in the rectangle "); else printf("A is not in the rectangle");
	return 0;
}
int rectangle(float c1, float c2, float d1, float d2)
{
	float x_component,y_component;
	x_component=d1-c1; y_component=d2-c2;
	if ((x_component==0) || (y_component==0)) return 0; else return 1;
}
int check(float a1,float a2, float x1, float x2, float y1, float y2)
{
	int count=0;
	if (((x1>a1) && (a1>y1)) || ((x1<a1) && (a1<y1))) count++;
	if (((x2>a2) && (a2>y2)) || ((x2<a2) && (a2<y2))) count++;
	if (count==2) return 1; else return 0;
}
