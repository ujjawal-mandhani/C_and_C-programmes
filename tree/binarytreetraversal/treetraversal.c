#include<stdio.h>
#include<stdlib.h>
#include"stackes.h"
struct node
{
	int data;
	struct node * lchild;
	struct node * rchild;
}* root=NULL;

struct queue
{
	int size;
	int front;
	int rear;
	struct node ** Q;
};


void create(struct queue * q,int size)
{
	q->size=size;
	q->front=q->rear=0;
	q->Q=(struct node **)malloc(sizeof(struct node *));
}

void enqueue(struct queue * q,struct node * x)
{
	if((q->rear + 1)%q->size==q->front)
		printf("\nQueue is full\n");
	else
	{
		q->rear=(q->rear + 1)%q->size;
		q->Q[q->rear]=x;
	}
}

struct node * dequeue(struct queue * q)
{
	struct node * x=NULL;
	if(q->front==q->rear)
		printf("\nQueue is empty\n");
	else
	{
		q->front=(q->front + 1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct queue q)
{
	return q.front==q.rear;
}

void Treecreate()
{
	struct node * p,* t;
	int x;
	struct queue q;
	create(&q,100);
	printf("\nEnter the root value\n");
	scanf("%d",&x);
	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!isEmpty(q))
	{
		p=dequeue(&q);
		printf("\nEnter left child of %d\n",p->data);
		printf("\nEnter -1 to stop grow the tree\n");
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("\nEnter the right child of %d\n",p->data);
		printf("\nEnter -1 to stop grow the tree\n");
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void preorder(struct node * p)
{
	if(p)
	{
		printf("%d\n",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct node * p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%d\n",p->data);
		inorder(p->rchild);
	}
}

void postorder(struct node * p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d\n",p->data);
	}
}
int main()
{
	Treecreate();
	preorder(root);
	inorder(root);
	postorder(root);
	return 0;
}