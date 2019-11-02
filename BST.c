#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

typedef struct node N;
N *root=NULL;

N *getNode(int x){
	N *ptr = (N*)malloc(sizeof(N));
	ptr->data = x;
	ptr->left = ptr->right = NULL;
	return ptr;
}

N *insert(N *ptr, int value){
	if(ptr==NULL){
		return getNode(value);
	}
	if(value < ptr->data){
		ptr->left = insert(ptr->left, value);
	}else if(value > ptr->data){
		ptr->right = insert(ptr->right, value);
	}
	return ptr;
}


void create(){
	int value, ch;
	printf("Enter the data for root: ");
	scanf("%d", &value);
	root = insert(root, value);
	do{
		printf("Enter the data: ");
		scanf("%d", &value);
		insert(root, value);
		printf("Continue(1/0)? ");
		scanf("%d", &ch);
	}while(ch==1);
}

N *minNode(N *root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

N *deleteNode(N *root, int key){
	N *tmp;
	if(root==NULL){
		return root;
	}
	if(root->data > key){
		root->left = deleteNode(root->left, key);
	}else if(root->data < key){
		root->right = deleteNode(root->right, key);
	}else{
		if(root->left==NULL && root->right==NULL){
			free(root);
			root=NULL;			
		}else if(root->left==NULL){
			tmp = root;
			root = root->right;
			free(tmp);			
		}else if(root->right==NULL){
			tmp = root;
			root = root->left;
			free(tmp);			
		}else{
			tmp = minNode(root->right);
			root->data = tmp->data;
			root->right=deleteNode(root->right, tmp->data);	
		}		
	}
	return root;	
}


void inorderTraversal(N *root){
	if(root!=NULL){		
		inorderTraversal(root->left);
		printf("%d  ", root->data);
		inorderTraversal(root->right);
	}
}

void preorderTraversal(N *root){
	if(root!=NULL){		
		printf("%d  ", root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}


void postorderTraversal(N *root){
	if(root!=NULL){		
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d  ", root->data);
	}
}

int searchBST(N *root, int key){
	if(root==NULL){
		return 0;
	}else if(root->data == key){
		return 1;
	}else if(root->data > key){
		searchBST(root->left, key);
	}else if(root->data < key){
		searchBST(root->right, key);
	}
}



void main(){	
	printf("Create the tree first.....\n");
	create(root);		
	int op, c, key;
	do{
		printf("Enter 1 to display tree in inorder traversal.\nEnter 2 to display tree in postorder traversal.\nEnter 3 to display tree in preorder traversal.\nEnter 4 to search an element.\nEnter 5 to delete a node. \nEnter option: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Inorder Traversal: ");
				inorderTraversal(root);
				printf("\n");
				break;
			case 2:
				printf("Postorder Traversal: ");
				postorderTraversal(root);
				printf("\n");
				break;
			case 3:
				printf("Preorder Traversal: ");	
				preorderTraversal(root);	
				printf("\n");
				break;
			case 4:
				printf("Enter the element to be searched: ");
				scanf("%d", &key);
				if(searchBST(root, key)==1){
					printf("Element Found.\n");
				}else{
					printf("Element Not Found.\n");
				}
				break;
			case 5:
				printf("Enter the element to be deleted: ");
				scanf("%d", &key);
				deleteNode(root, key);
				printf("Element is deleted\n");
				break;
			default:
				printf("Invalid\n");
				break;				
		}
		printf("Continue(1/0)? ");
		scanf("%d", &c);
	}while(c==1);
}
	

