// This is the main file where the functions are called.

#include "linked_list.h"
#include "linked_list.c"

void main(){
    create();
    printf("\nThe linked list: ");
    display();
    reverse();
    printf("\nThe linked list after reversal: ");
    display();
    printf("\n");
}
