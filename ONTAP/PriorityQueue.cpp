#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	int priority;
}Node;
typedef struct PriorityQueue{
	Node* head;
}PriorityQueue;
//khoi tao hang doi
void createQueue(PriorityQueue* q){
	q->head=NULL;
}
//kiem tra hang doi co rong khong
bool isEmpty(PriorityQueue* q){
	return q->head==NULL;
}
//them phan tu vao hang doi
void enqueue(PriorityQueue* q,int n,int p){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	newNode->priority=p;
	if(q->head==NULL){
		q->head=newNode;
		return;
	}
	//tim vi tri truoc priority
    Node* tmp=q->head;
    if(p<tmp->priority){
    	newNode->next=tmp;
    	q->head=newNode;
    	return;
	}
    while(tmp->next!=NULL&&tmp->next->priority<p){
    	tmp=tmp->next;
	}
	newNode->next=tmp->next;
	tmp->next=newNode;
}
//lay phan tu dau hang doi
void dequeue(PriorityQueue* q){
	Node* tmp=q->head;
	q->head=tmp->next;
	free(tmp);
}
void print(PriorityQueue *q){
	Node* tmp=q->head;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}
int main(){
	PriorityQueue q;
	createQueue(&q);
	enqueue(&q,10,1);
	print(&q);
	enqueue(&q,12,2);
	print(&q);
//	printf("Lay ra phan tu :%d\n",dequeue(&q));
//	print(&q);
	enqueue(&q,4,3);
	print(&q);
//	printf("Lay ra phan tu :%d\n",dequeue(&q));
//	print(&q);
}
