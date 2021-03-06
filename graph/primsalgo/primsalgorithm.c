#include<stdio.h>
#include<stdlib.h>
#define I 32767

int cost[][8]= {
			{I,I,I,I,I,I,I,I},
			{I,I,25,I,I,I,6,I},
			{I,25,I,12,I,I,I,I},
			{I,I,12,I,8,I,I,I},
			{I,I,I,8,I,16,I,14},
			{I,I,I,I,16,I,20,18},
			{I,5,I,I,I,20,I,I},
			{I,I,I,I,14,I,18,I}
		};
int t[2][6];
int near[8]={I,I,I,I,I,I,I,I};

int main()
{
	int i,j,k,u,v,n=7,min=I;
	for (i = 1; i <=n ; i++)
	{
		/* code */
		for (j = i; j <= n; j++)
		{
			/* code */
			if (cost[i][j] < min)
			{
				/* code */
				min=cost[i][j];
				u=i;
				v=j;
			}
		}
	}
	t[0][0]=u;
	t[1][0]=v;
	near[u]=near[v]=0;
	for (i = 1; i <= n; i++)
	{
		/* code */
		if(near[i]!=0)
		{
			if(cost[i][u] < cost[i][v])
				near[i]=u;
		}
		else
			near[i]=v;
	}
	for (i = 0; i < n-1; i++)
	{
		/* code */
		min=I;
		for (j = 1;j<=n; j++)
		{
			/* code */
			if(cost[j][near[j]] < min && near[j]!=0)
			{
				k=j;
				min=cost[j][near[j]];
			}
		}
		t[0][i]=k;
		t[1][j]=near[k];
		near[k]=0;
		for (j = 0; j <= n; j++)
		{
			/* code */
			if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
				near[j]=k;
		}
	}
	for ( i = 0; i < n-1; i++)
	{
		/* code */
		printf("%d %d\n",t[0][i],t[1][i]);
	}
	return 0;
}