#include <stdio.h>
#include "../tree.h"

void deleteNodeModule(TREENODE **root) {
    int value;
    char ch;
    
    printf("\n=== DELETE A NODE ===\n");
    while(1) {
        printf("Input value to delete: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {

            TREENODE *beforeDelete = searchNode(*root, value);
            *root = deleteNode(*root,value);
            TREENODE *afterDelete = searchNode(*root, value);


            if(beforeDelete != NULL && afterDelete == NULL) {
                green();
                printf("SUCCESS: node removed!\n\n");
                reset();
            } else {
                red();
                printf("ERROR: removing ndoe!\n\n");
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

    displayTree(*root);

    return;
}