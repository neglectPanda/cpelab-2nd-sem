#ifndef UTILITY_H
#define UTILITY_H

void clearInputBuffer();
void displayMenu();
void initializeUser(USER user[]);
int loginUser(USER user[]);
void saveTransactions(USER user[], int userIndex);
void loadTransactions(USER user[], int userIndex);
void initializeFile();
void initializeUserFile();
void loadUsersFromFile(USER user[]);
void updateUserFile(USER user[], int userIndex);

#endif