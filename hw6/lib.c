#include "lib.h"


void st_rand(Book books[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        books[i].len = rand() % 99 + 1;
        for (j = 0; j < STR_LEN - 1; j++)
            books[i].name[j] = 'a' + rand() % 25;
        books[i].name[j + 1] = '\0';
    }
}

void st_print(Book books[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("len: %3d; name: %s\n", books[i].len, books[i].name);
}

void swap(Book* b1, Book* b2) {
    Book* tmp = malloc(sizeof(Book));

    if (tmp == NULL) {
        printf("could not malloc\n");
        exit(1);
    }

    memcpy(tmp, b1, sizeof(Book));
    memcpy(b1, b2, sizeof(Book));
    memcpy(b2, tmp, sizeof(Book));
    free(tmp);
}

void selection_sort(Book books[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (books[j].len < books[i].len)
                swap(books + i, books + j);
        }
    }
}

Book* bin_search(Book books[], int n, int key) {
    Book* res = NULL;

    int low = 0, high = n - 1;
    
    while (low < high) {
        int mid = (int)((high + low) / 2);

        if (books[mid].len == key) {
            res = &books[mid];
            break;
        }
        low = (books[mid].len < key) ? mid + 1: low;
        high = (books[mid].len > key) ? mid - 1: high;
    }
    return res;
}

void pst(Book books[], int size, int n) {
    if (n >= size) {
        printf("index bigger then length of the array\n");
        exit(2);
    }
    
    printf("len: %2d; name: %s\n", books[n].len, books[n].name);
}

int find_pairs(Book b1[], int n1, Book b2[], int n2) {
    int res, i;
    for (i = 0; i < n1; i++) {
        Book* b_res = bin_search(b2, n2, b1[i].len);
        if (b_res == NULL) continue;
        res++;
    }
    return res;
}

void st_fprintf(Book books[], int n, char path[], char access[]) {
    int i;
    FILE* f = NULL;
    if ((f = fopen(path, access)) == NULL) {
        printf("Could not open file %s\n", path);
        exit(3);
    }

    for (i = 0; i < n; i++) {
        fprintf(f, "%d %s\n", books[i].len, books[i].name);
    }

    fclose(f);
}

int lines_num(char path[]) {
    int res = 0;
    char c;
    FILE* f = NULL; 
    if ((f = fopen(path, "r")) == NULL) {
        printf("Could not open file %s\n", path);
        exit(3);
    }

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') res++;
    }

    fclose(f);
    return res;
}

void st_fscanf(Book b[], int n, char path[]) {
    int i;
    FILE* f = NULL; 
    if ((f = fopen(path, "r")) == NULL) {
        printf("Could not open file %s\n", path);
        exit(3);
    }

    for (i = 0; i < n; i++) {
        fscanf(f, "%d %s\n", &b[i].len, b[i].name);
    }
    fclose(f);
}
