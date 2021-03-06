#include<stdio.h>
#include<stdlib.h>

void swap(int * x,int * y)
{
	int temp;
	temp=* x;
	* x=* y;
	* y= temp;
}
void selectionsort(int A[],int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=k=i;j<n;j++)
		{
			if(A[j]<A[k])
			{
				k=j;
			}
		}
		swap(&A[i],&A[k]);
	}
}

int main()
{
	printf("\nEnter the number of that you want to create the array\n");
	int n;
	scanf("%d",&n);
	printf("\nEnter the values in the array\n");
	int A[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	selectionsort(A,n);
	printf("Sorted Elements\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
	return 0;
}