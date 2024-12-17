#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Queue{
	Node* front;
	Node* rear;
} Queue;
//khoi tao hang doi
Queue* initializeQueue(){
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->front=NULL;
	q->rear=NULL;
	return q;
}
//kiem tra hang doi rong
bool isEmpty(Queue* q){
	return q->front==NULL;
}
//them phan tu vao hang doi
void enqueue(Queue* q,int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	if(q->rear==NULL){
		q->front=q->rear=newNode;
		return;
	}
	q->rear->next=newNode;
	q->rear=newNode;
}
//xoa phan tu khoi hang doi
void dequeue(Queue* q){
	if(isEmpty(q)){
		return;
	}
	Node* tmp=q->front;
	q->front=q->front->next;
		if(q->front==NULL){
		q->rear=NULL;
	}
	free(tmp);
}
//xem phan tu dau hang doi
int peek(Queue* q){
	return q->front->data;
}
//in phan tu hang doi
void print(Queue* q){
	Node* tmp=q->front;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
}
int main(){
	Queue* q=initializeQueue();
	 enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
}
