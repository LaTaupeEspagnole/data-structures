#include <stdio.h>
#include <string.h>

#include "list.h"
#include "alloc-list-string.h"

#include "test-suite.h"

struct test_rate test_list_string()
{
  struct test_rate res = {0, 0};

  struct list list;

  list_init(&list);
  list_append(&list, alloc_list_string_node("Sébastien"));
  list_append(&list, alloc_list_string_node("Aurélie"));

  test_assert(&res, "List size after append", list_size(&list) == 2);
  test_assert(&res, "Read value 1/2",
    !strcmp(read_list_string_node(list_get(&list, 0)), "Sébastien"));
  test_assert(&res, "Read value 2/2",
    !strcmp(read_list_string_node(list_get(&list, 1)), "Aurélie"));

  struct list_node* node0 = list_popright(&list);
  struct list_node* node1 = list_popright(&list);

  test_assert(&res, "Read rightpoped value 1/2",
    !strcmp(read_list_string_node(node0), "Aurélie"));
  test_assert(&res, "Read rightpoped value 2/2",
    !strcmp(read_list_string_node(node0), "Aurélie"));

  test_assert(&res, "List size after rightpop", list_size(&list) == 0);

  free_list_string_node(node0);
  free_list_string_node(node1);

  return res;
}
