#include <stdio.h>
#define MAX 5

typedef struct{
	int item[MAX];
	int top;
}Stack;

void initialise(Stack *S){
	S->top = -1;
}

void push(Stack *S, int num){
	if(S->top >= MAX-1){
		printf("Overflow\n");
	}else{
		S->item[++S->top] = num;
	}
}

int pop(Stack *S){
	int c;
	if(S->top <= -1)
		return -444546;
	return S->item[S->top--];
}

void display(Stack *S){
	int i;
	if(S->top <= -1){
		printf("Stack is empty\n");
	}else{
		printf("\nThe Elements in the stack are: ");
		for(i=S->top;i>=0;i--){
			printf("%d, ",S->item[i]);
		}
	}
}

void main(){
    Stack S;
    initialise(&S);
    push(&S,20);
    push(&S,30);
    push(&S,40);
    display(&S);
    printf("\nPopped Element: %d",pop(&S));
}