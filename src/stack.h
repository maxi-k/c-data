#include "linkedlist.h"
#ifndef _STACK_H_DEFINED
#define _STACK_H_DEFINED

typedef LINKED_LIST STACK;

STACK stacknew(int val);
void stackdestroy(STACK stack);
void stackpush(int val, STACK *stack);
int stackpop(STACK *stack);

#endif
