#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
}* front=NULL,* rear=NULL;

struct node * create()
{
	//struct node * q=NULL;
	struct node * t=NULL;
	printf("\nEnter the number of elements that you want to insert\n");
	int n,x;
	scanf("%d",&n);
	printf("\nEnter the elements in the queue\n");
	for(int i=1;i<=n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		printf("%d->",i);
		scanf("%d",&x);
		t->data=x;
		t->next=NULL;
		if(front==NULL)
		{
			rear=t;
			front=rear;
		}
		else
		{
			rear->next=t;
			rear=t;
		}

	}
	return front;
}

void enqueue(struct node * q,int x)
{
	struct node * t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(t==NULL)
	{
		printf("\nYour memory is full that is heap memory is full :(\n");
	}
	else
	{
		if(front==NULL)
		{
			rear=t;
			front=rear;
		}
		else
		{
			rear->next=t;
			rear=t;
		}
		printf("\nYour element is inserted successfully\n");
	}
}

int dequeue(struct node * q)
{
	int x=-32768;
	struct node * p=NULL;
	if(front==NULL)
		return x;
	else
	{
		p=front;
		front=front->next;
		x=p->data;
		p->next=NULL;
		free(p);
		return x;
	}
}

void display(struct node * q)
{
	struct node * p=NULL;
	p=front;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
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
						printf("\nSeems that your queue is already full\n");
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