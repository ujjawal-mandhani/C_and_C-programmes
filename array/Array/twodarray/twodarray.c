#include<stdio.h>
#include<stdlib.h>

void twodarray1(int row,int column)
{
	int * A[row];
	int i,j;
	for(i=0;i<row;i++)
		A[i]=(int *)malloc(column * sizeof(int)); 
	printf("\n enter elements in the array using first method \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("\n The array you have entered is \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<row;i++)
		free(A[i]);
}
void twodarray2(int row,int column)
{
	int ** A;
	A=(int **)malloc(column * sizeof(int));
	int i,j;
	for(i=0;i<row;i++)
		A[i]=(int *)malloc(column * sizeof(int));
	printf("\n enter elements in the array using second method \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("\n The array you have entered is \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<row;i++)
		free(A[i]);
}

void twodarray3(int row,int column)
{
	int A[3][4];
	int i,j;
	printf("\n enter elements in the array using Third method \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("\n The array you have entered is \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int r,c;
	printf("\n enter the number of rows using first methood \n");
	scanf("%d",&r);
	printf("\n enter the number of columns\n");
	scanf("%d",&c);
	twodarray1(r,c);
	twodarray2(r,c);
	twodarray3(r,c);
}
	
