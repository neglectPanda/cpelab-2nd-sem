#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

NODE *createNode(char name[20], int mobile) {
    NODE *newNode = (NODE *) malloc(sizeof(NODE));

    if(newNode == NULL) {
        printf("ERROR: memory allocation failed!\n\n");
        return NULL;
    }

    strcpy(newNode->name, name); // no direct assignments for strings
    newNode->mobile = mobile;
    newNode->next = NULL;

    return newNode;
}