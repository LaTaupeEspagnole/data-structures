#include <stdio.h>

#include "stack.h"

#include "test-suite.h"

struct test_rate test_stack()
{
  struct test_rate res = {0, 0};

  struct stack_node node0;
  struct stack_node node1;
  struct stack_node node2;
  struct stack_node node3;

  stack_initStack(&node0);
  stack_initStack(&node1);
  stack_initStack(&node2);
  stack_initStack(&node3);

  int zero = 0;
  int one = 1;
  int two = 2;
  int three = 3;

  node0.val = (void*)&zero;
  node1.val = (void*)&one;
  node2.val = (void*)&two;
  node3.val = (void*)&three;

//  printf("Inisialising stack...\n");
  struct stack_node stack;
  stack_initStack(&stack);

//  printf("Filling stack...\n");
  stack_push(&stack, &node0);
  stack_push(&stack, &node1);
  stack_push(&stack, &node2);
  stack_push(&stack, &node3);

/*
  printf("Is stack empty (should be no) : ");
  if (stack_isStackEmpty(&stack))
    printf("yes\n");
  else
    printf("no\n");
*/
  test_assert(&res, "Stack empty after fill", !stack_isStackEmpty(&stack));

/*
  printf("Poping the stack...\n");
  printf("Node3 poped : value = %d (should be 3)\n", *(int*)(stack_pop(&stack)->val));
  printf("Node2 poped : value = %d (should be 2)\n", *(int*)(stack_pop(&stack)->val));
  printf("Node1 poped : value = %d (should be 1)\n", *(int*)(stack_pop(&stack)->val));
  printf("Node0 poped : value = %d (should be 0)\n", *(int*)(stack_pop(&stack)->val));
  printf("Poped empty stack (should be NULL) : ");
  if (stack_pop(&stack) == NULL)
    printf("NULL\n");
  else
    printf("NOT NULL\n");
*/
  test_assert(&res, "Poping 1/4", *(int*)(stack_pop(&stack)->val) == 3);
  test_assert(&res, "Poping 2/4", *(int*)(stack_pop(&stack)->val) == 2);
  test_assert(&res, "Poping 3/4", *(int*)(stack_pop(&stack)->val) == 1);
  test_assert(&res, "Poping 4/4", *(int*)(stack_pop(&stack)->val) == 0);
  test_assert(&res, "Poping while empty stack", stack_pop(&stack) == NULL);


  return res;
}
