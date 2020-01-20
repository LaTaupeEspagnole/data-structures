#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
  printf("Creating queue nodes...\n");
  struct queue_node* node0 = malloc(sizeof(struct queue_node));
  struct queue_node* node1 = malloc(sizeof(struct queue_node));
  struct queue_node* node2 = malloc(sizeof(struct queue_node));
  struct queue_node* node3 = malloc(sizeof(struct queue_node));
  struct queue_node* node4 = malloc(sizeof(struct queue_node));
  struct queue_node* node5 = malloc(sizeof(struct queue_node));

  int zero = 0;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;

  node0->val = (void*)&zero;
  node1->val = (void*)&one;
  node2->val = (void*)&two;
  node3->val = (void*)&three;
  node4->val = (void*)&four;
  node5->val = (void*)&five;

  printf("Initialising queue...\n");
  struct queue queue;
  initQueue(&queue);

  printf("Size queue (should be 0) : %u\n", queueSize(&queue));

  printf("Is queue empty (should be yes) : ");
  if (isQueueEmpty(&queue))
    printf("yes\n");
  else
    printf("no\n");

  printf("Filling queue...\n");
  enqueue(&queue, node0);
  enqueue(&queue, node1);
  enqueue(&queue, node2);
  enqueue(&queue, node3);
  enqueue(&queue, node4);
  enqueue(&queue, node5);

  printf("Size queue (should be 6) : %u\n", queueSize(&queue));

  printf("Is queue empty (should be no) : ");
  if (isQueueEmpty(&queue))
    printf("yes\n");
  else
    printf("no\n");

  printf("Emptying queue...\n");
  printf("Node0 poped : value = %d (should be 0)\n", *(int*)(dequeue(&queue)->val));
  printf("Node1 poped : value = %d (should be 1)\n", *(int*)(dequeue(&queue)->val));
  printf("Node2 poped : value = %d (should be 2)\n", *(int*)(dequeue(&queue)->val));
  printf("Node3 poped : value = %d (should be 3)\n", *(int*)(dequeue(&queue)->val));
  printf("Node4 poped : value = %d (should be 4)\n", *(int*)(dequeue(&queue)->val));
  printf("Node5 poped : value = %d (should be 5)\n", *(int*)(dequeue(&queue)->val));
  printf("Poping while empty (should return NULL) : ");
  if (dequeue(&queue) == NULL)
    printf("NULL\n");
  else
    printf("NOT NULL\n");

  printf("Size queue (should be 0) : %u\n", queueSize(&queue));

  printf("Is queue empty (should be yes) : ");
  if (isQueueEmpty(&queue))
    printf("yes\n");
  else
    printf("no\n");

  printf("Filling queue...\n");
  enqueue(&queue, node0);
  enqueue(&queue, node1);
  enqueue(&queue, node2);
  enqueue(&queue, node3);
  enqueue(&queue, node4);
  enqueue(&queue, node5);

  printf("Size queue (should be 6) : %u\n", queueSize(&queue));

  printf("Is queue empty (should be no) : ");
  if (isQueueEmpty(&queue))
    printf("yes\n");
  else
    printf("no\n");

  printf("Emptying queue...\n");
  printf("Node0 poped : value = %d (should be 0)\n", *(int*)(dequeue(&queue)->val));
  printf("Node1 poped : value = %d (should be 1)\n", *(int*)(dequeue(&queue)->val));
  printf("Node2 poped : value = %d (should be 2)\n", *(int*)(dequeue(&queue)->val));
  printf("Node3 poped : value = %d (should be 3)\n", *(int*)(dequeue(&queue)->val));
  printf("Node4 poped : value = %d (should be 4)\n", *(int*)(dequeue(&queue)->val));
  printf("Node5 poped : value = %d (should be 5)\n", *(int*)(dequeue(&queue)->val));

  printf("Poping while empty (should return NULL) : ");
  if (dequeue(&queue) == NULL)
    printf("NULL\n");
  else
    printf("NOT NULL\n");

  printf("Size queue (should be 0) : %u\n", queueSize(&queue));

  printf("Is queue empty (should be yes) : ");
  if (isQueueEmpty(&queue))
    printf("yes\n");
  else
    printf("no\n");

  printf("Freeing node memory...\n");
  free(node0);
  free(node1);
  free(node2);
  free(node3);
  free(node4);
  free(node5);

  printf("End.\n");

  return 0;
}
