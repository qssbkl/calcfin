#ifndef SRC_MYSTACK_H_
#define SRC_MYSTACK_H_

struct st {
  char c;
  struct st *next;
};

int isNumber(char symbol);

struct st *push(struct st *, char);
char ysy(struct st **);
int priority(char);
void parsing_in_polish_notation(struct st *operations, char *input_str,
                                char *output_str);

#endif  // SRC_MYSTACK_H_
