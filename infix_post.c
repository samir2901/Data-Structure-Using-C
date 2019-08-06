#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

typedef struct{
	char item[MAX];
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
		return -232142125;
    return S->item[S->top--];
}

int priority(char op){
    if(op == '(')
        return 0;
    if(op == '-')
        return 1;
    if(op == '+')
        return 2;
    if(op == '/')
        return 3;
    if(op == '*')
        return 4;
    if(op == '^')
        return 5;
}

void main(){
    int i;
    Stack S;
    char ch,x;
    char exp[20];
    initialise(&S);
    printf("Enter the expression: ");
    scanf("%s",exp);
    printf("The infix expression: %s",exp);
    printf("\nThe postfix expression: ");
    for(i=0;i<strlen(exp);i++){
        ch = exp[i];
        if(isalnum(ch)){
            printf("%c",ch);
        }else if(ch == '('){
            push(&S,ch);
        }else if(ch == ')'){
            x = pop(&S);
            while(x!='('){
                printf("%c",x);
                x = pop(&S);
            }
        }else{
            while(priority(S.item[S.top])>=priority(ch)){
                printf("%c", pop(&S));
            }
            push(&S, ch);
        }
    }
    while (S.top != -1){
        printf("%c", pop(&S));
    }
    printf("\n");    
}