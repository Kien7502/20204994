#include <stdio.h>
struct list_int *list_reverse (struct list_int* li){
	struct list_int *cur, *prev;
	cur = prev = NULL;
	while (li != NULL) {cur = li;
		li = li->next;
	cur->next = prev;
	prev = cur;
}
return prev;
}