/*This file contains the functions for the
the linked list*/


#include <stdio.h>
#include <stdlib.h>

struct  node
{
    int info;
    struct node *next;
};

typedef struct node N;
N *head=NULL, *tail, *ptr;

void create(){
    int choice, val;
    do{
        ptr = (N*)malloc(sizeof(N));
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
    N *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d",temp->info);
        if(temp->next!=NULL){
            printf(", ");
        }
        temp = temp->next;
    }
}

void reverse(){
    N *current, *next, *prev=NULL;
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
