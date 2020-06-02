#pragma once

/**
 * \file stack.h
 * \brief Stack data structure file
 * \author Sébastien Goubeau (sebastien.goubeau@protonmail.com)
 *
 * Containes all the functions and structures needed to manipulate the stack
 * data structure.
 */

/**
 * Structure for a stack node contaning the value and the next node pointer.
 */
struct stack_node
{
  void*               val;    /*!< pointer to the value */
  struct stack_node*  next;   /*!< pointer to the next node */
};

/**
 * \brief Initiate the **stack** structure with default vales\n
 * **No allocation is done here**
 * \param stack Top node of the stack
 *
 * The first node of the stack can be considered the stack it self in this
 * implementation.
 */
void stack_initStack(struct stack_node* stack);

/**
 * \brief Check whether the stack is empty
 * \param stack Top node of the stack
 * \return true (1) if the **stack** is empty, false (0) otherwise
 */
int stack_isStackEmpty(struct stack_node* stack);

/**
 * \brief Push a node on top of the stack
 * \param stack Top node of the stack
 * \param node Node to push
 */
void stack_push(struct stack_node* stack, struct stack_node* node);

/**
 * \brief Pop the node on top of the stack\n
 * **No free is done here**
 * \param stack Top node of the stack
 * \return The node that just been poped
 */
struct stack_node* stack_pop(struct stack_node* stack);
