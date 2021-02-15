#include<stdio.h>
#include<stdlib.h>

struct array
{
	int * A;
	int size;
	int length;
};

struct array * create()
{
	int s,len;
	printf("\nYour array is creating...............Please enter the following details\n");
	printf("\nEnter the value size of array\n");
	scanf("%d",&s);
	printf("\nEnter the value length of array\n");
	scanf("%d",&len);
	struct array * p=(struct array *)malloc(sizeof(struct array));
	p->size=s;
	p->length=len;
	p->A=(int *)malloc((p->size) * sizeof(int));
	printf("\nEnter the elements in the array\n");
	for(int i=0;i<p->length;i++)
		scanf("%d",&p->A[i]);
	return p;
}
void display(struct array * p)
{
	int i;
	printf("\nElements are\n");
	for(i=0;i<p->length;i++)
	{
		printf("%d",p->A[i]);
		printf("\n");
	}
}
void append(struct array * p,int x)
{
	if(p->length<p->size)
		p->A[p->length++]=x;
}
void insert(struct array * p,int index,int x)
{
	int i;
	if(index < 0 || index > p->length)
	{
		printf("\nCheck the index you have inserted\n");
		return;
	} 
	else if(p->length == p->size)
	{
		printf("\nCannot be insert you have reach max space");
		return;
	}
	else
	{
		for(i=p->length;i>index;i--)
		{
			p->A[i]=p->A[i-1];
		}
		p->A[index]=x;
		p->length++;
	}
}
int delete(struct array * p,int index)
{	
	int x=0;
	if(index>=0 && index<=p->length-1)
	{
		x=p->A[index];
		for(int i=index;i<p->length-1;i++)
			p->A[i]=p->A[i+1];
		p->length--;
		return x;
	}
return 0;
}
int linearsearch(struct array * p,int key)
{
	for(int i=0;i<p->length;i++)
	{
		if(p->A[i]==key)
		{
			printf("\nKey found at index %d\n",i);
			return i;
		}
	}
	printf("\nElement is not in the array");
	return 0;
}
void swap(int * x,int * y)
{
	int temp;
	temp= * x;
	* x= * y;
	* y=temp;
}
int transformationlinearsearch(struct array * p,int key)
{
	for(int i=0;i<p->length;i++)
	{
		if(p->A[i]==key)
		{
			printf("\nKey found at index %d\n",i);
			swap(&p->A[i],&p->A[i-1]);
			return i;
		}
	}
	printf("\nElement is not in the array");
	return 0;
}
int issorted(struct array * p)
{
	int i;
	for(i=0;i< p->length;i++)
	{
		if(p->A[i] < p->A[i+1])
			return 1;
	}
	return 0;
}
int binarysearch(struct array * p,int key)
{
	int l,h,mid;
	l=0;
	h=p->length-1;
	if(!issorted(p))
	{
		printf("\nYour array is not sorted cannot perform binary search :(\n");
		return -1;
	}
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==p->A[mid])
		{
			printf("\nKey found at index %d\n",mid);
			return mid;
		}
		else if(key<p->A[mid])
			h=mid-1;
		else
			l=mid+1;
	}
printf("\nElement is not in the array");
return -1;
}	
int Rbinarysearch(struct array * p,int l1,int h1,int key1)
{
	if(!issorted(p))
	{
		printf("\nYour array is not sorted cannot perform binary search :(\n");
		return -1;
	}
	int mid1;
	if(l1<=h1)
	{
		mid1=(l1+h1)/2;
		if(key1==p->A[mid1])
		{
			printf("\nKey found at index %d\n",mid1);
			return mid1;
		}
		else if(key1<p->A[mid1])
			return Rbinarysearch(p,0,mid1-1,key1);
		else
			return Rbinarysearch(p,mid1+1,p->length,key1);
	}
	printf("\nElement is not in the array");
	return -1;
}

int getelement(struct array * p,int index)
{
	if(index>=0 && index< p->length)
		return p->A[index];
	return 0;
}
void setelement(struct array * p,int index,int x)
{
	if(index>=0 && index< p->length)
	{
		printf("\nYour element is updating please wait\n");
		p->A[index]=x;
	}
	else
	{
		printf("\nYour element cannot be update check the index wait\n");
	}
}
int max(struct array * p)
{
	int max;
	max=p->A[0];
	for(int i=1;i < p->length;i++)
	{
		if(p->A[i]>max)
			max=p->A[i];	
	}
	return max;
}
int min(struct array * p)
{
	int min;
	min=p->A[0];
	for(int i=1;i < p->length;i++)
	{
		if(p->A[i]<min)
			min=p->A[i];	
	}
	return min;
}
int sum(struct array * p)
{
	int sum=0,i;
	for(i=0;i<p->length;i++)
		sum=sum+p->A[i];
	return sum;
}
float average(struct array *p)
{
	int sum=0,i;
	for(i=0;i<p->length;i++)
		sum=sum+p->A[i];
	return sum/p->length;
}
void reverse(struct array * p)
{
	int i,j;
	int * B=(int *)malloc(p->length*sizeof(int));
	for(i=p->length-1,j=0;i>=0;i--,j++)
	{
		B[j]=p->A[i];
	}
	for(i=0;i< p->length;i++)
		p->A[i]=B[i];
	free(B);
}

void reverse2(struct array * p)
{	
	int i,j;
	for(i=0,j= p->length-1;i<j;i++,j--)
		swap(&p->A[i],&p->A[j]);
}
void insertsort(struct array * p,int x)
{
	int i=p->length-1;
	if(p->length==p->size)
	{
		printf("\nCannot be inserted you can not exceed the size of array\n");
		return;
	}
	while(i>=0 && p->A[i] > x)
	{
		p->A[i+1]=p->A[i];
		i--;
	}
	p->A[i+1]=x;
	printf("\nYour element is inserted at index %d in array\n",i+1);
	p->length++;
}
void rearrange(struct array * p)
{
	int i,j;
	i=0;
	j=p->length-1;
	while(i<j)
	{
		while(p->A[i] < 0)
			i++;
		while(p->A[j] >=0)
			j--;
		if(i<j)
		{
			swap(&p->A[i],&p->A[j]);
		}
	}
	printf("\nYour array is rearrange ;) type 1. to display the element\n");
}
struct array * merge()
{
	printf("\nEnter the details of first array that you want merge\n");
	struct array * first=create();
	printf("\nEnter the details of second array that you want merge\n");
	struct array * second=create();
	struct array * third=(struct array *)malloc(sizeof(struct array));
	third->size=first->size + second->size;
	third->A=(int *)malloc((third->size) * sizeof(int));
	int i=0, j=0, k=0;
	while(i < first->length && j< second->length)
	{
		if(first->A[i] < second->A[j])
			third->A[k++]=first->A[i++];
		else
			third->A[k++]=second->A[j++];
	}
	for(;i< first->length;i++)
		third->A[k++]=first->A[i];
	for(;j< first->length;j++)
		third->A[k++]=second->A[j];
	third->length=first->length + second->length;
	free(first);
	free(second);
	return third;
}
struct array * setunion()
{
	printf("\nEnter the details of first array(must be sorted) that you want union\n");
	struct array * first=create();
	printf("\nEnter the details of second array(must be sorted) that you want union with\n");
	struct array * second=create();
	if(!issorted(first) || !issorted(second))
	{
		printf("\nplease enter sorted array\n");
		return NULL;
	}
	struct array * third=(struct array *)malloc(sizeof(struct array));
	third->size=first->size + second->size;
	third->A=(int *)malloc((third->size) * sizeof(int));
	int i=0, j=0, k=0;
	while(i < first->length && j< second->length)
	{
		if(first->A[i] < second->A[j])
			third->A[k++]=first->A[i++];
		else if(first->A[i] > second->A[j])
			third->A[k++]=first->A[j++];
		else
		{
			third->A[k++]=first->A[i++];
			j++;
		}
	}
	for(;i< first->length;i++)
		third->A[k++]=first->A[i];
	for(;j< first->length;j++)
		third->A[k++]=second->A[j];
	third->length=k;
	free(first);
	free(second);
	return third;
}	
struct array * intersection()
{
	printf("\nEnter the details of first array(must be sorted) that you want Intersecetion\n");
	struct array * first=create();
	printf("\nEnter the details of second array(must be sorted) that you want Intersection with\n");
	struct array * second=create();
	if(!issorted(first) || !issorted(second))
	{
		printf("\nplease enter sorted array\n");
		return NULL;
	}
	struct array * third=(struct array *)malloc(sizeof(struct array));
	third->size=first->size + second->size;
	third->A=(int *)malloc((third->size) * sizeof(int));
	int i=0, j=0, k=0;
	while(i < first->length && j< second->length)
	{
		if(first->A[i] < second->A[j])
			i++;
		else if(first->A[i] > second->A[j])
			j++;
		else
		{
			third->A[k++]=first->A[i++];
			j++;
		}
	}
	third->length=k;
	free(first);
	free(second);
	return third;
}	
struct array * difference()
{
	printf("\nEnter the details of first array(must be sorted) that you want difference\n");
	struct array * first=create();
	printf("\nEnter the details of second array(must be sorted) that you want difference with\n");
	struct array * second=create();
	if(!issorted(first) || !issorted(second))
	{
		printf("\nplease enter sorted array\n");
		return NULL;
	}
	struct array * third=(struct array *)malloc(sizeof(struct array));
	third->size=first->size + second->size;
	third->A=(int *)malloc((third->size) * sizeof(int));
	int i=0, j=0, k=0;
	while(i < first->length && j< second->length)
	{
		if(first->A[i] < second->A[j])
			third->A[k++]=first->A[i++];
		else if(first->A[i] > second->A[j])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for(;i< first->length;i++)
		third->A[k++]=first->A[i];
	third->length=k;
	free(first);
	free(second);
	return third;
}	

int main()
{	
	int choice=1;
	struct array * p;
	while(choice)
	{	
		printf("\n***********************************\n");
		printf("\n*********1.Create An array*********\n");
		printf("\n*************2.Display*************\n");
		printf("\n*************3.Insert**************\n");
		printf("\n*************4.append**************\n");
		printf("\n*************5.Delete**************\n");
		printf("\n*****6.Using linear search*********\n");
		printf("\n****7.Transform linear search******\n");
		printf("\n********8.Binary search************\n");
		printf("\n****9.Recursive Binary search******\n");
		printf("\n***10.Get The Element By Index*****\n");
		printf("\n****11.set The Element By Index****\n");
		printf("\n********12.Find Max Element********\n");
		printf("\n********13.Find Min Element********\n");
		printf("\n********14.Find Sum Element********\n");
		printf("\n*****15.Find Average Element*******\n");
		printf("\n*****16.Reversing the array********\n");
		printf("\n***17.Reversing the array pt-2*****\n");
		printf("\n***18.Checking for sorted array****\n");
		printf("\n*****19.Insert in sortwise*********\n");
		printf("\n******20.Rearrange the array*******\n");
		printf("\n******21.Merge the two array*******\n");
		printf("\n*****22.Union of the two array*****\n");
		printf("\n***23.Intersection of  two array***\n");
		printf("\n***24.Difference of  two array***\n");
		printf("\n*************25.Exit***************\n");
		printf("\n***********************************\n");
		printf("\nEnter the choice to do operations\n");
		scanf("%d",&choice);
		switch(choice)
		{
		
			case 1 :
				p= create();
				break;
				
			case 2 :
				display(p);
				break;
			
			case 3 :
				printf("\nEnter the index you want to insert\n");
				int ind;
				int x;
				scanf("%d",&ind);
				printf("\nEnter the element you want to insert\n");
				scanf("%d",&x);
				insert(p,ind,x);
				break;
			
			case 4 :
				printf("\nEnter the element you want to append\n");
				int k;
				scanf("%d",&k);
				append(p,k);
				break;
			case 5 :
				printf("\nEnter the index you want to delete\n");
				int d,d1;
				scanf("%d",&d);
				d1=delete(p,d);
				if(d1)
					printf("\nelement %d is deleted\n",d1);
				else
					printf("\n element cannot be deleted");
				break;
			case 6 :
				printf("\nEnter the element you want to search using linear search\n");
				int s,s1;
				scanf("%d",&s);
				s1=linearsearch(p,s);
				break;
				
			case 7 :
				printf("\nEnter the element you want to search using Transform linear search\n");
				int t,t1;
				scanf("%d",&t);
				t1=transformationlinearsearch(p,t);
				break;
				
			case 8 :
				printf("\nEnter the element you want to search using Binary search\n");
				int b,b1;
				scanf("%d",&b);
				b1=binarysearch(p,b);
				break;
			case 9 :
				printf("\nEnter the element you want to search using Recursive Binary search \n");
				int rb,rb1;
				scanf("%d",&rb);
				rb1=Rbinarysearch(p,0,p->length,rb);
				break;
			case 10 :
				printf("\nEnter the index to get element of array\n");
				int ge,re;
				scanf("%d",&ge);
				re=getelement(p,ge);
				if(re)
					printf("\nelement %d is found\n",re);
				else
					printf("\n Check the index");
				
				break;
			case 11 :
				printf("\nEnter the index that you want to set element of an array\n");
				int se,xe;
				scanf("%d",&se);
				printf("\nEnter the element that you want to replace with element of an array\n");
				scanf("%d",&xe);
				setelement(p,se,xe);
				break;
			case 12 :
				printf("\nFinding the maximum element in the array\n");
				int max1;
				max1=max(p);
				printf("\nThe max element in the array is %d\n",max1);
				break;
			case 13 :
				printf("\nFinding the minimum element in the array\n");
				int min1;
				min1=min(p);
				printf("\nThe max element in the array is %d\n",min1);
				break;
			
			case 14 :
				printf("\nFinding the Sum of element in the array\n");
				int sum1;
				sum1=sum(p);
				printf("\nThe sum of element in the array is %d\n",sum1);
				break;
				
			case 15 :
				printf("\nFinding the Average of element in the array\n");
				float avg;
				avg=average(p);
				printf("\nThe Average of element in the array is %f\n",avg);
				break;
			case 16 :
				printf("\nplease wait while your array is reversing by method 1...........\n");
				printf("\nThe Rversed array is\n");
				reverse(p);
				display(p);
				break;
				
			case 17 :
				printf("\nplease wait while your array is reversing by method 2...........\n");
				printf("\nThe Rversed array is\n");
				reverse2(p);
				display(p);
				break;
				
			case 18 :
				printf("\nYour Array is checking is sorted or not,plz wait.............\n");
				int is;
				is=issorted(p);
				if(is)
					printf("\nYour array is sorted ;)\n");
				else
					printf("\nYour array is not sorted :(");
				
				break;
			case 19 :
				printf("\nEnter the element you want to insert using  insertion sort\n");
				int i1;
				scanf("%d",&i1);
				insertsort(p,i1);
				break;
			case 20 :
				printf("\n please wait to rearrange the array ie negative on one side and positive on the other\n");
				rearrange(p);
				break;
			case 21 :
				printf("\n please wait while creating your merged array ;)\n");
				struct array * mergearray;
				mergearray=merge();
				printf("\nYour array is created.......\n");
				printf("\nYour merged array is\n");
				display(mergearray);
				free(mergearray);
				break;
			case 22 :
				printf("\n please wait while creating your union array ;)\n");
				struct array * unionarray;
				unionarray=setunion();
				if(unionarray)
				{
					printf("\nYour array is created.......\n");
					printf("\nYour Union array is\n");
					display(unionarray);
					free(unionarray);
				}
				break;
			case 23 :
				printf("\n please wait while creating your Intersecting array ;)\n");
				struct array * intersect;
				intersect=intersection();
				if(intersect)
				{
					printf("\nYour array is created.......\n");
					printf("\nYour Intersection of two array is\n");
					display(intersect);
					free(intersect);
				}
				break;
			
			case 24 :
				printf("\n please wait while creating your difference of array ;)\n");
				struct array * difference1;
				difference1=difference();
				if(difference1)
				{
					printf("\nYour array is created.......\n");
					printf("\nYour Difference of two array is\n");
					display(difference1);
					free(difference1);
				}
				break;
				
			case 25 :
				printf("\nEXITING.........\n");
				choice=0;
				break;
			
			default:
				printf("\nThis choice is not available");
				choice=1;
				break;
		}
	}
}
