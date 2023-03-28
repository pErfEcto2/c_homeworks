#include "lib.h"


int main(int argc, char* argv[]) {
    srand(time(0));
    LinkedList* l = malloc(sizeof(LinkedList));
    if (l == NULL)
        exit(1);
    
    l->x = 10;
    l->next = NULL;
    l->prev = NULL;
    printf("Before add_tail(%d):\n", len(l));
    linked_print(l);

    int i;
    for (i = 0; i < N; i++)
        add_tail(l, rand() % 100);
    
    printf("\nAfter add_tail(%d):\n", len(l));
    linked_print(l);

    l = add_head(l, 5);
    printf("\nAfter add_head(%d):\n", len(l));
    linked_print(l);

    l = del_head(l);
    printf("\nAfter del_head(%d):\n", len(l));
    linked_print(l);

    swap(l, 0, 1);
    printf("\nAfter swap:\n");
    linked_print(l);

    del_tail(l);
    printf("\nAfter del_tail(%d):\n", len(l));
    linked_print(l);

    printf("\nGet first element: %d\n", get(l, 0));

    select_sort(l);
    printf("\nAfter sort:\n");
    linked_print(l);

    printf("\nWriting to file test.txt\n");
    list_fprintf(l, "test.txt");

    printf("\nRead from file test.txt:\n");
    LinkedList* l2 = list_fscanf("test.txt");
    linked_print(l2);

    free(l);
    return 0;
}
