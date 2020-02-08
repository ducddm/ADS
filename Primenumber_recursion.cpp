#include <stdio.h>

void find_prime_number(int n,int i){
	int count=0;
	if (i>n) return;
	else {
		for (int j=1;j<=i;j++){
			if (i%j==0) count=count+1; 
		}
	find_prime_number(n,i+1);
	if (count==2) printf("%d ",i);
	}
}

int main(){
	int n;
	printf("Enter an integer "); scanf("%d",&n);
	find_prime_number(n,1);
	return 0;
}

//There are 2 loops in the program. The first one is the recursion and the second one is the for loop. S
//So the complexity of the program is O(n^2)



