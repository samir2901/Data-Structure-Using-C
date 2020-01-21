#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *next;
};

typedef struct node N;

N *getNode(int data){
    N *ptr;
    ptr=(N*)malloc(sizeof(N));
    ptr->info=data;
    ptr->next = NULL;
}

void display(N *head){
    N *i;
    i=head;
    while(i!=NULL){
        printf("%d", i->info);
        if(i->next!=NULL){
            printf(", ");
        }
        i=i->next;
    }
    printf("\n");
}

N *merge(N *head1, N *head2){
   N *i;
   if(head1==NULL){
       return head2;
   }
   if(head2==NULL){
       return head1;
   }
   i=head1;
   while(i->next!=NULL){
       i=i->next;
   }
   i->next=head2;
   return head1;
   
}

void main(){
    N *head1=NULL, *tail1, *head2=NULL, *tail2, *ptr;
    int value, ch;        
    printf("Create the first linked list.....\n");
    do{
        printf("Enter the value: ");
        scanf("%d", &value);
        ptr = getNode(value);
        if(head1==NULL){
            head1=ptr;
            tail1=ptr;
        }else{
            tail1->next=ptr;
            tail1=ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d",&ch);
    }while(ch==1);

    printf("Create the second linked list.....\n");
    do{
        printf("Enter the value: ");
        scanf("%d", &value);
        ptr = getNode(value);
        if(head2==NULL){
            head2=ptr;
            tail2=ptr;
        }else{
            tail2->next=ptr;
            tail2=ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d",&ch);
    }while(ch==1);
    printf("The first linked list is: ");
    display(head1);
    printf("The second linked list is: ");
    display(head2);
    head1=merge(head1, head2); //merges head2 to head1
    printf("The merged linked list is: ");
    display(head1);
}