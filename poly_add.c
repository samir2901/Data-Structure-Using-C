#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff, expo;
    struct node *next;
};

typedef struct node N;
N *start1=NULL, *tail1, *start2=NULL, *tail2, *start3=NULL, *tail3, *ptr;

void create(){
    int c, pow, choice;
    
    printf("Create the first polynomial.........\n");
    do{
        ptr = (N *)malloc(sizeof(N));
        printf("Enter the value of the coefficient: ");
        scanf("%d", &c);
        printf("Enter the value of the exponent: ");
        scanf("%d", &pow);
        ptr->coeff = c;
        ptr->expo = pow;
        if(start1==NULL){
            start1 = ptr;
            tail1 = ptr;
        }else{
            tail1->next = ptr;
            tail1 = ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d", &choice);
    }while (choice==1); 
    tail1->next=NULL;

    printf("Create the second polynomial.........\n");
    do{
        ptr = (N *)malloc(sizeof(N));
        printf("Enter the value of the coefficient: ");
        scanf("%d", &c);
        printf("Enter the value of the exponent: ");
        scanf("%d", &pow);
        ptr->coeff = c;
        ptr->expo = pow;
        
        if(start2==NULL){
            start2 = ptr;
            tail2 = ptr;
        }else{
            tail2->next = ptr;
            tail2 = ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d", &choice);
    }while (choice==1);  
    tail2->next=NULL;
}


void addPoly(){
    N *temp1, *temp2, *ptr;
    temp1 = start1;
    temp2 = start2;
    while (temp1!=NULL || temp2!=NULL)
    {
        ptr = (N *)malloc(sizeof(N));
        if(temp1==NULL || temp2->expo > temp1->expo){
            ptr->coeff = temp2->coeff;
            ptr->expo = temp2->expo;
            temp2 = temp2->next; 
        }else if(temp2==NULL || temp1->expo > temp1->expo){
            ptr->coeff = temp1->coeff;
            ptr->expo = temp1->expo;
            temp1 = temp1->next;
        }else if(temp1->expo == temp2->expo){
            ptr->coeff = temp1->coeff + temp1->coeff;
            ptr->expo = temp1->expo;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        if(start3==NULL){
            start3=ptr;
            tail3=ptr;
        }else{
            tail3->next=ptr;
            tail3 = ptr;
        }        
    }
    tail3->next=NULL;    
}



void displayPoly(){
    N *temp;
    temp = start1;
    printf("The first polynomial is: ");
    while(temp!=NULL){
        printf("%d(x^%d)", temp->coeff, temp->expo);
        if(temp->next!=NULL){
            printf("+");
        }
        temp = temp->next;                
    }
    printf("\n");
    temp = start2;
    printf("The second polynomial is: ");
    while(temp!=NULL){
        printf("%d(x^%d)", temp->coeff, temp->expo);
        if(temp->next!=NULL){
            printf("+");
        }
        temp = temp->next;                
    }
    printf("\n");
    temp = start3;
    printf("The sum of the polynomials is: ");
    while(temp!=NULL){
        printf("%d(x^%d)", temp->coeff, temp->expo);
        if(temp->next!=NULL){
            printf("+");
        }
        temp = temp->next;                
    }
    printf("\n");
}



void main(){
    create();
    addPoly();
    displayPoly();
}