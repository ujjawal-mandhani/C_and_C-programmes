#include<stdio.h>
#include<stdlib.h>

struct toepiltzmatrix
{
	int * A;
	int n;
};

void setelements(struct toepiltzmatrix * m,int i,int j,int x)
{
	if(i==1)
		m->A[j-i]=x;
	else if(j==1)
		m->A[m->n+(i-j-1)]=x;
	else{}
}

void display(struct toepiltzmatrix * m)
{
	printf("\nThe Elements in the matrix are\n");
	for(int i=1;i<=m->n;i++)
	{
		for(int j=1;j<=m->n;j++)
		{
			if(i<=j)
				printf(" %d",m->A[j-i]);
			else if(i>j)
				printf(" %d",m->A[m->n+(i-j-1)]);
			else{}
		}
	printf("\n");
	}
}

struct toepiltzmatrix * create()
{
	struct toepiltzmatrix * m;
	int x;
	printf("\nYour matrix is creating please wait..........\n");
	printf("\nEnter the value of order that you want to create matrix\n");
	scanf("%d",&m->n);
	m->A=(int *)malloc(sizeof(int)*(2*m->n-1));
	printf("\nEnter the elements in the matrix\n");
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
	struct toepiltzmatrix * m=create();
	display(m);
	free(m->A);
	return 0;

}