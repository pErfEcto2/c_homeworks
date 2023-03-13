#include <stdio.h>

int main() {
    char c;

    printf("input: ");
    c = getchar();

    if (c != '\n') {
        int i;
        long long int res = 1;

        for (i = 1; i < c; i++) 
            if (i % 3 == 0)
                res *= i;
        
        printf("(int)c = %d; res = %lld\n", c, res);
    }

    return 0;
}