#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "sorting.h"

void insertionSort(int arr[], int size, char order) {
    //  int startRow = 3;

    if(toupper(order) != 'A' && toupper(order) != 'D') {
        printf("ERROR: invalid option!\n\n");
        return;
    }
    
    printf("Insertion\n");
    for(int i = 1; i < size ; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && ((toupper(order) == 'A' && arr[j] > key) || (toupper(order) == 'D' && arr[j] < key))) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;

        printArray(arr, size);
    }

    return;
}