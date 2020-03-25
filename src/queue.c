#include "queue.h"

#include <stdlib.h>

void queue_init(struct queue* q)
{
  q->size = 0;
  q->head = NULL;
  q->tail = NULL;
}

unsigned queue_size(struct queue* q)
{
  return q->size;
}

int queue_isEmpty(struct queue* q)
{
  return queue_size(q) == 0;
}

void queue_enqueue(struct queue* q, struct queue_node* n)
{
  q->size = q->size + 1;
  if (queue_size(q) == 1)
  {
    q->head = n;
    q->tail = n;
    n->next = n;
    n->prev = n;
    return;
  }

  n->next = q->tail;
  n->prev = q->head;
  q->head->next = n;
  q->tail->prev = n;
  q->tail = n;
}

struct queue_node* queue_dequeue(struct queue* q)
{
  if (queue_isEmpty(q))
    return NULL;

  q->size = q->size - 1;
  if (queue_isEmpty(q))
    return q->head;

  struct queue_node* head = q->head;
  q->head = q->head->prev;
  q->head->next = q->tail;
  q->tail->prev = q->head;
  return head;
}
