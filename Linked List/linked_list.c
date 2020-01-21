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
    ptr->next=NULL;
    return ptr;
}

void display(N *head){
    N *i;
    i=head;
    if(head==NULL)
        return;
    while(i!=NULL){
        printf("%d",i->info);
        if(i->next!=NULL){
            printf(", ");
        }
        i=i->next;
    }
    printf("\n");
}

N *insert(N *head, int data, int index){
    N *t, *ptr, *store;
    int i;
    ptr=getNode(data);
    if(index=0){        
        ptr->next=head;
        head=ptr;
        return head;
    }else{
        t=head;
        for(i=0;i<=index-1;i++){
            t=t->next;
        }
        store=t->next;
        t->next=ptr;
        ptr->next=store;
        return head;        
    }
}

N *append(N *head, int data){
    N *ptr, *i;
    ptr = getNode(data);
    i=head;
    while(i->next!=NULL){
        i=i->next;
    }    
    i->next=ptr;
    return head;
}

int length(N *head){
    int c=0;
    N *t;
    t = head;
    while (t!=NULL)
    {
        c++;
        t=t->next;
    }
    return c;    
}

