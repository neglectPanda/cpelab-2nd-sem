#ifndef USER_H
#define USER_H

#define TRANSACTION_NUM 50

typedef struct user {
    int passcode;
    float balance;
    int transactionCount;
    float transactionAmount[TRANSACTION_NUM];
    char transactionType[TRANSACTION_NUM][20];
} USER;

#endif