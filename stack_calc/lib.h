#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Node {
    double x;
    char operation;
    struct Node* next;
} Node;

void node_print(Node* node);
Node* push(Node* node, double x, char oper);
Node* del_head(Node* node);
Node get(Node* node, int n);
Node pop(Node** node);
int len(Node* n);

