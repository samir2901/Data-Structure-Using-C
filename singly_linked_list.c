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

void delete(int pos){
    struct node *temp, *t;
    int i;
    temp=head;
    if(head==NULL){
        printf("\nEmpty\n");
    }else{
        if(pos==1){
            head=head->next;
            temp->next=NULL;
            free(temp);
        }else{
            for(i=1;i<pos-1;i++){
                temp=temp->next;
            }
            t = temp->next;
            temp->next=(temp->next)->next;
            free(t);
        }
    }
}

void pop(){
    struct node *temp, *t;
    if(head == NULL){
        printf("\nEmpty\n");
    }else{
        temp = head;
        while (temp->next!=tail)
        {
            temp = temp->next;
        }
        t = temp->next;
        temp->next = NULL;
        tail = temp;
        free(t);       
    }
    
    
}


void main(){
    int option, pos, val, ch;
    printf("Create the linked list.........\n");
    create();
    do{
        printf("Enter 1 to insert into the list.\nEnter 2 to append(i.e. insert at the end) into the list.\nEnter 3 to delete a data from the list.\nEnter 4 to delete from the end of the list.\nEnter 5 to display the list.\nEnter choice: ");
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
            printf("\nEnter the position for deletion: ");
            scanf("%d", &pos);
            delete(pos);            
            break;
        case 4:
            pop();
            break;
        case 5:
            printf("\nThe linked list is: ");
            display();
            printf("\n");
            break;
        default:
            printf("\nInvalid Option\n");
            break;
        }
        printf("\nContinue(1/0)? ");
        scanf("%d", &ch);
    }while(ch==1);
}
