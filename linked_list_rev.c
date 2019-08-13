#include <stdio.h>
#include <stdlib.h>
struct  node
{
    int info;
    struct node *next;
}*head,*tail,*ptr;

void create(){
    int choice, val;
    do{
        ptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&val);
        ptr->info = val;
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
            tail = ptr;
        }else{
            tail->next = ptr;
            tail = ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d",&choice);
    }while(choice==1);
}

void display(){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d, ",temp->info);
        temp = temp->next;
    }
}

void reverse(){
    struct node *current, *next, *prev=NULL;
    current = head;
    while (current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    tail = head;
    head = prev;
}


void main(){
    create();
    printf("\nThe linked list: ");
    display();
    reverse();
    printf("\nThe linked list after reversal: ");
    display();
    printf("\n");
}
