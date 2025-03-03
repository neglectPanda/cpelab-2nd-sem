#include <stdio.h>
#include "../tree.h"

void searchNodeModule(TREENODE **root) {
    int value;
    char ch;
    
    printf("\n=== SEARCH NODE ===\n");
    
    while(1) {
        printf("Input value to search: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {
            
            TREENODE *found = searchNode(*root, value);

            if(found != NULL) {
                green();
                printf("SUCCESS: node found!\n\n");
                reset();
            } else {
                red();
                printf("ERROR: node not found!\n\n");
                reset();
            }

            break;

        } else {
            red();
            printf("ERROR: value is of type int!\n\n");
            reset();
            clearInputBuffer();
        }
    }
}