//Project to convert decimal number to binary number

#include<stdio.h>
#include<math.h>
#define N 100

int convert_from_decimal(int n, int m){
	int a[N],i,digit=0; int result=0;
	while (n!=0){
		a[digit]=n%m;
		n=n/m;
		digit = digit + 1;
	}
	for (i=digit-1;i>-1;i--){
		result = result + a[i] * pow(10,i);
	}
	return result;
}

char hexa(int n){
	switch (n) {
		case 0: return '0';		case 1: return '1';		case 2: return '2';		case 3: return '3';
		case 4: return '4';		case 5: return '5';		case 6: return '6';		case 7: return '7';
		case 8: return '8';		case 9: return '9';		case 10: return 'A';	case 11: return 'B';
		case 12: return 'C';	case 13: return 'D';	case 14: return 'E';	case 15: return 'F';
	}
}

void convert_to_hexa(int n, int m){
	int a[N],i,digit=0;
	while (n!=0){
		a[digit]=n%m;
		n=n/m;
		digit = digit + 1;
	}
	for (i=digit-1;i>-1;i--){
		printf("%c",hexa(a[i]));
	}
}


int main(){
	printf("%d\n",convert_from_decimal(10,2));
	convert_to_hexa(100,16);
	return 0;
}
