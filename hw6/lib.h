#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5
#define STR_LEN 16


typedef struct Book {
    int len;
    char name[STR_LEN];
} Book;

void  strcopy(char dst[], char src[]);
int   strcomp(char s1[], char s2[]);
void  memcopy(void* dst, void* src, size_t size);
void  st_rand(Book books[], int n);
void  st_print(Book books[], int n);
void  swap(Book* b1, Book* b2);
void  selection_sort(Book books[], int n);
Book* bin_search(Book books[], int n, int key);
void  pst(Book books[], int size, int n);
