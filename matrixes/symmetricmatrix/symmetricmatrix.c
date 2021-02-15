#include<stdio.h>
#include<stdlib.h>

int ** create(int n)
{
	int ** a;
	printf("\nYour matrix is creating please wait\n");
	* a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		a[i]=(int*)malloc(sizeof(int)*n);
	}
	printf("\nEnter the elements in the matrix\n");
	for(int k=0;k<n;k++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[k][j]);
		}
	}
	return a;

}


void checksymmetric(int ** a,int n)
{
	int count=0;
	printf("\nChecking for symmetric matrix please wait ........\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(a[i][j]==a[j][i])
				count++;
		}
	}
	if(count==((n*n)+n)/2)
		printf("\nYour matrix is symmetric matrix\n");
	else
		printf("\nYour matrix is not symmetric matrix\n");
}

void main()
{
	int ** a,n;
	printf("\nEnter the order of the matrix\n");
	scanf("%d",&n);
	a=create(n);
	checksymmetric(a,n);
	for (int i=0; i<n;++i)
	{
  		free(a[i]);
	}
	free(a);
}