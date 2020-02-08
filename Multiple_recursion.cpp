#include<stdio.h>
int multi(int num,int index){
	switch (index){
		case 0: return 0;
		case 1: return num;
	}
	if (index>1) return multi(num,index-1)+num;
	if (index<0) return multi(num,index+1)-num;
}
int main(){
	int a,b;
	printf("Enter a and b "); scanf("%d %d",&a,&b);
	printf("%d x %d = %d",a,b,multi(a,b));
	return 0;
}

