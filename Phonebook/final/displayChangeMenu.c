#include <stdio.h>

void displayChangeMenu() {
    char menuOptions[3][20] = {
        "Name",
        "Mobile No.",
        "Quit program"
    };
    int menuSize = sizeof(menuOptions)/sizeof(menuOptions[0]);
    int i;

    printf("\n");
    printf("What would you like to change?\n");
    for(i = 0; i < menuSize; i++) {
        printf("[%d] - %s\n", i+1, menuOptions[i]);
    }

    return;
}