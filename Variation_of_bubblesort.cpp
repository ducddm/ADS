#include <stdio.h>
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void var_of_bb_sort(int a[],int n){
	int j,i;
	for (j=1;j<=n;j++){
		for (i=j-1;i<n-j;i++){
			if (a[i+1]<a[i]) swap(&a[i+1],&a[i]);
		}
		for (i=n-j;i>=0;i--){
			if (a[i-1]>a[i]) swap(&a[i-1],&a[i]);
		}
	}
}
int main(){
	int a[13]={77,88,33,22,99,110,11,66,55,44,65,87,102};
	var_of_bb_sort(a,13);
	for (int i=0;i<13;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}
//Complexity of the algorithm
//Best scenario: O(n)
//Average scenario: O(n^2)
//Worst scenario: O(n^2)
