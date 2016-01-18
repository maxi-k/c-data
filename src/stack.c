#include "stack.h"
#include<stdlib.h>

STACK stacknew(int val)
{
  return llnew(val);
}

void stackdestroy(STACK stack)
{
  lldestroy(stack);
}

void stackpush(int val, STACK *stack)
{
  *stack = llcons(val, *stack);
}

int stackpop(STACK *stack)
{
  int val = llfirst(*stack);
  STACK rest = llrest(*stack);
  *stack = rest;
  return val;
}
