#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
}* front=NULL,* rear=NULL;

struct node * create()
{
	printf("\nWe are creating your queue please wait\n");
	struct node * t;
	printf("\nEnter the size of the that you want to create\n");
	int n,x;
	scanf("%d",&n);
	printf("\nEnter the elements in the queue one by one\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d->",i);
		scanf("%d",&x);
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->next=NULL;
		if(front==NULL)
		{
			front=rear=t;
			rear->next=front;
		}
		else
		{
			rear->next=t;
			rear=t;
			rear->next=front;
		}
	}
	printf("\nYour Queue is created successfully ;)\n");
	return front;
}

void enqueue(struct node * q,int x)
{
	struct node * t=(struct node *)malloc(sizeof(struct node));
	t->next=NULL;
	t->data=x;
	if(t==NULL)
		printf("\nSeems that your heap memory is full\n");
	else
	{
		if(front==NULL)
		{
			front=rear=t;
			front->next=front;
		}
		else
		{
			rear->next=t;
			rear=t;
			rear->next=front;
		}
	}
}

int dequeue(struct node * q)
{
	int x=-32768;
	struct node * p=NULL;
	p=front;
	if(front==NULL)
		printf("\nSeems that your queue is already empty\n");
	else
	{
		front=front->next;
		rear->next=front;
		p->next=NULL;
		x=p->data;
		free(p);
	}
	return x;
}

void display(struct node * q)
{
	struct node * p=NULL;
	p=front;
	do
	{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=front);
	printf("\n");
}

int main()
{
	struct node * q=NULL;
	int choice=1;
	static int cout=0;
	while(choice)
	{
		printf("\n1.Create the Queue\n");
		printf("\n2.Enqueue in the Queue\n");
		printf("\n3.Dequeue in the Queue\n");
		printf("\n4.Display the Queue\n");
		printf("\n5.Exit the Program\n");
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					q=create();
					cout++;
			break;

			case 2:
					printf("\nWe are enquing the element please wait\n");
					int x4;
					printf("\nEnter the element to insert in the queue\n");
					scanf("%d",&x4);
					enqueue(q,x4);
					cout++;
			break;

			case 3:
					printf("\nWe are dequeuing the element please wait\n");
					int x2;
					x2=dequeue(q);
					if(x2==-32768)
						printf("\nSeems that your queue is already empty\n");
					else
						printf("\nYour element is dequeued from queue successfully ;) and element is %d\n",x2);
					cout++;
			break;

			case 4:
					printf("\nThe elemnts present in the queue are\n");
					display(q);
					cout++;
			break;

			case 5:
					choice=0;
					if(q==NULL || cout==0)
						printf("\nSeems that you don't like my program:(\n");
					else
					{
						printf("\nExiting........\n");
						free(front);
					/*	free(q);*/
					}
			break;
		}
	}
}