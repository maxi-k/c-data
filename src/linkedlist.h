#ifndef _LINKEDLIST_H_INITIALIZED
#define _LINKEDLIST_H_INITIALIZED

typedef struct _cons_cell {
  int val;
  struct _cons_cell *next;
} CONS_CELL;

typedef CONS_CELL* LINKED_LIST;

LINKED_LIST llnew(int val);
void lldestroy(LINKED_LIST list);
LINKED_LIST llcons(int val, LINKED_LIST list);
int llfirst(LINKED_LIST list);
LINKED_LIST llrest(LINKED_LIST list);
void llprint(LINKED_LIST list);
int lleq(LINKED_LIST list1, LINKED_LIST list2);

void lldo(LINKED_LIST list, int (*f) (int));
LINKED_LIST llmap(LINKED_LIST list, int (*f) (int));
LINKED_LIST llreverse(LINKED_LIST list);
/* void* llreduce(LINKED_LIST list, void* initial, void* (*f) (int)); */

#endif
