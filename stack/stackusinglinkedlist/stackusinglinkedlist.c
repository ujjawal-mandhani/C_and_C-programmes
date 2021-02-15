#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
}* top=NULL;

void push(int x)
{
	struct node * t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
		printf("\nStack is flow or memory exceed of heap\n");
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

struct node * create(int x)
{
	int k;
	static int i;
	printf("\nEnter the element you want to insert\n");
	for(i=0;i<x;i++)
	{
		printf("%d->",i);
		scanf("%d",&k);
		push(k);
	}
	return top;
}


void display()
{
	struct node * p=NULL;
	p=top;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

int pop()
{
	struct node * t=NULL;
	int x=-32767;
	if(top==NULL){
		printf("\nStack is empty\n");
		return x;
	}
	else
	{
		t=top;
		top=top->next;
		t->next=NULL;
		x=t->data;
		free(t);
		return x;
	}
}

int stacktop()
{
	int x=-32767;
	if(top==NULL)
		return x;
	else
	{
		return top->data;
	}
}

int isEmpty()
{
	if(top==NULL)
		return 0;
	else			// return top? 0:1;
		return 1;
}

int isFull()
{
	struct node * t=NULL;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
		return 0;
	else
		return 1;


}
int main()
{
	int choice=1;
	static int count=0;
	while(choice)
	{
		printf("\n1.Push the element in to the stack\n");
		printf("\n2.Display the element present in the stack\n");
		printf("\n3.Pop the element from the stack\n");
		printf("\n4.Giving the value pesent at the top of stack\n");
		printf("\n5.Checking Whether that the stack is empty or not\n");
		printf("\n6.Checking Whether that the stack is full or not\n");
		printf("\n7.Exit the program\n");
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\nCreating the stack please wait......\n");
					printf("\nEnter the number of element that you want to insert\n");
					int n;
					scanf("%d",&n);
					top=create(n);
					count++;
			break;

			case 2:
					printf("\nThe element present in the satck are\n");
					display();
					count++;
			break;

			case 3:
					printf("\nWe are poping the element present in the stack please wait\n");
					int l;
					l=pop();
					if(l==-32767)
						printf("\nSeems that element cannot be poped check the stack if it is empty\n");
					else
						printf("\nElement %d poped successfully ;)\n",l);
					count++;
			break;

			case 4:
					printf("\nWe are returning the element present in the top of stack please wait......\n");
					int l1;
					l1=stacktop();
					if(l1==-32767)
						printf("\nSeems that element cannot be displayed, check the stack if it is empty :(\n");
					else
						printf("\nthe Element present at top of stack is %d ;)\n",l1);
						
					count++;
			break;

			case 5:
					printf("\nWe are checking that the stack is empty or not please wait......\n");
					int l2;
					l2=isEmpty();
					if(l2==0)
						printf("\nSeems that the stack is alredy empty :(\n");
					else
						printf("\nthe stack is not empty ;)\n");
			break;

			case 6:
					printf("\nWe are checking that the stack is full or not please wait......\n");
					int l3;
					l3=isFull();
					if(l3==0)
						printf("\nSeems that the stack is alredy full, and memory inheap is full :(\n");
					else
						printf("\nthe stack is not Full ;)\n");
			break;

			case 7:
					choice=0;
					if(top==NULL && count==0)
						printf("\nSeems that you don't like my program :(\n\nExiting...........\n");
					else if(top==NULL)
						printf("\nExiting.......\n");
					else
					{
						printf("\nExiting.......\n");
						free(top);
					}
			break;
		}
	}

	return 0;
}