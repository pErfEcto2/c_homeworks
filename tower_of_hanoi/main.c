/*
 * Это реализация Андрея, его благодарите
 */

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  node *head = NULL, *head2 = NULL, *head3 = NULL;
  pointer *addresses = NULL;
  int r;

  srand(time(NULL));

  printf("Generated linked list (method of head)\n");
  /*while ((r=(rand()%T)) < T/2){
          if (r==0) r+=1;
          head = add_head(head, r);
  }*/
  for (r = 1; r <= T / 2; r++) {
    head = add_head(head, r);
  }
  pr(head);
  printf("Length of linked list is: %d\n", length(head));
  printf("Sorted linked list\n");
  sort(head);
  pr(head);
  addresses = add_head_address(addresses, &head3);
  addresses = add_head_address(addresses, &head2);
  addresses = add_head_address(addresses, &head);
  hanoi_tower(length(head), &head, &head3, &head2, addresses);
  return 0;
}
