#include "lib.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  srand(time(0));
  LinkedList *numbers = malloc(sizeof(LinkedList));
  if (numbers == NULL)
    exit(1);

  char c;
  char flag = 'n';

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    } else if (c == ' ') {
      flag = 's';
      continue;
    }

    switch (c) {
    case '0' ... '9':
      if (flag == 's') {
        numbers = add_head(numbers, (double)(c - '0'));
        flag = 'n';
      } else {
        double a = get(numbers, 0).x;
        numbers = del_head(numbers);
        a = a * 10 + c - '0';
        numbers = add_head(numbers, a);
      }
      break;

    case '+':
    case '-':
    case '*':
    case '/':
      if (len(numbers) < 2) {
        printf("Invalid expression\n");
        exit(2);
      }

      double a = get(numbers, 0).x;
      numbers = del_head(numbers);
      double b = get(numbers, 0).x;
      numbers = del_head(numbers);

      b = (c == '+') ? b + a : b;
      b = (c == '-') ? b - a : b;
      b = (c == '*') ? b * a : b;
      b = (c == '/') ? b / a : b;

      numbers = add_head(numbers, b);
      break;
    }
  }

  printf("res: %lF", get(numbers, 0).x);

  free(numbers);
  return 0;
}
