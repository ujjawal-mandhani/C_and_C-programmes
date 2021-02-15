#include<stdio.h>
#include<stdlib.h>

struct element
{
	int r;
	int c;
	int v;
};
struct sparsematrix
{
	int m;
	int n;
	int num;
	struct element * ele;
};
static int cv=0;
void setelements(struct sparsematrix * s,int row,int col,int val)
{
	if(val!=0)
	{
		s->ele[cv].r=row;
		s->ele[cv].c=col;
		s->ele[cv].v=val;
		cv++;
	}
}

void display(struct sparsematrix * s)
{
	int k=0;
	printf("\nElements in the matrix are\n");
	for(int i=0;i<s->m;i++)
	{
		for(int j=0;j<s->n;j++)
		{
			if(i==s->ele[k].r && j==s->ele[k].c)
				printf(" %d",s->ele[k++].v);
			else
				printf(" 0");
		}
		printf("\n");
	}
}

struct sparsematrix * create()
{
	struct sparsematrix * s =(struct sparsematrix *)malloc(sizeof(struct sparsematrix));
	int x;
	printf("\nCreating your sparse matrix please wait.......\n");
	printf("\nEnter the value of rows in the matrix\n");
	scanf("%d",&s->m);
	printf("\nEnter the value of cols in the matrix\n");
	scanf("%d",&s->n);
	printf("\nEnter the value of non-zero numbers in the matrix\n");
	scanf("%d",&s->num);
	printf("\nEnter the elements in the array\n");
	s->ele=(struct element *)malloc(sizeof(struct element) * s->num);
	for(int i=0;i< s->m;i++)
	{
		for(int j=0;j< s->n;j++)
		{
			scanf("%d",&x);
			setelements(s,i,j,x);
		}
	}
	printf("\nYour sparse matrix is created :)\n");
	return s;

}

struct sparsematrix * addsparse()
{
	int i=0;int j=0;int k=0;
	struct sparsematrix * s1=create();
	struct sparsematrix * s2=create();
	printf("\nok1\n");
	struct sparsematrix * sum=(struct sparsematrix *)malloc(sizeof(struct sparsematrix));
	sum->ele=(struct element *)malloc((s1->num + s2->num)*(sizeof(struct element)));
	printf("\nok1\n");
	while(i< s1->num && j< s2->num)
	{
		if(s1->ele[i].r < s2->ele[j].r)
			sum->ele[k++]=s1->ele[i++];
		else if(s1->ele[i].r > s2->ele[j].r)
			sum->ele[k++]=s2->ele[j++];
		else
		{
			if(s1->ele[i].c < s2->ele[j].c)
				sum->ele[k++]=s1->ele[i++];
			else if(s1->ele[i].c > s2->ele[j].c)
				sum->ele[k++]=s2->ele[j++];
			else
			{
				sum->ele[k]=s1->ele[i];
				sum->ele[k++].v=s1->ele[i++].v + s2->ele[j++].v;
			}
		}
	}
	for(;i< s1->num;i++)
		sum->ele[k++]=s1->ele[i];
	for(;j<s1->num;j++)
		sum->ele[k++]=s2->ele[j];
	sum->m=s1->m;
	sum->n=s1->n;
	sum->num=k;
	printf("\nok\n");
	free(s1->ele);
	free(s1);
	free(s2->ele);
	free(s2);
	return sum;

}

int main()
{
	//struct sparsematrix * s=create();
	//display(s);
	struct sparsematrix * p=addsparse();
	display(p);
	//free(s->ele);
	free(p->ele);
	free(p);
	return 0;
}