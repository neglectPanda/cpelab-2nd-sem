#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USER_NUM 100
#define TRANS_NUM 100
#define MAX_ATTEMPTS 3 // Maximum login attempts

typedef struct user {
    float balance;
    int passcode;
    float transactionAmount[TRANS_NUM];
    int transactionCount;
    char transactionType[TRANS_NUM][30];
} USER;

void displayMenu();
void initializeUser(USER user[]);
void clearInputBuffer();
int loginUser(USER users[]);
float balanceInquiry(USER users[], int userIndex);
float deposit(USER user[], int userIndex);
float withdraw(USER user[], int userIndex);
void transactionSummary(USER users[], int userIndex);

int main(void) {
    int choice, userIndex;
    USER users[USER_NUM];
    char ch;
    float balance;

    initializeUser(users);

    while (1) { // Loop to allow re-login after logging out
        userIndex = loginUser(users);
        balance = balanceInquiry(users, userIndex);

        while (1) { // Loop for user actions until log out
            while (1) {
                displayMenu();
                printf("Enter choice: ");
                if ((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
                    break;
                } else {
                    printf("INPUT ERROR: choice is of type int\n\n");
                    clearInputBuffer();
                }
            }

            switch (choice) {
                case 1:
                    printf("\nBalance: %.2f\n\n", balance);
                    break;
                case 2:
                    balance = deposit(users, userIndex);
                    printf("Current balance: %.2f\n\n", balance);
                    break;
                case 3:
                    balance = withdraw(users, userIndex);
                    break;
                case 4:
                    transactionSummary(users, userIndex);
                    break;
                case 5:
                    printf("Exiting...\n");
                    return 0; // Gracefully exit the program
                case 6:
                    printf("Logging out...\n\n");
                    break; // Break to re-login
                default:
                    printf("Invalid option.\n\n");
            }

            if (choice == 6) {
                break; // Exit the user actions loop to re-login
            }
        }
    }

    return 0;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void displayMenu() {
    char menuOptions[6][100] = {
        "Balance Inquiry",
        "Deposit",
        "Withdraw",
        "Transaction Summary",
        "Exit",
        "Log Out"
    };
    int i;
    int menuOptionSize = sizeof(menuOptions) / sizeof(menuOptions[0]);

    for (i = 0; i < menuOptionSize; i++) {
        printf("[%d] - %s\n", i + 1, menuOptions[i]);
    }

    return;
}

void initializeUser(USER user[]) {
    user[0].passcode = 1234;
    user[0].balance = 0.00;
    user[0].transactionCount = 0;

    user[1].passcode = 5678;
    user[1].balance = 0.00;
    user[1].transactionCount = 0;

    user[2].passcode = 1011;
    user[2].balance = 0.00;
    user[2].transactionCount = 0;
}

int loginUser(USER users[]) {
    int inputPasscode, i, attempts = 0;
    char ch;

    while (attempts < MAX_ATTEMPTS) {
        printf("INPUT ACCESS CODE: ");
        if ((scanf("%d%c", &inputPasscode, &ch)) == 2 && ch == '\n') {
            for (i = 0; i < USER_NUM; i++) {
                if (users[i].passcode == inputPasscode) {
                    printf("SUCCESS: access code granted!\n");
                    return i; // Return index for the logged-in user
                }
            }
            printf("ERROR: invalid access code!\n\n");
        } else {
            printf("ERROR: invalid input!\n\n");
            clearInputBuffer();
        }
        attempts++;
        printf("Attempts remaining: %d\n\n", MAX_ATTEMPTS - attempts);
    }

    printf("Maximum login attempts exceeded. Exiting...\n\n");
    exit(0); // Return -1 to indicate failed login
}

float balanceInquiry(USER users[], int userIndex) {
    int transCount = users[userIndex].transactionCount;
    strncpy(users[userIndex].transactionType[transCount], "INQUIRY", 30);
    users[userIndex].transactionAmount[transCount] = 0.00;
    users[userIndex].transactionCount++;

    return users[userIndex].balance;
}

float deposit(USER user[], int userIndex) {
    float amount;
    char ch;

    int transCount = user[userIndex].transactionCount;

    while (1) {
        printf("\nInput amount to deposit: ");
        if ((scanf("%f%c", &amount, &ch)) == 2 && ch == '\n') {
            if (amount > 0) {
                user[userIndex].balance += amount;
                user[userIndex].transactionAmount[transCount] = amount;
                user[userIndex].transactionCount++;

                strncpy(user[userIndex].transactionType[transCount], "DEPOSIT", 30);
                printf("Current balance: %.2f\n\n", user[userIndex].balance);
            } else {
                printf("Invalid amount deposited.\n\n");
            }
            break;
        } else {
            printf("Invalid amount deposited.\n\n");
            clearInputBuffer();
        }
    }

    return user[userIndex].balance;
}

float withdraw(USER user[], int userIndex) {
    float amount;
    int transCount = user[userIndex].transactionCount;
    char ch;

    while (1) {
        printf("Input amount to withdraw: Php ");
        if ((scanf("%f%c", &amount, &ch)) == 2 && ch == '\n') {
            if (amount <= 0) {
                printf("ERROR: invalid amount!\n\n");
                break;
            }

            if (amount > user[userIndex].balance) {
                printf("ERROR: remaining balance is Php %.2f\n\n", user[userIndex].balance);
                break;
            }

            user[userIndex].balance -= amount;
            user[userIndex].transactionAmount[transCount] = amount;
            strncpy(user[userIndex].transactionType[transCount], "WITHDRAW", 30);
            user[userIndex].transactionCount++;

            printf("SUCCESS: current balance is now Php %.2f\n\n", user[userIndex].balance);
            break;
        } else {
            printf("ERROR: invalid input.\n\n");
            clearInputBuffer();
        }
    }

    return user[userIndex].balance;
}

void transactionSummary(USER users[], int userIndex) {
    int i;

    printf("\n============================= TRANSACTION SUMMARY =============================\n");
    printf("%-15s%-30s%-20s\n", "Transaction #", "Transaction Type", "Transaction Amount");
    printf("------------------------------------------------------------------------\n");

    for (i = 0; i < users[userIndex].transactionCount; i++) {
        printf("%-15d%-30s%-20.2f\n", i + 1, users[userIndex].transactionType[i], users[userIndex].transactionAmount[i]);
    }

    return;
}