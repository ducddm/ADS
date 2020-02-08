#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int val;
	struct _node *pnext;
} Node ;

Node *pHead=NULL;

void initNode(int val){
	Node *newNode = (Node*) malloc(sizeof(newNode));
	newNode->val=val;
	newNode->pnext=pHead;
	pHead = newNode;
}

int check_prime_number(int nom){
	int count=0;
	for (int i=1;i<=nom;i++){
		if (nom%i==0) count++;
	}
	if (count==2) return 1; else return 0;
}

void prime_factorization(int N){
	int j;
	while (N!=1){
		for (int i=1;i<=N;i++){
			if ((N%i==0) && (check_prime_number(i))){
				j=i;
				initNode(j);
				break;
			}
		}
		N=N/j;
	}
}

void display(){
	Node *current=pHead;
	while (current!=NULL){
		printf("%d ",current->val);
		current = current->pnext;
	}
}

int main(){
	int n;
	printf("Enter an integer "); scanf("%d",&n);
	prime_factorization(n);
	display();
	return 0;
}

//There is 1 loop at the check_prime_number function and 2 loops at the prime_factorization function, so the complexity is O(n^2)
