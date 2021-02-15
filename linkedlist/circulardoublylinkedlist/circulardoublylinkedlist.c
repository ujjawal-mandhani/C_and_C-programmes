#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node * prev;
	int data;
	struct node * next;
}* first,* last;

struct node * create()
{
	printf("\nYour doubly circular linked is creating please wait\n");
	int * A;
	struct node * t;
	int n;
	first=(struct node *)malloc(sizeof(struct node));
	first->next=first->prev=NULL;
	last=first;
	printf("\nEnter the size of doubly linked that you want to create\n");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	printf("\nEnter the elements in the doubly linked list\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	first->data=A[0];
	first->next=first;
	first->prev=first;
	for(int i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
		last->next=t;
		t->prev=last;
		t->next=first;
		first->prev=t;
		last=t;
	}
	free(A);
	printf("\nYour circular doubly Linked is created ;) \n");
	return first;
}

void display(struct node * p)
{
	printf("\nThe elements in the doubly circular linked are..\n");
	first=p;
	do
	{
		if(p->next==first)
			printf("%d",p->data);
		else
			printf("%d <=>",p->data);
		p=p->next;
	}while(p!=first);
	printf("\n");
}
int length(struct node * p)
{
	first=p;
	int count=0;
	do
	{
		count++;
		p=p->next;
	}while(p!=first);
	return count;
}
struct node * insertdoublycircular(struct node * p,int pos,int x)
{
	printf("\nWe are inserting the element in your doubly circular linked please wait .....\n");
	first=p;
	struct node * t=NULL;
	if(pos<0 || pos>length(p))
		return NULL;
	else if(pos==0)
	{
		do
		{
			p=p->next;
		}while(p->next!=first);
		last=p;
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->next=first;
		first->prev=t;
		t->prev=last;
		last->next=t;
		first=t;
		p=first;
		return p;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
			p=p->next;
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		if(p->next==first)
		{
			last=t;
		}
		t->next=p->next;
		p->next->prev=t;
		p->next=t;
		t->prev=p;
		p=first;
		return p;
	}

}

struct node * delete(struct node * p,int pos)
{
	first=p;
	if(pos<1 || pos>length(p))
		return NULL;
	else if(pos==1)
	{
		first=first->next;
		if(first!=NULL)
		{
			first->prev=NULL;
			free(p);
			last->next=first;
			first->prev=last;
			p=first;
			return p;
		}
	}
	else
	{
		for(int i=0;i<pos-1;i++)
			p=p->next;
		if(p->next==first)
		{
			last=last->prev;
			last->next=first;
			first->prev=last;
			free(p);
			p=first;
			return p;
		}
		else
		{
			p->prev->next=p->next;
			p->next->prev=p->prev;
			p->next=p->prev=NULL;
			free(p);
			p=first;
			return p;
		}
	}
}

int main()
{
	struct node * p=NULL;
	int choice=1;
	while(choice)
	{
		printf("\n1.Create the doubly circular linked\n");
		printf("\n2.Display the doubly circular linked\n");	
		printf("\n3.Finding length of doubly circular linked by iterative method\n");
		printf("\n4.Insert the elements in the circular doubly linked list by taking position and element from the user\n");
		printf("\n5.Delete the elements in the circular doubly linked list by taking position from the user\n");
		printf("\n6.Exit The program\n");
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	
					p=create();
			break;

			case 2:
					display(p);
					//printf("%d\n",last->next->data);//checking it is doubly circular linked or not
					//printf("%d\n",first->prev->data);//checking it is doubly circular linked or not
			break;

			case 3:
					printf("\nThe number of elements in the doubly circular linked are %d\n",length(p));
			break;

			case 4:
					printf("\nWe are inserting the elements in the doubly circular linked please wait....\n");\
					int x;
					int pos;
					printf("\nEnter the element that you want to insert in doubly circular linked\n");
					scanf("%d",&x);
					printf("\nEnter the position that you want to insert the element in doubly circular linked\n");
					scanf("%d",&pos);
					struct node * t;
					t=insertdoublycircular(p,pos,x);
					p=t;
					if(t==NULL)
						printf("\nSeems that you have enter the incorrect position or doubly circular linked  is empty\n");
					else
						printf("\nYour element is inserted ;)\n");
			break;

			case 5:
					printf("\nWe are deleting the elements in the doubly circular linked please wait....\n");
					int pos1;
					printf("\nEnter the position that you want to insert the element in doubly circular linked\n");
					scanf("%d",&pos1);
					struct node * t1;
					t1=delete(p,pos1);
					p=t1;
					if(t1==NULL)
						printf("\nSeems that you have enter the incorrect position or doubly circular linked  is empty\n");
					else
						printf("\nYour element is deleted ;)\n");
			break;

			case 6:
					choice=0;
					if(p==NULL)
						printf("\nSeems that you don't like my program :(\n");
					else{
						printf("\nExiting...........\n");
						free(p);
					}
			break;
		}

	}

	//printf("%d\n",last->next->data);//checking it is doubly circular linked or not
	//printf("%d\n",first->prev->data);//checking it is doubly circular linked or not
	return 0;
}