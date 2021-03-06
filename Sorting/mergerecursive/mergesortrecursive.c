#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int l,int mid,int h)
{
	int i=l,j=mid+1,k=l;
	int B[100];
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


void Mergesort(int A[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		Mergesort(A,l,mid);
		Mergesort(A,mid+1,h);
		merge(A,l,mid,h);
	}
}

int main()
{
	/* code */
	int A[]={1,37,17,189,198,98,89};
	int n=7;
	Mergesort(A,0,n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",A[i]);
	}
	return 0;
}