#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char name[31];
	char tel[12];
	char mail[31];
}Address;
struct list{
	Address add;
	struct list *next;
};
struct list *root;
struct list *cur;
int input()
{
	int i;
	struct list *New;
	FILE *in = fopen("Phonebook.dat","rb");
	if (in==NULL)
		return 1;
	for (i=0;i<10;i++)
	{
		New=(struct list *)malloc(sizeof(struct list));
		New->next=NULL;
		fread(&(New->add),sizeof(Address),1,in);
		if (i==0)
			root=cur=New;
		else 
		{
			cur->next=New;
			cur=cur->next;
		}
	}
	fclose(in);
	return 0;
}
void join(struct list *a, struct list *b)
{
	struct list *tmp;
	if (a==root)
		return;
	for (tmp=root;tmp->next!=a;tmp=tmp->next);
	tmp->next=a->next;
	if (b==root)
		root=a;
	else
	{
		for (tmp=root;tmp->next!=b;tmp=tmp->next);
		tmp->next=a;
	}
	a->next=b;
}
void QuickSort()
{
	struct list *tmp;
	struct list *sortp;
	for (cur=root->next;cur!=NULL;)
	{
		for(sortp=root;sortp!=cur;sortp=sortp->next)
		{
			if (strcmp(cur->add.name,sortp->add.name)<0)
			{
				tmp=cur;
				cur=cur->next;
				join(tmp,sortp);
				break;
			}
		}
		if (sortp==cur)
			cur=cur->next;
	}
}
struct list *BinarySearch(char *search, int selfsortnum)
{
	int first=selfsortnum;
	int last=9;
	int mid;
	int i;
	int k;
	for (i=0,cur=root;i<selfsortnum;i++,cur=cur->next)
		if (strcmp(search,cur->add.name)==0)
			return cur;
	while (last>=first)
	{
		mid=(first+last)/2;
		for (i=0,cur=root;i<mid;i++,cur=cur->next);
		k=strcmp(search,cur->add.name);
		if (k==0)
			return cur;
		else if (k<0)
			last=mid-1;
		else first=mid+1;
	}
	return NULL;
}
void Output(struct list *result)
{
	FILE *out=fopen("Output.dat","a+b");
	fwrite(&(result->add),sizeof(Address),1,out);
	fclose(out);
}
int main()
{
	int k;
	char search[31];
	struct list *result;
	struct list *secondresult;
	if (input()==1)
	{
		printf("Cannot open the address folder.\n");
		return 1;
	}
	QuickSort();
	printf("Enter the name to search: ");
	fgets(search,31,stdin);
	search[strlen(search)-1]='\0';
	result=BinarySearch(search,0);
	if (result==NULL)
		printf("Cannot found the entered name.\n");
	else
	{
		Output(result);
		printf("Name found!\n");
		join(result,root);
	}
	printf("Enter the second name to search: ");
	fgets(search,31,stdin);
	search[strlen(search)-1]='\0';
	secondresult=BinarySearch(search,1);
	if (secondresult==NULL)
		printf("Cannot found the entered name.\n");
	else
	{
		Output(secondresult);
		printf("Name found!\n");
	}
	return 0;
}
