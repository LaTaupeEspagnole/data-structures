#pragma once

#include "list.h"

struct list_node* alloc_list_string_node(const char* str);

void free_list_string_node(struct list_node* node);

char* read_list_string_node(struct list_node* node);
