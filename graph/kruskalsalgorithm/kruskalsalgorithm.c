#include<stdio.h>
#include<stdlib.h>
#define I 32767

int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};

int included[9]={0,0,0,0,0,0,0,0,0};

int edges[3][9]={
					{1,1,2,2,3,4,4,5,5},
					{2,6,3,7,4,5,7,6,7},
					{2,5,5,12,10,16,14,20,18}
};

int t[2][6];

void myunion(int u,int v)
{
	if(set[u] < set[v])
	{
		set[v]=u;
	}
	else
	{
		set[v]+=set[u];
		set[u]=v;
	}
}

int find(int u)
{
	int x=u,v=0;
	while(set[x] > 0)
		x=set[x];
	while(u!=x)
	{
		v=set[v];
		set[u]=x;
		u=v;
	}
}

int main()
{
	int i,j,k,u,v,min=I,n=7,e=9;
	i=0;
	while(i < n-1)
	{
		min=I;
		for (j = 0; i < e; j++)
		{
			/* code */
			if(edges[2][j] < min)
			{
				min=edges[2][j];
				u=edges[0][j];
				v=edges[0][j];
				k=j;
			}
		}
		if(find(u)!= find(v))
		{
			t[0][i]=u;
			t[1][i]=v;
			myunion(find(u),find(v));
			i++;
		}
		included[k]=1;
	}
	for (int i = 0; i < n-1; i++)
	{
		/* code */
		printf("%d %d\n",t[0][i],t[1][i] );
	}
}