#include <stdio.h>

#include "list.h"

int main()
{
  struct list_node node0;
  struct list_node node1;
  struct list_node node2;
  struct list_node node3;

  int zero = 0;
  int one = 1;
  int two = 2;
  int three = 3;

  node0.val = (void*)&zero;
  node1.val = (void*)&one;
  node2.val = (void*)&two;
  node3.val = (void*)&three;

  printf("Inisialising list...\n");
  struct list list;
  list_init(&list);

  printf("Size of the list (should be 0) : %u\n", list_size(&list));
  printf("Is the list empty ? (should be yes) : ");
  if (list_isEmpty(&list))
    printf("yes\n");
  else
    printf("no\n");

  printf("Appending list...\n");
  list_append(&list, &node0);
  list_append(&list, &node1);
  list_append(&list, &node2);
  list_append(&list, &node3);

  printf("Size of the list (should be 4) : %u\n", list_size(&list));
  printf("Is the list empty ? (should be no) : ");
  if (list_isEmpty(&list))
    printf("yes\n");
  else
    printf("no\n");

  printf("rightpoping list (should be 3) : %d\n", *(int*)(list_popright(&list)->val));
  printf("rightpoping list (should be 2) : %d\n", *(int*)(list_popright(&list)->val));
  printf("rightpoping list (should be 1) : %d\n", *(int*)(list_popright(&list)->val));
  printf("rightpoping list (should be 0) : %d\n", *(int*)(list_popright(&list)->val));
  printf("rightpoping list (should be NULL) : ");
  if (list_popright(&list) == NULL)
    printf("NULL\n");
  else
    printf("NOT NULL\n");

  printf("Size of the list (should be 0) : %u\n", list_size(&list));
  printf("Is the list empty ? (should be yes) : ");
  if (list_isEmpty(&list))
    printf("yes\n");
  else
    printf("no\n");

  printf("Prepending list...\n");
  list_prepend(&list, &node0);
  list_prepend(&list, &node1);
  list_prepend(&list, &node2);
  list_prepend(&list, &node3);

  printf("Size of the list (should be 4) : %u\n", list_size(&list));
  printf("Is the list empty ? (should be no) : ");
  if (list_isEmpty(&list))
    printf("yes\n");
  else
    printf("no\n");

  printf("leftpoping list (should be 3) : %d\n", *(int*)(list_popleft(&list)->val));
  printf("leftpoping list (should be 2) : %d\n", *(int*)(list_popleft(&list)->val));
  printf("leftpoping list (should be 1) : %d\n", *(int*)(list_popleft(&list)->val));
  printf("leftpoping list (should be 0) : %d\n", *(int*)(list_popleft(&list)->val));
  printf("leftpoping list (should be NULL) : ");
  if (list_popright(&list) == NULL)
    printf("NULL\n");
  else
    printf("NOT NULL\n");

  printf("Size of the list (should be 0) : %u\n", list_size(&list));
  printf("Is the list empty ? (should be yes) : ");
  if (list_isEmpty(&list))
    printf("yes\n");
  else
    printf("no\n");

  printf("Inserting in list...\n");
  list_insert(&list, &node0, 0);
  list_insert(&list, &node1, 0);
  list_insert(&list, &node2, 1);
  list_insert(&list, &node3, 3);

  printf("Size of the list (should be 4) : %u\n", list_size(&list));
  printf("Is the list empty ? (should be no) : ");
  if (list_isEmpty(&list))
    printf("yes\n");
  else
    printf("no\n");


  printf("removing list index 0 (should be 1) : %d\n", *(int*)(list_remove(&list, 0)->val));
  printf("removing list index 1 (should be 0) : %d\n", *(int*)(list_remove(&list, 1)->val));
  printf("removing list index 1 (should be 3) : %d\n", *(int*)(list_remove(&list, 1)->val));
  printf("removing list index 0 (should be 2) : %d\n", *(int*)(list_remove(&list, 0)->val));

  printf("Size of the list (should be 0) : %u\n", list_size(&list));
  printf("Is the list empty ? (should be yes) : ");
  if (list_isEmpty(&list))
    printf("yes\n");
  else
    printf("no\n");

  return 0;
}
