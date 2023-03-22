#include "lib.h"


int main(int argc, char* argv[]) {
    srand(time(0));

    Book* books1 = malloc(sizeof(Book) * N);
    Book* books2 = malloc(sizeof(Book) * N);

    if (books1 == NULL || books2 == NULL) {
        printf("could not malloc\n");
        exit(1);
    }

    st_rand(books1, N);
    st_rand(books2, N);

    printf("First array:\n");
    st_print(books1, N);
    printf("\nSecond array:\n");
    st_print(books2, N);

    selection_sort(books1, N);
    selection_sort(books2, N);

    printf("\nFirst array after sort:\n");
    st_print(books1, N);
    printf("\nSecond array after sort:\n");
    st_print(books2, N);

    Book* res = bin_search(books1, N, 15);

    if (res == NULL)
        printf("\nNo such book\n");
    else
        printf("\nLength: %2d; name: %s\n", res->len, res->name);

    printf("\nElement in first array: ");
    pst(books1, N, (int)(N * 0.7));
    printf("Element in second array: ");
    pst(books2, N, (int)(N * 0.3));

    printf("\nNumber of pairs: %d\n", find_pairs(books1, N, books2, N));

    st_fprintf(books1, N, "books.txt", "w");
    st_fprintf(books2, N, "books.txt", "a");

    int line_number = lines_num("books.txt");
    printf("\nNumber of lines in books.txt is %d\n", line_number);

    Book* books3 = malloc(sizeof(Book) * line_number);

    if (books3 == NULL) {
        printf("could not malloc\n");
        exit(1);
    }

    st_fscanf(books3, line_number, "books.txt");

    printf("\nThird array is:\n");
    st_print(books3, line_number);

    free(books1);
    free(books2);
    free(books3);
    return 0;
}
