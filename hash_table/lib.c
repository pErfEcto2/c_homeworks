#include "lib.h"

int hash(char k[]) {
  int i;
  unsigned long res = 0;
  for (i = 0; k[i]; i++)
    res += k[i];
  return (int)(N * fmod(res * A, 1));
}

Bucket *create_bucket(char *key, char *value, int i) {
  Bucket *res = NULL;
  if ((res = malloc(sizeof(Bucket))) == NULL)
    exit(1);

  res->key = malloc(strlen(key) + 1);
  res->value = malloc(strlen(value) + 1);
  res->index = i;

  strcpy(res->key, key);
  strcpy(res->value, value);

  return res;
}

HashTable *create_table(void) {
  HashTable *res = NULL;
  if ((res = malloc(sizeof(HashTable))) == NULL)
    exit(1);

  res->count = 0;
  res->size = N;

  res->buckets = NULL;

  if ((res->buckets = malloc(sizeof(Bucket *) * N)) == NULL)
    exit(2);

  int i;
  for (i = 0; i < N; i++)
    res->buckets[i] = NULL;

  return res;
}

void set(HashTable *ht, char key[], char value[]) {
  int index = hash(key);

  if (ht->buckets[index] == NULL) {
    ht->buckets[index] = create_bucket(key, value, index);
    return;
  }
  char *tmp_k = ht->buckets[index]->key;
  if (strcmp(tmp_k, key) == 0) {
    free(ht->buckets[index]->value);
    ht->buckets[index]->value = malloc(strlen(value) + 1);
    strcpy(ht->buckets[index]->value, value);
    return;
  }
  printf("Collision(keys: %s and %s)\n", key, ht->buckets[index]->key);
}

char *get(HashTable *ht, char *key) {
  int index = hash(key);
  return ht->buckets[index]->value;
}

void delete_element(HashTable *ht, char *key) {
  int index = hash(key);
  if (ht->buckets[index] == NULL)
    return;
  free(ht->buckets[index]->value);
  free(ht->buckets[index]->key);
  free(ht->buckets[index]);
}

void free_table(HashTable *ht) {
  int i;
  for (i = 0; i < N; i++) {
    if (ht->buckets[i] != NULL) {
      free(ht->buckets[i]->value);
      free(ht->buckets[i]->key);
      free(ht->buckets[i]);
    }
  }
  free(ht);
}

void print_table(HashTable *ht) {
  int i;
  for (i = 0; i < N; i++) {
    if (ht->buckets[i] != NULL)
      printf("index: %d; key: %s; value: %s\n", ht->buckets[i]->index,
             ht->buckets[i]->key, ht->buckets[i]->value);
  }
  printf("size: %d; count: %d\n", ht->size, ht->count);
}
