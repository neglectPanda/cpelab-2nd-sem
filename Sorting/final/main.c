#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#include "sorting.h"

int main() {
    Input input = inputModule();

    if(input.arr == NULL) {
        printf("ERROR: no input!\n\n");
        return 0;
    }

    int *copyArr1 = malloc(input.size * sizeof(int));
    int *copyArr2 = malloc(input.size * sizeof(int));
    int *copyArr3 = malloc(input.size * sizeof(int));

    if (!copyArr1 || !copyArr2 || !copyArr3) {
        printf("ERROR: memory allocation failed!\n");
        free(copyArr1);
        free(copyArr2);
        free(copyArr3);
        free(input.arr);
        return 0;
    }

    memcpy(copyArr1, input.arr, input.size * sizeof(int));
    memcpy(copyArr2, input.arr, input.size * sizeof(int));
    memcpy(copyArr3, input.arr, input.size * sizeof(int));

    
    bubbleSort(copyArr1, input.size, input.order);
    selectionSort(copyArr2, input.size, input.order);
    insertionSort(copyArr3, input.size, input.order);
    
    free(input.arr);
    free(copyArr1);
    free(copyArr2);
    free(copyArr3);
    
    return 0;
}