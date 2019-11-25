#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int item[MAX];
    int top;
}Stack;

struct Node{
    int info;
    struct Node *next;
};

typedef struct Node N;

void init(Stack *S){
    S->top = -1;
}

void push(Stack *S, int value){
    if(S->top>=MAX-1){
        return;
    }else{
        S->item[++(S->top)] = value;
    }
}

int pop(Stack *S){
    if(S->top<=-1){
        return -35325432;
    }else{
        return S->item[(S->top)--];
    }
}

N *head=NULL, *tail;

N *getNode(int value){
    N *ptr;
    ptr = (N*)malloc(sizeof(N));
    ptr->info = value;
    ptr->next = NULL;
    return ptr;
}

void create(){
    N *ptr;
    int ch, value;
    do
    {
        printf("Enter value: ");
        scanf("%d",&value);
        ptr=getNode(value);
        if(head==NULL){
            head=ptr;
            tail=ptr;
        }else{
            tail->next = ptr;
            tail = ptr;
        }
        printf("Continue?(1/0) ");
        scanf("%d",&ch);
    } while (ch==1);    
}

void display(){
    N *tmp;
    if(head==NULL)
        return;
    tmp = head;
    while(tmp!=NULL){
        printf("%d",tmp->info);
        if(tmp->next!=NULL){
            printf(", ");
        }
        tmp = tmp->next;
    }
}

void reverse(){
    N *tmp;
    Stack S;
    init(&S);
    tmp = head;
    while(tmp!=NULL){
        push(&S, tmp->info);
        tmp = tmp->next;
        //printf("It's working...\n");
    }
    tmp = head;
    while(S.top!=-1){
        tmp->info = pop(&S);
        tmp = tmp->next;
    }
}

void main(){
    create();
    printf("The linked list: ");
    display();
    printf("\n");
    reverse();
    printf("The reversed linked list: ");
    display();
    printf("\n");
}
