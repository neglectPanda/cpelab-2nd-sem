#include <stdio.h>
#include <string.h>

#include "user.h"
#include "utility.h"

float withdraw(USER user[], int userIndex) {
    char ch;
    float amount;

    int transCount = user[userIndex].transactionCount;
    char transactionMsg[10] = "WITHDRAW";
    int transactionMsgLen = strlen(transactionMsg);

    while(1) {
        printf("Input amount to withdraw: Php ");
        if((scanf("%f%c", &amount, &ch)) ==  2 && ch == '\n') {

            if(amount <= 0) {
                printf("ERROR: cannot withdraw amount!\n\n");
                break;
            }

            if(amount > user[userIndex].balance) {
                printf("ERROR: remaining balance is %.2f\n\n", user[userIndex].balance);
                break;
            }

            user[userIndex].balance -= amount;
            user[userIndex].transactionAmount[transCount] = amount;
            strncpy(user[userIndex].transactionType[transCount], transactionMsg, transactionMsgLen);
            user[userIndex].transactionType[transCount][transactionMsgLen] = '\0';
            user[userIndex].transactionCount++;

            printf("SUCCESS: current balance is now Php %.2f\n\n", user[userIndex].balance);

            break;
        } else {
            printf("ERROR: invalid input!\n\n");
            clearInputBuffer();
        }
    }

    return user[userIndex].balance;
}