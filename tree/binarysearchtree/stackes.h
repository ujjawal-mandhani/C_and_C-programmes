struct stack
{
	struct node ** Q;
	int top;
	int size;
};

void createstack(struct stack * stk,int size)
{
	stk->size=size;
	stk->top=-1;
	stk->Q=(struct node **)malloc(sizeof(struct node *));
}

void push(struct stack * stk,struct node * x)
{
	if(stk->top==stk->size-1)
	{
		printf("\nSeems that stack is already full\n");
	}
	else
	{
		stk->top++;
		stk->Q[stk->top]=x;
	}
}

struct node * pop(struct stack * stk)
{
	struct node * x=NULL;
	if(stk->top==-1)
	{
		printf("\nSeems that your stack is already empty\n");
	}
	else
	{
		x=stk->Q[stk->top];
		stk->top--;
	}
	return x;
}

int sisEmpty(struct stack * stk)
{
	return stk->top==-1;
}