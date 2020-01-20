#pragma once

struct queue_node
{
  void*         val;
  struct node*  next;
  struct node*  prev;
};

struct queue
{
  unsigned      size;
  struct node*  head;
  struct node*  tail;
};

void initQueue(struct queue* q);

int isQueueEmpty(struct queue* q);

unsigned queueSize(struct queue* q);

void enqueue(struct queue* q, struct queue_node* n);

struct queue_node* dequeue(struct queue* q);
