#include "specifier-list-string.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_node* list_string_alloc_node(const char* str)
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

void list_string_free_node(struct list_node* node)
{
  if (!node)
    return;

  if (node->val)
    free(node->val);

  free(node);
}

char* list_string_read_node(struct list_node* node)
{
  if (!node || !node->val)
    return NULL;

  return (char*)node->val;
}

int list_string_equal(void* left, void* right)
{
  return strcmp((char*)left, (char*)right);
}
