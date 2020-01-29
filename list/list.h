#pragma once

struct list_node
{
  void*             val;
  struct list_node* next;
  struct list_node* prev;
};

struct list {
  unsigned          size;
  struct list_node* first;
};

void list_init(struct list* list);

unsigned list_size(struct list* list);

int list_isEmpty(struct list* list);

void list_append(struct list* list, struct list_node* node);

void list_prepend(struct list* list, struct list_node* node);

struct list_node* list_popleft(struct list* list);

struct list_node* list_popright(struct list* list);

struct list_node* list_get(struct list* list, unsigned index);

int list_insert(struct list* list, struct list_node* node, unsigned index);

struct list_node* list_remove(struct list* list, unsigned index);
