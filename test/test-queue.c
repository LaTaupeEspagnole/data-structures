#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#include "test-suite.h"

struct test_rate test_queue()
{

  struct test_rate res = {0, 0};

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

  struct queue queue;
  queue_init(&queue);

  test_assert(&res, "Queue size after init", queue_size(&queue) == 0);
  test_assert(&res, "Queue is empty after init", queue_isEmpty(&queue));

  queue_enqueue(&queue, node0);
  queue_enqueue(&queue, node1);
  queue_enqueue(&queue, node2);
  queue_enqueue(&queue, node3);
  queue_enqueue(&queue, node4);
  queue_enqueue(&queue, node5);

  test_assert(&res, "Queue size after enqueue", queue_size(&queue) == 6);
  test_assert(&res, "Queue is empty after enqueue", !queue_isEmpty(&queue));

  test_assert(&res, "Poping 1/6", *(int*)(queue_dequeue(&queue)->val) == 0);
  test_assert(&res, "Poping 2/6", *(int*)(queue_dequeue(&queue)->val) == 1);
  test_assert(&res, "Poping 3/6", *(int*)(queue_dequeue(&queue)->val) == 2);
  test_assert(&res, "Poping 4/6", *(int*)(queue_dequeue(&queue)->val) == 3);
  test_assert(&res, "Poping 5/6", *(int*)(queue_dequeue(&queue)->val) == 4);
  test_assert(&res, "Poping 6/6", *(int*)(queue_dequeue(&queue)->val) == 5);
  test_assert(&res, "Poping while empty queue", queue_dequeue(&queue) == NULL);
  test_assert(&res, "Queue size after poping", queue_size(&queue) == 0);
  test_assert(&res, "Queue is empty after poping", queue_isEmpty(&queue));

  queue_enqueue(&queue, node0);
  queue_enqueue(&queue, node1);
  queue_enqueue(&queue, node2);

  test_assert(&res, "Queue size after enqueue", queue_size(&queue) == 3);
  test_assert(&res, "Queue is empty after enqueue", !queue_isEmpty(&queue));

  test_assert(&res, "Poping 1/3", *(int*)(queue_dequeue(&queue)->val) == 0);
  test_assert(&res, "Poping 2/3", *(int*)(queue_dequeue(&queue)->val) == 1);
  test_assert(&res, "Poping 3/3", *(int*)(queue_dequeue(&queue)->val) == 2);
  test_assert(&res, "Poping while empty queue", queue_dequeue(&queue) == NULL);
  test_assert(&res, "Queue size after poping", queue_size(&queue) == 0);
  test_assert(&res, "Queue is empty after poping", queue_isEmpty(&queue));

  free(node0);
  free(node1);
  free(node2);
  free(node3);
  free(node4);
  free(node5);

  return res;
}
