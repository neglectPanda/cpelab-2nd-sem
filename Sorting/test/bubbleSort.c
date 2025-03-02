#include <stdio.h>
#include <ctype.h>

#include "sorting.h"

void bubbleSort(int arr[], int size, char order) {
    int passCount = 0, iterCount;

    printHeader();

    for(int i = 0; i < size; i++) {
        iterCount = 0;

        for(int j = 0; j < size - 1; j++) {
            switch(toupper(order)) {
                case 'A':
                    if(arr[j] > arr[j+1]) {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                    break;
                case 'D':
                    if(arr[j] < arr[j+1]) {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                    break;
                default:
                    printf("ERROR: invalid option!\n\n");
            }

            iterCount++;


            if(iterCount == 1) {
                printf("%-5d %-10d ", passCount + 1, iterCount);
            } else {
                printf("%-5s %-10d ", "", iterCount);
            }
            printArray(arr, size);
        }

        passCount++;
    }

    printf("%26s" ,"done!\n"); 

    return;
}