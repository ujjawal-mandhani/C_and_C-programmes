#include<stdio.h>
#include<stdlib.h>

struct lowertriangularmatrix
{
	int * A;
	int n;
};

void display(struct lowertriangularmatrix * m)
{
	int i,j;
	printf("\nElements in the matrixes are\n");
	for(i=1;i<= m->n;i++)
	{
		for(j=1;j<= m->n;j++)
		{
			if(i>=j)
			printf(" %d",m->A[((i*(i-1))/2)+(j-1)]);
			else
				printf(" 0");
		}
		printf("\n");
	}
}

void setlowertriangularmatrix(struct lowertriangularmatrix * m,int i,int j,int x)
{
	if(i>=j)
		m->A[((i*(i-1))/2)+(j-1)]=x;
}

struct lowertriangularmatrix * create()
{
	int p,x;
	struct lowertriangularmatrix * m;
	printf("\nEnter the size of the array that you want to create\n");
	scanf("%d",&m->n);
	m->A=(int *)malloc(sizeof(int)*((m->n*(m->n+1))/2));
	printf("\nEnter the elements in the matrix Lower Triangular Matrix\n");
	for(int i=1;i<= m->n;i++)
	{
		for(int j=1;j<= m->n;j++)
		{
				scanf("%d",&x);
				setlowertriangularmatrix(m,i,j,x);
		}
	}
	printf("\nYour array is created\n");
	return m;
} 

int main()
{
	struct lowertriangularmatrix * m=create();
	display(m);
	free(m->A);
}
