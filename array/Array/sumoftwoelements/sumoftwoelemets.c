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
void findpair(int * p,int n,int k)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i]+p[j]==k)
			printf("\n%d and %d are the pairs whose sum is %d\n",p[i],p[j],k);
		}
	}
}
void findpair2(int * p,int n,int k)
{
	int i;
	int * hash=(int *)malloc(sizeof(int)*k);
	for(i=0;i<n;i++)
	{
		if(hash[k-p[i]]!=0)
		{
			printf("\n%d and %d are the pairs whose sum is %d\n",p[i],k-p[i],k);
		}
		else
			hash[p[i]]++;
	}
	free(hash);
}
void findpair3(int * p,int n,int k)
{
	int i=0,j=n-1;
	if(issorted(p,n))
	{
		while(i<j)
		{	
			if(p[i]+p[j]==k)
			{
				printf("\n%d and %d are the pairs whose sum is %d\n",p[i],p[j],k);
				i++;
				j--;
			}
		else if(p[i]+p[j]<k)
			i++;
		else 
			j--;
		}
	}
	else
		printf("\nplease enter sorted array or there is no pairs can be generated\n");
}
int main()
{
	printf("\nEnter the number of elements in the array\n");
	int n,k;
	scanf("%d",&n);
	int * p=create(n);
	printf("\nEnter the number that you want to sum as pairs in the array\n");
	scanf("%d",&k);
	printf("\nSo,the pairs of number of elements are\n");
	findpair(p,n,k);
	printf("\nSo,the pairs of number of elements using second method are\n");
	findpair2(p,n,k);
	printf("\nSo,the pairs of number of elements using third method are\n");
	findpair3(p,n,k);
	free(p);
	return 0;
}
