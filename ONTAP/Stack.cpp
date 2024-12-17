#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data[100];
	int top;
}Stack;

void initializeStack(Stack* stack){
	stack->top=-1;
}
bool isEmpty(Stack* stack){
	return stack->top==-1;
}
bool isFull(Stack* stack){
	return stack->top==99;
}
void push(Stack* stack,int n){
	if(isFull(stack)){
		return;
	}
	stack->data[++stack->top]=n;
}
void pop(Stack* stack){
	if(isEmpty(stack)){
		return;
	}
	stack->top--;
}
int peek(Stack* stack){
	return stack->data[stack->top];
}
int main(){
	Stack st;
	initializeStack(&st);
	push(&st,1);
}
