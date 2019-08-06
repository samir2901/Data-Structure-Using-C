#include <stdio.h>
#define MAX 20

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
	if(S->top <= -1){
		printf("Empty\n");
	}else{
		return (S->item[S->top--]);
	}
}

void main(){
    int i;
    Stack s1, s2;
    int arr[5] = {10,50,30,20,40};
    printf("Original Array: ");
    for(i=0;i<5;i++){
    	printf("%d, ",arr[i]);
    }
    
    initialise(&s1);
    initialise(&s2);
    push(&s1, arr[0]);
    for(i=1;i<5;i++){
        while(arr[i]>s1.item[s1.top]){
            push(&s2, pop(&s1));
        }
        push(&s1, arr[i]);
        while (s2.top > -1)
        {
            push(&s1, pop(&s2));
        }        
    }
    printf("\nSorted Array: ");
    for(i=4;i>=0;i--){
        printf("%d, ",s1.item[i]);
    }
    printf("\n");
}
