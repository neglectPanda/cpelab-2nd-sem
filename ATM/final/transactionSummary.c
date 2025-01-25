#include <stdio.h>
#include "user.h"

void transactionSummary(USER user[], int userIndex) {
    int i;

    printf("                        Transaction Summary\n");
    printf("%-15s%-30s%-20s\n", "Transaction #", "Transaction Type", "Transaction Amount");
    printf("====================================================================\n");

    for(i = 0; i < user[userIndex].transactionCount; i++) {
        printf("%-15d%-30s%-20.2f\n", i+1, user[userIndex].transactionType[i], user[userIndex].transactionAmount[i]);
    }

    printf("\n");

    return;
}