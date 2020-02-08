#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node {
	int val;
	struct _node *next;
} node;

node *top = NULL;

void push(int val){
	node *a = (node*) malloc(sizeof(node));
	a->val = val;
	
	a->next = top;
	top = a;
}

int pop(){
	node *p;
	if (top==NULL) return 0;
	
	p = top;
	top = top->next;
	
	return p->val;
	free(p);
}

int postfix(char *exp){
	int i;
	for (i=0; i<strlen(exp);i++){
		if (exp[i]==' ') continue;
		else if (isdigit(exp[i])) {
			int num = 0;
			while (isdigit(exp[i])){
				num = num*10 + (int)(exp[i] - '0');
				i++;
			}
			i--;
			push(num);
		}
		else {
			int val1 = pop();
			int val2 = pop();
			switch (exp[i]){
				case '+': push(val2+val1); break;
				case '-': push(val2-val1); break;
				case '*': push(val2*val1); break;
				case '/': push(val2/val1); break;
			}
			
			}
		}
	return pop();
}

int main(){
	char exp[] = "100 200 + 2 / 5 * 7 +";
	printf("Result is %d",postfix(exp));
	return 0;
}


