#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size;
	int front;
	int rear;
	int * Q;
};

struct Queue * create()
{
	struct Queue * q=NULL;
	printf("\nWe are creating your queue please wait\n");
	printf("\nEnter the maximum size of the Queue\n");
	q=(struct Queue *)malloc(sizeof(struct Queue));
	q->front=q->rear=-1;
	scanf("%d",&q->size);
	q->Q=(int *)malloc(sizeof(int)*q->size);
	printf("\nEnter the number of element that you want to enqueue in the queuqe must less than size\n");
	int n;
	scanf("%d",&n);
	printf("\nEnter the elemnts in the Queue using array\n");
	if(n>q->size)
		return NULL;
	else
	{
		for(int i=0;i<n;i++)
		{
			printf("%d->",i);
			q->rear++;
			scanf("%d",&q->Q[i]);
		}
	}
	printf("\nYour Queue is created ;)\n");
	return q;
}

void enqueue(struct Queue * q,int x)
{
	if(q->rear==q->size-1)
		printf("\nQueue is already full cannot insert more elements\n");
	else
	{
		q->rear++;
		q->Q[q->rear]=x;
		printf("\nYour element is enqued in the queue\n");
	}
}

int dequeue(struct Queue * q)
{
	int x=-32768;
	if(q->rear==q->front)
	{
		printf("\nQueue is already empty cannot dequeue element more\n");
		return x;
	}
	else
	{
		q->front++;
		x=q->Q[q->front];
		return x;
	}

}

void display(struct Queue * q)
{
	for(int i = q->front+1 ; i <= q->rear; i++)
	{
		printf("%d\n",q->Q[i]);
	}
	printf("\n");
}

int main()
{
	struct Queue * q=NULL;
	int choice=1;
	static int cout=0;
	while(choice)
	{
		printf("\n1.Create the Queue\n");
		printf("\n2.Enqueue in the Queue\n");
		printf("\n3.Dequeue in the Queue\n");
		printf("\n4.Display the Queue\n");
		printf("\n5.Exit the Program\n");
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					q=create();
					if(q==NULL){
						printf("\nYour queue cannot be created,you may have enter more than the size of array try again!!!!\n");
						choice=1;
					}
			break;

			case 2:
					printf("\nWe are enquing the element please wait\n");
					int x;
					printf("\nEnter the element to insert in the queue\n");
					scanf("%d",&x);
					enqueue(q,x);
					cout++;
			break;

			case 3:
					printf("\nWe are dequeuing the element please wait\n");
					int x2;
					x2=dequeue(q);
					if(x2==-32768)
						printf("\nSeems that your queue is already full\n");
					else
						printf("\nYour element is dequeued from queue successfully ;) and element is %d\n",x2);
					cout++;
			break;

			case 4:
					printf("\nThe elemnts present in the queue are\n");
					display(q);
					cout++;
			break;

			case 5:
					choice=0;
					if(q==NULL || cout==0)
						printf("\nSeems that you don't like my program:(\n");
					else
					{
						printf("\nExiting........\n");
						free(q->Q);
						free(q);
					}
			break;
		}
	}
}