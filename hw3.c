#include <stdio.h>
#include <stdlib.h>


#define N 20

void selectionSort(int* arr, int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void bubbleSort(int* arr, int n) {
    int i, j, tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void insertionSort(int* arr, int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char** argv) {
    srand(time(0));

    int* arr1 = malloc(sizeof(int) * N);
    int* arr2 = malloc(sizeof(int) * N);
    int* arr3 = malloc(sizeof(int) * N);
    int i;

    for (i = 0; i < N; i++) {
        int d = rand() % 100;
        arr1[i] = d;
        arr2[i] = d;
        arr3[i] = d;
    }

    selectionSort(arr1, N);
    insertionSort(arr2, N);
    bubbleSort(arr3, N);

    printf("Selection sort: ");
    for (i = 0; i < N; i++)
        printf("%d ", arr1[i]);
    
    printf("\nInsertion sort: ");
    for (i = 0; i < N; i++)
        printf("%d ", arr2[i]);
    
    printf("\nBubble sort:    ");
    for (i = 0; i < N; i++)
        printf("%d ", arr3[i]);
    
    printf("\n");

    return 0;
}
