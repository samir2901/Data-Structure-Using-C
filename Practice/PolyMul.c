#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef, expo;
    struct Node *next;
};

typedef struct Node N;

N *start1=NULL, *start2=NULL, *tail1, *tail2;

void create(){
    N *ptr;
    int ai, p, c;
    printf("Create First Polynomial....");
    do{
        printf("Enter coefficient: ");
        scanf("%d",&ai);
        printf("Enter exponent: ");
        scanf("%d",&p);
        ptr=(N*)malloc(sizeof(N));
        ptr->coef=ai;
        ptr->expo=p;
        ptr->next=NULL;
        if(start1==NULL){
            start1=ptr;
            tail1=ptr;
        }else{
            tail1->next = ptr;
            tail1 = ptr;
        }
        printf("Continue(1/0)? ");
        scanf("%d",&c);
    }while(c==1);

    printf("Create Second Polynomial....");
    do{
        printf("Enter coefficient: ");
        scanf("%d",&ai);
        printf("Enter exponent: ");
        scanf("%d",&p);
        ptr=(N*)malloc(sizeof(N));
        ptr->coef=ai;
        ptr->expo=p;
        ptr->next=NULL;
        if(start2==NULL){
            start2=ptr;
            tail2=ptr;
        }else{
            tail2->next = ptr;
            tail2 = ptr;
        }
        printf("Continue(1/0)? ");
        scanf("%d",&c);
    }while(c==1);
}


N *start3=NULL, *tail3;

void removeDuplicates(N *start){
    N *i, *j, *store;
    i = start;
    while(i!=NULL&&i->next!=NULL){
        j=i;
        while(j->next!=NULL){
            if(i->expo==(j->next)->expo){
                i->coef = i->coef + (j->next)->coef;
                store = j->next;
                j->next = (j->next)->next;
                free(store);
            }else{
                j=j->next;
            }
        }
        i=i->next;
    }
}

void polyMul(){
    N *i, *j, *ptr;
    i = start1;
    while (i!=NULL){
        j=start2;
        while (j!=NULL){
            ptr = (N*)malloc(sizeof(N));
            ptr->coef = i->coef * j->coef;
            ptr->expo = i->expo + j->expo;
            ptr->next = NULL;
            if(start3==NULL){
                start3=ptr;
                tail3=ptr;
            }else{
                tail3->next=ptr;
                tail3=ptr;
            }
            j=j->next;
        }
        i=i->next;
    }    
    removeDuplicates(start3);
}



void display(){
    N *t;
    t = start1;
    printf("The first polynomial: ");
    while(t!=NULL){
        printf("%dx^%d",t->coef,t->expo);
        if(t->next!=NULL){
            printf("+");
        }
        t=t->next;
    }
    printf("\n");

    t = start2;
    printf("The second polynomial: ");
    while(t!=NULL){
        printf("%dx^%d",t->coef,t->expo);
        if(t->next!=NULL){
            printf("+");
        }
        t=t->next;
    }
    printf("\n");

    t = start3;
    printf("The product of the two polynomials: ");
    while(t!=NULL){
        printf("%dx^%d",t->coef,t->expo);
        if(t->next!=NULL){
            printf("+");
        }
        t=t->next;
    }
    printf("\n");
}


void main(){
    create();
    polyMul();
    display();
}