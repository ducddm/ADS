#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct _valnode {
	double val;
	struct _valnode *next;
} Val_node;

Val_node *top = NULL;

typedef struct _opnode {
	char op;
	struct _opnode *onext;
} Op_node;

Op_node *otop = NULL; 

void push_val(double val){
	Val_node *a = (Val_node*) malloc(sizeof(Val_node));
	a->val = val;
	
	a->next = top;
	top = a;
}

void push_op(char op){
	Op_node *a = (Op_node*) malloc(sizeof(Op_node));
	a->op = op;
	
	a->onext = otop;
	otop = a;
}

double pop_val(){
	Val_node *cr;
	if (top==NULL) return 0;
	
	cr = top;
	top = top->next;
	
	return cr->val;
	free(cr);
}

void pop_op(){
	Op_node *cr;
	if (otop==NULL) return;
	
	cr = otop;
	otop = otop->onext;

}

char head(){
	Op_node *cr;
	cr = otop;
	return cr->op;
}

int prior(char op){
	if (op=='+' || op=='-') return 1;
	if (op=='*' || op=='/') return 2;
	return 0;
}

double applyOp(double a, double b, char op){
	switch (op){
		case '+': return a+b; 
		case '-': return a-b; 
		case '*': return a*b; 
		case '/': return a/b; 
	}
}

double evaluate(char *exp){
	int i;
	for (i=0;i<strlen(exp);i++){
		if (exp[i] ==' ') continue;
		
		else if (exp[i]=='(') {
			push_op(exp[i]);
			
		}
		
		else if (isdigit(exp[i])){
			int num = 0;
			while (isdigit(exp[i])){
				num = num*10 + (int)(exp[i] - '0');
				i++;
			}
			i--;
			push_val(num);
		}
		
		else if (exp[i]=='.'){
			int j=0; double num = pop_val();
			while (isdigit(exp[i+1])){
				num = num + pow(10,j-1)*(int)(exp[i+1] - '0');
				j--;
				i++;
			}
			push_val(num);	
		}
		
		else if (exp[i]==')'){
			while ((otop!=NULL) && (head()!='(')){
				double val2 = pop_val();
				double val1 = pop_val();
				char op = head();
				
				pop_op();
				
				push_val(applyOp(val1,val2,op));
			}
			pop_op();
		}
		
		else {
			
			while ((otop!=NULL) && (prior(head())>=prior(exp[i]))){
				double val2 = pop_val();
				double val1 = pop_val();
				char op = head();
				
				pop_op();
				
				push_val(applyOp(val1,val2,op));
			}
			
			push_op(exp[i]);
		}
	}
	
	while (otop!=NULL){
		double val2 = pop_val();
		double val1 = pop_val();
		char op = head();
		
		pop_op();
		
		
		push_val(applyOp(val1,val2,op));
	}
	
	return pop_val();
}

int main(){
	char exp[]= "(10.55 + 1.7) * (2 + 12) / 14 + 5.555 - 6.6 / 3 ";
	printf("%lf ",evaluate(exp));
	return 0;
}
