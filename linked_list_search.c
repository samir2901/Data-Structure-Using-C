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

int search(int key){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        if(temp->info == key){
            return 1;
            break;
        }
        temp = temp->next;
    }
    return 0;
}


void main(){
    int key, c;
    printf("\nCreate the linked list\n");
    create();
    printf("\n");
    printf("Enter the value you want to search: ");
    scanf("%d", &key);
    if(search(key)==1){
        printf("\nThe value is present in the list.\n");
    }else{
        printf("\nThe value is not present in the list\n");
    }
    printf("Do you want to see the list?(1/0)");
    scanf("%d",&c);
    if(c==1){
        printf("The linked list is ");
        display();
    }
    printf("\n");
}