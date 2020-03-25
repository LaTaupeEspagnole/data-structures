#include "allocator_string.h"

#include <stdlib.h>
#include <stdio.h>

char* allocator_string_alloc(const char* str)
{
  alloc = malloc(sizeof(char) * strlen(str));
  if (!alloc)
  {
    perror("allocator_string_alloc");
    exit(1);
  }

  return alloc;
}

void allocator_string_free(char* str)
{
  if (str)
    free(str);
}

void* allocator_string_untype(char* str)
{
  return (voir*)str;
}

char* allocator_string_retype(void* str)
{
  return (char*)str;
}
