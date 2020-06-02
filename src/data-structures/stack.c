#include "stack.h"

#include <stdlib.h>

void stack_initStack(struct stack_node* stack)
{
  stack->next = NULL;
}

int stack_isStackEmpty(struct stack_node* stack)
{
  return stack->next == NULL;
}

void stack_push(struct stack_node* stack, struct stack_node* node)
{
  node->next = stack->next;
  stack->next = node;
}

struct stack_node* stack_pop(struct stack_node* stack)
{
  if (stack_isStackEmpty(stack))
    return NULL;

  struct stack_node* head = stack->next;
  stack->next = stack->next->next;
  return head;
}
