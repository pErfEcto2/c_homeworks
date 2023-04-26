#include "lib.h"

int main(void) {
  HashTable *h = create_table();

  set(h, "test", "TEST");
  set(h, "1", "12");

  char *res1 = get(h, "test");
  char *res2 = get(h, "1");
  printf("%s %s\n", res1, res2);

  set(h, "1", "21");
  set(h, "test", "perfecto");

  res1 = get(h, "1");
  res2 = get(h, "test");
  printf("%s %s\n", res1, res2);

  printf("\n");
  print_table(h);

  delete_element(h, "1");
  delete_element(h, "2");

  printf("\n");
  print_table(h);

  free_table(h);

  return 0;
}
