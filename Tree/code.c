#include <stdio.h>
#include "binaryTree.h"
#include "binaryTree.c"

void main(){
    //creating tree
    N *root1;
    root1 = newNode(2);
    root1->left = newNode(3);
    root1->right = newNode(4);
    (root1->left)->left = newNode(5);

    /*
         2
        / \
       3   4
      /
     5
     This is the tree
    */

   printf("The preorder traversal: ");
   preorderTraversal(root1);
   printf("\n");

   printf("The postorder traversal: ");
   postorderTraversal(root1);
   printf("\n");

   printf("The inorder traversal: ");
   inorderTraversal(root1);
   printf("\n");

   printf("The size of the tree: %d", treeSize(root1));
   printf("\n");

}