#include<stdio.h>
#include<stdlib.h>

struct uppertriangularmatrix
{
	int * A;
	int n;
};

void setelements(struct uppertriangularmatrix * m,int i,int j,int x)
{
	if(i<=j)
	{
		m->A[((j*(j-1))/2)+i-1]=x;
	}
}

struct uppertriangularmatrix * create()
{
	int x;
	printf("\nYour matrix is creating please wait\n");
	struct uppertriangularmatrix * m;
	printf("\nEnter the size of the matrix\n");
	scanf("%d",&m->n);
	m->A=(int *)malloc(sizeof(int)*((m->n*(m->n+1))/2));
	printf("\nEnter the elements of the matrix\n");
	for(int i=1;i<=m->n;i++)
	{
		for(int j=1;j<=m->n;j++)
		{
			scanf("%d",&x);
			setelements(m,i,j,x);
		}
	}
	return m;
}

void display(struct uppertriangularmatrix * m)
{
	printf("\nThe Elements in the matrix are \n");
	for(int i=1;i<=m->n;i++)
	{
		for(int j=1;j<=m->n;j++)
		{
			if(i<=j)
				printf(" %d",m->A[((j*(j-1))/2)+i-1]);
			else
				printf(" 0");
		}
		printf("\n");
	}
}

int main()
{
	struct uppertriangularmatrix * m=create();
	display(m);
	free(m->A);
	return 0;
}