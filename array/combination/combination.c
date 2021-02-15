#include<stdio.h>

int fact(int n)
{
	if(n==0)
		return 1;
	return n*fact(n-1);
}

int C1(int r,int n)
{
	int t1=fact(n);
	int t2=fact(n-r);
	int t3=fact(r);
	return t1/(t2*t3);
}

int C2(int r,int n)
{
	if(n==r||r==0)
		return 1;
		
	return C2(r-1,n-1)+C2(r,n-1);
	
}
int main()
{
	int l,m;
	printf("Enter the value of r and n to find the combination \n");
	scanf("%d %d",&l,&m);
	printf("\n so the combination(normal)of %d and %d is:\n",m,l);
	printf("%d",C1(l,m));
	printf("\n so the combination(recursion)of %d and %d is:\n",m,l);
	printf("%d \n",C2(l,m)); 
	
}
	
