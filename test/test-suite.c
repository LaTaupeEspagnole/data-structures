#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test-suite.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct test_rate test()
{
  int number_section = 2;
  struct test_section section_tab[number_section];

  /* Add your test section here */
  section_tab[0].name = "Queue";
  section_tab[0].test_function = test_queue;
  section_tab[0].rate.number_test = 0;
  section_tab[0].rate.number_success = 0;

  section_tab[1].name = "Stack";
  section_tab[1].test_function = test_stack;
  section_tab[1].rate.number_test = 0;
  section_tab[1].rate.number_success = 0;
  /* END */

  struct test_rate res = {.number_test = 0, .number_success = 0};

  for (int i = 0; i < number_section; i++)
  {
    printf("********** SECTION - %s\n", section_tab[i].name);
    struct test_rate ret = section_tab[i].test_function();
    res.number_test += ret.number_test;
    res.number_success += ret.number_success;
    section_tab[i].rate.number_test = ret.number_test;
    section_tab[i].rate.number_success = ret.number_success;
    printf("\n  RESULTS (test / success / rate) : %u / %u / ", \
      res.number_test, res.number_success);
    test_print_rate(res.number_test, res.number_success);
    printf("\n\n");
  }

  printf("*************** SUMMARY ****************\n");
  for (int i = 0; i < number_section; i++)
  {
    printf("SECTION %15.15s : %4u / %4u / ", \
      section_tab[i].name, \
      section_tab[i].rate.number_test, \
      section_tab[i].rate.number_success);
    test_print_rate(section_tab[i].rate.number_test, \
      section_tab[i].rate.number_success);
    printf("\n");
  }

  printf("TOTAL                   : %4u / %4u / ", \
    res.number_test, res.number_success);
  test_print_rate(res.number_test, res.number_success);
  printf("\n");

  return res;
}

void test_assert(struct test_rate* rate, const char* name, int assert)
{
  rate->number_test += 1;
  if (assert)
  {
    rate->number_success += 1;
    printf(ANSI_COLOR_GREEN " [SUCCESS] " ANSI_COLOR_RESET);
  }
  else
    printf(ANSI_COLOR_RED " [ ERROR ] " ANSI_COLOR_RESET);
  printf("%.50s\n", name);
}

void test_print_rate(unsigned tests, unsigned succes)
{
  float res = (float)succes / (float)tests * 100.0;
  if (res < 100.0)
    printf(ANSI_COLOR_RED);
  else
    printf(ANSI_COLOR_GREEN);
  printf("%3.2f%%" ANSI_COLOR_RESET, res);
}

int main()
{
  printf("****************************************\n");
  printf("************** TEST-SUITE **************\n");
  printf("****************************************\n\n");

  struct test_rate res = test();

  return res.number_test == res.number_success;
}
