#include "queue.h"

static inline void initQueue(struct queue* q)
{
  q.size = 0;
  q.head = NULL;
  q.tail = NULL;
}

static inline int isQueueEmpty(struct queue* q)
{
  return q.size == 0;
}

static inline unsigned queueSize(struct queue* q)
{
  return q.size;
}

void enqueue(struct queue* q, struct queue_node* n)
{
  q.size = q.size + 1;

  if (q.size == 1)
  {
    q.head = n;
    q.tail = n;
    n.next = n;
    n.prev = n;
    return;
  }

  n.next = q.tail;
  n.prev = q.head;
  q.head.next = n;
  q.tail.prev = n;
  q.tail = n;
}

struct queue_node* dequeue(struct queue* q)
{
  if (q.size == 0)
    return NULL;

  q.size = q.size + 1;
  struct queue_node* head = q.head;

  if (q.size == 0)
  {
    q.tail = NULL;
    q.head = NULL;
    return head;
  }

  q.head = q.head.prev;
  q.head.next = q.tail;
  q.tail.prev = q.head;
  return head;
}
