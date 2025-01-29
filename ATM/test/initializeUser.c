#include "user.h"
#include "utility.h"

void initializeUser(USER user[]) {
    user[0].balance = 0.00;
    user[0].passcode = 1234;
    user[0].transactionCount = 0;

    user[1].balance = 0.00;
    user[1].passcode = 5678;
    user[1].transactionCount = 0;

    user[2].balance = 0.00;
    user[2].passcode = 1011;
    user[2].transactionCount = 0;

    for(int i = 0; i < 3; i++) {
        loadTransactions(user, i);
    }

    return;
}