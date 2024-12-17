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
    printf("2. Duyet cây theo PreOrder\n");
    printf("3. Duyet cây theo InOrder\n");
    printf("4. Duyet cây theo PostOrder\n");
    printf("5. Tìm kiem phan tu trong cây\n");
    printf("6. Thoát\n");
    printf("Chon chuc nang: ");
}
int main(){
	Node* root=NULL;
	int choice,value;
	do{
	   switch(choice){
	   	 case 1:
	   	 	 printf("Nh?p giá tr? c?n thêm: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Ðã thêm %d vào cây.\n", value);
                break;
         case 2: // Duy?t cây theo PreOrder
                printf("Duy?t cây theo PreOrder: ");
                preOrder(root);
                printf("\n");
                break;

            case 3: // Duy?t cây theo InOrder
                printf("Duy?t cây theo InOrder: ");
                inorder(root);
                printf("\n");
                break;

            case 4: // Duy?t cây theo PostOrder
                printf("Duy?t cây theo PostOrder: ");
                postOrder(root);
                printf("\n");
                break;

            case 5: // Tìm ki?m ph?n t?
                printf("Nh?p giá tr? c?n tìm: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Ph?n t? %d có trong cây.\n", value);
                } else {
                    printf("Ph?n t? %d không có trong cây.\n", value);
                }
                break;
             case 6: // Thoát chuong trình
                printf("Thoát chuong trình.\n");
                break;

	   	 default:
	   	 	 printf("L?a ch?n không h?p l?! Vui lòng th? l?i.\n");
	   }
	}while(choice!=6);
}
