#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node N;
N *head, *tail, *ptr;
void create(){
    int choice, val;
    do{
        ptr = (N *)malloc(sizeof(N));
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
            printf(",");
        }
        temp = temp->next;
    }
}
void swapData(N *n1, N *n2){
    int t;
    t = n1->info;
    n1->info = n2->info;
    n2->info = t;
}
void sort(){
    N *i, *j;
    if(head==NULL){
        return;
    }else{
        for(i=head;i->next!=NULL;i=i->next){
            for(j=i->next;j!=NULL;j=j->next){
                if(i->info > j->info){
                    swapData(i,j);
                }
            }
        }
    }    
}
