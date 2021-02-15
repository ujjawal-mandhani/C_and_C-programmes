#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node * next;
}* top=NULL;

char pop()
{
	struct node * t;
	char x;
	if(top==NULL)
		printf("\nstack is already empty\n");
	else
	{	
		t=top;
		top=top->next;
		x=t->data;
		t->next=NULL;
		free(t);
	}
	return x;
}

void display()
{
	struct node * p;
	p=top;
	while(p!=top)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}

void push(char c)
{
	struct node * t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
		printf("\nStack is already full cannot insert anymore\n");
	else
	{
		t->data=c;
		t->next=top;
		top=t;	
	}
}

int isBalanced(char * exp)
{
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
		}
		else if(exp[i]==')')
		{
			if(top==NULL)
				return 0;
			else
				pop();
		}
	}
	if(top==NULL)
		return 1;
	else
		return 0;
}

int main()
{
	char * exp="((a+b)*(c-d))";
	int p=isBalanced(exp);
	if(p)
		printf("\nIt is balanced\n");
	else
		printf("\nIt is not balanced\n");
	return 0;
}