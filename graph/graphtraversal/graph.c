#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;

}* front=NULL,* rear=NULL;

void enqueue(int x)
{
	struct node * t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
		printf("\nHeap memory is full :(\n");
	else
	{
		t->data=x;
		t->next=NULL;
		if(front==NULL)
			front=rear=t;
		else
		{
			rear->next=t;
			rear=t;
		}
	}
}

int dequeue()
{
	int x=-32767;
	struct node * t;
	if(front==NULL)
		printf("\nSeems that queue is already empty\n");
	else
	{
		x=front->data;
		t=front;
		front=front->next;
		free(t);
	}
	return x;
}

int isEmpty()
{
	return front==NULL;
}

void BFS(int G[][7],int start,int n)
{
	int i=start;
	int visited[7];
	for (int k = 0; k < 7; k++)
	{
		visited[k]=0;
	}
	printf("\n%d\n",i);
	visited[i]=1;
	enqueue(1);
	while(!isEmpty())
	{
		i=dequeue();
		for (int j = 0; j < n; j++)
		{
			if(G[i][j]==1 && visited[j]==0)
			{
				printf("\n%d\n",j);
				visited[j]=1;
				enqueue(j);
			}
		}
	}
}

void DFS(int G[][7],int start,int n)
{
	static int visited[7];
	for (int i = 0; i < 7; i++)
	{
		visited[i]=0;
	}
	if(visited[start]==0)
	{
		printf("%d\n",start);
		visited[start]=1;
		for (int i = 0; i < 7; ++i)
		{
			if(G[start][i]==1 && visited[i]==0)
			{
				DFS(G,i,n);
			}
		}
	}
}

int main()
{
	int G[7][7]={
		{0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};
	BFS(G,1,7);/*
	DFS(G,1,7);*/ /*Incomplete Base condition is not complete*/
	return 0;
}