#include <stdio.h>
#include <stdlib.h>

struct  node
{
    char name[20];
    struct node *next;
};

typedef struct node N;

N *head=NULL, *tail;
int c;

void create(){
    N *ptr;
    int choice;
    do{
        ptr = (N*)malloc(sizeof(N));
        printf("Enter the name of the soldier: ");
        scanf("%s",&ptr->name);
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
            tail = ptr;
        }else{
            tail->next = ptr;
            tail = ptr;
        }
        printf("Want to enter more names?(1/0) ");
        scanf("%d",&choice);
        c++;
    }while(choice==1);
    tail->next = head;
}

void display(){
    N *temp;
    printf("%s\n", head->name);
    temp=head->next;
    while(temp!=head){
        printf("%s\n", temp->name);
        temp=temp->next;
    }
}

void main(){
    int i, n;
    N *temp, *prev, *store;
    create();
    printf("The soldiers are:\n");
    display();
    printf("\n");
    printf("\nEnter the counting number: ");
    scanf("%d",&n);
    temp=head;
    while(c>1){
        for(i=1;i<n;i++){
            prev = temp;
            temp = temp->next;
        }
        printf("Killed Soldier: %s\n", temp->name);
        if(temp==head){
            head=temp->next;
        }else if(temp==tail){
            tail=prev;
        }
        prev->next = temp->next;
        store = temp;
        free(store);
        temp=temp->next;
        c--;
    }
    printf("\nThe survivor is: ");
    display();
    printf("\n");
}















