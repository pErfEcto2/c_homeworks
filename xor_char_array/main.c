#include "lib.h"


int main(int argc, char* argv[]) {
    srand(time(0));
    Node* n1 = NULL;
    Node* n2 = NULL;
    Node* n3 = NULL;
    if ((n1 = malloc(sizeof(Node))) == NULL ||
        (n2 = malloc(sizeof(Node))) == NULL ||
        (n3 = malloc(sizeof(Node))) == NULL) {
        printf("could not malloc\n");
        exit(2);
    }

    int i;
    for (i = 0; i < N; i++) {
        char s[STR_LEN];
        int j;
        
        for (j = 0; j < STR_LEN - 1; j++) 
            s[j] = 'a' + rand() % 2;
        s[STR_LEN - 1] = '\0';
        
        n1 = add_tail(n1, s);

        for (j = 0; j < STR_LEN - 1; j++) 
            s[j]= 'a' + rand() % 2;
        s[STR_LEN - 1] = '\0';
        n2 = add_tail(n2, s);
    }

    printf("Source arrays:\n");
    node_print(n1);
    printf("\n");
    node_print(n2);

    n3 = xor_find(n1, n2);

    printf("\nFinal array:\n");
    node_print(n3);

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
