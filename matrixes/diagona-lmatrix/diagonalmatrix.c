#include<stdio.h>
#include<stdlib.h>

struct diagonalmatrix
{
	int * A;
	int n;
};
void setdiagonalmatrix(struct diagonalmatrix * m,int i,int j,int x)
{
	if(i==j)
	{
		m->A[i]=x;
	}
}
int getdiagonalmatrx(struct diagonalmatrix * m,int i,int j)
{
	if(i==j)
		return m->A[i-1];
	else
		return 0;
}

void display(struct diagonalmatrix * m)
{
	int i;
	int j;
	printf("\nYour matrix is.....\n");
	for(i=0;i< m->n;i++)
	{
		for(j=0;j< m->n;j++)
		{
			if(i==j)
				printf(" %d",m->A[i]);
			else 
				printf(" 0");
		}
		printf("\n");
	}
}

struct diagonalmatrix * creatematrix()
{
	struct diagonalmatrix * m;
	int x;
	printf("\nEnter the size(order) of matrix\n");
	scanf("%d",&m->n);
	m->A=(int *)malloc(sizeof(int)*m->n);
	printf("\nEnter the elements in the matrix\n");
	for(int i=0;i< m->n;i++)
	{
		for(int j=0;j< m->n;j++)
		{
			scanf("%d",&x);
			setdiagonalmatrix(m,i,j,x);
		}
	}
	printf("\nYour matrix is creating please wait............................\n");
	return m;
}

void main()
{
	struct diagonalmatrix * m=creatematrix();
	display(m);
	free(m->A);
}