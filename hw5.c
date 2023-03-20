#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define STR_LEN 16

struct Book {
    int len;
    char name[STR_LEN];
};


void init(struct Book* books, int n) {
    srand(time(0));
    
    int i;
    for (i = 0; i < n; i++) {
        (books + i)->len = rand() % 100;
        int j;
        for (j = 0; j < STR_LEN - 1; j++)
            (books + i)->name[j] = 'a' + rand() % 26;
        (books + i)->name[STR_LEN - 1] = '\0';
    }
}

void print_books(struct Book* books, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("len: %d; name: ", (books + i)->len);
        int j;
        for (j = 0; (books + i)->name[j] != '\0'; j++)
            printf("%c", (books + i)->name[j]);
        printf("\n");
    }
}


int main(int argc, char* argv[]) {
    struct Book* books = malloc(sizeof(struct Book) * N);

    init(books, N);

    print_books(books, N);

    free(books);
    return 0;
}
