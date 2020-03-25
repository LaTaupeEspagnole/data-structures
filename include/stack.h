#pragma once

struct stack_node
{
  void*               val;
  struct stack_node*  next;
};

void stack_initStack(struct stack_node* stack);

int stack_isStackEmpty(struct stack_node* stack);

void stack_push(struct stack_node* stack, struct stack_node* node);

struct stack_node* stack_pop(struct stack_node* stack);
