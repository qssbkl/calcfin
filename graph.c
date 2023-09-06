#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculation.h"
#include "mystack.h"

int main() {
//  char **graph = calloc_matrix(HEIGHT, WIDTH + 1);
  struct st *operations = NULL;
  char input_string[80], output_string[80];
  fflush(stdin);
  fgets(input_string, 80, stdin);
  parsing_in_polish_notation(operations, input_string, output_string);
  printf("\n%s\n", output_string);
  fflush(stdin);
  HEAD head;
  init(&head);
  double x = 5.12;
  printf("\n%f\n", counter(output_string, &head, x));
  return 0;
}
