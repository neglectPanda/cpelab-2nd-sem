#include <stdio.h>
#include "../tree.h"

void addNodeModule(TREENODE **root) {
    int value;
    char ch;

    printf("\n=== ADD NODE ===\n");
    while(1) {
        printf("Insert value to add: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {
            
            // stores orig root
            TREENODE *oldRoot = *root;
            TREENODE *oldNode = searchNode(*root, value);
            
            // insert and do checkings
            TREENODE *newRoot = insertNode(*root, value);
            if (newRoot == NULL) {
                // insertNode failed
                red();
                printf("FAILED: memory allocation error when adding node!\n\n");
                reset();
                break;
            }
            
            *root = newRoot;
            TREENODE *newNode = searchNode(*root, value);

            if((oldNode == NULL && newNode != NULL) || (*root != NULL && oldNode == NULL && value == (*root)->value)) {
                green();
                printf("SUCCESS: node added!\n\n");
                reset();
            } else {
                red();
                printf("FAILED: adding node!\n\n");
                reset();
            }

            displayTree(*root);
            break;

        } else {
            red();
            printf("ERROR: value is of type int!\n\n");
            reset();
            clearInputBuffer();
        }
    }

    return;
}