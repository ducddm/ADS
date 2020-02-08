#include <iostream>

int total_10 = 0;
int total_13 = 0;

void check_last_digit_10(int a[], int i){
	if (i>9) return;
	else {
		total_10 = total_10 + a[i]*(i+1);
	}
	check_last_digit_10(a,i+1);
}

void check_last_digit_13(int a[], int i){
	if (i>13) return;
	else {
		if ((i+1)%2==1) {
			total_13 = total_13 + a[i];
		}
		else {
			total_13 = total_13 + a[i]*3;
		}
	}
	check_last_digit_13(a,i+1);
}

int main(){
	int last_digit_10, last_digit_13;
	
	int ISBN10[]={8,7,5,9,1,2,9,8,7};
	int ISBN13[]={9,7,8,0,3,0,6,4,0,6,1,5};
	
	check_last_digit_10(ISBN10,0);
	check_last_digit_13(ISBN13,0);
	
	last_digit_10 = total_10 % 11;
	last_digit_13 = 10 - total_13 % 10;
	
	printf("%d",last_digit_10);
	printf("\n%d",last_digit_13);
	
	
}

