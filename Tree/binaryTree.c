#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *left, *right;
};

typedef struct node N;

N* newNode(int data){
    N *ptr;
    ptr = (N*)malloc(sizeof(N));
    ptr->info = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void preorderTraversal(N *rootNode){
    if(rootNode==NULL){
        return;
    }
    printf("%d ", rootNode->info);
    preorderTraversal(rootNode->left);
    preorderTraversal(rootNode->right);
}

void postorderTraversal(N *rootNode){
    if(rootNode==NULL){
        return;
    }
    postorderTraversal(rootNode->left);
    postorderTraversal(rootNode->right);
    printf("%d ", rootNode->info);
}

void inorderTraversal(N *rootNode){
    if(rootNode==NULL){
        return;
    }
    inorderTraversal(rootNode->left);
    printf("%d ", rootNode->info);
    inorderTraversal(rootNode->right);
}

int treeSize(N *rootNode){
    if(rootNode==NULL)
        return 0;
    return treeSize(rootNode->left) + treeSize(rootNode->right) + 1;
}

