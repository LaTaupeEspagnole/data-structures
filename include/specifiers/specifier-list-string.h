#pragma once

#include "list.h"

/**
 * \file specifier-list-string.h
 * \brief List data structure specifier for string values
 * \author Sébastien Goubeau (sebastien.goubeau@protonmail.com)
 *
 * Containes all the functions to allocate a list node, free it, read a string
 * from it or compare it.
 */

/**
 * \brief Allocate a new node with the string **str** value
 * \param str String to copy in the node
 * \return The just allocated node
 *
 * There are two allocation here, one for the list_node structure and one for
 * the str argument.
 */
struct list_node* list_string_alloc_node(const char* str);

/**
 * \brief Free a string node
 * \param node The node to free
 *
 * There are two free done here, one for the list_node structure and one for
 * the value (string) of the node.
 */
void list_string_free_node(struct list_node* node);

/**
 * \brief Reads the string value in a string node
 * \param node Node to read from
 * \return The pointer to the string in the node
 *
 * The pointer returned is from the node it self, no copy is done here.
 */
char* list_string_read_node(struct list_node* node);

int list_string_equal(void* left, void* right);
