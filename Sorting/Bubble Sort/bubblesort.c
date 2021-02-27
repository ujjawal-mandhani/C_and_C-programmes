#include<stdio.h>
#include<stdlib.h>

void swap(int * x,int * y)
{
	int temp = * x;
	* x = * y;
	* y = temp;

}
void Bubble(int A[],int n)
{
	int i,j;
	for(i=0;i< n-1 ;i++)
	{
		for(j=0;j< n-1-i ;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
			}
		}
	}
}
void Bubbleimprove(int A[],int n)
{
	int i,j,flag=0;
	for(i=0 ; i < n-1 ; i++)
	{
		flag=0;
		for(j=0;j< n-1-i ; j++)
		{
			if(A[j] > A[j+1])
			{
				swap(&A[j],&A[j+1]);
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}

int main()
{
	printf("\nEnter the value of array that you want to create\n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("\nEnter the values in the array\n");
	for (int i = 0; i < n ; ++i)
	{
		scanf("%d",&A[i]);
	}
	printf("\nSorted order in improved binary search\n");
	Bubbleimprove(A,n);
	for (int i = 0; i < n ; ++i)
	{
		printf("%d\n",A[i]);
	}
	Bubble(A,n);
	printf("\nSorted order\n");
	for (int i = 0; i < n ; ++i)
	{
		printf("%d\n",A[i]);
	}
	return 0;

}