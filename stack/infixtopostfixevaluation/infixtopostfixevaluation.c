#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node * next;
}* top=NULL;

void push(int x)
{
	struct node * t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
		printf("\nElement cannot be inserted stack is full or heap memory is full\n");
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int pop()
{
	int x=-32767;
	struct node * t=NULL;
	if(top==NULL)
		return x;
	else
	{
		t=top;
		top=top->next;
		t->next==NULL;
		t->data=x;
		free(t);
		return x;
	}
}

/*void display()
{
	struct node * p=NULL;
	p=top;
	while(p!=NULL)
	{
		printf("%d"p->data);
		p=p->next;
	}
	printf("\n");
}*/

int isOperand(char x)
{
	if(x=='+' || x=='-' || x=='/' || x=='*')
		return 0;
	else
		return 1;
}

/*int precidencevalue(char x)
{
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	return 0;
}*/
/*
char * IntoPost(char * infix)
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
			if(precidencevalue(infix[i])>precidencevalue(top->data + '0'))
				push(infix[i++] - '0');
			else 
			{
				postfix[j++]=pop() + '0';
			}
		}
	}
	while(top!=NULL)
		postfix[j++]=pop()+'0';
	postfix[j]='\0';
	return postfix;
}*/
int Eval(char * postfix)
{
	int i=0;
	int x1,x2,r;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isOperand(postfix[i]))
			push(postfix[i]-'0');
		else
		{
			x2=pop();
			x1=pop();
			switch(postfix[i])
			{
				case '+':
						r=x1+x2;
				break;

				case '-':
						r=x1-x2;
				break;

				case '*':
						r=x1*x2;
				break;

				case '/':
						r=x1/x2;
				break;
			}
			push(r);
		}
	}
	return top->data;
}

void main()
{
	char * i="234*+22/-";
	int p=Eval(i);
	printf("%d\n",p);
}
