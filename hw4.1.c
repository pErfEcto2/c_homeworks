#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define N 30


struct Book {
    int len;
    char name[50];
};

void selectSort(struct Book books[], int n) {
    int i, j;
    struct Book tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((books + j)->len < (books + i)->len) {
                tmp = *(books + i);
                *(books + i) = *(books + j);
                *(books + j) = tmp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    srand(time(0));
    struct Book* books = malloc(sizeof(struct Book) * N);

    if (!books) {
        printf("error\n");
        exit(2);
    }
    
    int i;
    for (; i < N; i++) {
        books[i].len = rand() % 100;
        strcpy(books[i].name, "test");
    }

    selectSort(books, N);

    for (i = 0; i < N; i++) {
        printf("%d ", books[i].len);
    }
    printf("\n");

    free(books);

    return 0;
}
