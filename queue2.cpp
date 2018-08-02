/*
queue --> linked list implementation
array has a fix size, but linked list does not have
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//prototyping
void enQ(int x);
int dQ(); //return dQ value
bool isEmpty();
//bool isFull(); you dont need this becasue it is a linked list never full
int atFront();
int atRear();

//you need a node to start with
struct Node{
	int data;
	Node* next;
};

//two pointer point at the front and rear, remember this is not a node, just at pointer
Node* front = NULL;
Node* rear = NULL;

int main(){
	int temp;
	Node* p; //loop thru the linked list

	if(isEmpty())
		cout << "the queue is empty" << endl;
	enQ(1);
	if(isEmpty())
		cout << "the queue is empty" << endl;
	printf("%d\n", atFront());
	printf("%d\n", atRear());
	enQ(2);
	printf("%d\n", atFront());
	printf("%d\n", atRear());
	enQ(3);
	if(isEmpty())
		cout << "the queue is empty" << endl;
	enQ(4);
	temp = dQ();
	printf("%d\n", temp);
	printf("%d\n", atFront());
	enQ(5);
	printf("%d\n", atRear());

	/*
	1. you can assign the address
	2. whatever address contains you can specify by using "->"
	3. to print the element using * sign
	4. a good practice is to use p=p->next since it is a linked list structure, however p++ might work as well
	*/
	p = front;
	while(p->next!=NULL){
		printf("%d\n", *p);
		p=p->next;
		//p++;
	}

}

void enQ(int x){
	//you have to create a node structure
	Node* newNode = new Node();
	newNode -> data = x;
	newNode -> next = NULL;

	if(isEmpty()){
		front = rear = newNode;
		return;
	}
	else{
		//be careful here
		rear -> next = newNode;
		rear = newNode;
		return;
	}
}

int dQ(){
	Node* temp;
	int x; //store the dequeaue element
	if(isEmpty()){
		printf("Sorry the queue is empty, you cannot dequeue\n");
	}
	else if(front == rear){
		x = front -> data;
		front -> data = NULL;
		front -> next = NULL;
		return x;
	}
	else{
		x = front -> data;
		temp = front;
		front = front -> next;
		temp -> data = NULL;
		temp -> next = NULL;
		return x;
	}
}

bool isEmpty(){
	if(front == NULL){
		return true;
	}
	else{
		return false;
	}
}

int atFront(){
	return front -> data;
}

int atRear(){
	return rear -> data;
}



