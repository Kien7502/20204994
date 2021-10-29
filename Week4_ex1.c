#include <stdio.h>
#define Max 50
typedef int Eltype;
typedef struct StackRec {
Eltype storage[Max];
int top;
};
typedef struct StackRec StackType;
