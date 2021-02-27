#include<stdio.h>
#include<stdlib.h>

void insertion(int A[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		j=i-1;
		x=A[i];
		while(j>-1 && A[j] > x)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
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
	printf("\nSorted order\n");
	insertion(A,n);
	for (int i = 0; i < n ; ++i)
	{
		printf("%d\n",A[i]);
	}
	return 0;

}