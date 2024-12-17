#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

//ham tao note moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	return newNode;
}
//them phan tu dau danh sach
void insertToHead(Node** head,int n){
	Node* newNode=createNode(n);
    	newNode->next=*head;
		*head=newNode;	
}
//them phan tu vao cuoi danh sach
void insertToTail(Node** head,int n){
	Node* newNode=createNode(n);
	if(*head==NULL){
		*head->next=newNode;
		return;
	}
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=newNode;
}
//xoa phan tu dau danh sach
void removeAtHead(Node** head){
	if(*head==NULL){
		return;
	}
	Node* tmp=*head;
	*head=(*head)->next;
	free(tmp);
}
//xoa phan tu cuoi danh sach
void removeAtTail(Node** head){
	if(*head==NULL){
		return;
	}
	Node* tmp=*head;
	while(tmp->next->next!=NULL){
		tmp=tmp->next;
	}
	free(tmp->next);
    tmp->next=NULL;
}
//in danh sach
void printList(Node** head){
	Node* tmp=*head;
	while(tmp!=NULL){
		printf("%d->",tmp->data);
	}
	printf("NULL");
}
//tim kiem 
void search(Node** head, int n){
	Node* tmp=*head;
	while(tmp!=NULL){
		if(tmp->data==n){
		    printf("Tim thay gia tri");
			return;	
		}
	}
	printf("Khong tim thay gia tri");
}
int main(){
	Node* head=NULL;
	insertToTail(&head,3);
	insertToTail(&head,4);
	insertToTail(&head,5);
}
