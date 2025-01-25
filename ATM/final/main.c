#include <stdio.h>
#include "user.h"
#include "operations.h"
#include "utility.h"

#define USER_NUM 50

int main() {
    int choice, userIndex;
    USER user[USER_NUM];
    char ch;
    float balance;

    initializeUser(user);

    while(1) {
        userIndex = loginUser(user);
        balance = balanceInquiry(user, userIndex);

        int isLoggedIn = 1;

        while(isLoggedIn) {
            while(1) {
                displayMenu();
                printf("Enter choice: ");
                if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
                    break;
                } else {
                    printf("ERROR: choice is of type int!\n\n");
                    clearInputBuffer();
                }
            }

            switch(choice) {
                case 1:
                    printf("\nBalance: %.2f\n\n", balance);
                    break;
                case 2:
                    balance = deposit(user, userIndex);
                    break;
                case 3:
                    balance = withdraw(user, userIndex);
                    break;
                case 4:
                    transactionSummary(user, userIndex);
                    break;
                case 5:
                    printf("Logging out...\n\n");
                    isLoggedIn = 0;
                    break;
                case 6:
                    printf("Exiting...\n\n");
                    return 0;
                default:
                    printf("Invalid option.\n\n");
            }
        }
    }

    return 0;
}