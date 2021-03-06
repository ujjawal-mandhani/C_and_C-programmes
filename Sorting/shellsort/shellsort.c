#include<stdio.h>
#include<stdlib.h>

void Shellsort(int * A,int n)
{
	int gap,i,j,temp;
	for (gap = n/2 ; gap >1 ; gap/=2)
	{
		/* code */
		for (i = gap; i < n; i++)
		{
			/* code */
			temp=A[i];
			j=i-gap;
			while(j>0 && A[j]>temp)
			{
				A[j+gap]=A[j];
				j=j-gap;
			}
			A[j+gap]=temp;
		}
	}
}

int main()
{
	/* code */
	printf("\nEnter the number of terms in the array\n");
	int n;
	scanf("%d",&n);
	printf("\nEnter the elements in the array\n");
	int * A;
	A=(int *)malloc(sizeof(int) * (n+1));
	for (int i = 0; i < n; i++)
	{
		/* code */
		scanf("%d",&A[i]);
	}
	Shellsort(A,n);
	printf("\nSorted elements are\n");
	for (int i = 0; i < n; i++)
	{
		/* code */
		printf("%d\n",A[i]);
	}
	free(A);
	return 0;
}