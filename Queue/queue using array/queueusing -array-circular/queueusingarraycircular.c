#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int front;
	int rear;
	int size;
	int * Q;
};

struct queue * create()
{
	struct queue * q=NULL;
	q=(struct queue *)malloc(sizeof(struct queue));
	printf("\nCreating Your queue please wait\n");
	printf("\nEnter the maximum size of the queue that you want to create\n");
	scanf("%d",&q->size);
	q->front=q->rear=0;
	q->Q=(int *)malloc(sizeof(int)*q->size);
	printf("\nPlease enter the number of element that you want to enter \n");
	int n;
	scanf("%d",&n);
	if(n > q->size)
	{
		printf("\nThe size you enter is greater than the max size of queue that you want to create try agan!!!!\n");
		free(q);
		return NULL;
	}
	else
	{
		int i=q->front+1;
		int j=q->rear +1;
		do
		{
			printf("%d->",i);
			scanf("%d",&q->Q[i]);
			i=(i+1) % q->size;
			q->rear=(q->rear + 1)%q->size;

		}while(i<=n);
		printf("\nYour queue is created ;)\n");
		return q;
	}
}

void enqueue(struct queue * q,int x)
{
	if((q->rear + 1) % q->size == q->front)
		printf("\nSeems that your Queue is already full cannot insert more element\n");
	else
	{
		q->rear=(q->rear + 1) % q->size;
		q->Q[q->rear]=x;
	}
}

int dequeue(struct queue * q)
{
	int x=-32768;
	if((q->front +1)%q->size == q->rear)
	{
		return x;
	}
	else
	{
		q->front=(q->front + 1)% q->size;
		x=q->Q[q->front];
		return x;
	}

}

void display(struct queue * q)
{
	int i = q->front + 1;
	int j= q->rear + 1;
	do
	{
		printf("%d\n",q->Q[i]);
		i=(i+1) % q->size;
	}while(i!= j % q->size);
}

int main()
{
	struct queue * q=NULL;
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
					printf("We are enquing the element please wait");
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
						printf("\nSeems that your queue is already empty cannot dequeue more elements\n");
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
						printf("\nSeems that you don't like my program :( \n");
					else
					{
						printf("\nExiting........\n");
						free(q->Q);
						free(q);
					}
			break;

			default:
					printf("\nWrong Choice please check the choice\n");
					choice=1;
			break;
		}
	}
}