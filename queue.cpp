/*
Queue (array implementation with circular array)
basic operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define N 10 //arrray length
using namespace std;

//empyt queue index
int front = -1;
int rear = -1;
int A[N];

bool isEmpty();
bool isFull();
void enQ(int x);
int dQ(); // return the dequeue elements
int atFront();
int atRear();

int main(){
	int temp;
	if(isEmpty()){
		cout << "the queue is empty" << endl;
	}
		
	enQ(1);
	enQ(2);
	if(isEmpty()){
		cout << "the queue is empty" << endl;
	}
	enQ(3);
	printf("%d\n", atRear());
	enQ(4);
	enQ(5);
	if(isFull()){
		cout << "the queue is full" << endl;
	}
	enQ(6);
	printf("%d\n", atRear());
	enQ(7);
	enQ(8);
	printf("%d\n", atFront());
	enQ(9);
	enQ(10);
	if(isFull()){
		cout << "the queue is full" << endl;
	}

	temp = dQ();
	cout << temp << endl;
	printf("%d\n", atFront());
	dQ();
	dQ();
	dQ();
	dQ();
	printf("%d\n", atFront());
	dQ();
	dQ();
	dQ();
	dQ();
	dQ();
	dQ();// the extra one
	if(isEmpty()){
		cout << "the queue is now Empty" << endl;
	}
}

bool isEmpty(){
	if(front == -1 && rear == -1){
		return true;
	}else{
		return false;
	}
}
//using circular array
bool isFull(){
	if((rear+1)%N == front){
		return true;
	}
	else{
		return false;
	}	
}

void enQ(int x){
	if(isFull()){
		return;
	}
	else if(isEmpty()){
		front = 0;
		rear = 0;
		A[rear] = x;
	}
	else{
		rear = (rear + 1)%N;
		A[rear] = x;
	}
}

int dQ(){
	if(isEmpty()){
		printf("Sorry the queue is empty, you cannot dequeue\n");
		return 0;
	}		
	else if(front == rear){
		int x = front;
		front = -1;
		rear = -1;
		return A[front];
	}
	else{
		int y = front;
		front = (front + 1)%N;
		return A[y];
	}
}

int atFront(){
	return A[front];
}

int atRear(){
	return A[rear];
}


