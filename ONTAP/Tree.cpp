#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//ham tao node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
//them node moi vao cay nhi phan thuong
Node* insert(Node* root,int n){
	Node* newNode=createNode(n);
	if(root==NULL){
		return newNode;
	}
	if(root->left==NULL){
		root->left=newNode;
	}else if(root->right==NULL){
		root->right=newNode;
	}else{
		root->left=insert(root->left,n);
	}
	return root;
}
//them node moi vao cay nhi phan tim kiem
Node* insertNode(Node* root,int n){
	if(root==NULL){
		return createNode(n);
	}
	if(root->data>n){
		root->left=insertNode(root->left,n);
	}
	if(root->data<n){
		root->right=insertNode(root->right,n);
	}
	return root;
}
//duyet truoc
void preOrder(Node* root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}
//duyet giua
void inorder(Node* root){
	if(root==NULL){
		return;
	}
	preOrder(root->left);
	printf("%d ",root->data);
	preOrder(root->right);
}
//duyet sau
void postOrder(Node* root){
	if(root==NULL){
		return;
	}
	preOrder(root->left);
	
	preOrder(root->right);
	printf("%d ",root->data);
}
//tim kiem
bool search(Node* root,int n){
	 if (root == NULL) {
        return false; 
    }
	if(root->data==n){
		return true;
	}
	if(search(root->left,n)){
		return true;
	}
	if(search(root->right,n)){
		return true;
	}
	return false;
}
void menu(){
	printf("Chon menu\n");
	printf("1.Them nut\n");
    printf("2. Duyet c�y theo PreOrder\n");
    printf("3. Duyet c�y theo InOrder\n");
    printf("4. Duyet c�y theo PostOrder\n");
    printf("5. T�m kiem phan tu trong c�y\n");
    printf("6. Tho�t\n");
    printf("Chon chuc nang: ");
}
int main(){
	Node* root=NULL;
	int choice,value;
	do{
	   switch(choice){
	   	 case 1:
	   	 	 printf("Nh?p gi� tr? c?n th�m: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("�� th�m %d v�o c�y.\n", value);
                break;
         case 2: // Duy?t c�y theo PreOrder
                printf("Duy?t c�y theo PreOrder: ");
                preOrder(root);
                printf("\n");
                break;

            case 3: // Duy?t c�y theo InOrder
                printf("Duy?t c�y theo InOrder: ");
                inorder(root);
                printf("\n");
                break;

            case 4: // Duy?t c�y theo PostOrder
                printf("Duy?t c�y theo PostOrder: ");
                postOrder(root);
                printf("\n");
                break;

            case 5: // T�m ki?m ph?n t?
                printf("Nh?p gi� tr? c?n t�m: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Ph?n t? %d c� trong c�y.\n", value);
                } else {
                    printf("Ph?n t? %d kh�ng c� trong c�y.\n", value);
                }
                break;
             case 6: // Tho�t chuong tr�nh
                printf("Tho�t chuong tr�nh.\n");
                break;

	   	 default:
	   	 	 printf("L?a ch?n kh�ng h?p l?! Vui l�ng th? l?i.\n");
	   }
	}while(choice!=6);
}
