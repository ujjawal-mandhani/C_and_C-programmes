#include<stdio.h>
#include<stdlib.h>
#include"stackes.h"
#include"queue.h"
struct node 
{
	int data;
	struct node * lchild;
	struct node * rchild;
}* root=NULL;

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
		printf("\nEnter -1 to put the NULL in the node or to stop the tree\n");
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("\nEnter the right child of %d\n",p->data);
		printf("\nEnter -1 to put the NULL in the node or to stop the tree\n");
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
		printf("\n%d\n",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct node * p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("\n%d\n",p->data);
		inorder(p->rchild);
	}
}

void postorder(struct node * p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("\n%d\n",p->data);
	}
}

void iterpreorder(struct node * p)
{
	struct stack stk;
	createstack(&stk,100);
	while(p!=NULL || !sisEmpty(&stk))
	{
		if(p)
		{
			printf("%d\n",p->data);
			push(&stk,p);
			p=p->lchild;
		}
		else
		{
			p=pop(&stk);
			p=p->rchild;
		}
	}
}

void iterinorder(struct node * p)
{
	struct stack stk;
	createstack(&stk,100);
	while(p!=NULL || !sisEmpty(&stk))
	{
		if(p)
		{
			push(&stk,p);
			p=p->lchild;
		}
		else
		{
			p=pop(&stk);
			printf("\n%d\n",p->data);
			p=p->rchild;
		}

	}
}
void deallocate(struct node * p)
{
	if(p==NULL)
		return;
	deallocate(p->lchild);
	deallocate(p->rchild);

	free(p);
}
int main()
{
	Treecreate();
	preorder(root);
	iterinorder(root);
	iterpreorder(root);
	deallocate(root);
}