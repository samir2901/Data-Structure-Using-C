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

void insert(int pos, int value){
    int i;
    struct node *temp, *store;
    temp = head;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(pos==1){
        ptr->info=value;
        ptr->next=head;
        head = ptr;
    }else{
        for(i=1;i<pos-1;i++){
            temp=temp->next;
        }
        store = temp->next;
        ptr->info = value;
        temp->next = ptr;
        ptr->next = store;
    }
}

void append(int value){
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->info = value;
    tail->next = ptr;
    ptr->next = NULL;
    tail = ptr;
}


void display(){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d, ",temp->info);
        temp = temp->next;
    }
}

void main(){
    int option, pos, val, ch;
    printf("Create the linked list.........\n");
    create();
    do{
        printf("Enter 1 to insert into the list.\nEnter 2 to append(i.e. insert at the end) into the list.\nEnter 3 to display the list.\nEnter choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the position for insertion: ");
            scanf("%d", &pos);
            printf("Enter the data for insertion: ");
            scanf("%d", &val);
            insert(pos, val);
            break;
        case 2:
            printf("Enter the value to append: ");
            scanf("%d", &val);
            append(val);
            break;
        case 3:
            printf("\nThe linked list is: ");
            display();
            printf("\n");
            break;
        default:
            printf("\nInvalid Option\n");
            break;
        }
        printf("Continue(1/0)?");
        scanf("%d", &ch);
    }while(ch==1);
}