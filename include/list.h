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
 * \struct list_node
 * \brief Structure for a list node contaning the value and the next/prev node.
 */
struct list_node
{
  void*             val;
  struct list_node* next;
  struct list_node* prev;
};

/**
 * \struct list
 * \brief Structure for a list contaning le size and first element of the list.
 */
struct list {
  unsigned          size;
  struct list_node* first;
};

/**
 * \fn void list_init(struct list* list)
 * \brief Initiates the **list** structure with default values.\n
 * **No allocation is done here.**
 * \param list List structure
 */
void list_init(struct list* list);

unsigned list_size(struct list* list);

int list_isEmpty(struct list* list);

void list_append(struct list* list, struct list_node* node);

void list_prepend(struct list* list, struct list_node* node);

struct list_node* list_popleft(struct list* list);

struct list_node* list_popright(struct list* list);

struct list_node* list_get(struct list* list, unsigned index);

int list_insert(struct list* list, struct list_node* node, unsigned index);

struct list_node* list_remove(struct list* list, unsigned index);
