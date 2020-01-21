#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coef,exp;
	struct node *next;
};
typedef struct node N;
N *head1=NULL;
N *head2=NULL;
N *head3=NULL;
N *ptr;
N *tail1,*tail2,*tail3;


void create()
{
	int ch,x;
	printf("Create first polynomial...........\n");
	do{
		ptr=(struct node*)malloc(sizeof(struct node));
		printf("Enter the coefficient:");
		scanf("%d",&x);
		ptr->coef=x;
		printf("Enter the exponent:");
		scanf("%d",&x);
		ptr->exp=x;
		ptr->next=NULL;
		if(head1==NULL)
		{
			head1=ptr;
			tail1=ptr;
		}
		else
		{
			tail1->next=ptr;
			tail1=ptr;
		}
		printf("Do you want to continue?(0/1)");
		scanf("%d",&ch);
	}while(ch==1);
	printf("Create second polynomial..........\n");
	do{
		ptr=(struct node*)malloc(sizeof(struct node));
		printf("Enter the coefficient:");
		scanf("%d",&x);
		ptr->coef=x;
		printf("Enter the exponent:");
		scanf("%d",&x);
		ptr->exp=x;
		ptr->next=NULL;
		if(head2==NULL)
		{
			head2=ptr;
			tail2=ptr;
		}
		else
		{
			tail2->next=ptr;
			tail2=ptr;
		}
		printf("Do you want to continue?(0/1)");
		scanf("%d",&ch);
	}while(ch==1);
}

void polyAdd()
{
	N *temp1,*temp2,*temp3;
	temp1=head1;
	temp2=head2;
	while(temp1!=NULL || temp2!=NULL)
	{
		ptr=(N*)malloc(sizeof(N));
		if(temp1==NULL)
		{
			ptr->coef=temp2->coef;
			ptr->exp=temp2->exp;
			temp2=temp2->next;
		}
		else if(temp2==NULL)
		{
			ptr->coef=temp1->coef;
			ptr->exp=temp1->exp;
			temp1=temp1->next;
		}
		else if(temp1->exp==temp2->exp)
		{
			ptr->coef=temp1->coef+temp2->coef;
			ptr->exp=temp1->exp;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->exp>temp2->exp)
		{
			ptr->coef=temp1->coef;
			ptr->exp=temp1->exp;
			temp1=temp1->next;
		}
		else
		{
			ptr->coef=temp2->coef;
			ptr->exp=temp2->exp;
			temp2=temp2->next;
		}

		if(head3==NULL)
			head3=tail3=ptr;
		else
		{
			tail3->next=ptr;
			tail3=ptr;
		}
	}
	tail3->next=NULL;
}


void display(){
	printf("\n1st Polynomial: ");
	struct node *temp;
	temp=head1;
	while(temp!=NULL)
	{
		printf("%dx^%d",temp->coef,temp->exp);
		if(temp->next!=NULL)
		{
			printf(" + ");
		}
		temp=temp->next;
	}
	printf("\n");
	printf("\n2nd Polynomial: ");
	temp=head2;
	while(temp!=NULL)
	{
		printf("%dx^%d",temp->coef,temp->exp);
		if(temp->next!=NULL)
		{
			printf(" + ");
		}
		temp=temp->next;
	}
	printf("\n");
	printf("\nSum of the Polynomials:\n");
	temp=head3;
	while(temp!=NULL)
	{
		printf("%dx^%d",temp->coef,temp->exp);
		if(temp->next!=NULL)
		{
			printf(" + ");
		}
		temp=temp->next;
	}
	printf("\n");
}

void main()
{
	create();
	polyAdd();
	display();

}
