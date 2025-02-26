#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#include "sorting.h"

void selectionSort(int arr[], int size, char order) {
    //int startRow = 3;

    if(toupper(order) != 'A' && toupper(order) != 'D') {
        printf("ERROR: invalid option!\n\n");
        return;
    } 

    printf("Selection\n");

    for(int i = 0; i < size - 1; i++) {
        int min = i;
        
        for(int j = i + 1; j < size; j++) {
            if(toupper(order) == 'A' && arr[j] < arr[min] ||
               toupper(order) == 'D' && arr[j] > arr[min]) {

                min = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        printArray(arr, size);
    }

    return;
}