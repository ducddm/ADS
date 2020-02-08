#include <stdio.h>
#include <math.h>
void zero_e(float m, float n){
	if (m==-n) printf("\nThe equation has infinite solution");
	else printf("\nNo solution !");
}
void fst_or(float p, float q){
	if (p==0){
		if (q==0) printf("\nThe equation has infinite solutions !");
		else printf("\nThe equation has no solution !");
	}
	else {
		float x=-q/p;
		printf("\nThe equation has only one solution. The solution is %f",x);
	}
}
void fst_or_sys_1(float m1,float n1, float m2, float n2, float q1, float q2){
	float D=m1*n2-n1*m2; float Dx=q1*n2-q2*n1; float Dy=m1*q2-q1*m2;
	if (D!=0){
		float x=Dx/D; float y=Dy/D;
		printf("\nThe system has unique solution ! X = %f , Y = %f ",x,y);
	}
	else {
		if (Dx==0) {
			printf("\nThe system has infinite solutions which is suitable the first-order equation %f * x + %f * y = %f",m1,n1,q1);
		}
		else printf("\nNo solution !!!");
		;
	}
}
void sec_or(float g, float h, float i){
	float D=h*h-4*g*i;
	if (D==0){
		float x=-h/2/g; printf("\nThe quadratic has only one solution. The solution is %",x);
	}
	else {
		if (D>0) {
			float x1=(-h-sqrt(D))/2/g; float x2=(-h+sqrt(D))/2/g;
			printf("\nThe quadratic has two solutions: X1 = %f , X2 = %f ",x1,x2);
		}
		else {
			printf("\nThe quadratic has no solutions in R !");
			printf("\nWe have to use complex number. The numbers we have to use is in C set ");
			float x=-h/2/g; float y=sqrt(-D)/2/g;
			printf("\nThe quadratic has 2 complex solutions: Z1 = %f + %f * i , Z2 = %f - %f * i ",x,y,x,y);
		}
	}
}
int main(){
	printf("\nWELCOME TO OUR MATHEMATICAL PROBLEM !!!!!!");
	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
	printf("\nWE HAVE SEVERAL FUNCTIONS FOR YOU TO CHOOSE ");
	printf("\n-------------------------------------------");
	printf("\nI>>BASIC FUNCTIONS");//Solve easy equations
	printf("\nI>>BASIC>>1. SOLVE ZERO-ORDER-ONE-VARIABLE EQUATION"); //a+b=0
	printf("\nI>>BASIC>>2. SOLVE FIRST-ORDER-ONE-VARIABLE EQUATION"); //ax+b=0;
	printf("\nI>>BASIC>>3. SOLVE FIRST-ORDER-TWO-VARIBALES EQUATION"); // a1 * x + b1 * y = 0 && a2 * x + b2 * y = 0
	printf("\nI>>BASIC>>4. SOLVE QUADRATIC EQUATION"); // a * x ^ 2 + b * x + c = 0
	printf("\n-------------------------------------------");
	int sel; char c;
	while (c!='N'){
		printf("\nEnter your selection (1/2/3/4) "); scanf("%d",&sel);
			if (sel==1) 
			{
				float a,b;
				printf("\nEnter a and b "); scanf("%f %f",&a,&b);
				zero_e(a,b);
			}
				
			if (sel==2){
				float a,b;
				printf("\nEnter a and b "); scanf("%f %f",&a,&b);
				fst_or(a,b);
			}
			if (sel==3){
				float a1,b1,a2,b2,c1,c2;
				printf("\nEnter a1 b1 and c1 "); scanf("%f %f %f",&a1,&b1,&c1);
				printf("\nEnter a2 b2 and c2 "); scanf("%f %f %f",&a2,&b2,&c2);
				fst_or_sys_1(a1,b1,a2,b2,c1,c2);
			}
			if (sel==4){
				float a,b,c;
				printf("\nEnter a b c "); scanf("%f %f %f",&a,&b,&c);
				sec_or(a,b,c);
			}
		printf("\nDo you want to continue ? (Yes = Y / No = N). The answer is "); scanf("%s",&c);
		}
return 0;	
}
