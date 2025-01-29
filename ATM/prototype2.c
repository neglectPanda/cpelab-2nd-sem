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
void fileHandle(USER user[], int userIndex);

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

                    fileHandle(users, i);

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

    if (transCount >= TRANS_NUM) {
        printf("Transaction limit reached. Cannot perform more transactions.\n");
        return user[userIndex].balance;
    }

    while (1) {
        printf("\nInput amount to deposit: ");
        if ((scanf("%f%c", &amount, &ch)) == 2 && ch == '\n') {
            if (amount > 0) {
                user[userIndex].balance += amount;
                user[userIndex].transactionAmount[transCount] = amount;
                user[userIndex].transactionCount++;

                strncpy(user[userIndex].transactionType[transCount], "DEPOSIT", 30);
                printf("Current balance: %.2f\n\n", user[userIndex].balance);

                fileHandle(user, userIndex);
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

    if (transCount >= TRANS_NUM) {
        printf("Transaction limit reached. Cannot perform more transactions.\n");
        return user[userIndex].balance;
    }

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

            fileHandle(user, userIndex);
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

void fileHandle(USER users[], int userIndex) {
    int i;
    FILE *file = fopen("atm.txt", "r+");

    if (!file) {
        file = fopen("atm.txt", "w+");

        if (!file) {
            printf("ERROR: cannot open file!\n\n");
            return;
        }
    }

    // Read the entire file content into memory
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *fileContent = (char *)malloc(fileSize + 1);
    if (!fileContent) {
        printf("ERROR: memory allocation failed!\n\n");
        fclose(file);
        return;
    }

    fread(fileContent, 1, fileSize, file);
    fileContent[fileSize] = '\0'; // Null-terminate the file content

    char userHeader[50];
    snprintf(userHeader, sizeof(userHeader), "User %d", userIndex + 1);

    // Check if the user section already exists in the file
    char *userStart = strstr(fileContent, userHeader);
    char *nextUserStart = NULL;

    if (userStart) {
        // Find the start of the next user section (if any)
        nextUserStart = strstr(userStart + 1, "User ");
    }

    // Build the updated user section
    char userSection[2000] = "";
    snprintf(userSection, sizeof(userSection),
             "%s\n                             Transaction Summary\n"
             "=========================================================================\n"
             "Transaction #         Transaction Type         Transaction Amount\n\n",
             userHeader);

    char transactionLine[200];
    for (i = 0; i < users[userIndex].transactionCount; i++) {
        snprintf(transactionLine, sizeof(transactionLine), "%-25d %-30s Php %.2f\n", i + 1, users[userIndex].transactionType[i], users[userIndex].transactionAmount[i]);
        strcat(userSection, transactionLine);
    }
    strcat(userSection, "\n");

    // Update the file content
    char *newFileContent = (char *)malloc(fileSize + strlen(userSection) + 1);
    if (!newFileContent) {
        printf("ERROR: memory allocation failed!\n\n");
        free(fileContent);
        fclose(file);
        return;
    }

        if (userStart) {
        // Copy the content before the existing user section
        size_t prefixLength = userStart - fileContent;
        strncpy(newFileContent, fileContent, prefixLength);
        newFileContent[prefixLength] = '\0';

        // Append the updated user section
        strcat(newFileContent, userSection);

        // Append the remaining file content after the next user section, if any
        if (nextUserStart) {
            strcat(newFileContent, nextUserStart);
        }
    } else {
        // If no user section found, append the new user section to the file content
        strcpy(newFileContent, fileContent);
        strcat(newFileContent, userSection);
    }

    // Write the updated content back to the file
    freopen("atm.txt", "w", file); // Open file in write mode to overwrite
    fputs(newFileContent, file);

    // Cleanup memory and file pointers
    free(fileContent);
    free(newFileContent);
    fclose(file);

    printf("Transaction history updated successfully!\n");
    return;
}