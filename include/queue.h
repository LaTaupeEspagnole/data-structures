#pragma once

/**
 * \file queue.h
 * \brief Queue data structure file
 * \author Sébastien Goubeau (sebastien.goubeau@protonmail.com)
 *
 * Containes all the functions and structures needed to manipulate the queue
 * data structure.
 */

/**
 * \brief Structure for a queue_node contaning the value and the next/prev
 * node.
 */
struct queue_node
{
  void*               val;    /*!< pointer to the value */
  struct queue_node*  next;   /*!< pointer to the next node */
  struct queue_node*  prev;   /*!< pointer to the previous node */
};

/**
 * \brief Structure for a queue contaning le size, head and tail element of the
 * queue
 */
struct queue
{
  unsigned            size;   /*!< size of the queue */
  struct queue_node*  head;   /*!< pointer to the head node of the queue */
  struct queue_node*  tail;   /*!< pointer to the tail node of the queue */
};

/**
 * \brief Initiate the **queue** structure with default values\n
 * **No allocation is done here**
 * \param q Queue structure
 */
void queue_init(struct queue* q);

/**
 * \brief Get the size of the queue
 * \param q Queue of which to get the size from
 * \return Size of the queue **queue**
 */
unsigned queue_size(struct queue* q);

/**
 * \brief Check whether the queue is empty
 * \param q Queue of which to check emptiness
 * \return true (1) if the **queue** is empty, false (0) otherwise
 */
int queue_isEmpty(struct queue* q);

/**
 * \brief Enqueue a node to a queue
 * \param q Queue to enqueue from
 * \param n Node to enqueue
 */
void queue_enqueue(struct queue* q, struct queue_node* n);

/**
 * \brief Dequeue a node from a queue\n
 * **No free is done here**
 * \param q Queue to dequeue from
 * \return The just dequeued node. Returns NULL if the queue is empty.
 */
struct queue_node* queue_dequeue(struct queue* q);
