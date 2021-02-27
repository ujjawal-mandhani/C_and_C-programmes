#include<stdio.h>
#include<stdlib.h>
#include"stackes.h"

struct node 
{
	int data;
	struct node * lchild;
	struct node * rchild;
}* root=NULL;

void insert(int key)
{
	struct node * t=root;
	struct node * r,* p;
	if(root==NULL)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return;
	}
	while(t!=NULL)
	{
		r=t;
		if(key < t->data)
		{
			t=t->lchild;
		}
		else if(key > t->data)
		{
			t=t->rchild;
		}
		else
			return;
	}
	p=(struct node *)malloc(sizeof(struct node));
	p->data=key;
	p->lchild=p->rchild=NULL;
	if(key < r->data)
		r->lchild=p;
	else
		r->rchild=p;
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

struct node * search(int key)
{
	struct node * t=root;
	while(t!=NULL)
	{
		if(t->data == key)
			return t;
		else if(t->data > key)
		{
			t=t->lchild;
		}
		else
		{
			t=t->rchild;
		}
	}
	return NULL;
}
struct node * recursiveinsert(struct node * p,int key)
{
	if(p==NULL)
	{
		struct node * t=(struct node *)malloc(sizeof(struct node));
		t->lchild=t->rchild=NULL;
		t->data=key;
		return t;
	}

	if(key < p->data)
	{
		p->lchild=recursiveinsert(p->lchild,key);
	}
	else if(key > p->data)
	{
		p->rchild=recursiveinsert(p->rchild,key);
	}
}

int height(struct node * p)
{
	int x,y;
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		x=height(p->lchild);
		y=height(p->rchild);
		return x>y?x+1:y+1;
	}
}

struct node * inpre(struct node * p)
{
	while(p && p->rchild)
	{
		p=p->rchild;
	}
	return p;
}

struct node * insucc(struct node * p)
{
	while(p && p->lchild)
	{
		p=p->lchild;
	}
	return p;
}
struct node * delete(struct node * p,int key)
{
	struct node * q=NULL;
	if(p==NULL)
		return NULL;
	if(p->lchild && p->rchild)
	{
		if(p==root)
		{
			root=NULL;
			free(p);
			return NULL;
		}
	}

	if(key > p->data)
	{
		p->lchild=delete(p->lchild,key);
	}
	else if(key < p->data)
	{
		p->rchild=delete(p->rchild,key);
	}
	else
	{
		if(height(p->lchild) > height(p->rchild))
		{
			q=inpre(p->lchild);
			p->data=q->data;
			p->lchild=delete(p->lchild,q->data);
		}
		else
		{
			q=insucc(p->rchild);
			p->data=q->data;
			p->rchild=delete(p->rchild,q->data);
		}
	}
	return p;
}
void deallocate(struct node * p)
{
	if(p==NULL)
		return;

	deallocate(p->lchild);
	deallocate(p->rchild);
	free(p);
}
void createpreorder(int * pre, int n)
{
	struct stack stk;
	struct node * t;
	struct node * p;
	int i=0;
	if(root==NULL)
		root=(struct node *)malloc(sizeof(struct node));
	else
	{
		printf("\nSeems that your tree is already contains some elements\n");
		return;
	}
	root->data=pre[i++];
	root->lchild=root->rchild=NULL;
	p=root;
	while(i<n)
	{
		if(pre[i] < p->data)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=pre[i++];
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			push(&stk,p);
			p=t;
		}
		else
		{
			if(pre[i] > p->data && pre[i] < (stackTop(&stk))->data)
			{
				t=(struct node *)malloc(sizeof(struct node));
				t->data=pre[i++];
				t->lchild=t->rchild=NULL;
				p=t;
			}
			else
				p=pop(&stk);
		}
	}
}

int main()
{
	int choice=1;
	int cout=0;
	while(choice)
	{
		printf("\n1.Insert the number in the binary search tree\n");
		printf("\n2.Insert the number in the binary search tree using recursive method\n");
		printf("\n3.Display the binary search tree using preorder traversal\n");
		printf("\n4.Display the binary search tree using inorder traversal\n");
		printf("\n5.Display the binary search tree using postorder traversal\n");
		printf("\n6.Search the elements in the binary Search tree\n");
		printf("\n7.Deleting the element in the binary search tree by taking value from the user\n");
		printf("\n8.Creating the binary search tree using preorder treversal\n");
		printf("\n9.Exit the program\n");
		printf("\nEnter the choice that you want to execute\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\nEnter the element that you want to insert in binary search tree\n");
					int x1;
					scanf("%d",&x1);
					insert(x1);
					cout++;
					printf("\nYour element is inserted successfully ;)\n");

			break;

			case 2:
					printf("\nEnter the element that you want to insert in binary search tree using recursive method\n");
					int x3;
					scanf("%d",&x3);
					struct node * t3;
					/*t3=root;
					recursiveinsert(t3,x3);*/
					cout++;
					printf("\nYour element is inserted successfully ;)\n");

			break;

			case 3:
					printf("\nThe preorder traversal of the tree is\n");
					preorder(root);
			break;

			case 4:
					printf("\nThe inorder traversal of the tree is\n");
					inorder(root);
			break;

			case 5:
					printf("\nThe postorder traversal of the tree is\n");
					postorder(root);
			break;

			case 6:
					printf("\nEnter the element that you want to search in binary search tree\n");
					int x2;
					scanf("%d",&x2);
					struct node * t1=search(x2);
					cout++;
					if(t1==NULL)
						printf("\nSeems that your element not found\n");
					printf("\nYour element %d is found successfully ;)\n",t1->data);
					cout++;
			break;

			case 7:
					printf("\nEnter the element that you want to delete in binary search tree\n");
					int x5;
					scanf("%d",&x5);
					struct node * t4=root;
					delete(t4,x5);
					cout++;
					/*if(t4==NULL)
						printf("\nSeems that your element was root or Your binary search tree is already empty\n");
					printf("\nYour element %d is found successfully ;)\n",t4->data);*/
					printf("\nYour element deleted successfully ;)\n");
					cout++;

			break;

			case 8:
					printf("\nEnter the number of element of the tree that you want to create\n");
					int b;
					scanf("%d",&b);
					printf("\nPlease Enter the preorder traversal of the binary search tree\n");
					int * arr=(int *)malloc(sizeof(int) * b);
					for(int m=0; m<b; m++)
					{
						printf("%d ->",m);
						scanf("%d",&arr[m]);
					}
					createpreorder(arr,b);
					cout++;
			break;

			case 9:
					choice=0;
					if(root==NULL && cout == 0)
						printf("\nSeems that you don't like my program :(\n");
					else
					{
						deallocate(root);
						printf("\nExitting........\n");
					}
			break;
		}
	}
}