#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	int index;
	int ele;
	struct _node *next;
} node;
node *head=NULL;
node *last=NULL;

int total=0;

void init_node(int i, int data){
	node *new_node=(node *) malloc (sizeof(new_node));
	new_node->index=i;
	new_node->ele=data;
	
	new_node->next=NULL;
	if (head==NULL){
		head=new_node;
		last=new_node;
	}
	else {
		last->next=new_node;
		last=new_node;
	}
}

void display(){
	node *current = head;
	while (current!=NULL){
		printf("%d ",current->ele);
		current= current->next;
	}
}

void sum(node *current,int i){
	if (i>6) return;
	else {
		total = total + current->ele;
	}
	sum(current->next,i+1);
}

int main(){
	init_node(1,10);
	init_node(2,6);
	init_node(3,7);
	init_node(4,9);
	init_node(5,8);
	init_node(6,11);
	display();
	sum(head,head->index);
	printf("\nSum is %d",total);
	return 0;
}	

