#include<stdio.h>
#include<stdlib.h>

int * increasesize(int * p,int * q,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		 q[i]=p[i];
	}
	free(p);
	p=q;
	return p;
}
void display(int * q,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("%d \n",q[i]);
		
	}
}

int main()
{
	int x,i;
	printf("enter no of element to create array");
	scanf("%d",&x);
	int * p=(int *)malloc(x*sizeof(int));
	printf("\n enter number in the array\n");
	for(i=0;i<x;i++)
	{
		scanf("%d",&p[i]);
	}
	int y;
	printf("\nenter the new size to create new size of array");
	scanf("%d",&y);
	int * q=(int *)malloc(y*sizeof(int));
	display(increasesize(p,q,x),y);
	free(q);
}
	
	
