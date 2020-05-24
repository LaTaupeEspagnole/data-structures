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

  struct stack_node stack;
  stack_initStack(&stack);

  stack_push(&stack, &node0);
  stack_push(&stack, &node1);
  stack_push(&stack, &node2);
  stack_push(&stack, &node3);

  test_assert(&res, "Stack empty after fill", !stack_isStackEmpty(&stack));
  test_assert(&res, "Poping 1/4", *(int*)(stack_pop(&stack)->val) == 3);
  test_assert(&res, "Poping 2/4", *(int*)(stack_pop(&stack)->val) == 2);
  test_assert(&res, "Poping 3/4", *(int*)(stack_pop(&stack)->val) == 1);
  test_assert(&res, "Poping 4/4", *(int*)(stack_pop(&stack)->val) == 0);
  test_assert(&res, "Poping while empty stack", stack_pop(&stack) == NULL);


  return res;
}
