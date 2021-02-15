int * create(int n)
{
	int * p=(int *)malloc(n*sizeof(int));
	printf("\nEnter elements in the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	return p;
}
	
void display(int * q,int x)
{
	int i;
	printf("\nYour elements are\n");
	for(i=0;i<x;i++)
	{
		printf("%d \n",q[i]);
		
	}
}

