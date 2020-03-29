#include "alloc-list-string.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_node* alloc_list_string_node(const char* str)
{
  if (!str)
    return NULL;

  void* alloc = malloc(sizeof(char) * (strlen(str) + 1));
  if (!alloc)
  {
    perror("alloc_list_string_node:alloc");
    exit(1);
  }
  strcpy(alloc, str);

  struct list_node* node = malloc(sizeof(*node));
  if (!node)
  {
    perror("alloc_list_string_node:node");
    exit(1);
  }

  node->val = alloc;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

void free_list_string_node(struct list_node* node)
{
  if (!node)
    return;

  if (node->val)
    free(node->val);

  free(node);
}

char* read_list_string_node(struct list_node* node)
{
  if (!node || !node->val)
    return NULL;

  return (char*)node->val;
}
