#include<stdio.h>
#include<stdlib.h>

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
	q->Q=(struct node **)malloc(struct node *);
}

void enqueue(struct queue * q,node * x)
{
	if((q->rear + 1)%q->size==q->front)
		printf("\nQueue is full\n");
	else
	{
		q->rear=(q->rear)%q->size;
		q->Q[q->rear]=x;
	}
}

node * dequeue(struct node * q)
{
	node * x=NULL;
	if(q->front==q->rear)
		printf("\nQueue is full\n");
	else
	{
		q->front=(q->front + 1)q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct queue q)
{
	return q.front=q.rear;
}

void Treecreate()
{
	struct node * p,* t;
	int x;
	struct queue q;
	create(&q,100);
	printf("\nEnter the root value\n");
	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!isEmpty(&q))
	{
		p=dequeue(&q);
		printf("\nEnter left child of %d\n",p->data);
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
		printf("%d",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

int main()
{
	Treecreate();
	preorder(root);
	return 0;
}