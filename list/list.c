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

  node->prev = list->first->prev;
  node->next = list->first;
  list->first->prev->next = node;
  list->first->prev = node;
}

void list_prepend(struct list* list, struct list_node* node)
{
  if (list->size == 0)
  {
    list_append(list, node);
    return;
  }

  list->size = list->size + 1;

  node->prev = list->first->prev;
  node->next = list->first;
  list->first->prev->next = node;
  list->first->prev = node;

  list->first = node;
}

struct list_node* list_popleft(struct list* list)
{
  if (list->size == 0)
    return NULL;

  struct list_node* first = list->first;
  if (list->size == 1)
  {
    list->first = NULL;
    list->size = 0;
    return first;
  }

  list->first = first->next;
  first->next->prev = first->prev;
  first->prev->next = first->next;
  list->size = list->size - 1;
  return first;
}

struct list_node* list_popright(struct list* list)
{
  if (list->size == 0)
    return NULL;

  if (list->size == 1)
    return list_popleft(list);

  struct list_node* last = list->first->prev;

  last->prev->next = last->next;
  last->next->prev = last->prev;

  list->size = list->size - 1;
  return last;
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
    unsigned iter = 0;
    struct list_node* pos = list->first;
    while (iter < index)
    {
      pos = pos->next;
      ++iter;
    }

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
  if (list->size == 0 || index > list->size)
    return NULL;

  if (index == 0)
    return list_popleft(list);

  if (index == list->size - 1)
    return list_popright(list);

  unsigned iter = 0;
  struct list_node* pos = list->first;
  while (iter < index)
  {
    pos = pos->next;
    ++iter;
  }

  pos->prev->next = pos->next;
  pos->next->prev = pos->prev;
  list->size = list->size - 1;
  return pos;
}
