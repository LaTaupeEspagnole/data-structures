#include <stdio.h>

#include "list.h"

#include "test-suite.h"

struct test_rate test_list()
{
  struct test_rate res = {0, 0};

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

  struct list list;
  list_init(&list);

  test_assert(&res, "Size of a empty list", list_size(&list) == 0);
  test_assert(&res, "Is list empty while empty", list_isEmpty(&list));

  list_append(&list, &node0);
  list_append(&list, &node1);
  list_append(&list, &node2);
  list_append(&list, &node3);

  test_assert(&res, "Size of list after append", list_size(&list) == 4);
  test_assert(&res, "Is list empty after append", !list_isEmpty(&list));
  test_assert(&res, "Rightpoping list 1/4", *(int*)(list_popright(&list)->val) == 3);
  test_assert(&res, "Rightpoping list 2/4", *(int*)(list_popright(&list)->val) == 2);
  test_assert(&res, "Rightpoping list 3/4", *(int*)(list_popright(&list)->val) == 1);
  test_assert(&res, "Rightpoping list 4/4", *(int*)(list_popright(&list)->val) == 0);
  test_assert(&res, "Rightpoping while empty list", list_popright(&list) == NULL);
  test_assert(&res, "Size of list after rightpoping all nodes", list_size(&list) == 0);
  test_assert(&res, "Is list empty after rightpoping all nodes", list_isEmpty(&list));

  list_prepend(&list, &node0);
  list_prepend(&list, &node1);
  list_prepend(&list, &node2);
  list_prepend(&list, &node3);

  test_assert(&res, "Size of list after prepend", list_size(&list) == 4);
  test_assert(&res, "Is list empty after prepend", !list_isEmpty(&list));
  test_assert(&res, "Leftpoping list 1/4", *(int*)(list_popleft(&list)->val) == 3);
  test_assert(&res, "Leftpoping list 2/4", *(int*)(list_popleft(&list)->val) == 2);
  test_assert(&res, "Leftpoping list 3/4", *(int*)(list_popleft(&list)->val) == 1);
  test_assert(&res, "Leftpoping list 4/4", *(int*)(list_popleft(&list)->val) == 0);
  test_assert(&res, "Leftpoping while empty list", list_popright(&list) == NULL);

  test_assert(&res, "Size after leftpoping all nodes", list_size(&list) == 0);
  test_assert(&res, "Is list empty after leftpoping all nodes", list_isEmpty(&list));

  list_insert(&list, &node0, 0);
  list_insert(&list, &node1, 0);
  list_insert(&list, &node2, 1);
  list_insert(&list, &node3, 3);

  test_assert(&res, "Size list after inserting", list_size(&list) == 4);
  test_assert(&res, "Is list empty after inserting", !list_isEmpty(&list));
  test_assert(&res, "Getting in list 1/4", *(int*)(list_get(&list, 0)->val) == 1);
  test_assert(&res, "Getting in list 2/4", *(int*)(list_get(&list, 1)->val) == 2);
  test_assert(&res, "Getting in list 3/4", *(int*)(list_get(&list, 2)->val) == 0);
  test_assert(&res, "Getting in list 4/4", *(int*)(list_get(&list, 3)->val) == 3);

  test_assert(&res, "Size of list after insert", list_size(&list) == 4);
  test_assert(&res, "Removing in list 1/4", *(int*)(list_remove(&list, 0)->val) == 1);
  test_assert(&res, "Removing in list 2/4", *(int*)(list_remove(&list, 1)->val) == 0);
  test_assert(&res, "Removing in list 3/4", *(int*)(list_remove(&list, 1)->val) == 3);
  test_assert(&res, "Removing in list 4/4", *(int*)(list_remove(&list, 0)->val) == 2);
  test_assert(&res, "Size of list after removing", list_size(&list) == 0);
  test_assert(&res, "Is list empty after removing", list_isEmpty(&list));

  return res;
}
