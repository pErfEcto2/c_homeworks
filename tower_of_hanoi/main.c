#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 Это код Андрея, его благодарите
 */

int main(int argc, char *argv[]) {

  node *head = NULL, *head2 = NULL, *head3 = NULL;
  int r;

  srand(time(NULL));

  printf("Generated linked list (method of head)\n");
  while ((r = (rand() % 100)) < 75)
    head = add_head(head, r);
  pr(head);

  printf("Length of linked list is: %d\n", length(head));

  printf("Sorted linked list\n");
  sort(head);
  pr(head);

  hanoi_tower(length(head), &head, &head3, &head2, &head, &head2, &head3);
  return 0;
}
