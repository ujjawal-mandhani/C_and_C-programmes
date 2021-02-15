#include<stdio.h>
#include<stdlib.h>
#define mine -65336
#define maxe 65336

struct node{
	int data;
	struct node * next;
} * first=NULL;

void display(struct node * p)
{
	printf("\nThe elements in the linked list are\n");
	while(p)
	{
		if(p->next!=NULL){
			printf("%d ->",p->data);
			p=p->next;
		}
		else if(p->next==NULL){
			printf("%d\n",p->data);
			p=p->next;
		}
	}
}

void Rdisplay(struct node *p)
{
	if(p!=NULL)
	{
		if(p->next!=NULL)
		{
			printf("%d ->",p->data);
		}
		else if(p->next==NULL)
		{
			printf("%d\n",p->data);
		}
		Rdisplay(p->next);
	}
}

void RecursiveReverseDispaly(struct node * p)
{
	if(p!=NULL)
	{
		RecursiveReverseDispaly(p->next);
		printf("%d ->",p->data);
	 }
}

struct node * create()
{
	int n;
	first=(struct node *)malloc(sizeof(struct node));
	struct node * t,* last;
	printf("\nYour Linked list is creating please wait ........\n");
	printf("\nEnter the number of terms that you want to create linked list\n");
	scanf("%d",&n);
	int * A=(int *)malloc(sizeof(int) * n);
	printf("\nEnter the number of terms in the linked list\n");
	for(int i=0;i < n;i++)
		scanf("%d",&A[i]);
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(int j=1;j < n;j++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[j];
		t->next=NULL;
		last->next=t;
		last=t;
	}
	printf("\nYour Linked list is created point to be note that we created linked list in right direction ;)\n");
	free(A);
	return first;
}
int count(struct node * p)
{
	int c=0;
	while(p)
	{
		c++;
		p=p->next;
	}
	return c;
}
int Rcount(struct node * p)
{
	if(p!=NULL)
	{
		return Rcount(p->next) + 1;
	}
	else
		return 0;
}

void sumofelements(struct node * p)
{
	printf("\nCalculating the sum of all elements in the linked list\n");
	int sum=0;
	while(p!=NULL)
	{
		sum=sum+p->data;
		p=p->next;
	}
	printf("\nThe sum of all the elements in the linked list are %d\n",sum);
}
int Rsumofelements(struct node * p)
{
	if(p==NULL)
		return 0;
	else
		return Rsumofelements(p->next) + p->data;
}
void maximumelement(struct node * p)
{
	printf("\nFinding the maximum element in the linked list\n");
	int m =-32767;
	while(p!=NULL)
	{
		if(p->data > m)
			m=p->data;
		p=p->next;
	}
	printf("\nThe maximum element in the linked list is %d\n",m);
}
int Rmaximumelement(struct node * p)
{
	static int x=-32767;
	if(p==NULL)
		return x;
	else
	{
		x=Rmaximumelement(p->next);
		if(x > p->data)
			return x;
		else
			return p->data;	//return x> p->data ? x : p->data;
	}
}

int Rminimumelement(struct node * p)
{
	static int x=32767;
	if(p==NULL)
		return x;
	else
	{
		x=Rminimumelement(p->next);
		if(x < p->data)
			return x;
		else
			return p->data; //return x < p->data ? x : p->data;
	}
}
void minimumelement(struct node * p)
{
	printf("\nFinding minimum element in the linked list\n");
	int m=32767;
	while(p!=NULL)
	{
		if(p->data < m)
			m=p->data;
		p=p->next;
	}
	printf("\nThe minimum element in the linked list is %d\n",m);
}

struct node * search(struct node * p,int key)
{
	printf("\nChecking that your key is in the linked list\n");
	if(p==NULL)
		return NULL;
	else if(p->data == key)
		return p;
	else
		return search(p->next,key);
}

struct node * improvedLinearsearch(struct node * p,int key)
{
	printf("\nChecking that your key is in the linked list\n");
	struct node * q = NULL;
	first=p;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=NULL;
			p->next=first;
			first=p;
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

struct node * Recursivesearch(struct node * p,int key)
{
	if(p==NULL)
		return NULL;
	if(key==p->data)
		return p;
	return Recursivesearch(p->next,key);
}
struct node * insertinlinkedlist(struct node * p,int pos,int x)
{
	struct node * t;
	if(pos < 0 || pos > count(p))
		return NULL;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(pos==0)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(int i=0;i< pos-1;i++)
			p=p->next;
		t->next=p->next;
		p->next=t;
		p=first;
	}
	return p;
}

struct node * sortedinsertion(struct node * p,int x)
{
	struct node * t,* q=NULL;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	//first=p;
	if(p==NULL)
	{
		first=t;
		p=first;
		return p;
	}
	else
	{
		while(p!=NULL && p->data < x)
		{
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next=first;
			first=t;
			p=first;
			return p;	
		}	
		else
		{
			t->next=q->next;
			q->next=t;
			p=first;
			return p;
		}
	}
}

int deletelinkedlist(struct node * p,int pos)
{
	struct node * q=NULL;
	int x=mine;
	if(pos<1 || pos>count(p))
		return x;
	else if(pos==1)
	{
		q=first;
		x=first->data;
		first=first->next;
		free(q);
		return x;
	}
	else
	{
		for(int i=0;i< pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		free(p);
		return x;
	}
}
void issorted(struct node * p)
{
	int x=mine;
	while(p!=NULL)
	{
		if(p->data < x)
		{
			printf("\nYour linked list is not sorted :(\n");
			return;
		}
		x=p->data;
		p=p->next;
	}
	printf("\nYour linked list is sorted:)\n");
	return;
}
struct node * removeduplicate(struct node * p)
{
	struct node * q= p->next;
	struct node * h=p;
	printf("\nWe are removing the duplicates if (they are consecutive)\n");
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			q->next=NULL;
			free(q);
			q=p->next;
		}
	}
	p=h;
	printf("\nAll the duplicates are removed\n");
	return p;
}

struct node * reverse_iteratively_linkedlist_method1(struct node * p)
{
	int * A=(int *)malloc(sizeof(int)*count(p));
	struct node * q=NULL;
	int i=0;
	q=p;
	while(q!=NULL)
	{
		A[i]=q->data;
		q=q->next;
		i++;
	}
	q=p;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
	free(A);
	return p;
}

struct node * reverse_iteratively_linkedlist_method2(struct node * p)
{
	struct node * q=NULL,* r=NULL;
	first=p;
	printf("\nWe are reversing your linked list please wait\n");
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
	p=q;
	return p;
}

void reverse_recursively_linkedlist(struct node * q,struct node * p)
{
	if(p!=NULL)
	{
		reverse_recursively_linkedlist(p,p->next);
		p->next=q;
	}
	else
		first=q;
}

struct node * concatenation(struct node * p)
{
	struct node * q=create();
	struct node * l;
	l=p;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	q=NULL;
	p=l;
	return p;
}

struct node * merging(struct node * p)
{
	struct node * q=create();
	struct node * third,* last;
	third=NULL;
	last=NULL;
	if(p->data < q->data)
	{
		third=last=p;
		p=p->next;
		last->next=NULL;
	}
	else
	{
		third=last=q;
		q=q->next;
		last->next=NULL;
	}
	while(p!=NULL && q!=NULL)
	{
		if(p->data < q->data)
		{
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
		}
		else
		{
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
		}
	}
	if(p!=NULL)
		last->next=p;
	if(q!=NULL)
		last->next=q;
	return third;

}

bool isloooping(struct node * p)
{
	struct node * q=NULL;
	struct node * t=NULL;
	q=t=p;
	do{
		q=q->next;
		t=t->next;
		t=t ? t->next : q;
	}while(q && t && q!=t);
	if(q==t)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	int choice =1;
	struct node * p=NULL;
	while(choice)
	{
		printf("\n1.Create the linked list\n");
		printf("\n2.Display the linked list using iterative method\n");
		printf("\n3.Display the linked list using recurrsive method\n");
		printf("\n4.Reverse the Linked list using Recurrsive method\n");
		printf("\n5.Count the number of elements in the linked list using iterative method\n");
		printf("\n6.Count the number of elements in the linked list using recurrsive method\n");
		printf("\n7.Sum of elements in the linked list using iterative method\n");
		printf("\n8.Sum of elements in the linked list using recurrsive method\n");
		printf("\n9.Finding The maximum element in the linked list using Iterative method\n");
		printf("\n10.Findinng the minimum element in the linked list using iterartive method\n");
		printf("\n11.Finding The maximum element in the linked list using Recursive method\n");
		printf("\n12.Finding The mininmum element in the linked list using Recursive method\n");
		printf("\n13.Finding element in the linked list using linear search by Iterative method\n");
		printf("\n14.Finding element in the linked list using Improved linear search by Iterative method\n");
		printf("\n15.Finding element in the linked list using linear search by Recursive method\n");
		printf("\n16.Inserting element in the linked list by taking index by user by Iterative method\n");
		printf("\n17.Inserting element in the linked list in sorted manner by Iterative method\n");
		printf("\n18.Deleting element in the linked list by taking index from user by Iterative method\n");
		printf("\n19.Checking the elements in the linked list is sorted or not using Iterative method\n");
		printf("\n20.Removing the elements in the linked list if they are duplicates (consecutive elements only) using Iterative method\n");
		printf("\n21.Reverse the linked list by iterative method method 1\n");
		printf("\n22.Reverse the linked list by iterative method method 2\n");
		printf("\n23.Reverse the linked list by Reversive method method 3\n");
		printf("\n24.Concatenating the two linked list by Iterative method method 3\n");
		printf("\n25.Merging the two linked list by Iterative method\n");
		printf("\n26.Exit the program\n");
		printf("\nEnter the choice that you want to execute\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
					printf("\nCreating....\n");
					p=create();
			break;

			case 2:
					display(p);
			break;

			case 3:
					printf("\nThe elements in the linked list are\n");
					Rdisplay(p);
			break;

			case 4:
					printf("\nThe elements of a linked list in reveversive direction are\n");
					RecursiveReverseDispaly(p);
			break;

			case 5:
					printf("\nThe length of a linked list is %d\n",count(p));
			break;

			case 6:
					printf("\nThe number of elements in the linked list using recurrsive method is %d\n",Rcount(p));
			break;

			case 7:
					sumofelements(p);
			break;
			
			case 8:
					printf("\nSum of elements in the linked list using recurrsive method is %d\n",Rsumofelements(p));
			break;

			case 9:
					maximumelement(p);
			break;

			case 10:
					minimumelement(p);
			break;

			case 11:
					printf("\nFinding the maximum element in the linked list by recursive method\n");
					int ma;
					ma=Rmaximumelement(p);
					if(ma==-32767)
						printf("\nIt seems that You have not created the linked list:(\n");
					else
						printf("\nThe maximum element in the linked list is %d\n",ma);
			break;

			case 12:
					printf("\nFinding the minimum element in the linked list by recursive method\n");
					int mm;
					mm=Rminimumelement(p);
					if(mm==32767)
						printf("\nIt seems that You have not created the linked list:(\n");
					else
						printf("\nThe minimum element in the linked list is %d\n",mm);
			break;

			case 13:
					printf("\nFinding element in the linked list by linear search iterative method\n");
					int key1;
					printf("\nEnter the value that you want to search\n");
					scanf("%d",&key1);
					struct node * t1;
					t1=search(p,key1);
					if(t1==NULL)
						printf("\nIt seems that the element you are finding is not in the linked list or your linked list is empty\n");
					else
						printf("\nYour element found ;)\n");
			break;

			case 14:
					printf("\nFinding element in the linked list by Improoved linear search iterative method\n");
					int key2;
					printf("\nEnter the value that you want to search\n");
					scanf("%d",&key2);
					struct node * t2;
					t2=improvedLinearsearch(p,key2);
					p=t2;
					if(t2==NULL)
						printf("\nIt seems that the element you are finding is not in the linked list or your linked list is empty\n");
					else
						printf("\nYour element found ;)\n");
			break;

			case 15:
					printf("\nFinding element in the linked list by linear search Recursive method\n");
					int key3;
					printf("\nEnter the value that you want to search\n");
					scanf("%d",&key3);
					struct node * t3;
					t3=search(p,key3);
					if(t3==NULL)
						printf("\nIt seems that the element you are finding is not in the linked list or your linked list is empty\n");
					else
						printf("\nYour element found ;)\n");
			break;

			case 16:
					printf("\nInserting element in the linked list by taking index from user by iterative method\n");
					int pos1,x1;
					printf("\nEnter the positiion that you want to insert\n");
					scanf("%d",&pos1);
					printf("\nEnter the element that you want to insert\n");
					scanf("%d",&x1);
					struct node * t4 = NULL;
					t4=insertinlinkedlist(p,pos1,x1);
					p=t4;
					if(t4==NULL)
						printf("\nIt seems that the element you are inserting is out of range or less than range of linked list or your linked list is empty\n");
					else
						printf("\nYour element inserted ;)\n");
			break;

			case 17:
					printf("\nInserting element in the linked list in sorted order by iterative method\n");
					int x2;
					printf("\nEnter the element that you want to insert\n");
					scanf("%d",&x2);
					struct node * t5 = NULL;
					t5=sortedinsertion(p,x2);
					p=t5;
					printf("\nYour element inserted ;)\n");
			break;

			case 18:
					printf("\nDeleting element in the linked list by taking index from user by iterative method\n");
					int x3,d;
					printf("\nEnter the index range(1,length of linked list) that you want to delete\n");
					scanf("%d",&x3);
					d=deletelinkedlist(p,x3);
					p=first;
					if(d==mine)
						printf("\nSeems that you have enter the wrong index or element not found\n");
					else
						printf("\nYour element deleted ;)\n");
			break;

			case 19:
					printf("\nChecking that linked list is sorted or not please wait.....\n");
					issorted(p);
			break;

			case 20:
					printf("\nRemoving the duplicates in the linked list (only comsecutive)\n");
					struct node * t6;
					t6=removeduplicate(p);
					p=t6;
			break;

			case 21:
					printf("\nReversing the linked list method1 by iterative method ;)\n");
					struct node * t7;
					t7=reverse_iteratively_linkedlist_method1(p);
					printf("\nYour linked list reversed ;)\n");
					p=t7;
			break;

			case 22:
					printf("\nReversing the linked list method2 by iterative method ;)\n");
					struct node * t8;
					t8=reverse_iteratively_linkedlist_method2(p);
					printf("\nYour linked list reversed ;)\n");
					p=t8;
			break;

			case 23:
					printf("\nReversing the linked list method3 by Recursive method ;)\n");
					reverse_recursively_linkedlist(NULL,p);
					printf("\nYour linked list reversed ;)\n");
					p=first;
			break;

			case 24:
					printf("\nConcatenating the linked list by iterative method ;)\n");
					struct node * t9;
					t9=concatenation(p);
					printf("\nYour linked list is concatenated with other ;)\n");
					p=t9;
			break;

			case 25:
					printf("\nMerging the two linked list by iterative method ;)\n");
					struct node * t10;
					t10=merging(p);
					printf("\nYour linked list is merged with other ;)\n");
					p=t10;
			break;



			case 26:
					printf("\nExiting.......\n");
					choice=0;
					if(!p)
					{
						printf("\nSeems like You don't like my program :(\n");
					}
					else
						free(p);
			break;
		}
	}
	
	
	
	return 0;
}