#include<stdio.h>
#include<stdlib.h>

struct node
{
	int col;
	int data;
	struct node * next;
};

struct node ** create(int r,int c)
{
	struct node ** q=NULL;
	struct node * p=NULL;
	int x;
	printf("\nWe are creating your sparse matrix please wait......\n");
	struct node ** A;
	A=(struct node **)malloc(sizeof(struct node *)* r);
	for(int i=0;i<r;i++)
		A[i]=NULL;
	printf("\nEnter the elements in the matrix\n");
	for(int i=0;i<r;i++)
	{
		p=A[i];
		for(int j=0;j<c;j++)
		{
			scanf("%d",&x);
			if(x!=0)
			{
				if(p!=NULL)
				{
					while(p->next!=NULL)
						p=p->next;
					p->next=(struct node *)malloc(sizeof(struct node));
					p->next->col=j;
					p->next->data=x;
					p->next->next=NULL;
				}
				else if(p==NULL)
				{
					A[i]=(struct node *)malloc(sizeof(struct node));
					A[i]->col=j;
					A[i]->data=x;
					A[i]->next=NULL;
				}
			}
		}
	}
	for(int i=0;i<r;i++)
	{
		p=A[i];
		for(int j=0;j<c;j++)
		{
			
			while(p!=NULL){
			printf("%d",p->data);
			p=p->next;
		}
		}
	}
	q=A;
	return q;
}
void display(struct node ** q,int r,int c)
{
	printf("\nThe elements in the matrix are\n");
	struct node * p=NULL;
	for(int i=0;i<r;i++)
	{
		p=q[i];
		for(int j=0;j<c;j++)
		{
			if(p==NULL)
				printf(" 0 ");
			else if(p!=NULL)
			{
				if(j==p->col)
				{
					printf(" %d ",p->data);
					p=p->next;
				}
				else
				{
					//printf(" 0 ");
					//p=p->next;
				}
			}
		}
		printf("\n");
	}
}
int main()
{
	int ro,co;
	printf("\nPlease enter the number of rows of matrix\n");
	scanf("%d",&ro);
	printf("\nPlease enter the number of cols of matrix\n");
	scanf("%d",&co);
	struct node ** p=create(ro,co);
	display(p,ro,co);
	free(p);
	return 0;
}