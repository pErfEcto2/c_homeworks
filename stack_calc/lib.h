#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5

typedef struct LinkedList {
  double x;
  struct LinkedList *next;
} LinkedList;

void linked_print(LinkedList *l);
LinkedList *add_head(LinkedList *l, double x);
LinkedList *del_head(LinkedList *l);
int len(LinkedList *l);
LinkedList get(LinkedList *l, int n);
