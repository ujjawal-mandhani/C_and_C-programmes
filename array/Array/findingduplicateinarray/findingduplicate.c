#include<stdio.h>
#include<stdlib.h>
#include "createdisplay.h"


void duplicate(int * p,int n)
{
	printf("\nThe duplicate elements are in array is\n");
	int lastduplicate=0;
	for(int i=0;i<n;i++)
	{
		if(p[i]==p[i+1] && lastduplicate!=p[i])
		{
			printf("%d\n",p[i]);
			lastduplicate=p[i];
		}
	}
}
void countduplicate(int * p,int n)
{
	int j;
	printf("\nThe number duplicate elements are in array is\n");
	for(int i=0;i<n-1;i++)
	{
		if(p[i]==p[i+1])
		{
			j=i+1;
			while(p[i]==p[j])
				j++;
			printf("%d occurs %d times\n",p[i],j-i);
			i=j-1;
		}
	}
}
void countduplicate2(int * p,int n)
{
	int k;
	printf("\nThe number duplicate elements are in array is\n");
	int max=p[0];
	for(k=1;k<n;k++)
	{
		if(max<p[k])
			max=p[k];
	}
	int * hash=(int *)malloc(sizeof(int)*max);
	for(k=0;k<n;k++)
	{
		hash[p[k]]++;
	}
	for(k=0;k<=max;k++)
	{
		if(hash[k]>=2)
			printf("%d occurs %d times\n",k,hash[k]);
	}
	free(hash);
}
int issorted(int * p,int n)
{
	int i,count=0;
	for(i=0;i<n-1;i++)
	{
		if(p[i] < p[i+1])
		{
			count=count+1;
		}
	}
	if(count==n-1)
		return 1;
	else
		return 0;
}
void countduplicate3(int * p,int n)
{
	int i,j;
	int count1;
	for(i=0;i<n-1;i++)
	{
		count1=1;
		if(p[i]==-1)
		{
			for(j=i+1;j<n;j++)
			{
				if(p[i]==p[j])
				{
					count1++;
					p[j]=-1;
				}
			}
		}
		if(count1>1)
			printf("\n%d occurs %d times\n",p[i],count1);
	}
}
int main()
{
	int n;
	printf("\nEnter the value of number that you want to create array\n");
	scanf("%d",&n);
	int * p=create(n);
	if(issorted(p,n))
	{
		duplicate(p,n);
		countduplicate(p,n);
	}
	else
		printf("\nEnter sorted array\n");
	
	countduplicate2(p,n);
	countduplicate3(p,n);
	free(p);
	return 0;
}


