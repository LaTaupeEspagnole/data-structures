#pragma once

struct test_rate
{
  unsigned number_test;
  unsigned number_success;
};

struct test_section
{
  char* name;
  struct test_rate (*test_function)(void);
  struct test_rate rate;
};

void test_assert(struct test_rate* rate, const char* name, int assert);

void test_print_rate(unsigned tests, unsigned succes);

/* Section function */
struct test_rate test_queue(void);
