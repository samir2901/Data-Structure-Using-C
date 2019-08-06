#include<stdio.h>
#define MAX 5
typedef struct{
	int item[MAX];
	int rear;
	int front;
}CircularQueue;
void init(CircularQueue *Q){
	Q->rear = -1;
	Q->front = -1;
}
void insert(CircularQueue *Q, int x){
	if(Q->front == (Q->rear+1)%MAX){
		printf("\nFull\n");
	}
	if(Q->front == -1 || Q->rear == -1){
		Q->front = 0;
		Q->rear = 0;
		Q->item[Q->rear] = x;
	}else{
		Q->rear = (Q->rear+1)%MAX;
		Q->item[Q->rear] = x;
	}	
}
int delete(CircularQueue *Q){
	int c;
	if(Q->front <= -1){
		return 0;
	}else{
		c = Q->item[Q->front];
		if(Q->rear == Q->front){
			Q->rear = -1;
			Q->front = -1;
		}else{
			Q->front = (Q->front+1)%MAX;
		}
		return c;
	}
}
void display(CircularQueue *Q){
	int i;
	if(Q->front<=-1){
		printf("\nNothing to be printed.\n");
	}else{
		for(i=Q->front;i<=Q->rear;i++){
			printf("%d, ",Q->item[i]);
		}
		if(Q->front > Q->rear){
			for(i=Q->front;i<=MAX-1;i++){
				printf("%d, ",Q->item[i]);
			}
			for(i=0;i<=Q->rear;i++){
				printf("%d, ",Q->item[i]);
			}
		}
	}
}

void main(){
	CircularQueue Q;
	int i,choice,n,x;
	init(&Q);
	do{
		printf("\nEnter 1 to insert element into queue.\nEnter 2 to delete element from queue\nEnter 3 to display the queue\nEnter choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			printf("Enter the number to insert: ");
			scanf("%d", &n);
			insert(&Q, n);
			break;
		case 2:
			if(i=delete(&Q)){
				printf("\nDeleted Element: %d\n",i);
			}else{
				printf("\nNothing to print\n");
			}
			break;
		case 3:
			printf("The Queue is:\n");
			display(&Q);
			break;		
		default:
			printf("\nInvalid Choice\n");
			break;
		}
		printf("\nContinue?(1/0) ");
		scanf("%d", &x);
	}while(x == 1);
}