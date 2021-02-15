#include<stdio.h>
#include<stdlib.h>

struct tridiagonalmatrix
{
	int * A;
	int n;
};

void setelements(struct tridiagonalmatrix * m,int i,int j,int x)
{
	if((i-j)==1)
	{
		m->A[i-j]=x;
	}
	else if((i-j)==0)
	{
		m->A[m->n-2-i]=x;
	}
	else if((i-j)==-1)
	{
		m->A[2*(m->n)-2+i]=x;
	}
	else{}
}

void display(struct tridiagonalmatrix * m)
{
	printf("\nElements in the matrix are\n");
	for(int i=1;i<=m->n;i++)
	{
		for(int j=1;j<=m->n;j++)
		{
			if((i-j)==1)
			{
				printf(" %d",m->A[i-j]);
			}
			else if((i-j)==0)
			{
				printf(" %d",m->A[m->n-2-i]);
			}
			else if((i-j)==-1)
			{
				printf(" %d",m->A[2*(m->n)-2+i]);
			}
			else
			{
				printf(" 0");
			}
		}
		printf("\n");
	}
}

struct tridiagonalmatrix * create()
{
	struct tridiagonalmatrix * m;
	int x;
	printf("\nYour Tridiagonal Matrix is creating please wait......\n");
	printf("\nPlease enter the size of matrix that You want to create\n");
	scanf("%d",&m->n);
	m->A=(int *)malloc(sizeof(int)*(3*(m->n)-2));
	printf("\nPlease enter the Elements in the matrix\n");
	for(int i=1;i<=m->n;i++)
	{
		for(int j=1;j<=m->n;j++)
		{
			scanf("%d",&x);
			setelements(m,i,j,x);
		}
	}
	printf("\nYour matrix is created :)\n");
	return m;
}

int main()
{
	struct tridiagonalmatrix * m=create();
	display(m);
	free(m->A);
	return 0;
}