#include<stdio.h>
#include<stdlib.h>

int recurrsivefibb(int n)
{
	if(n<=1)
		return n;
	return recurrsivefibb(n-2) + recurrsivefibb(n-1);
}

int loopfibb(int n)
{
	if(n<=1)
		return n;
	int t0=0;
	int t1=1;
	int s,i;
	for(i=2;i<=n;i++)
	{
		s=t0 + t1;
		t0=t1;
		t1=s;
	}
return s;
}
int F[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int memorizefibb(int n)
{
	if (n<=1)
	{
		F[n]=n;
		return n;
	}
	else
	{
		if(F[n-2]==-1)
			F[n-2]=memorizefibb(n-2);
		if(F[n-1]==-1)
			F[n-1]=memorizefibb(n-1);
		return F[n-2]+F[n-1];
	}
}

int main()
{
	int m;
	printf("enter the value of n in fibbonacci sum \n");
	scanf("%d",&m);
	printf("\n");
	printf("Hence the fibbonacci sum of given number is \n %d \n",recurrsivefibb(m));
	printf("\n");
	printf("Hence the fibbonacci sum of given number is \n %d \n",loopfibb(m));
	printf("\n");
	printf("Hence the fibbonacci sum of given number is \n %d \n",memorizefibb(m));
}
