#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

TREENODE *createNode(int value) {
    TREENODE *newNode = (TREENODE *)malloc(sizeof(TREENODE));

    if(newNode == NULL) {
        red();
        printf("ERROR: failed memory allocation!\n\n");
        reset();
        return NULL;
    }

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}