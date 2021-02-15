#include<stdio.h>
#include<stdlib.h>
#define mine -32767
#define maxe 32768

struct node{
	int data;
	struct node * next;
}* head;

void display(struct node * p)
{
	do{
		if(p->next==head){
			printf("%d",p->data);
			p=p->next;
		}
		else
		{
			printf("%d ->",p->data);
			p=p->next;	
		}
	}while(p!=head);
	printf("\n");
}

void ReverseDisplay(struct node * p)
{
	static int flag=0;
	if(p!=head || flag==0)
	{
		flag=1;
		printf("%d ->",p->data);
		ReverseDisplay(p->next);
	}
	flag=0;
}
int length(struct node * p)
{
	int c=0;
	do{
		c++;
		p=p->next;
	}while(p!=head);
	return c;
}
struct node * insert(struct node * p,int pos,int x)
{
	struct node * t;
	int i;
	head=p;
	if(pos<0 || pos>length(p))
		return NULL;
	else if (pos==0)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		if(head==NULL)
		{
			head=t;
			head->next=head;
		}
		else
		{
			while(p->next!=head)
				p=p->next;
			p->next=t;
			t->next=head;
			head=t;
		}
	}
	else
	{
		for(i=0;i<pos-1;i++)
			p=p->next;
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->next=p->next;
		p->next=t;
	}
	return head;
}



struct node * create()
{
	int n;
	struct node * t;
	struct node * last;
	head =(struct node *)malloc(sizeof(struct node));
	printf("\nYour circular linked list is creating please wait.......\n");
	printf("\nPlease enter the size of circular linked list you want to create\n");
	scanf("%d",&n);
	int * A=(int *)malloc(sizeof(int)*n);
	printf("\nPlease enter the elements of circular linked list\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	head->data=A[0];
	head->next=head;
	last=head;
	for(int j=1;j<n;j++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[j];
		t->next=head;	//last->next is head bcoz head is pointing on itself or t->next=head; or t->next=last->next;
		last->next=t;
		last=t;
	}
	free(A);
	return head;
}

struct node * delete(struct node * p,int pos)
{
	struct node * q=NULL;
	int i,x;
	head=p;
	if(pos<0 || pos>length(p))
		return NULL;
	else if(pos==1)
	{
		while(p->next!=head)
			p=p->next;
		x=head->data;
		if(head==p)
		{
			free(p);
			head=NULL;
			return head;
		}
		else
		{
			p->next=head->next;
			free(head);
			head=p->next;
			return head;
		}
	}
	else
	{
		for(i=0;i<pos-2;i++)
			p=p->next;
		q=p->next;
		p->next=q->next;
		x=q->data;
		free(q);
		return head;
	}

}

int main()
{
	int choice=1;
	struct node * p=NULL;
	while(choice)
	{
		printf("\n1.Create the circular linked list\n");
		printf("\n2.Display the circular linked list in iterative method\n");
		printf("\n3.Display the circular linked list by recursive manner\n");
		printf("\n4.Finding the length of circular linked list by iterative method\n");
		printf("\n5.Inserting the elements in the circular linked list by taking the index(0,length(p)) from the user\n");
		printf("\n6.Deleting the element in the circular linked list by taking the position(0,lenegth(p)) from the user\n");
		printf("\n7.Exit the program :(\n");
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					p=create();
			break;

			case 2:
					printf("\nThe elements in the circular linked list are\n");
					display(p);
			break;

			case 3:
					printf("\nThe elements in the circular linked list are\n");
					ReverseDisplay(p);
			break;

			case 4:
					printf("\nThe element in the circular linked list are %d\n",length(p));
			break;

			case 5:
					printf("\nInserting the element in your circular linked list please wait...\n");
					struct node * t1;
					int x1,pos1;
					printf("\nEnter the element that you want to insert\n");
					scanf("%d",&x1);
					printf("\nEnter the position that you want to insert the element in circular linked list\n");
					scanf("%d",&pos1);
					t1=insert(p,pos1,x1);
					p=t1;
					if(t1==NULL)
						printf("\nSeems that that your index is wrong please check the index\n");
					else{
						printf("\nYour element is inserted in the circular linked list\n");
					}


			break;

			case 6:
					printf("\nDeleting the element in your circular linked list please wait...\n");
					struct node * t2;
					int pos2;
					printf("\nEnter the position that you want to delete the element in circular linked list\n");
					scanf("%d",&pos2);
					t2=delete(p,pos2);
					p=t2;
					if(t2==NULL)
						printf("\nSeems that that your index is wrong or your circular linked list is already empty please check the index\n");
					else{
						printf("\nYour element is deleted in the circular linked list\n");
					}


			break;

			case 7:
					choice=0;
					if(p==NULL)
						printf("\nSeems that you don't like my program :(\n");
					else
					{
						printf("\nThank you for using my program\n");
						printf("\nExitting.........\n");
						free(p);
					}


			break;


		}
	}
}