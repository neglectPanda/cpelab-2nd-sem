#include <stdio.h>

void displayMenu() {
    int i;
    char menu[5][50] = {
        "Load Stapler",
        "Unload Stapler",
        "Use Stapler",
        "Display Stapler Status",
        "Exit"
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    printf("\n======== Stapler ========\n");
    for(i = 0; i < menuSize; i++) {
        printf("[%d] - %s\n", i+1, menu[i]);
    }

    return;
}