#include <stdio.h>
#include <stdlib.h>


#define N 5
#define WIDTH 4
#define HEIGHT 5

int main() {
    srand(time(0));

    int a[N];
    int b[HEIGHT][WIDTH];

    int i, j;
    for (i = 0; i < N; i++) a[i] = rand() % 100;

    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < WIDTH; j++)
            b[i][j] = rand() % 100;
    

    int max = a[0], min = a[0];
    for (i = 0; i < sizeof(a) / sizeof(int); i++) {
        if (a[i] > max) max = a[i];
        else if (a[i] < min) min = a[i];
    }
    printf("a: min=%d; max=%d\n", min, max);


    max = b[0][0], min = b[0][0];
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (b[i][j] > max) max = b[i][j];
            else if (b[i][j] < min) min = b[i][j];
        }
    }
    printf("b: min=%d; max=%d\n", min, max);

    return 0;
}
