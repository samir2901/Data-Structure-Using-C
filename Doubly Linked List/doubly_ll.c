//This file contains the function definitions.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
};

typedef struct node N;

N *start=NULL, *tail;

void create(){
    N *ptr;
    int x, ch;
    do{
        ptr = (N*)malloc(sizeof(N));
        printf("Enter the data: ");
        scanf("%d", &x);
        ptr->info = x;
        ptr->next = NULL;
        ptr->prev = NULL;
        if(start == NULL){
            start = ptr;
            tail = ptr;
        }else{
            tail->next = ptr;
            ptr->prev = tail;
            tail = ptr;
        }
        printf("Do you want to continue?(1/0)");
        scanf("%d", &ch);
    }while(ch == 1);
}

void display(){
    N *tmp;
    tmp = start;
    while(tmp!=NULL){
        printf("%d", tmp->info);
        if(tmp->next!=NULL){
            printf(",");
        }
        tmp = tmp->next;
    }
}

void insert(int pos, int value){
    N *ptr, *tmp;
    int i;
    tmp=start;
    ptr = (N*)malloc(sizeof(N));
    ptr->info = value;
    if(pos==0){
        start->prev = ptr;
        ptr->next = start;
        start = ptr;
    }else{
        for(i=0;i<pos-1;i++){
            tmp = tmp->next;
        }
        ptr->prev = tmp;
        ptr->next = tmp->next;
        tmp->next = ptr;
    }
}

void insertatEnd(int value){
    N *ptr;
    ptr = (N*)malloc(sizeof(N));
    ptr->info = value;
    tail->next = ptr;
    ptr->prev = tail;
    ptr->next = NULL;
    tail = ptr;
}
