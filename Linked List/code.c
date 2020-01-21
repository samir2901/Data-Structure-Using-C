#include "linked_list.h"
#include "linked_list.c"

void main(){
    N *root=NULL;
    root=getNode(12);
    printf("The linked list is: ");
    display(root);
    printf("The length of list is: %d\n", length(root));
    root=append(root, 20);
    printf("The linked list after insertion is: ");
    display(root);
    printf("The length of list is: %d\n", length(root));
}