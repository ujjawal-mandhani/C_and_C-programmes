#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data;
	struct node * next;
}* top=NULL;

char pop()
{
	char x=-1;
	struct node * t=NULL;
	if(top==NULL)
	{
		printf("\nThe stack is already empty cannot be poped\n");
	}
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

void push(char x)
{
	struct node * t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
	{
		printf("\nCannot push stack or your memory is already overflow\n");
	}
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
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

int isOperand(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/')
		return 0;
	else
		return 1;
}

int precidenceofoperand(char x)
{
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	return 0;
}

char * InToPost(char * infix)
{
	int i,j;
	i=j=0;
	int len=strlen(infix);
	char * postfix=(char *)malloc(sizeof(char) * (len + 1));
	while(infix[i]!='\0')
	{
		if(isOperand(infix[i]))
			postfix[j++]=infix[i++];
		else 
		{
			if(precidenceofoperand(infix[i])>precidenceofoperand(top->data))
				push(infix[i++]);
			else
				postfix[j++]=pop();
		}
	}
	while(top!=NULL)
		postfix[j++]=pop();
	postfix[j]='\0';
	return postfix;
}

int main()
{
	char * infix="a+b*c-d/e";
	push('#');
	char * postfix=InToPost(infix);
	printf("%s\n",postfix);
}