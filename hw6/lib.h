#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 3
#define STR_LEN 16


typedef struct Book {
    int len;
    char name[STR_LEN];
} Book;

void  st_rand(Book books[], int n);
void  st_print(Book books[], int n);
void  swap(Book* b1, Book* b2);
void  selection_sort(Book books[], int n);
Book* bin_search(Book books[], int n, int key);
void  pst(Book books[], int size, int n);
int   find_pairs(Book b1[], int n1, Book b2[], int n2);
void  st_fprintf(Book books[], int n, char path[], char access[]);
int   lines_num(char path[]);
void  st_fscanf(Book b[], int n, char path[]);
