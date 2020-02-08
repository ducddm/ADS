//Problem to solve the quadratic equation

#include <stdio.h>
#include <math.h>

double quadratic(double a0, double b0, double c0){
	double delta, x1, x2,x,y;
	delta = b0*b0 - 4*a0*c0;
	if (delta==0){ // Real roots
		x = -b0/2/a0;
		printf("\nThe equation has only one real root. This root is %lf",x);
	}
	else {
		if (delta > 0 ){
			x1 = (-b0-sqrt(delta))/2/a0;
			x2 = (-b0+sqrt(delta))/2/a0;
			printf("\nThe equation has 2 real roots. These roots are %lf and %lf ",x1,x2);
		}
		else { // Complex roots
			x = -b0/2/a0;
			y = sqrt(-delta)/2/a0;
			printf("\nThe equation has 2 complex roots. The first root is %lf + %lf * i. The second root is %lf - %lf * i",x,y,x,y);
		}
	}
}

int main(){
	double A,B,C;
	printf("Enter the value of efficients A,B and C. These values are "); scanf("%lf %lf %lf",&A,&B,&C);
	quadratic(A,B,C);
	return 0;
}
	

