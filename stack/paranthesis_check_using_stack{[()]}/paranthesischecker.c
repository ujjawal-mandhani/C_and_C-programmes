#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node * next; //Stack Using linked list
}* top=NULL;

void push(char x)
{
	struct node * t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
		printf("\nStack is full cannot push element\n");
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

char pop()
{
	char x=-1;
	struct node * t=NULL;
	if(top==NULL)
		printf("\nStack is empty\n");
	else
	{
		t=top;
		top=top->next;
		t->next=NULL;
		x=t->data;
		free(t);
	}
	return x;
}

void display()
{
	struct node * p=NULL;
	p=top;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
}

int isBalanced(char * exp)
{
	int x1,x2,x3;
	x1=x2=x3=0;
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
			x1++;
		}
		else if(exp[i]==')')
		{
			if(top==NULL)
				return 0;
			pop();
			x1--;
		}
		else if(exp[i]=='{')
		{
			push(exp[i]);
			x2++;
		}
		else if(exp[i]=='}')
		{
			if(top==NULL)
				return 0;
			pop();
			x2--;
		}
		else if(exp[i]=='[')
		{
			push(exp[i]);
			x3++;
		}
		else if(exp[i]==']')
		{
			if(top==NULL)
				return 0;
			pop();
			x3--;
		}
	}
	if(top==NULL && x1==0 && x2==0 && x3==0)
		return 1;
	return 0;
}

int main()
{
	char * p="{(a+b+c)*(c+a)-[(c-b-a)*a*b*c]}";
	display(p);
	int k=isBalanced(p);
	if(k)
		printf("\nBlanced\n");
	else
		printf("\nUnblanced\n");
	return 0;
}