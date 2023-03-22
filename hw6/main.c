#include "lib.h"


int main(int argc, char* argv[]) {
    Book* books = malloc(sizeof(Book) * N);

    if (books == NULL) {
        printf("could not malloc\n");
        exit(1);
    }

    st_rand(books, N);
    st_print(books, N);

    selection_sort(books, N);
    printf("\n");
    st_print(books, N);

    printf("\n");
    Book* res = bin_search(books, N, 15);
    if (res->len == 0)
        printf("No such book\n");
    else
        printf("length: %2d; name: %s\n", res->len, res->name);

    printf("\n");
    pst(books, N, (int)(N * 0.6));

    free(books);
    return 0;
}
