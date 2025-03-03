#include <stdio.h>
#include "tree.h"

int main() {
    int choice;
    char ch;
    TREENODE *root = NULL;

    while(1) {
        displayMainMenu();
        printf("Choice: ");
        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
            
            switch(choice) {
                case 1:
                    addNodeModule(&root);
                    break;
                case 2:
                    deleteNodeModule(&root);
                    break;
                case 3:
                    searchNodeModule(&root);
                    break;
                case 4:
                    editNodeModule(&root);
                    break;
                case 5:
                    traverseTreeModule(&root);
                    break;
                case 6:
                    printf("Exiting...\n\n");
                    return 0;
                default:
                    red();
                    printf("ERROR: invalid choice!\n\n");
                    reset();
            }

        } else {
            red();
            printf("ERROR: choice is of type int!\n\n");
            reset();
            clearInputBuffer();
        }
    }

    return 0;
}