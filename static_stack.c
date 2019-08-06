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
	if(S->top <= -1)
		return 0;
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
	int n,x,choice;
	Stack S;
	initialise(&S);
	do{
		printf("\nEnter 1 to push into stack.\nEnter 2 to pop from stack.\nEnter 3 to display the stack.\nEnter the choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter a number into insert into stack: ");
				scanf("%d",&n);
				push(&S,n);
				break;
			case 2:
				printf("\nThe deleted element is : %d\n",pop(&S));				
				break;
			case 3:
				display(&S);
				break;		
			default:
				printf("\nInvalid Choice\n");
		}
		printf("\n");
		printf("Continue?(1/0) ");
		scanf("%d",&x);
	}while(x==1);
}