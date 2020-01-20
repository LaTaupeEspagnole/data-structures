#pragma once

struct queue_node
{
  void*               val;
  struct queue_node*  next;
  struct queue_node*  prev;
};

struct queue
{
  unsigned            size;
  struct queue_node*  head;
  struct queue_node*  tail;
};

void initQueue(struct queue* q);

unsigned queueSize(struct queue* q);

int isQueueEmpty(struct queue* q);

void enqueue(struct queue* q, struct queue_node* n);

struct queue_node* dequeue(struct queue* q);
