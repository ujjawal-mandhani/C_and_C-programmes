#include<stdio.h>
#include<stdlib.h>

void swap(int * x,int * y)
{
	int temp=* x;
	* x=* y;
	* y=temp;
}

int partition(int A[],int l,int h)
{
	int pivot=A[l];
	int i=l,j=h;
	do
	{
		do{i++;}while(A[i]<=pivot);
		do{j--;}while(A[j]>pivot);
		if(i<j)
			swap(&A[i],&A[j]);
	}while(i<j);
	swap(&A[l],&A[j]);
	return j;
}
void quicksort(int A[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(A,l,h);
		quicksort(A,l,j);
		quicksort(A,j+1,h);
	}
}
int main()
{
	printf("\nEnter the number of that you want to create the array\n");
	int n;
	int l=0;
	scanf("%d",&n);
	printf("\nEnter the values in the array\n");
	int A[n+1];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	A[n]=32767;
	int h=n;
	quicksort(A,l,h);
	printf("Sorted Elements\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
	return 0;
}