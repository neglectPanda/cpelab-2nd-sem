#include <string.h>
#include "user.h"

float balanceInquiry(USER user[], int userIndex) {
    int transCount = user[userIndex].transactionCount;
    char transactionMsg[10] = "INQUIRY";
    int transactionMsgLen = strlen(transactionMsg);

    user[userIndex].transactionAmount[transCount] = 0.00;
    strncpy(user[userIndex].transactionType[transCount], transactionMsg, transactionMsgLen);
    user[userIndex].transactionType[transCount][transactionMsgLen] = '\0';

    user[userIndex].transactionCount++;

    return user[userIndex].balance;
}