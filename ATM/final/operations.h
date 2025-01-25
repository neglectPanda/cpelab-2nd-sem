#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "user.h"

float balanceInquiry(USER user[], int userIndex);
float deposit(USER user[], int userIndex);
float withdraw(USER user[], int userIndex);
void transactionSummary(USER user[], int userIndex);


#endif