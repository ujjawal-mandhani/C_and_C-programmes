#include<stdio.h>
#include<stdlib.h>

struct t{

	int coeff;
	int exp;
};

struct poly{
	int n;
	struct t * term;
};
struct poly * create()
{
	struct poly * p=(struct poly *)malloc(sizeof(struct poly));
	int i;
	printf("\nPlease Enter the number of terms in the polynomial\n");
	scanf("%d",&p->n);
	p->term=(struct t *)malloc(sizeof(struct t) * p->n);
	printf("\nEnter the coefficient and exponent in the polynomial\n");
	for(i=0;i< p->n;i++)
	{
		scanf("%d %d",&p->term[i].coeff,&p->term[i].exp);
	}
	printf("\nYour polynomial is created ;)\n");
	return p;
}

void display(struct poly * p)
{
	printf("\nThe Elements in the polynomial are\n");
	int i;
	for(i=0;i<p->n;i++)
	{
		if(i==p->n-1)
			printf("%dX%d",p->term[i].coeff,p->term[i].exp);
		else
			printf("%dX%d +",p->term[i].coeff,p->term[i].exp);
	}
	printf("\n");
}
struct poly * addpolynomial()
{
	struct poly * p1=create();
	struct poly * p2=create();
	struct poly * sum=(struct poly *)malloc(sizeof(struct poly));
	sum->term=(struct t *)malloc(sizeof(struct t)*(p1->n + p2->n));
	int i=0;int j=0;int k=0;
	printf("\nCreating Your sum polynomial please wait ....\n");
	while(i< p1->n && j< p2->n)
	{
		if(p1->term[i].exp > p2->term[j].exp)
			sum->term[k++] = p1->term[i++];
		else if(p1->term[i].exp < p2->term[j].exp)
			sum->term[k++] = p2->term[j++];
		else
		{
			sum->term[k].exp = p1->term[i].exp;
			sum->term[k++].coeff = p1->term[i++].coeff + p2->term[j++].coeff;
		}
	}
	for(;i< p1->n;i++)
		sum->term[k++]=p1->term[i];
	for(;j< p2->n;j++)
		sum->term[k++]=p2->term[j];
	sum->n=k;
	free(p1->term);
	free(p1);
	free(p2->term);
	free(p2);
	printf("\nYour sum of two polynomials is craeted ;)\n");
	return sum;
}


int main()
{
	//struct poly * m=create();
	//display(m);
	//free(m->term);
	//free(m);
	struct poly * sum1=addpolynomial();
	display(sum1);
	free(sum1->term);
	free(sum1);
	return 0;
}

