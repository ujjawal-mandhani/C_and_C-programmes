#include<stdio.h>
void TOH(int n,int A,int B,int C)
{
	if(n>0)
	{
		TOH(n-1,A,C,B);
		printf("Move the disc from %d Tower to %d Tower\n",A,C);
		TOH(n-1,B,A,C);
	}
}

int main()
{
	int k;
	printf("Enter the number of Disc in the first pannel\n");
	scanf("%d",&k);
	printf("\nMove the disc in this oreder\n");
	TOH(k,1,2,3);
}
