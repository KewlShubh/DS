#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *top1=NULL;
node *top2=NULL;
void push(node **top,int d)
{
	if(*top==NULL)
	{
		(*top)->data=d;
		(*top)->next=NULL;
		printf("top : %p,d:%d",*top,d);
	}
	else
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->data=d;
		temp->next=*top;
		*top=temp;
	}
}
int pop(node *top)
{
	node *temp=(node *)malloc(sizeof(node));
	int d=top->data;
	temp=top;
	top=top->next;
	free(temp);
	return d;
}
void enqueue(node **top1)
{
	int d;
	printf("Enter the value : ");
	scanf("%d",&d);
	push(top1,d);
}
/*void dequeue()
{
	node *temp=(node *)malloc(sizeof(node));
	while(top1!=NULL)
	{
		push(top2,pop(top1));
	}
	printf("%d popped\n",pop(top2));
	while(top2!=NULL)
	{
		push(top1,pop(top2));
	}
}/*

/*void display()
{
	if(top1==NULL)
		printf("underflow");
	else
	{
		printf("Queue contains : ");
		int info;
		while(top1!=NULL)
		{
			push(&top2,pop(&top1));
		}
		while(top2!=NULL)
		{
			info=pop(top2);
			printf("%d ",info);
			push(&top1,info);
		}
	}
}*/
void display()
{
	node *temp=(node *)malloc(sizeof(node));
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void main()
{
	int c;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:enqueue();
					break;
			case 2:dequeue();
					break;
			case 3:display();
					break;
			case 4:exit(0);
					break;
			default:("Try agaim\n");
		}
	}
}