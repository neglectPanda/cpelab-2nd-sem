#include <stdio.h>

void displayMenu() {
    char menuOptions[6][30] = {
        "Balance Inquiry",
        "Deposit",
        "Withdraw",
        "Transaction Summary",
        "Log out",
        "Exit"
    };
    int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]);
    int i;

    for(i = 0; i < menuSize; i++) {
        printf("[%d] - %s\n", i+1, menuOptions[i]);
    }

    return;
}