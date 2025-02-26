#ifndef SORTING_H
#define SORTING_H

typedef struct input {
    int *arr;
    char order;
    int size;
} Input;

Input inputModule();
void bubbleSort(int arr[], int size, char order);
void selectionSort(int arr[], int size, char order);
void insertionSort(int arr[], int size, char order);

// print modules
void printHeader();
void printArray(int arr[], int size);
void printArrayInLine(int arr[], int size); //change

#endif