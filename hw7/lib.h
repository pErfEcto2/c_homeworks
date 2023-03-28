#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5

typedef struct LinkedList {
    int x;
    struct LinkedList* next;
    struct LinkedList* prev;
} LinkedList;

void linked_print(LinkedList* l);
void add_tail(LinkedList* l, int value);
LinkedList* add_head(LinkedList* l, int value);
LinkedList* del_head(LinkedList* l);
void del_tail(LinkedList* l);
int len(LinkedList* l);
void swap(LinkedList* l1, int i, int j);
int get(LinkedList* l, int n);
void select_sort(LinkedList* l);
void list_fprintf(LinkedList* l, char path[]);
LinkedList* list_fscanf(char path[]);
