#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5
#define STR_LEN 8

typedef struct LinkedList {
    int x;
    struct LinkedList* next;
    struct LinkedList* prev;
    char name[STR_LEN];
} LinkedList;

void linked_print(LinkedList* l);
LinkedList* add_tail(LinkedList* l, int x, char name[]);
LinkedList* add_head(LinkedList* l, int x, char name[]);
LinkedList* del_head(LinkedList* l);
void del_tail(LinkedList* l);
int len(LinkedList* l);
LinkedList get(LinkedList* l, int n);

void swap(LinkedList* l1, int i, int j);
void select_sort(LinkedList* l);
void list_fprintf(LinkedList* l, char path[]);
LinkedList* list_fscanf(char path[]);
