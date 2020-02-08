#include <iostream>
#include <stdlib.h>
#include <math.h>
typedef struct node{
	int degree;
	int co_efficient;
	struct node *next; }term;
 
term *Head = NULL; 
term *Tail = NULL;

void init_term(int deg, char coeff){
	term *newTerm = (term *) malloc(sizeof(newTerm));	
	newTerm->degree=deg;
	newTerm->co_efficient=coeff;
	
	newTerm->next=NULL;

	if (Head == NULL){	
		Head = newTerm;
	 	Tail = newTerm;}
	else{ Tail->next = newTerm; Tail = newTerm; } } 


void display(){
	term* Current = Head;
	while (Current!=NULL){
		printf(" %d x ^ %d + ",Current->co_efficient,Current->degree);
		Current=Current->next;
		}
	}
void insert(int deg, int coff){
	term* Insert = Head;
	while (Insert!=NULL){
		if (Insert->degree==deg){
			Insert->co_efficient=Insert->co_efficient+coff;
			}
	Insert=Insert->next;
	}
}
void remove(int del){
	term* p=Head;
	if ((p->degree==del)){
		Head=p->next;
		free(p);
		return;
	}
	term* q=p->next;
	while (p->degree!=del){
		q=p;
		p=p->next; 
	}
	if (p!=NULL){
		q->next=p->next;
		free(p);
	}
}
double calculate(double x){
	term* Current=Head; double total=0;
	while (Current!=NULL){
		total=total+pow(x,Current->degree)*(Current->co_efficient);
		Current=Current->next;
	}
	return total;
}

double derivative(double x){ //Center method
	double f1 = calculate(x+0.01);
	double f2 = calculate(x-0.01);
	double res = (f1-f2)/2/0.01;
	return res;
}

double integral(double a, double b){
	int n=16;
	double s=0;
	double h = (b-a)/n;
	for (int i=0;i<n;i++){
		s = s+ calculate(a+h*i)+calculate(a+h*(i+1));
	}
	double result = (b-a)*s/2/n;
	return result;
}

double find_root(double x0){
	double x[100];
	double error=0;
	
	x[0]=x0;
	
	for (int i=0;i<100;i++){
		x[i+1]=x[i]-calculate(x[i])/derivative(x[i]);
	}
	
	return x[100];
}
int main(){
	//Test all the function
	//Function init
	init_term(0,1);
	init_term(1,3);
	init_term(2,3);
	init_term(3,1);
	init_term(4,2);
	//Function insert
	insert(2,0);
	//Function remove
	remove(4);
	//Function display
	display();
	//Function calculate
	printf("\nResult is %lf ",calculate(4));
	//Function derivative
	printf("\nDerivative at 2 is %lf",derivative(2));
	//Function integral
	printf("\nIntegral of f(x) at 2 points 1 and 2 is %lf",integral(1,2));
	//Function find root
	printf("\nRoot of f(x) = 0 is %lf ",find_root(-0.5));
return 0;
}

