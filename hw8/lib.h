#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 3
#define STR_LEN 8

typedef struct LinkedList {
    int x;
    struct LinkedList* next;
    struct LinkedList* prev;
    char name[STR_LEN];
} LinkedList;

void linked_print(LinkedList* l);
LinkedList* add_tail(LinkedList* l, LinkedList node);
LinkedList* add_head(LinkedList* l, LinkedList node);
LinkedList* del_head(LinkedList* l);
void del_tail(LinkedList* l);
int len(LinkedList* l);
LinkedList get(LinkedList* l, int n);
void tower_of_hanoi(int n, LinkedList* start, LinkedList* finish, LinkedList* tmp);
void linked_free(LinkedList* l);
