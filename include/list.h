#pragma once

/**
 * \file list.h
 * \brief List data structure file
 * \author Sébastien Goubeau (sebastien.goubeau@protonmail.com)
 *
 * Containes all the functions and structures needed to manipulate the list
 * data structure.
 */


/**
 * \brief Structure for a list node contaning the value and the next/prev node.
 */
struct list_node
{
  void*             val;    /*!< pointer to the value */
  struct list_node* next;   /*!< pointer to the next node */
  struct list_node* prev;   /*!< pointer to the previous node */
};

/**
 * \brief Structure for a list contaning le size and first element of the list.
 */
struct list {
  unsigned          size;   /*!< size of the list */
  struct list_node* first;  /*!< pointer to the first node of the list */
};

/**
 * \brief Initiate the **list** structure with default values\n
 * **No allocation is done here**
 * \param list List structure
 */
void list_init(struct list* list);

/**
 * \brief Get the size of the list
 * \param list List of which to get the size from
 * \return Size of the list **list**
 */
unsigned list_size(struct list* list);

/**
 * \brief Check whether the list is empty
 * \param list List of which to check emptiness
 * \return true (1) if the **list** is empty, false (0) otherwise
 */
int list_isEmpty(struct list* list);

/**
 * \brief Append a node to a list
 * \param list List to append from
 * \param node Node to append
 */
void list_append(struct list* list, struct list_node* node);

/**
 * \brief Prepend a node to a list
 * \param list List to prepend from
 * \param node Node to prepend
 */
void list_prepend(struct list* list, struct list_node* node);

/**
 * \brief Pop the left node of a list\n
 * **No free is done here**
 * \param list List from which to pop from
 * \return The just leftpoped node
 */
struct list_node* list_popleft(struct list* list);

/**
 * \brief Pop the right node of a list\n
 * **No free is done here**
 * \param list List from which to pop from
 * \return The just rightpoped node
 */
struct list_node* list_popright(struct list* list);

/**
 * \brief Get a node from a list
 * \param list List from which to get the node from
 * \param index Index of the node to fetch from the left
 * \return Node's pointer
 */
struct list_node* list_get(struct list* list, unsigned index);

/**
 * \brief Insert a node at an index of a list
 * \param list List from which to insert to
 * \param node Node to insert
 * \param index Index of the new node in the **list**
 * \return true (1) if the node has been inserted, false (0) otherwise. The
 * function returns false if the index is greater than the list's size.
 */
int list_insert(struct list* list, struct list_node* node, unsigned index);

/**
 * \brief Remove a node from a list\n
 * **No free is done here**
 * \param list List from which to remove from
 * \param index Index of the node to remove
 * \return The just removed node. The function returns NULL if the index is
 * greater or equal to the list's size.
 */
struct list_node* list_remove(struct list* list, unsigned index);
