#include <iostream>
#include <stdio.h>
#define max 100
int main()
{
	int i,sum=0,*p,n;
	int a[max];
	printf("Enter number of elements "); scanf("%d",&n);
	for (i=0;i<n;i++)
		{
			printf("a[%d]=",i); scanf("%d",&a[i]);
		}
	for (i=0;i<n;i++)
		{
			p=&a[i];
			sum+=*p;
		}
	printf("Sum is %d",sum);
	return 0;
}
