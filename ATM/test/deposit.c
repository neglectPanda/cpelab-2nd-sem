#include <stdio.h>
#include <string.h>

#include "user.h"
#include "utility.h"

float deposit(USER user[], int userIndex) {
    float amount;
    char ch;

    char transactionMsg[10] = "DEPOSIT";
    int transactionMsgLen = strlen(transactionMsg);
    int transCount = user[userIndex].transactionCount;

    while(1) {
        printf("Input amount to deposit: ");
        if((scanf("%f%c", &amount, &ch)) == 2 && ch == '\n') {
            if(amount > 0) {
                user[userIndex].balance += amount;
                user[userIndex].transactionCount++;
                strncpy(user[userIndex].transactionType[transCount], transactionMsg, transactionMsgLen);
                user[userIndex].transactionType[transCount][transactionMsgLen] = '\0';
                user[userIndex].transactionAmount[transCount] = amount;

                printf("SUCCESS: current balance is now %.2f\n\n", user[userIndex].balance);

            } else {
                printf("ERROR: invalid amount!\n\n");
            }

            break;

        } else {
            printf("ERROR: invalid input!\n\n");
            clearInputBuffer();
        }
    }

    saveTransactions(user, userIndex);
    updateUserFile(user, userIndex);
    return user[userIndex].balance;

}