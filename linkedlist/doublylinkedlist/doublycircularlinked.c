#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node * prev;
	int data;
	struct node * next;
}* first=NULL;

void display(struct node * p)
{
	printf("\nThe Elements in the doubly linked array are\n");
	while(p!=NULL)
	{
		if(p->next==NULL)
		{
			printf("%d",p->data);
			p=p->next;
		}
		else
		{
			printf("%d<=>",p->data);
			p=p->next;
		}
	}
	printf("\n");
}

struct node * create()
{
	first=(struct node *)malloc(sizeof(struct node));
	int n;
	int * A;
	struct node * t,* last;
	printf("\nCreating Your doubly linked ;)\n");
	printf("\nPlease enter the values in the doubly linked array\n");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	printf("\nEnter the elements in the doubly linked array\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	first->data=A[0];
	first->prev=first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
		t->next=NULL;	//Also we can do this t->next=last->next which (last->next) is basically NULL all time.
		t->prev=last;
		last->next=t;
		last=t;
	}
	printf("\nYour doubly linked is created ;)\n");
	free(A);
	return first;
}

int length(struct node * p)
{
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
struct node * Insertdoublylinked(struct node * p,int pos,int x)
{
	struct node * t;
	first=p;
	if(pos<0 || pos>length(p))
		return NULL;
	else if(pos==0)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->next=t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
		p=first;
		return p;
	}
	else
	{
		t=(struct node *)malloc(sizeof(struct node));
		for(int i=0;i<pos-1;i++)
			p=p->next;
		t->data=x;
		t->next=t->prev=NULL;
		t->prev=p;
		t->next=p->next;
		if(p->next)
			p->next->prev=t;
		p->next=t;	
		p=first;
		return p;
	}
}
struct node * deletedoublilinkedlist(struct node * p,int pos)
{
	struct node * q;
	first=p;
	if(pos<1 || pos>length(p))
		return NULL;
	if(pos==1)
	{
		first=first->next;
		if(first!=NULL)
			first->prev=NULL;
		free(p);
		p=first;
		return p;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
			p=p->next;
		p->prev->next=p->next;
		if(p->next!=NULL)
			p->next->prev=p->prev;
		free(p);
		p=first;
		return p;
	}
}
struct node * reversedoubly(struct node * p)
{
	struct node * q=NULL;
	first=p;
	while(p!=NULL)
	{
		q=p->next;
		p->next=p->prev;
		p->prev=q;
		p=p->prev;
		if(p!=NULL && p->next==NULL)
			first=p;
	}
	p=first;
	return p;
}
int main()
{
	struct node * p=NULL;
	int choice=1;
	while(choice)
	{
		printf("\n1.Creating the doubly linked list\n");
		printf("\n2.Display the elements in the doubly linked list by iterative method\n");
		printf("\n3.Finding the length doubly linked array by iterative method\n");
		printf("\n4.Inserting the element in the doubly linked list by taking position and value by user by iterative method\n");
		printf("\n5.Deleting the element in the doubly linked list by taking position from the user by iterative method\n");
		printf("\n6.Reversing the doubly linked list by iterative method\n");		
		printf("\n7.Exiting......\n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					p=create();
			break;

			case 2:
					display(p);
			break;

			case 3:
					printf("\nThe number of elements in the doubly linked array %d\n",length(p));
			break;

			case 4:
					printf("\nInserting the element in the doubly linked list please wait....... \n");
					int x1;
					int pos1;
					struct node * t1;
					printf("\nplease enter the position that you want to insert in doubly linked list\n");
					scanf("%d",&pos1);
					printf("\nPlease enter the element that you want to insert in the doubly linked list\n");
					scanf("%d",&x1);
					t1=Insertdoublylinked(p,pos1,x1);
					p=t1;
					if(t1==NULL)
						printf("\nSeems that you have entered the wrong position or your linked list is empty :(\n");
					else
						printf("\nYour element is inserted successfully ;)\n");
			break;

			case 5:
					printf("\nDeleting the element in the doubly linked list please wait....... \n");
					int pos2;
					struct node * t2;
					printf("\nplease enter the position that you want to delete in doubly linked list\n");
					scanf("%d",&pos2);
					t2=deletedoublilinkedlist(p,pos2);
					p=t2;
					if(t2==NULL)
						printf("\nSeems that you have entered the wrong position or your doubly linked list is empty :(\n");
					else
						printf("\nYour element is deleted successfully ;)\n");
			break;

			case 6:
					printf("\nReversing the doubly linked list by iterative method please wait......\n");
					struct node * t3;
					t3=reversedoubly(p);
					p=t3;
					if(t3==NULL)
						printf("\nSeems that your doubly linked list is empty :(\n");
					else
						printf("\nYour element is reversed successfully ;)\n");
			break;


			case 7:
					choice=0;
					if(p==NULL)
						printf("\nSeems that you don't like my progrem :(\n");
					else
					{
						free(p);
						printf("\nExiting................\n");
					}
			break;
		}
	}
}
