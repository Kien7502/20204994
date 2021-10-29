#include <stdio.h>
#define Max 50
typedef int Eltype;
typedef struct StackRec {
	Eltype storage[Max];
	int top;
};
typedef struct StackRec StackType;
struct node *pop(struct node *p, int *value){
	struct node *temp;
	if(p==NULL)
	{
		printf(" The stack is empty can 
		not pop Error\n");
		exit(0);
	}
	*value = p->data;
	temp = p;
	p = p->link;
	free(temp);
	return(p);
}
