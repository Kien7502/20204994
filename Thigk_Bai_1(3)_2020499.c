#include <stdio.h>
#include <string.h>
typedef struct{
	char name[31];
	char tel[12];
	char mail[31];
}Phonebook;
Phonebook queue[11];
int front;
int rear;

int cycle(int num)
{
	if (num==10)
		return 0;
	else return num+1;
}
int input()
{
	front=0;rear=0;
	FILE *in = fopen("Phonebook.dat","rb");
	if (in==NULL)
		return 1;
	for (rear=0;rear<10;rear++)
		fread(&queue[rear],sizeof(Phonebook),1,in);
	fclose(in);
	return 0;
}
Phonebook pop()
{
	int tmp=front;
	front=cycle(front);
	return queue[tmp];
}
void push(Phonebook dat)
{
	queue[rear]=dat;
	rear=cycle(rear);
}
void sort()
{
	int imax;
	Phonebook max,tmp;
	int i,j;
	for (i=0;i<10;i++)
	{
		imax=0;
		max=pop();
		push(max);
		for (j=1;j<10-i;j++)
		{
			tmp=pop();
			if (strcmp(tmp.name,max.name)>0)
			{
				max=tmp;
				imax=j;
			}
			push(tmp);
		}
		for(j=0;j<i;j++)
			push(pop());
		for (j=0;j<10-i;j++)
		{
			if (imax==0)
				pop();
			else push(pop());
			imax--;
		}
		push(max);
		for (j=0;j<i;j++)
			push(pop());
	}
}
int BinarySearch(char *search)
{
	int first=0;
	int last=9;
	int mid;
	int i,k;
	int result=-1;
	while (last>=first&&result==-1)
	{
		mid=(first+last)/2;
		for (i=0;i<mid;i++)
			push(pop());
		k=strcmp(search,queue[front].name); 
		if (k==0)
		{
			result=mid;
		}
		else if (k<0)
			last=mid-1;
		else first=mid+1;
		for(i=mid;i<10;i++)
			push(pop());
	}
	return result;
}
void output(int k)
{
	int i;
	FILE *out=fopen("Output.dat","a+b");
	for(i=0;i<k;i++)
		push(pop());
	fwrite(&queue[front],sizeof(Phonebook),1,out);
	for(i=k;i<11;i++)
		push(pop());
	fclose(out);
}
int main()
{
	int k;
	char search[31];
	if (input()==1)
	{
		printf("Cannot open the Phonebook folder.\n");
		return 1;
	}
	sort();
	printf("Enter the name to search: ");
	fgets(search,31,stdin);
	search[strlen(search)-1]='\0';
	k=BinarySearch(search);
	if (k==-1)
	{
		printf("Cannot found the entered name.\n");
		return 1;
	}
	output(k);
	printf("Name found!\n");
	return 0;
}
