#include<stdio.h>
#include<stdlib.h>

void insert(int * H,int n)
{
	int i=n,temp;
	trmp=H[i];
	while(i>1 && temp > H[i/2])
	{	
		H[i]=H[i/2];
		i=i/2;
	}
	A[i]=temp;
}

int delete(int * A,int n)
{
	int i,j,val=A[i];
	x=A[n];
	A[1]=A[n];
	A[n]=val;
	i=1;
	j=2*i;
	while(j < n-1)
	{
		if(A[j+1] > A[j])
			j=j+1;
		if(A[i] < A[j])
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i=j;
			j=2*i;
		}
		else
			break;
	}
	return val;
}

int main()
{	
	int choice=1;
	int cout=0;
	int * H;
	while(choice)
	{
		printf("\n1.Create the heap\n");
		printf("\n2.Insert the element in the heap\n");
		printf("\n3.Delete the element from the heap\n");
		printf("\n4.Dispaly the element of the heap array\n");
		printf("\n5.Exit the program :(\n");
		printf("\nEnter the choice that you want to execute\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\nCreate the heap array\n");
					int n;
					printf("\nEnter the size of the array that you want to create\n");
					scanf("%d",&n);
					int H[n];
					printf("\nEnter the elements in the heap array\n");
					H[0]=0;
					for(int i=1;i<n;i++)
						scanf("%d",&H[i]);
					printf("\nYour array is created ;)\n");
			break;

			case 2:
					printf("\nEnter the element that you want to insert in the heap array\n");
					int x;
					scanf("%d",&x);
					insert(H,x);
			break;

			case 3:
					printf("\nEnter the element you want to insert in the heap array\n");
					int x2;
					scanf("%d",&x2);
					insert(H,x2);

			break;

			case 4:
					printf("\nThe elements in the heap array are\n");
					for(int k=0;k<)
			break;

			case 5:
					/*if(H==NULL && cout ==0)
						printf("\nSeems that you don't like my program\n");*/
					free(H);
					choice=0;
		}
	}
}