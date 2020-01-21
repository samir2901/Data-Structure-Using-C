//This is the main file where the functions are called.
#include "doubly_ll.h"
#include "doubly_ll.c"

void main(){
    int val, pos, op, ch;
    printf("Create the linked list....\n");
    create();
    do{
        printf("(Position 0 denotes the start)\nEnter 1 to insert at begin.\nEnter 2 to insert at the end.\nEnter 3 to insert at any middle position.\nEnter 4 to display the list.\nEnter option: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert(0, val);
            break;
        case 2:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insertatEnd(val);
            break;
        case 3:
            printf("Enter the postion: ");
            scanf("%d", &pos);
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert(pos, val);
            break;
        case 4:
            printf("The linked list: ");
            display();
            printf("\n");
            break;
        default:
            printf("Invalid option!!!");
            break;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d", &ch);
    }while(ch==1);
}
