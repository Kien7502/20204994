#include <stdio.h>
Student *find_student(Student *root, char*id){
Student *to_search = root;
while(to_search != NULL){
 if(strcmp(to_search->id, id) == 0)
 	return to_search;
	to_search = to_search->next;
}
return NULL;
}