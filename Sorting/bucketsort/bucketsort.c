#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node * next;
};

int findmax(int * A,int n)
{
	int max=-32768;
	for (int i = 0; i < n; i++)
	{
		if(A[i]>max)
			max=A[i];
	}
	return max;
}

int * Binsort(int * A,int n)
{
	int max,i,j;
	struct node ** bins;
	struct node * p;
	max=findmax(A,n);
	bins=(struct node **)malloc(sizeof(struct node *) * (max+1));
	for (int i = 0; i < max +1; i++)
		bins[i]=NULL;
	for (int i = 0; i < n; i++)
	{
		p=bins[A[i]];
		if(p==NULL)
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->data=A[i];
		}
		else if(p!=NULL)
		{
			while(p->next!=NULL)
				p=p->next;
			p=(struct node *)malloc(sizeof(struct node));
			p->data=A[i];	
		}
		else
		{

		}
		
	}
	i=j=0;
	while(i < max+1)
	{
		p=bins[i];
		while(p!=NULL)
		{
			A[j++]=p->data;
			p=p->next;
		}
		i++;
	}

	return A;
}

int main()
{
	/* code */
	int n;
	printf("\nEnter the number of elements that you want to create\n");
	scanf("%d",&n);
	printf("\nEnter the elements in the array\n");
	int * A=(int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		/* code */
		scanf("%d",&A[i]);
	}
	A=Binsort(A,n);
	printf("\nSorted elements are\n");
	for (int i = 0; i < n; i++)
	{
		/* code */
		printf("%d\n",A[i]);
	}
	return 0;
}