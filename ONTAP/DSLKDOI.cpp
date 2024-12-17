#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* previous;
}Node;

Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	newNode->previous=NULL;
	return newNode;
}
//them phan tu dau danh sach
void insertToHead(Node** head,int n){
	Node* newNode=createNode(n);
	newNode->next=*head;
	*head=newNode;
}
//them phan tu cuoi danh sach
void insertToTail(Node** head,int n){
	Node* newNode=createNode(n);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->previous=tmp;
}
//xoa node o dau danh sach
void deleteAtHead(Node** head){
	Node* tmp=*head;
	(*head)->next->previous=NULL;
	*head=(*head)->next;
	free(tmp);
}
//xoa node cuoi danh sach
void deleteAtTail(Node** head){
	Node* tmp=*head;
	while(tmp->next->next!=NULL){
		tmp=tmp->next;
	}
	free(tmp->next);
	tmp->next=NULL;
}
//xoa node o vi tri bat ky
void deleteAtPosition(Node** head,int p){
	if(p==0){
		deleteAtHead(head);
		return;
	}
	Node* tmp=*head;
	//duyet den vi tri truoc vi tri can xoa
	for(int i=0;i<p-1&&tmp!=NULL;i++){
		tmp=tmp->next;
	}
	if(tmp==NULL){
		printf("Error");
		return;
	}
	Node* x=tmp->next->next;
    free(tmp->next);
    tmp->next=x;
    if(x!=NULL){
    	x->previous=tmp;
	}
}
//duyet danh sach tu dau den cuoi
void print(Node** head){
	Node* tmp=*head;
	while(tmp!=NULL){
		printf("%d->",tmp->data);
		tmp=tmp->next;
	}
	printf("NULL");
}
//duyet danh sach tu cuoi len dau
void printReverse(Node** head){
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	while(tmp!=NULL){
		printf("%d->",tmp->data);
		tmp=tmp->previous;
	}
}
int main(){
	Node* head=NULL;
}
