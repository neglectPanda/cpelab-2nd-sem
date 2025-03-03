#include <stdio.h>
#include "../tree.h"

void editNodeModule(TREENODE **root) {
    int value, newValue;
    char ch;
    TREENODE *found;

    printf("\n=== EDIT A NODE ===\n");
    while(1) {
        printf("Input value to edit: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {

            found = searchNode(*root, value);
            if(found != NULL) {
                green();
                printf("SUCCESS: node found!\n\n");

                while(1) {
                    printf("Input new value: ");
                    if((scanf("%d%c", &newValue, &ch)) == 2 && ch == '\n') {
                        *root = editNode(*root, value, newValue);

                        green();
                        printf("SUCCESS: node edited!\n\n");
                        reset();

                        displayTree(*root);

                        break;
                    } else {
                        red();
                        printf("ERROR: newValue is of type int!\n\n");
                        reset();
                        clearInputBuffer();
                    }
                }
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

    return; 
}