#include<stdio.h>
#include<stdlib.h>

struct node{
	int coeff;
	int exp;
	struct node * next;
}* first=NULL,* last=NULL;

struct node * create()
{
	struct node * p;
	struct node * t;
	int n;
	printf("\nEnter the number of terms of polynomial\n");
	scanf("%d",&n);
	printf("\nEnter the coefficient and exponent of the polynomial\n");
	for(int i=0;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		scanf("%d %d",&t->coeff,&t->exp);
		if(first==NULL)
			first=last=t;
		else
		{
			last->next=t;
			last=t;
		}
	}
	p=first;
	return p;
}

void display(struct node * p)
{
	first=p;
	while(p!=NULL)
	{
		if(p->next!=NULL)
			printf("%dx%d +",p->coeff,p->exp);
		else
			printf("%dx%d\n",p->coeff,p->exp);
		p=p->next;
	}
	printf("\n");
	p=first;
}
int power(int val,int p)
{
	int s=1;
	for(int i=0;i<p;i++)
		s=s*val;
	return s;
}
long evaluation(struct node * p,int x)
{
	long sum=0;
	while(p!=NULL)
	{
		sum=sum+ p->coeff*(power(x,p->exp));
		p=p->next;
	}
	return sum;
}
int main()
{
	struct node * p=create();
	display(p);
	printf("\nThe solution of the polynomial is %ld\n",evaluation(p,1));
	free(p);
	return 0;
}