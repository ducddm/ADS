#include <stdio.h>
#define qtt 30
int Fibonacci(int index){
	switch (index) {
		case 0: return 0;
		case 1: return 1;
	}
	if (index>1) return Fibonacci(index-2)+Fibonacci(index-1);
	if (index<0) return Fibonacci(index+2)-Fibonacci(index+1);
}
int main(){
	int ch; char slt;
	int no_id; 
	int under_lim, above_lim; int i;
	printf("This is a Fibonacci problem");
	printf("\nThere are 2 functions ");
	printf("\nFunction 1: Print numbers ");
	printf("\nFunction 2: Display sequence ");
	printf("\n------------------------------");
	while (slt!='N'){
		printf("\nChoose your function "); scanf("%d",&ch);
		switch (ch) {
			case 1:
				
				printf("\nEnter index you want (index<=45)"); scanf("%d",&no_id);
				printf("\nNumber you want with index %d is %d",no_id,Fibonacci(no_id));
				break;
			case 2: 
				
				printf("\nEnter under and above limits "); scanf("%d %d",&under_lim,&above_lim);
				for (i=1;i<=qtt;i++){
					if ((Fibonacci(i)>=under_lim) && (Fibonacci(i)<=above_lim)) printf("%d ",Fibonacci(i));
				}
				break;
			}
		printf("\nDo you want to continue ? (Yes=Y/ No=N)"); scanf("%s",&slt);	
			
		}
return 0;	
}
