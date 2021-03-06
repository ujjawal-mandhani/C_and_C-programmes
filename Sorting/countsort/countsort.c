#include<stdio.h>
#include<stdlib.h>

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
void countsort(int * A,int n)
{
	int i,j,max,* c;
	max=findmax(A,n);
	c=(int *)malloc(sizeof(int) * (max + 1));
	for (i = 0; i < max + 1; i++)
		c[i]=0;
	for (i = 0; i < n; i++)
		c[A[i]]++;
	i=j=0;
	while(i< max + 1)
	{
		if(c[i]>0)
		{
			A[j++]=i;
			c[i]--;
		}
		else
			i++;
	}
}

int main()
{
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
	countsort(A,n);
	printf("\nSorted elements are\n");
	for (int i = 0; i < n; i++)
	{
		/* code */
		printf("%d\n",A[i]);
	}
	return 0;
}