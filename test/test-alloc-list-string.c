#include <stdio.h>

#include "list.h"
#include "alloc-list-string.h"

int main()
{
  struct list list;

  list_init(&list);
  list_append(&list, alloc_list_string_node("Sébastien"));
  list_append(&list, alloc_list_string_node("Aurélie"));

  printf("List size : %u\n", list_size(&list));
  printf("list[0] = %s\n", read_list_string_node(list_get(&list, 0)));
  printf("list[1] = %s\n", read_list_string_node(list_get(&list, 1)));
  printf("\n");

  struct list_node* node0 = list_popright(&list);
  struct list_node* node1 = list_popright(&list);
  printf("list_popright(list) = %s\n", read_list_string_node(node0));
  printf("list_popright(list) = %s\n", read_list_string_node(node1));
  printf("\n");
  printf("List size : %u\n", list_size(&list));

  free_list_string_node(node0);
  free_list_string_node(node1);

  return 0;
}
