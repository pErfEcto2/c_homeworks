#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 3
#define STR_LEN 3

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    char name[STR_LEN];
} Node;

void node_print(Node* n);
Node* add_tail(Node* n, char s[]);
Node get(Node* node, int n);
Node* xor_find(Node* n1, Node* n2);
int len(Node* n);
