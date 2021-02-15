#include<stdio.h>
#include<stdlib.h>

struct array
{
	int * A;
	int size;
	int length;
};

void display(struct array arr)
{
	int i;
	printf("\nElements in the array are \n");
	for(i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);
}

int main()
{
	struct array arr;
	printf("\nEnter size of an array");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size * sizeof(int));
	arr.length=0;
	printf("\nEnter length of an array");
	scanf("%d",&arr.length);
	printf("\nEnter the Elements\n");
	for(int i=0;i<arr.length;i++)
		scanf("%d",&arr.A[i]);
	display(arr);
	printf("\n");
	free(arr.A);
}
	
