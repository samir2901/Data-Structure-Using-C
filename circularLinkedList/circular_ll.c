#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node N;

N *head=NULL, *tail;

void create(){
    N *ptr;
    int ch, value;
    do{
        ptr = (N*)malloc(sizeof(N));
        printf("Enter a data: ");
        scanf("%d", &value);
        ptr->data = value;
        ptr->next = NULL;
        if(head==NULL){
            head = ptr;
            tail = ptr;
        }else{
            tail->next = ptr;
            tail = ptr;
            tail->next = head;            
        }
        printf("Continue?(1/0) ");
        scanf("%d", &ch);
    }while(ch==1);
}

void display(){
    N *tmp;
    tmp = head;
    while(tmp->next!=head){
        printf("%d, ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d", tmp->data);
}