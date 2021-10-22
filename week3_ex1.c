#include <stdio.h>
struct AddressList {
	struct AddressList *next;
	struct Address addr;
};