#include "linkedlist.h"
#include<stdlib.h>
#include<stdio.h>

LINKED_LIST llnew(int val)
{
  CONS_CELL* cell = malloc(sizeof(CONS_CELL));
  cell->val = val;
  cell->next = NULL;
  return cell;
}

void lldestroy(LINKED_LIST list)
{
  LINKED_LIST next;
  if (list == NULL) return;
  next = llrest(list);
  free(list);
  lldestroy(next);
}

LINKED_LIST llcons(int val, LINKED_LIST list)
{
  LINKED_LIST start = llnew(val);
  start->next = list;
  return start;
}

int llfirst(LINKED_LIST list)
{
  if (list == NULL)
    return 0;
  return list->val;
}

LINKED_LIST llrest(LINKED_LIST list)
{
  if (list == NULL)
    return NULL;
  return list->next;
}

void llprint(LINKED_LIST list)
{
  LINKED_LIST cur = list;
  if (cur == NULL)
    return;
  printf("( ");
  while (cur != NULL) {
    printf("%i ", llfirst(cur));
    cur = llrest(cur);
  }
  puts(")");
}

int lleq(LINKED_LIST list1, LINKED_LIST list2)
{
  if (list1 == NULL && list2 == NULL)
    return 1;
  if (list1 == NULL || list2 == NULL)
    return 0;
  return (llfirst(list1) == llfirst(list2)) && lleq(llrest(list1), llrest(list2));
}

void lldo(LINKED_LIST list, int (*f) (int))
{
  if (list == NULL) return;
  f(llfirst(list));
  lldo(llrest(list), f);
}

LINKED_LIST llmap(LINKED_LIST list, int (*f) (int))
{
  if (list == NULL) return NULL;
  return llcons(f(llfirst(list)), llmap(llrest(list), f));
}

LINKED_LIST llreverse(LINKED_LIST list)
{
  LINKED_LIST new;
  LINKED_LIST tmp;
  if (list == NULL) return NULL;
  new = llnew(llfirst(list));
  tmp = llrest(list);
  while (tmp != NULL) {
    new = llcons(llfirst(tmp), new);
    tmp = llrest(tmp);
  }
  return new;
}
