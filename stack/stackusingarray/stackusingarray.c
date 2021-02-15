#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * s;
};

struct stack * createstack()
{
	struct stack * st;
	st=(struct stack *)malloc(sizeof(struct stack));
    struct stack * p=NULL;
    printf("\nPlease wait we are creating your stack\n");
    printf("\nPlease enter the size of the stack\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(sizeof(int)*(st->size));
    printf("\nPlease enter the elements in the stack\n");
    for(int i=0;i < st->size;i++)
    {
        scanf("%d",&st->s[i]);
        st->top++;
    }
    p=st;
    printf("\nYour stack is created ;)\n");
    return p;
}

void display(struct stack * st)
{
    printf("\nThe elements in the stack are\n");
    for(int i=st->top;i>=0;i--)
        printf("%d\n",st->s[i]);
    printf("\n");
}

struct stack * push(struct stack * st,int x)
{
	if(st->top==st->size-1)
		printf("\nYour stack is full you cannot insert more elements :(\n");
	else
	{
		st->top++;
		st->s[st->top]=x;
		printf("\nYour element is pushed in the stack ;)\n");
	}
	return st;
}

struct stack * pop(struct stack * st)
{
	int x;
	if(st->top==-1)
		printf("\nYour stack is already empty cannot pop more elements :(\n");
	else
	{
		x=st->s[st->top];
		st->top--;
		printf("\nyour element %d is poped from the stack ;)\n",x);
	}
	return st;
}

int peek(struct stack * st,int pos)
{
	int x=-32767;
	printf("\nWe are finding the element at the given position\n");
	if(st->top - pos + 1<0){
		return x;
	}
	else
	{
		x=st->s[st->top - pos + 1];
		return x;
	}
}

int stacktop(struct stack * st)
{
	int x=-32767;
	if(st->top==-1)
		return x;
	else
		return st->s[st->top];
}

int isEmpty(struct stack * st)
{
	if(st->top==-1)
		return 1;
	else
		return 0;
}

int isFull(struct stack * st)
{
	if(st->top==st->size-1)
		return 1;
	else
		return 0;
}
int main()
{
	int choice =1;
    struct stack * p=NULL;
    while(choice)
    {
    	printf("\n1.Create the stack\n");
    	printf("\n2.Display the stack\n");
    	printf("\n3.Push the element in the stack at the top of it\n");
    	printf("\n4.Pop the element from the stack from the top\n");
    	printf("\n5.Giving the value present at that index taken by the user\n");
    	printf("\n6.Returning the element present at the top of the stack\n");
    	printf("\n7.Checking whether that the stack is empty or not\n");
    	printf("\n8.Checking whether that the stack is full or not\n");
    	printf("\n9.Exit the program :(\n");
    	printf("\nEnter the choice that you want to execute\n");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
    				p=createstack();
    		break;

    		case 2:
    				display(p);
    		break;

    		case 3:
    				printf("\nplease wait we are pushing the element.....\n");
    				printf("\nPlease enter the element that you want to insert\n");
    				int x;
    				scanf("%d",&x);
    				struct stack * t1=push(p,x);
    				p=t1;
    		break;

    		case 4:
    				printf("\nPlease wait we are  poping the element.....\n");
    				struct stack * t2=pop(p);
    				p=t2;
    		break;

    		case 5:
    				printf("\nPlease Enter index that you want to peek\n");
    				int x2;
    				scanf("%d",&x2);
    				int res=peek(p,x2);
    				if(res==-32767)
    					printf("\nSeems that you have given the wrong index :(\n");
    				else 
    					printf("\nThe Element present at index %d is %d\n",x2,res);
    		break;

    		case 6:
    				printf("\nChecking That what is present in the stacktop\n");
    				int res1=stacktop(p);
    				if(res1==-32767)
    					printf("\nSeems that stack is already empty :(\n");
    				else 
    					printf("\nThe Element present at the top of stack is %d \n",res1);
    		break;

    		case 7:
    				printf("\nChecking whether that the stack is empty or not\n");
    				int res2=isEmpty(p);
    				if(res2)
    					printf("\nSeems that stack is already empty :(\n");
    				else 
    					printf("\nStack is not empty\n");
    		break;
    		case 8:
    				printf("\nChecking whether that the stack is full or not\n");
    				int res3=isFull(p);
    				if(res3)
    					printf("\nSeems that stack is already full :(\n");
    				else 
    					printf("\nStack is not full\n");
    		break;

    		case 9:
    				choice=0;
    				if(p==NULL)
    					printf("\nSeems that you don't like my program :(\n");
    				else
    				{
    				    free(p->s);
    					free(p);
    				}
    				printf("\nExitting......\n");
    		break;
    	}
    }

	return 0;
}