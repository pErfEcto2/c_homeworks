#include "lib.h"

void linked_print(LinkedList *l) {
  while (l != NULL) {
    printf("%lF\n", l->x);
    l = l->next;
  }
}

LinkedList *add_head(LinkedList *l, double x) {
  if (l == NULL) {
    l = malloc(sizeof(LinkedList));
    if (l == NULL)
      exit(1);
    l->x = x;
    l->next = NULL;
  }

  if (l->x == 0.0) {
    l->x = x;
    l->next = NULL;
    return l;
  }

  LinkedList *tmp = malloc(sizeof(LinkedList));
  if (tmp == NULL)
    exit(1);

  tmp->next = l;
  tmp->x = x;
  return tmp;
}

LinkedList *del_head(LinkedList *l) {
  if (l == NULL)
    return NULL;
  else if (l->next == NULL) {
    free(l);
    l = NULL;
    return NULL;
  }
  LinkedList *tmp = l->next;
  free(l);
  l = NULL;
  return tmp;
}

int len(LinkedList *l) {
  int res = 0;
  while (l != NULL) {
    res++;
    l = l->next;
  }
  return res;
}

LinkedList get(LinkedList *l, int n) {
  if (n > len(l))
    exit(3);
  int i;
  for (i = 0; i < n; i++) {
    l = l->next;
  }
  return *l;
}
