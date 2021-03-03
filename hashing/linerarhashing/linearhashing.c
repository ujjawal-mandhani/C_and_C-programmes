#include<stdio.h>
#include<stdlib.h>
#define size 10

int hash(int key)
{
	return key%size;
}

int probe(int H[],int key)
{
	int index=hash(key);
	int i=0;
	while(H[index + i]% size!= 0)
		i++;
	return (index + i)%size;
}

void Insert(int H[],int key)
{
	int index=hash(key);
	if(H[index]!=0)
		index=probe(H,key);
	H[index]=key;
}

int search(int H[],int key)
{
	int index=hash(key);
	int i;
	while(H[(index+i)%size]!=key)
		i++;
	return (index + i)%size;
}

int main()
{
	int n,x;
	printf("\nEnter the value of size that you want to enter in the array\n");
	scanf("%d",&n);
	int H[n];
	printf("\nEnter the value of element in the array\n");
	for (int i = 0; i < n; i++)
	{
		/* code */
		scanf("%d",&x);
		Insert(H,x);
	}
	printf("\nEnter the element that you want search\n");
	int s;
	scanf("%d",&s);
	printf("\nElement %d found\n",search(H,s)); 
	return 0;

}