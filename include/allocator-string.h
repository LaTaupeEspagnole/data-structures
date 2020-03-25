#pragma once

char* allocator_string_alloc(const char* str);

void allocator_string_free(char* str);

void* allocator_string_untype(char* str);

char* allocator_string_retype(void* str);
