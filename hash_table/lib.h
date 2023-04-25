#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 128
#define A 0.6180339887

typedef struct Bucket {
  char *key;
  char *value;
  int index;
} Bucket;

typedef struct HashTable {
  int size;
  int count;
  Bucket **buckets;
} HashTable;

int hash(char k[]);
Bucket *create_bucket(char key[], char value[], int i);
HashTable *create_table(void);
char *get(HashTable *ht, char key[]);
void delete_element(HashTable *ht, char key[]);
void set(HashTable *ht, char key[], char value[]);
void free_table(HashTable *ht);
void print_table(HashTable *ht);
