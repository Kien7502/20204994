#include <stdio.h>
#include <string.h>
typedef struct{
	char name[31];
	char tel[12];
	char mail[31];
}Phonebook;
Phonebook list[100];
int input()
{
	FILE *in = fopen("Phonebook.dat","rb");
	if (in==NULL)
		return 1;
	fread(list,sizeof(Phonebook),10,in);
	fclose(in);
	return 0;
}
void QuickSort()
{
	Phonebook tmp;
	int i,j;
	for (i=0;i<9;i++)
		for(j=i+1;j<10;j++)
			if (strcmp(list[i].name,list[j].name)>0)
			{
				tmp=list[i];
				list[i]=list[j];
				list[j]=tmp;
			}
}
int BinarySearch(char *search)
{
	int first=0;
	int last=9;
	int mid;
	int k;
	while (last>=first)
	{
		mid=(first+last)/2;
		k=strcmp(search,list[mid].name);
		if (k==0)
			return mid;
		else if (k<0)
			last=mid-1;
		else first=mid+1;
	}
	return -1;
}
void Output(int k)
{
	FILE *out=fopen("Output.dat","a+b");
	fwrite(&list[k],sizeof(Phonebook),1,out);
	fclose(out);
}
int main()
{
	int k;
	char search[31];
	if (input()==1)
	{
		printf("Cannot open the phonebook folder.\n");
		return 1;
	}
	QuickSort();
	printf("Enter the name to search: ");
	fgets(search,31,stdin);
	search[strlen(search)-1]='\0';
	k=BinarySearch(search);
	if (k==-1)
	{
		printf("Cannot found the entered name.\n");
		return 1;
	}
	Output(k);
	printf("Name found!\n");
	return 0;
}
