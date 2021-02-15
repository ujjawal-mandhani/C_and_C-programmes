#include<stdlib.h>
#include<stdio.h>

int erecursive(int x,int n)
{
	static int s=1;
	if(n==0)
		return s;
	s=1+(x/n)*s;
	return erecursive(x,n-1);
}
int eloop(int x,int n)
{
	int s=1;
	for(;n>0;n--)
		s=1+(x/n)*s;
	return s;
}
int main()
{
	int m,l;
	printf("enter the value of x in taylor series \n");
	scanf("%d",&m);
	printf("enter the number of terms in taylor series ie n \n");
	scanf("%d",&l);
	printf("The value of taylor series througrh recursion is \n %d \n",erecursive(m,l));
	printf("The value of taylor series througrh loop is \n %d \n",eloop(m,l));
	return 0;
}
