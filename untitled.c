#include<stdio.h>
int main()
{
	int n;
	double n1;
	scanf("%d",&n);
	scanf("%lf",&n1);
	if(n>n1)
		printf("%lf\n",n1);
	else
	{
		if(n%5 == 0)
		{
			printf("%lf\n",n1-n-0.5);
		}
		else
		{
			printf("%lf\n",n1);
		}
	}
}

