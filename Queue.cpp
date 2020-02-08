#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _pass {
	int age;
	struct _pass* next;
} pass;

pass* front = NULL;
pass* back = NULL; 


void Enqueue(int a) {
	printf("One person arrive. Age is %d\n", a);
	pass* p = (pass*)malloc(sizeof(pass));
	p->age=a;
	p->next = NULL; 
	if(front == NULL && back == NULL){
		front = back = p;
		return;
	}
	back->next = p; 
	back = p; 
}

// Only the first person in the queue can enter at a time
void Dequeue() {
	printf("One person enters ");
	pass* p = front; // create temp to store front to free later
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == back) {
		front = back = NULL;
	}
	else {
		front = front->next;
	}
	free(p); // free the old front
}

void Print(){ // just like print in Linked List
	pass* temp = front;
	printf("Current Queue: ");
	while(temp != NULL) {
		printf("%d ",temp->age);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	Enqueue(9);
	Enqueue(10);
	Enqueue(45);
	Enqueue(65);
	Print();
	Dequeue();
	Dequeue();
	Print();
	Enqueue(55);
	Enqueue(60);
	Print();
	
	
	return 0;
}
