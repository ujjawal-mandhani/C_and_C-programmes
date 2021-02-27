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
		printf("\nEnter -1 to stop grow the tree\n");
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
	while(p || !sisEmpty(&stk))
	{
		if(p)
		{
			push(&stk,p);
			p=p->lchild;
		}
		else
		{
			p=pop(&stk);
			printf("%d\n",p->data);
			p=p->rchild;
		}
	}
}
/*void iterpostorder(struct node * p)
{
	struct stack stk;
	long int temp;
	while(p!=NULL || sisEmpty(stk))
	{
		if(p!=NULL)
		{
			push(&stk,p);
			p=p->lchild;
		}
		else
		{
			temp=pop(&stk);
			if(temp>0)
			{
				push(&stk,-temp);
				t=((node *)temp)->rchild;
			}
			else
			{
				printf("%d\n",((node *)temp->data ));
				t=NULL;
			}
		}
	}
}*/
void levelorder(struct node * p)
{
	struct queue q;
	printf("%d\n",p->data);
	enqueue(&q,p);
	while(!isEmpty(q))
	{
		p=dequeue(&q);
		if(p->lchild)
		{
			printf("%d\n",p->data);
			enqueue(&q,p->lchild);
		}
		if(p->rchild)
		{
			printf("%d\n",p->data);
			enqueue(&q,p->rchild);
		}
	}
}

int countingnodes(struct node * p)
{
	int x,y;
	if(p)
	{
		x=countingnodes(p->lchild);
		y=countingnodes(p->rchild);
		return x+y+1;
	}
	return 0;
}

int countingnodesdeg2(struct node * p)
{
	int x,y;
	if(p)
	{
		x=countingnodesdeg2(p->lchild);
		y=countingnodesdeg2(p->rchild);
		if(p->lchild && p->rchild)
		{
			return x+y+1;
		}
		else
			return x+y;
	}
	return 0;
}

int sumofnodes(struct node * p)
{
	int x,y;
	if(p)
	{
		x=sumofnodes(p->lchild);
		y=sumofnodes(p->rchild);
		return x+y+p->data;
	}
	return 0;
}

int height(struct node * p)
{
	int x,y;
	x=y=0;
	if(p)
	{
		x=height(p->lchild);
		y=height(p->rchild);
		if(x>y)
			return x+1;
		else
			return y+1;
	}
}

int countingnodesdeg0(struct node * p)
{
	int x,y;
	if(p)
	{
		x=countingnodesdeg0(p->lchild);
		y=countingnodesdeg0(p->rchild);
		if(p->lchild==NULL && p->rchild==NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
	return 0;
}

int countingnodesdeg1(struct node * p)
{
	int x,y;
	if(p)
	{
		x=countingnodesdeg1(p->lchild);
		y=countingnodesdeg1(p->rchild);
		if(p->lchild!=NULL ^ p->rchild!=NULL)  /*if((p->lchild!=NULL && p->rchild==NULL) || (p->lchild==NULL && p->rchild!=NULL))*/
		{
			return x+y+1;
		}
		else
		{
			x+y;
		}
	}
	return 0;
}
void deallocate (struct node * p)
{
    if(p==NULL)
    	return;

    deallocate(p->lchild);
    deallocate(p->rchild);

    free(p);
}
int main()
{
	int choice =1;
	static int cout=0;
	while(choice)
	{
		printf("\n1.Create the tree\n");
		printf("\n2.Preorder traversal by recursive method\n");
		printf("\n3.Inorder traversal by recursive method\n");
		printf("\n4.Postorder traversal by recursive method\n");
		printf("\n5.Preorder traversal by Iterative method\n");
		printf("\n6.Inorder traversal by Iterative method\n");
		printf("\n7.Postorder traversal by Iterative method\n");
		printf("\n8.Counting the number of nodes in the tree(recursive)\n");
		printf("\n9.Counting the number of nodes with degree 0 (leaf nodes)in the tree(recursive)\n");
		printf("\n10.Counting the number of nodes with degree 1 in the tree(recursive)\n");
		printf("\n11.Counting the number of nodes with degree 2 in the tree(recursive)\n");
		printf("\n12.Counting the sum of all nodes in the tree by recursive method\n");
		printf("\n13.Counting the height of the tree by recursive method\n");
		printf("\n14.Exit the program :(\n");
		printf("\nEnter the choice that you want to execute\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\nWe are creating your tree please wait ;)\n");
					Treecreate();
					cout++;
			break;

			case 2:
					printf("\nThe preorder traversal of the tree is by recursive method\n");
					preorder(root);
					cout++;
			break;

			case 3:
					printf("\nThe Inorder traversal of the tree is by recursive method\n");
					inorder(root);
					cout++;
			break;

			case 4:
					printf("\nThe Postorder traversal of the tree is by recursive method\n");
					postorder(root);
					cout++;
			break;

			case 5:
					printf("\nThe Preorder traversal of the tree is by iterative method\n");
					iterpreorder(root);
					cout++;
					
			break;

			case 6:
					printf("\nThe Inorder traversal of the tree is by iterative method\n");
					iterinorder(root);
					cout++;
			break;

			case 7:
					printf("\nThe Inorder traversal of the tree is by iterative method\n");
					//iterpostorder(root);
			break;

			case 8:
					printf("\nCounting the number of nodes in the tree by recursive method\n");
					int x1=countingnodes(root);
					cout++;
					printf("\nThe nomber nodes present in the tree are %d\n",x1);
			break;

			case 9:
					printf("\nCounting the number of nodes in the tree of degree 0 by recursive method\n");
					int x2=countingnodesdeg0(root);
					printf("\nThe nomber nodes present in the tree of degree 0 are %d\n",x2);
					cout++;
			break;

			case 10:
					printf("\nCounting the number of nodes in the tree of degree 1 by recursive method\n");
					int x3=countingnodesdeg1(root);
					printf("\nThe nomber nodes present in the tree of degree 1 are %d\n",x3);
					cout++;
			break;

			case 11:
					printf("\nCounting the number of nodes in the tree of degree 2 by recursive method\n");
					int x4=countingnodesdeg2(root);
					printf("\nThe nomber nodes present in the tree of degree 2 are %d\n",x4);
					cout++;
			break;

			case 12:
					printf("\nFinding the sum of all the nodes present in the tree by recursive method\n");
					int x5=sumofnodes(root);
					printf("\nThe sum of all the elements present in the nodes are %d\n",x5);
					cout++;
			break;

			case 13:
					printf("\nFinding the height of the tree \n");
					int x6=height(root);
					printf("\nThe height of the tree is %d\n",x6);
					cout++;
			break;

			case 14:
					choice=0;
					if(cout==0 || root==NULL)
						printf("\nSeems that you don't like my program :(\n");
					else
					{
						printf("\nExiting............\n");
						deallocate(root);
					}
			break;
		}
	}
	/*printf("preorder\n");
	preorder(root);
	printf("\nInorder\n");
	inorder(root);
	printf("\npostorder\n");
	postorder(root);
	printf("\npreorder\n");
	iterpreorder(root);
	printf("\nInorder\n");
	iterinorder(root);*/
	/*int h=countingnodes(root);
	printf("%d\n",h);
	int h2=countingnodesdeg2(root);
	printf("%d\n",h2);*/
	/*int h3=sumofnodes(root);
	printf("%d\n",h3);*/
	/*int h4=height(root);
	printf("%d\n",h4);*/
	/*int h5=countingnodesdeg0(root);
	printf("%d\n",h5);*/
	/*int h5=countingnodesdeg1(root);
	printf("%d\n",h5);*/
	/*printf("\nlevelorder\n");
	levelorder(root);*/
	return 0;
}