#include<stdio.h>
#include<stdlib.h>
int * create(int n)
{
	int * p=(int *)malloc(n*sizeof(int));
	printf("\nEnter elements in the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	return p;
}
	
void display(int * q,int x)
{
	int i;
	printf("\nYour elements are\n");
	for(i=0;i<x;i++)
	{
		printf("%d \n",q[i]);
		
	}
}
void missingelementpart2(int * p,int n)
{
	int diff =p[0];
	for(int i=0;i<n;i++)
	{
		if(p[i]-i!=diff)
			{
				printf("\nMissing Element is %d\n",i+diff);
				break;
			}
	}
}
int missingelement1(int * p,int n)
{
	int sum =0;
	for(int i=0;i<n;i++)
	{
		sum=sum+p[i];
	}
	int s=(n+1)*(n+2)/2;
	return s-sum;
}
void missingelement3(int * p,int n)
{
	int max,i;
	max=p[0];
	for(i=1;i<n;i++)
	{
		if(max < p[i])	 
		{
			max=p[i];
		}
	}
	int * hash;
	hash=(int*)malloc(sizeof(int)*max);
	for(i=0;i<n;i++)
	{
		hash[p[i]]++;
	}
	for(int i=0;i<max;i++)
	{
		if(hash[i]==0)
		{
			printf("\nSo the missing element are%d\n",i);
		}
	}

}
int main()
{
	int x;
	printf("\nenter no of element to create array\n");
	scanf("%d",&x);
	int * p=create(x);
	display(p,x);
	//printf("\nSo the missing element is %d\n",missingelement1(p,x));
	//printf("\nSo the missing element using second method is \n");
	//missingelementpart2(p,x);
	missingelement3(p,x);
	free(p);
}
	
