#include "lib.h"

void node_print(Node *n) {
  while (n != NULL) {
    printf("%s\n", n->name);
    n = n->next;
  }
}

Node *add_tail(Node *n, char s[]) {
  if (n == NULL) {
    if ((n = malloc(sizeof(Node))) == NULL) {
      printf("could not malloc\n");
      exit(1);
    }
    n->next = NULL;
    n->prev = NULL;
    memcpy(n->name, s, STR_LEN);
    return n;
  }
  if (!strcmp(n->name, "\0")) {
    memcpy(n->name, s, STR_LEN);
    n->next = NULL;
    n->prev = NULL;
    return n;
  }

  Node *res = n;
  while (n->next != NULL)
    n = n->next;

  Node *tmp = malloc(sizeof(Node));
  memcpy(tmp->name, s, STR_LEN);
  tmp->prev = n;
  n->next = tmp;
  return res;
}

Node get(Node *node, int n) {
  int i;
  for (i = 0; i < n; i++) {
    node = node->next;
  }
  return *node;
}

int len(Node *n) {
  int res = 0;
  while (n != NULL) {
    res++;
    n = n->next;
  }
  return res;
}

Node *xor_find(Node *n1, Node *n2) {
  int i, j, f = 0;
  Node *res = NULL;
  if ((res = malloc(sizeof(Node))) == NULL) {
    printf("could not malloc\n");
    exit(3);
  }

  for (i = 0; i < len(n1); i++) {
    Node tmp1 = get(n1, i);
    for (j = 0; j < len(n2); j++) {
      Node tmp2 = get(n2, j);
      if (strcmp(tmp1.name, tmp2.name) == 0) {
        f = 1;
      }
    }
    if (f == 0) {
      Node tmp = get(n1, i);
      res = add_tail(res, tmp.name);
    }
    f = 0;
  }

  for (i = 0; i < len(n2); i++) {
    Node tmp2 = get(n2, i);
    for (j = 0; j < len(n1); j++) {
      Node tmp1 = get(n1, j);
      if (strcmp(tmp2.name, tmp1.name) == 0) {
        f = 1;
      }
    }
    if (f == 0) {
      Node tmp = get(n2, i);
      res = add_tail(res, tmp.name);
    }
    f = 0;
  }

  return res;
}
