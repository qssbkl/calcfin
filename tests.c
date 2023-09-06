#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculation.h"
#include "mystack.h"

START_TEST(test1) {
  struct st *operations = NULL;
  char *input_string = "sin(1)+cos(1)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_double_eq(counter(output_string, &head, x), (sin(1)+cos(1)));
}
END_TEST

START_TEST(test2) {
  struct st *operations = NULL;
  char *input_string = "tg(1)-z(1)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_float_eq(counter(output_string, &head, x), (tan(1)-asin(1)));
}
END_TEST

START_TEST(test3) {
  struct st *operations = NULL;
  char *input_string = "ln(0)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_double_eq(counter(output_string, &head, x), log(0));
}
END_TEST

START_TEST(test4) {
  struct st *operations = NULL;
  char *input_string = "log(0)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_double_eq(counter(output_string, &head, x), log10(0));
}
END_TEST

START_TEST(test5) {
  struct st *operations = NULL;
  char *input_string = "(z(7)*56/11-3^(-2))";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_int_eq(isnan(counter(output_string, &head, x)), isnan(pow(asin(7)*56/11-3, (-2))));
}
END_TEST

START_TEST(test6) {
  struct st *operations = NULL;
  char *input_string = "sqrt(4)-v(0)+b(0)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_double_eq(counter(output_string, &head, x), sqrt(4)-acos(0)+atan(0));
}
END_TEST

START_TEST(test7) {
  struct st *operations = NULL;
  char *input_string = "1+1-1+sin(1)-cos(1)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_double_eq(counter(output_string, &head, x), 1+1-1+sin(1)-cos(1));
}
END_TEST

START_TEST(test8) {
  struct st *operations = NULL;
  char *input_string = "8.0+tg(1+1)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_double_eq(counter(output_string, &head, x), 8.0+tan(1+1));
}
END_TEST

START_TEST(test9) {
  struct st *operations = NULL;
  char *input_string = "1-b(0)*z(0)*v(0)";
  char *output_string;
  parsing_in_polish_notation(operations, input_string,
                            output_string);
  HEAD head;
  init(&head);
  double x = 5.12;
  ck_assert_double_eq(counter(output_string, &head, x), 1-asin(0)*acos(0)*atan(0));
}
END_TEST

Suite *Suite_create(void) {
  Suite *s21_string = suite_create("s21_string");
  TCase *tcase_test = tcase_create("test");

  tcase_add_test(tcase_test, test2);
  tcase_add_test(tcase_test, test1);
  tcase_add_test(tcase_test, test3);
  tcase_add_test(tcase_test, test4);
  tcase_add_test(tcase_test, test5);
  tcase_add_test(tcase_test, test6);
  tcase_add_test(tcase_test, test7);
  tcase_add_test(tcase_test, test8);
  tcase_add_test(tcase_test, test9);

  suite_add_tcase(s21_string, tcase_test);

  return s21_string;
}

int main(void) {
  Suite *suite = Suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(suite_runner);

  srunner_free(suite_runner);

  return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
