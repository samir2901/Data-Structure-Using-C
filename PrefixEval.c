#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 50

typedef struct{
  char item[MAX];
  int top;
}Stack;

void init(Stack *S){
  S->top = -1;
}

void push(Stack *S, char item){
  if(S->top >= MAX-1)
    return;
  else
    S->item[++(S->top)] = item;
}

char pop(Stack *S){
  if(S->top <= -1)
    return '@';
  return S->item[S->top--];
}

int isOperator(char ch){
  if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
    return 1;
  return 0;
}

int operation(char op, char ch1, char ch2){
  int result;
  if(op=='+'){
    result = (int)(ch1 - '0') + (int)(ch2 - '0');
    return result;
  }
  if(op=='-'){
    result = (int)(ch1 - '0') - (int)(ch2 - '0');
    return result;
  }
  if(op=='/'){
    result = (int)(ch1 - '0') / (int)(ch2 - '0');
    return result;
  }
  if(op=='*'){
    result = (int)(ch1 - '0') * (int)(ch2 - '0');
    return result;
  }
  if(op=='^'){
    result = pow((int)(ch1 - '0'),(int)(ch2 - '0'));
    return result;
  }
}

int evalPrefix(char exp[]){
  Stack S;
  init(&S);
  for(int i=strlen(exp)-1;i>=0;i--){
    if(!isOperator(exp[i])){
      push(&S,exp[i]);
    }else if(isOperator(exp[i])){
      char ch2 = pop(&S);
      char ch1 = pop(&S);
      int result = operation(exp[i],ch1,ch2);
      push(&S,result);
    }
  }
  return S.item[S.top];
}

void main(){
  char exp[34];
  printf("Enter postfix expression: ");
  scanf("%s",exp);
  printf("The result is: %d\n", evalPrefix(exp));
}
