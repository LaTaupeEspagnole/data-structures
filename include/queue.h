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

void queue_init(struct queue* q);

unsigned queue_size(struct queue* q);

int queue_isEmpty(struct queue* q);

void queue_enqueue(struct queue* q, struct queue_node* n);

struct queue_node* queue_dequeue(struct queue* q);
