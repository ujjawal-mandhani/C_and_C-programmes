#include<stdio.h>
int main()
{
	int n;
	float n1;
	scanf("%d",&n);
	scanf("%f",&n1);
	if(n>n1)
		printf("%f\n",n1);
	else
	{
		if(n%5 == 0)
		{
			printf("%f\n",n1-n-0.5);
		}
		else
		{
			printf("%f\n",n1);
		}
	}
}

