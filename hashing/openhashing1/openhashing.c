#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
}* first=NULL;

void sortedinsert(struct node ** H,int x)
{
	struct node * t,* q=NULL,* p=* H;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(* H==NULL)
		* H=t;
	else
	{
		while(p && p->data < x)
		{
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next=first;
			first=t;
		}
		else
		{
			t->next=q->next;
			q->next=t;
		}
	}
}

struct node * search(struct node * p,int key)
{
	while(p!=NULL)
	{
		if(key==p->data)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}

int hash(int key)
{
	return key%10;
}

void Insert(struct node * H,int key)
{
	int index=hash(key);
	sortedinsert(H[index],key);
}

int main()
{
	struct node * temp;
	int n,x,s;
	printf("\nEnter the number of element that you want to insert in hash table\n");
	scanf("%d",&n);
	struct node ** HT=(struct node **)malloc(sizeof(struct node *) *(n+1));
	for (int i = 0; i < n; i++)
	{
		/* code */
		HT[i]=NULL;
	}
	printf("\nEnter the element in the hash table\n");
	for (int i = 0; i < n; i++)
	{
		/* code */
		scanf("%d",&x);
		Insert(HT[i],x);
	}
	printf("\nEnter the element that you want to search\n");
	scanf("%d",&s);
	temp=search(HT[hash(s)],s);
	if(temp!=NULL)
	{
		printf("\nelement found %d\n",temp->data);
	}
	/*for (int i = 0; i < n; ++i)
	{
		
	}*/
	free(HT);
	return 0;
}