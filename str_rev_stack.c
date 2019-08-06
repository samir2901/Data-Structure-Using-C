#include <stdio.h>
#define MAX 20

typedef struct{
    char item[MAX];
    int top;
}Stack;

void init(Stack *S){
    S->top = -1;
}

void push(Stack *S, char x){
    if(S->top >= MAX-1){
        printf("Stack is full");
    }else{
        S->item[++S->top] = x;
    }
}

char pop(Stack *S){
    if(S->top <= -1){
		printf("Empty");
	}else{
		return S->item[S->top--];
	}
}

void main(){
    Stack s;
    int i;
    char str[5]="hello";
    init(&s);
   
    for(i=0;i<5;i++){
        push(&s, str[i]);
    }
    printf("Original String: %s\n",str);
    printf("Reversed String: ");
    
    for(int i=s.top;i>=0;i--){
        printf("%c",pop(&s));
    }
    printf("\n");
}
