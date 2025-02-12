#include <stdio.h>
#include <stdlib.h>

#include "stapler.h"

#define MAX_MAG 3
#define MAX_STAPLES 5

int main() {
    STAPLER stapler;
    int choice;
    char ch;

    stapler.top = -1;

    while(1) {
        displayMenu();
        printf("Choice? ");
        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {

            switch(choice) {
                case 1:
                    loadModule(&stapler);
                    break;
                case 2:
                    unloadModule(&stapler);
                    break;
                case 3:
                    useStapler(&stapler);
                    break;
                case 4:
                    displayStaplerStatus(&stapler);
                    break;
                case 5:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("ERROR: choice invalid!\n\n");
            }

        } else {
            printf("ERROR: choice is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return 0;
}