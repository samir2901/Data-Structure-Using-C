#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff, expo;
    struct node *next;
};

typedef struct node N;

N *start1=NULL, *start2=NULL, *start3=NULL, *tail1, *tail2, *tail3;

void create(){
    N *ptr;
    int val, pow, ch;
    printf("Create polynomial one......\n");
    do{
        ptr = (N*)malloc(sizeof(N));
        printf("Enter the coefficient: ");
        scanf("%d",&val);
        printf("Enter the exponent: ");
        scanf("%d", &pow);
        ptr->coeff = val;
        ptr->expo = pow;
        ptr->next = NULL;
        if(start1 == NULL){
            start1 = ptr;
            tail1 = ptr;
        }else{
            tail1->next = ptr;
            tail1 = ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d",&ch);
    }while(ch==1);

    printf("Create polynomial two......\n");
    do{
        ptr = (N*)malloc(sizeof(N));
        printf("Enter the coefficient: ");
        scanf("%d",&val);
        printf("Enter the exponent: ");
        scanf("%d", &pow);
        ptr->coeff = val;
        ptr->expo = pow;
        ptr->next = NULL;
        if(start2 == NULL){
            start2 = ptr;
            tail2 = ptr;
        }else{
            tail2->next = ptr;
            tail2 = ptr;
        }
        printf("Do you want to continue?(1/0) ");
        scanf("%d",&ch);
    }while(ch==1);
}

int len(N *start){
    struct node *temp;
    int c = 0;
    temp = start;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    return c;
}

void removeDuplicates(N *start){
    N *i, *j, *dup;
    i = start;
    while(i!=NULL && i->next!=NULL){
        j = i;
        while(j->next!=NULL){
            if(i->expo == (j->next)->expo){
                i->coeff = i->coeff + (j->next)->coeff;
                dup = j->next;
                j->next = (j->next)->next;
                free(dup);
            }else{
                j=j->next;
            }
        }
        i=i->next;
    }
}




void polyMult(){
    N *tmp1, *tmp2, *ptr;
    if(len(start1) >= len(start2)){
        for(tmp1 = start1; tmp1!=NULL; tmp1=tmp1->next){
            for(tmp2 = start2; tmp2!=NULL; tmp2=tmp2->next){
                ptr = (N*)malloc(sizeof(N));
                ptr->coeff = tmp1->coeff * tmp2->coeff;
                ptr->expo = tmp1->expo + tmp2->expo;
                ptr->next = NULL;
                if(start3==NULL){
                    start3=ptr;
                    tail3=ptr;
                }else{
                    tail3->next=ptr;
                    tail3 = ptr;
                }
            }
        }
    }else{
        for(tmp1 = start2; tmp1!=NULL; tmp1=tmp1->next){
            for(tmp2 = start1; tmp2!=NULL; tmp2=tmp2->next){
                ptr = (N*)malloc(sizeof(N));
                ptr->coeff = tmp1->coeff * tmp2->coeff;
                ptr->expo = tmp1->expo + tmp2->expo;
                ptr->next = NULL;
                if(start3==NULL){
                    start3=ptr;
                    tail3=ptr;
                }else{
                    tail3->next=ptr;
                    tail3 = ptr;
                }
            }
        }   
    }
    removeDuplicates(start3);
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
    printf("The product of the polynomials is: ");
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
    polyMult();
    displayPoly();
    printf("\n");
}
