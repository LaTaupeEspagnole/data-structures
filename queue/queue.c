#include "queue.h"

#include <stdlib.h>

void initQueue(struct queue* q)
{
  q->size = 0;
  q->head = NULL;
  q->tail = NULL;
}

unsigned queueSize(struct queue* q)
{
  return q->size;
}

int isQueueEmpty(struct queue* q)
{
  return queueSize(q) == 0;
}

void enqueue(struct queue* q, struct queue_node* n)
{
  q->size = q->size + 1;
  if (queueSize(q) == 1)
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

struct queue_node* dequeue(struct queue* q)
{
  if (isQueueEmpty(q))
    return NULL;

  q->size = q->size - 1;
  if (isQueueEmpty(q))
    return q->head;

  struct queue_node* head = q->head;
  q->head = q->head->prev;
  q->head->next = q->tail;
  q->tail->prev = q->head;
  return head;
}
