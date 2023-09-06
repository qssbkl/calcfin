#include "calculation.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

double counter(char *output_str, HEAD *head, double x) {
  int n = strlen(output_str);
  double num1, num2;
  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    if (output_str[i] == 'x') {
      printf("%f", x);
      pushing(x, head);
    } else if (output_str[i] >= '0' && output_str[i] <= '9') {
      int n = 1;
      double d = (output_str[i] - '0');
      while (output_str[i+n] >= '0' && output_str[i+n] <= '9') {
        d = d * 10;
        d = d + (output_str[i+n] - '0');
        n++;
      }
      if (output_str[i+n] == '.') {
        n++;
        int t = 1;
        while (output_str[i+n] >= '0' && output_str[i+n] <= '9') {
          double g = (output_str[i+n] - '0') / pow(10, t);
          printf("%f", g);
          d = d + g;
          n++;
          t++;
        }
      }
      i = i + n;
      pushing(d, head);
    } else if (output_str[i] == '+') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 + num2, head);
    } else if (output_str[i] == '-') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 - num2, head);
    } else if (output_str[i] == '*') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 * num2, head);
    } else if (output_str[i] == '/') {
      num2 = pop(head);
      num1 = pop(head);
      if (num2 != 0)
        pushing(num1 / num2, head);
      else
        pushing(INFINITY, head);
    } else if (output_str[i] == '^') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(pow(num1, num2), head);
    } else if (output_str[i] == 'm') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(fmod(num1, num2), head);
    } else if (output_str[i] == 's') {
      num1 = pop(head);
      pushing(sin(num1), head);
    } else if (output_str[i] == 'c') {
      num1 = pop(head);
      pushing(cos(num1), head);
    } else if (output_str[i] == 't') {
      num1 = pop(head);
      pushing(tan(num1), head);
    } else if (output_str[i] == 'g') {
      num1 = pop(head);
      pushing(1 / tan(num1), head);
    } else if (output_str[i] == 'q') {
      num1 = pop(head);
      if (isnan(sqrt(num1))) return 1;
      pushing(sqrt(num1), head);
    } else if (output_str[i] == 'l') {
      num1 = pop(head);
      pushing(log(num1), head);
    } else if (output_str[i] == 'u') {
      num1 = pop(head);
      pushing(0 - num1, head);
    } else if (output_str[i] == 'p') {
        num1 = pop(head);
        pushing(num1, head);
    } else if (output_str[i] == 'z') {
      num1 = pop(head);
      num2 = asin(num1);
      pushing(num2, head);
    } else if (output_str[i] == 'v') {
      num1 = pop(head);
      num2 = acos(num1);
      pushing(num2, head);
    } else if (output_str[i] == 'b') {
      num1 = pop(head);
      num2 = atan(num1);
      pushing(num2, head);
    } else if (output_str[i] == 'o') {
      num1 = pop(head);
      pushing(log10(num1), head);
    }
  }
  res = pop(head);
  return res;
}


void init(HEAD *head) { head->point = NULL; }

void pushing(double sym, HEAD *head) {
  OPERATIONS *tmp;
  tmp = head->point;
  OPERATIONS *new = (OPERATIONS *)malloc(sizeof(OPERATIONS));
  new->oper = sym;
  new->point = tmp;
  head->point = new;
}

double pop(HEAD *head) {
  double j;
  OPERATIONS *tmp = head->point;
  j = head->point->oper;
  head->point = head->point->point;
  free(tmp);
  return j;
}
