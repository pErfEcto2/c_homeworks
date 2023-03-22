#include "lib.h"


void strcopy(char dst[], char src[]) {
    char c;
    for (; (c = *src) && (*src != '\0'); src++) {
        *(dst++) = c;
    }
    *dst = '\0';
}

void st_rand(Book* books, int n) {
    srand(time(0));
    int i, j;
    for (i = 0; i < n; i++) {
        books[i].len = rand() % 100;
        for (j = 0; j < STR_LEN - 1; j++)
            books[i].name[j] = 'a' + rand() % 25;
        books[i].name[j + 1] = '\0';
    }
}

void st_print(Book* books, int n) {
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
    Book* res;

    res->len = 0;
    strcopy(res->name, "no such book");
    int low, high = n - 1;
    
    while (low < high) {
        int mid = (int)((high + low) / 2);

        if (books[mid].len == key) {
            memcpy(res, &books[mid], sizeof(Book));
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
