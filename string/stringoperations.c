#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * createstring()
{
	int n,i;
	printf("\nEnter the size of string that you want to create\n");
	scanf("%d",&n);
	char * p=(char *)malloc(sizeof(char)*(n+1));
	printf("\nEnter Your String\n");
	char ch;
	ch=getchar();
	for(i=0;i<n;i++)
		scanf("%c",&p[i]);
	p[i]='\0';
	return p;
}
void display(char * p)
{
	int i=0;
	while(p[i]!='\0')
	{
		printf("%c",p[i]);
		i++;
	}
	printf("\n");
}
int length(char * p)
{
	int i;
	for(i=0;p[i]!='\0';i++){}
	return i;
}
char * lowertoupper(char * p)
{
	int i;
	printf("\nLower case to upper case of a string is\n");
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]==' ')
			i++;
		p[i]=p[i]-32;
	}
	return p;
}
char * uppertolower(char * p)
{
	int i;
	printf("\nUpper case to Lower case of a string is\n");
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]==' ')
			i++;
		p[i]=p[i]+32;
	}
	return p;
}
char * toggle(char * p)
{
	int i;
	printf("\nToggling of a string is\n");
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>='a' && p[i]<='z')
		{
			p[i]=p[i]-32;
		}
		else if(p[i]>='A' && p[i]<='Z')
		{
			p[i]=p[i]+32;
		}
	}
	return p;
}
void countingvowelsandconsonents(char * p)
{
	int i,vcount=0,ccount=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u'||p[i]=='A'||p[i]=='E'||p[i]=='I'||p[i]=='O'||p[i]=='U')
			vcount++;
		else if(p[i]>=65 && p[i]<=90 || p[i]>=97 && p[i]<=122)
			ccount++;
	}
	printf("\nSo the number of vowels in the string is%d\n",vcount);
	printf("\nSo the number of consonants in the string is%d\n",ccount);
}
void countingnumberofwords(char * p)
{
	int word=0;
	for(int i=0;p[i]!='\0';i++)
	{
		if(p[i]==' '){}
		else
			word++;
	}

	printf("\nSo the number of words in the string is %d\n",word);
}
int validate(char * p)
{
	printf("\nOnly Alphabets and numbers are allowed\n");
	int i;
	for(i=0;p[i]!='\0';i++)
	{
		if(!((p[i]>=65 && p[i]<=90) || (p[i]>=97 && p[i]<=122) || (p[i]>=48 && p[i]<=57)||p[i]=='\n'))
		{
			return 0;
		}
	}
	return 1;
}
char * reverse1(char * p)
{
	char * b=(char *)malloc(sizeof(char)*length(p));
	int i,j;
	for(i=0;p[i]!='\0';i++)
	{}
	i=i-1;
	for(j=0;i>=0;i--,j++)
	{
		b[j]=p[i];
	}	
	b[j]='\0';
	return b;
}
char * reverse2(char * p)
{
	int i,j;
	for(i=0;p[i]!='\0';i++)
	{}
	j=i-1;
	for(i=0;i<j;i++,j--)
	{
		char temp=p[i];
		p[i]=p[j];
		p[j]=temp;
	}
	return p;
}
int comparisionbetweentwostrings()
{
	char * a=createstring();
	char * b=createstring();
	int i,j;
	for(i=0,j=0;a[i]!='\0'&&b[j]!='\0';i++,j++)
	{
		if(a[i]!=b[j])
			return 0;
	}
	return 1;
}
int equalstrings(char * a,char * b)
{
	int count=0;
	int i,j;
	for(i=0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++)
	{
		if(a[i]==b[j])
			count++;
	}
	if(count==length(a))
		return 1;
	else
		return 0;
}
int plaindrome1(char * p)
{
	char * p1=reverse1(p);
	if(equalstrings(p1,p))
		return 1;
	else 
		return 0;
}
void findingduplicate1(char * p)
{
	int i,j;
	printf("\nFinding duplicate using method 1 in your given string please wait.......\n");
	for(i=0;p[i]!='\0';i++)
	{
		for(j=i+1;p[j]!='\0';j++)
		{
			if(p[i]==p[j])
			{
				printf("\n'%c' is duplicate\n",p[j]);
			}
		}
	}
}
void findingduplicate2(char * p)
{
	int * H=(int *)malloc(sizeof(int)*26);
	int i;
	printf("\nFinding duplicate using method 2 in your given string please wait.......\n");
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>=65 && p[i]<=90)
			H[p[i]-65]++;
		else if (p[i]>=97 && p[i]<=122)
			H[p[i]-97]++;
		else{}
	}
	for(i=0;i<26;i++)
	{
		if(H[i]>1)
			printf("\n'%c'occurs %d times\n",i+97,H[i]);
	}
	free(H);
}
void findingduplicate3(char * p)
{
	printf("\nFinding duplicate using method 2 in your given string please wait.......\n");
	int x=0,H=0;
	for(int i=0;p[i]!='\0';i++)
	{
		x=1;
		x=x << p[i]-97;
		if(x && H>0)
			printf("\n'%c' is duplicate\n",p[i]);
		else
			H=x/H;
	}
}
void anagram()
{
	int count=0;
	printf("\nEnter the details of first string\n");
	char * a=createstring();
	printf("\nEnter the details of first string\n");
	char * b=createstring();
	printf("\nChecking for the anagram of both strings please wait........\n");
	int * H=(int *)malloc(sizeof(int)*26);
	for(int i=0;i<26;i++)
	{
		H[i]=0;
	}
	for(int j=0;a[j]!='\0';j++)
	{
		H[a[j]-97]+=1;
	}
	for(int k=0;b[k]!='\0';k++)
	{
		H[b[k]-97]-=1;
	}
	for(int l=0;l<26;l++)
	{
		if(H[l]!=0)
		{
			count++;
		}
	}
	free(H);
	free(a);
	free(b);
	if(count)
		printf("\nYour string is not anagram\n");
	else
		printf("\nYour string is anagram\n");
}
void permutation1(char * p,int k)
{
	int n=length(p);
	static int A[10]={0};
	static char res[10];
	if(p[k]=='\0')
	{
		res[k]='\0';
		display(res);
	}
	for(int j=0;p[j]!='\0';j++)
	{
		if(A[j]==0)
		{
			res[k]=p[j];
			A[j]=1;
			permutation1(p,k+1);
		}
	}
}
void swap(char * x,char * y)
{
	char temp;
	temp=* x;
	* x=* y;
	* y=temp;

}
void permutation2(char * p,int l,int h)
{
	if(l==h)
		display(p);
	else
	{
		for(int i=l;i<=h;i++)
		{
			swap(&p[l],&p[i]);
			permutation2(p,l+1,h);
			swap(&p[l],&p[i]);
		}
	}
}
int main()
{
	int choice=1;
	while(choice)
	{
		printf("\n************************************1.Create a string************************************\n");
		printf("\n**********************************2.Display the string***********************************\n");
		printf("\n*********************************3.Length of the string**********************************\n");
		printf("\n**********************4.Lower case to Upper case of a string*****************************\n");
		printf("\n**********************5.Upper case to Lower case of a string*****************************\n");
		printf("\n*********************************6.Toggling of a string**********************************\n");
		printf("\n**********************7.Counting Number of Vowels and consonants*************************\n");
		printf("\n*****************************8.Counting Number of Words**********************************\n");
		printf("\n******************************9.Validation of a string***********************************\n");
		printf("\n************************10.Reverse of a string using method 1****************************\n");
		printf("\n************************11.Reverse of a string using method 2****************************\n");
		printf("\n************************12.Comparision between two strings*******************************\n");
		printf("\n******************************13.Checking Palindrome*************************************\n");
		printf("\n*********************14.Finding duplicate in a string Using Method 1*********************\n");
		printf("\n*********************15.Finding duplicate in a string Using Method 2*********************\n");
		printf("\n*********************16.Finding duplicate in a string Using Method 3*********************\n");
		printf("\n*********************17.Finding that two string is anagram or not************************\n");
		printf("\n*****************18.Finding the permutations in a string using method 1******************\n");
		printf("\n*****************19.Finding the permutations in a string using method 2******************\n");
		printf("\n************************************20.Exiting......*************************************\n");
		printf("\nEnter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nYour string is creating please wait.....\n");
				char * p=createstring();
			break;
			
			case 2:
				printf("\nThe characters in the strings are \n");
				display(p);
			break;
			
			case 3:
				printf("\nThe length of the string is\n");
				int i;
				i=length(p);
				printf("%d\n",i);
			break;
			
			case 4:
				printf("\nOn converting lower case to uppercase\n");
				char * k=lowertoupper(p);
				display(k);
			break;
			
			case 5:
				printf("\nOn converting uppercase to lowercase\n");
				char * l=uppertolower(p);
				display(l);
			break;
			
			case 6:
				printf("\nOn Togglling the string\n");
				char * m=toggle(p);
				display(m);
			break;
			
			case 7:
				printf("\n");
				countingvowelsandconsonents(p);
			break;

			case 8:
				printf("\n");
				countingnumberofwords(p);
			break;

			case 9:
				printf("\nYour string is validating please wait\n");
				int v;
				v=validate(p);
				if(v)
					printf("\nYour string is valid and contains no special character\n");
				else
					printf("\nYour string is not valid and contains  special character\n");
			break;

			case 10:
				printf("\nYour string is reversing please wait\n");
				char * r=(char *)malloc(sizeof(char));
				r=reverse1(p);
				if(r)
				{
					printf("\nYour Reverse string is\n");
					display(r);
				}
				else
					printf("\nYour string is Null cannot be reversed\n");
				free(r);
			break;

			case 11:
				printf("\nYour string is reversing please wait\n");
				char * r2=(char *)malloc(sizeof(char));
				r2=reverse1(p);
				if(r2)
				{
					printf("\nYour Reverse string is\n");
					display(r2);
				}
				else
					printf("\nYour string is Null cannot be reversed\n");
				free(r2);
			break;

			case 12:
				printf("\n");
				int c=comparisionbetweentwostrings();
				if(c)
					printf("\nBoth the strings are same\n");
				else
					printf("\nBoth strings are different\n");

			break;

			case 13:
				printf("\n");
				int p2=plaindrome1(p);
				if(p2)
					printf("\nString is plaindrome\n");
				else
					printf("\nString is not palindrome\n");
			case 14:
				printf("\n");
				findingduplicate1(p);
			break;

			case 15:
				printf("\n");
				findingduplicate2(p);
			break;

			case 16:
				printf("\n");
				findingduplicate3(p);
			break;

			case 17:
				printf("\n");
				anagram();
			break;

			case 18:
				printf("\nGiving all pemutation of a string\n");
				permutation1(p,0);
			break;

			case 19:
				printf("\nGiving all pemutation of a string\n");
				permutation2(p,0,length(p));
			break;

			case 20:
				choice=0;
				printf("\nExiting......\n");
				free(p);
			break;
			
			default:
				printf("\nPlease enter correct choice\n");
				choice=1;
			break;
		}
	}
}
