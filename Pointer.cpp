#include <iostream>
int main()
{
	float x,y,*p,*q,sum;
	printf("Enter value X and Y "); scanf("%f %f",&x,&y);
	p=&x; q=&y;
	sum=*p+*q;
	printf("Sum is %f ",sum); return 0;
}
