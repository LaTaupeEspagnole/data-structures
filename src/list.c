#include "list.h"

#include <stdlib.h>
#include <stdbool.h>

void list_init(struct list* list)
{
  list->size = 0;
  list->first = NULL;
}

unsigned list_size(struct list* list)
{
  return list->size;
}

int list_isEmpty(struct list* list)
{
  return list_size(list) == 0;
}

void list_hard_append(struct list* list, struct list_node* node)
{
  node->prev = list->first->prev;
  node->next = list->first;
  list->first->prev->next = node;
  list->first->prev = node;
}

void list_append(struct list* list, struct list_node* node)
{
  list->size = list->size + 1;
  if (list->size == 1)
  {
    list->first = node;
    node->next = node;
    node->prev = node;
    return;
  }

  list_hard_append(list, node);
}

void list_prepend(struct list* list, struct list_node* node)
{
  if (list->size == 0)
  {
    list_append(list, node);
    return;
  }

  list->size = list->size + 1;
  list_hard_append(list, node);
  list->first = node;
}

struct list_node* list_hard_remove(struct list* list, struct list_node* node)
{
  node->prev->next = node->next;
  node->next->prev = node->prev;
  list->size = list->size - 1;
  return node;
}

struct list_node* list_popleft(struct list* list)
{
  if (list->size == 0)
    return NULL;

  struct list_node* save = list->first;
  if (list->size == 1)
  {
    list->first = NULL;
    list->size = 0;
    return save;
  }

  list->first = save->next;

  return list_hard_remove(list, save);
}

struct list_node* list_popright(struct list* list)
{
  if (list->size == 0)
    return NULL;

  if (list->size == 1)
    return list_popleft(list);

  return list_hard_remove(list, list->first->prev);
}

struct list_node* list_get(struct list* list, unsigned index)
{
  if (index >= list->size)
    return NULL;

  unsigned iter = 0;
  struct list_node* pos = list->first;
  while (iter < index)
  {
    pos = pos->next;
    ++iter;
  }

  return pos;
}

int list_insert(struct list* list, struct list_node* node, unsigned index)
{
  if (index > list->size)
    return false;

  if (index == 0)
    list_prepend(list, node);
  else if (index == list->size)
    list_append(list, node);
  else
  {
    struct list_node* pos = list_get(list, index);
    node->next = pos;
    node->prev = pos->prev;
    pos->prev->next = node;
    pos->prev = node;
    list->size = list->size + 1;
  }

  return true;
}

struct list_node* list_remove(struct list* list, unsigned index)
{
  if (index >= list->size)
    return NULL;

  if (index == 0)
    return list_popleft(list);

  if (index == list->size - 1)
    return list_popright(list);

  return list_hard_remove(list, list_get(list, index));
}
