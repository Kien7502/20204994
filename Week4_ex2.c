#include <stdio.h>
#define Max 50
typedef int Eltype;
typedef struct StackRec {
Eltype storage[Max];
int top;
};
typedef struct StackRec StackType;

struct node *push(struct node *p, int value) {
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct 
	node));
	if(temp==NULL) {
		printf("No Memory available Error
		\n");
		exit(0); 
	}
		temp
		->data = value;
		temp
		->link = p;
		p = temp;
		return(p);
}