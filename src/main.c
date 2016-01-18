#include "linkedlist.h"
#include "stack.h"
#include<stdio.h>

int times2(int);
int print_times2(int);

int main()
{
  LINKED_LIST list = llnew(1);
  LINKED_LIST list2 = NULL;
  STACK stack = NULL;
  int l;

  int i;
  for (i = 2; i < 10; ++i) {
    list = llcons(i, list);
  }

  printf("Liste1: "); llprint(list);
  list2 = llmap(list, times2);
  printf("Liste2: "); llprint(list2);
  list2 = llreverse(list2);
  printf("Liste2: "); llprint(list2);
  printf("\n");

  stack = list;
  stackpush(15, &stack);
  stackpush(20, &stack);

  printf("Stack: "); llprint(stack);
  printf("Liste1: "); llprint(list);
  printf("Eq(Stack, List1): %i\n", lleq(stack, list));
  printf("\n");

  l = stackpop(&stack);
  printf("Stackpop: %i\n", l);
  llprint(stack);
  l = stackpop(&stack);
  printf("Stackpop: %i\n", l);
  llprint(stack);
  printf("Eq(Stack, List1): %i\n", lleq(stack, list));

  lldestroy(list);
  /* Segmentation fault error because list was already pointing to (part of)
     stack and cleared. What to do here?? How to check if something is referenced
     by something else? */
  /* lldestroy(stack); */
  lldestroy(list2);
  return 0;
}

int times2(int x)
{
  return x * 2;
}

int print_times2(int x)
{
  printf("%i\n", x * 2);
  return x * 2;
}
