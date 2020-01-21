#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node N;

N *getNode(int data){
    N *ptr;
    ptr=(N*)malloc(sizeof(N));
    ptr->info=data;
    ptr->next=NULL;
    return ptr;
}

int length(N *start){
    N *i;
    int c=0;
    for(i=start;i!=NULL;i=i->next){
        c++;
    }
    return c;
}

void display(N *start){
    N *i;
    i=start;
    while(i!=NULL){
        printf("%d", i->info);
        if(i->next!=NULL){
            printf(", ");
        }
        i=i->next;
    }
    printf("\n");
}

void main(){
    N *root=NULL, *tail, *ptr;
    int value, ch;        
    do{
        printf("Enter the value: ");
        scanf("%d", &value);
        ptr = getNode(value);
        if(root==NULL){
            root=ptr;
            tail=ptr;
        }else{
            tail->next=ptr;
            tail=ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d",&ch);
    }while(ch==1);
    display(root);
    printf("The number of elements are: %d\n", length(root));
}

