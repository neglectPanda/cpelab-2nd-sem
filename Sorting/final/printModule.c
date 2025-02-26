#include <stdio.h>
#include <windows.h>

#include "sorting.h"

void printHeader() {
    printf("%-5s %-10s %-25s %-25s %-20s\n", "Pass#", "Iter#", "Bubble Sort", "Selection Sort", "Insertion Sort");
    printf("===============================================================================================\n");
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArrayInLine(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}