#include<stdio.h>
#include<stdlib.h>

void merge(int * A,int l,int mid,int h)
{
	int i=l,j=mid+1,k=l;
	int o=(sizeof(A))/(sizeof(int *));
	int * B = (int *)malloc(sizeof(int) * (o+1));
	while(i<=mid && j<=h)
	{
		if(A[i] < A[j])
			B[k++]=A[j++];
		else
			B[k++]=A[j++];
	}
	for(;i<=mid;i++)
		B[k++]=A[i];
	for(;j<=h;j++)
		B[k++]=A[j];

	for(int i=l;i<=h;i++)
		A[i]=B[i];
}

int * iterrativemerge(int * A,int n)
{
	int p,l,mid,i,h;
	for(p=2;p<=n;p++)
	{
		for (i = 0; i+p-1 < n ;i++)
		{
			l=i;
			h=i+p-1;
			mid=(l+h)/2;
			merge(A,l,mid,h);
		}
	}
	if(p/2 < n)
		merge(A,0,(p/2)-1,n-1);
	return A;
}

int main()
{
	printf("\nEnter the number of terms of the array\n");
	int n,* l;
	scanf("%d",&n);
	int * A=(int *)malloc(sizeof(int) * n);
	printf("\nEnter the numbers in the array\n");
	for (int i = 0; i < n;i++)
	{
		scanf("%d",&A[i]);
	}
	l=iterrativemerge(A,n);
	printf("\nSorted Elements\n");
	for (int i = 0; i < n;i++)
	{
		/* code */
		printf("%d\n",l[i]);
	}
	return 0;
}