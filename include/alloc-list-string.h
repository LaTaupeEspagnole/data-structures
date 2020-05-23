#pragma once

#include "list.h"

/**
 * \file alloc-list-string.h
 * \brief List data structure allocator for string values
 * \author Sébastien Goubeau (sebastien.goubeau@protonmail.com)
 *
 * Containes all the functions to allocate a list node, free it and read a
 * string from it.
 */

/**
 * \brief Allocate a new node with the string **str** value
 * \param str String to copy in the node
 * \return The just allocated node
 *
 * There are two allocation here, one for the list_node structure and one for
 * the str argument.
 */
struct list_node* alloc_list_string_node(const char* str);

/**
 * \brief Free a string node
 * \param node The node to free
 *
 * There are two free done here, one for the list_node structure and one for
 * the value (string) of the node.
 */
void free_list_string_node(struct list_node* node);

/**
 * \brief Reads the string value in a string node
 * \param node Node to read from
 * \return The pointer to the string in the node
 *
 * The pointer returned is from the node it self, no copy is done here.
 */
char* read_list_string_node(struct list_node* node);
