struct queue
{
	int size;
	int front;
	int rear;
	struct node ** Q;
};

void create(struct queue * q,int size)
{
	q->size=size;
	q->front=q->rear=-1;
	q->Q=(struct node **)malloc(sizeof(struct node *));
}

void enqueue(struct queue * q,struct node * x)
{
	if((q->rear + 1)%q->size==q->front)
		printf("\nQueue is full\n");
	else
	{
		q->rear=(q->rear +1)%q->size;
		q->Q[q->rear]=x;
	}
}

struct node * dequeue(struct queue * q)
{
	struct node * x=NULL;
	if(q->front==q->rear)
		printf("\nQueue is empty\n");
	else
	{
		q->front=(q->front +1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct queue q)
{
	return q.front==q.rear;
}