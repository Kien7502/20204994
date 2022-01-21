#include <stdio.h>
#include <string.h>
typedef struct{
	char name[31];
	char tel[12];
	char mail[31];
}Phonebook;
Phonebook queue[11];
int front=0;
int rear=0;
int cycle(int num)
{
	if (num==10)
		return 0;
	else return num+1;
}
int IsFull()
{
	if(cycle(rear)==front)
		return 1;
	else return 0;
}
void pop()
{
	printf("\nThe queue is full! Returning phonebook data:\n");
	printf("\tName: %s\n",queue[front].name);
	printf("\tTelephone number: %s\n",queue[front].tel);
	printf("\tEmail: %s\n\n",queue[front].mail);
	front=cycle(front);
}
void push()
{
	
	if(IsFull())
		pop();
	printf("Enter the phonebook data:\n");
	printf("\tName: ");
	fgets(queue[rear].name,31,stdin);
	queue[rear].name[strlen(queue[rear].name)-1]='\0';
	printf("\tTelephone number: ");
	fgets(queue[rear].tel,12,stdin);
	queue[rear].tel[strlen(queue[rear].tel)-1]='\0';
	printf("\tEmail: ");
	fgets(queue[rear].mail,31,stdin);
	queue[rear].mail[strlen(queue[rear].mail)-1]='\0';
	printf("\n");
	rear=cycle(rear);
}
int main()
{
	int i;
	for(i=0;;i++)
	{
		push();
	}
	return 0;
}
