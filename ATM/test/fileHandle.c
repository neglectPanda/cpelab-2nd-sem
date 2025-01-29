#include <stdio.h>
#include <string.h>
#include "user.h"

void initializeFile() {
    FILE *fp = fopen("atm.txt", "r");
    if (fp == NULL) {
        fp = fopen("atm.txt", "w");
        if (fp == NULL) {
            return;
        }
        
        for (int i = 1; i <= 3; i++) {
            fprintf(fp, "User %d\n", i);
            fprintf(fp, "                                             Transaction Summary\n");
            fprintf(fp, "=============================================\n");
            fprintf(fp, "Transaction #       Transaction Type       Transaction Amount\n");
            if (i < 3) {
                fprintf(fp, "\n\n");
            }
        }
        fclose(fp);
    } else {
        fclose(fp);
    }
}

void saveTransactions(USER user[], int userIndex) {
    FILE *fp = fopen("atm.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // temp file para di magbuffer
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    char line[256];
    int currentUser = -1;
    int foundUser = 0;
    
    // kato ni where the contents are copied tas mo update ra sa specific user section
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "User %d", &currentUser) == 1) {
            // user header titles
            fprintf(temp, "%s", line);
            
            fprintf(temp, "                        Transaction Summary\n");
            fprintf(temp, "================================================================\n");
            fprintf(temp, "Transaction #       Transaction Type       Transaction Amount\n");

            if (currentUser == userIndex + 1) {
                // get user transactions
                for (int i = 0; i < user[userIndex].transactionCount; i++) {
                    fprintf(temp, "%-15d%-30s%-20.2f\n",
                            i + 1,
                            user[userIndex].transactionType[i],
                            user[userIndex].transactionAmount[i]);
                }
                foundUser = 1;

                // old trans line skip
                while (fgets(line, sizeof(line), fp)) {
                    if (line[0] == '\n' || strstr(line, "User") != NULL) {
                        fprintf(temp, "\n\n");

                        if (strstr(line, "User") != NULL) {
                            fprintf(temp, "%s", line);
                        }

                        break;
                    }
                }

                continue;
            }
            
            // old header lines skip
            for (int i = 0; i < 3; i++) {
                fgets(line, sizeof(line), fp);
            }

        } else {
            fprintf(temp, "%s", line);
        }
    }

    if (!foundUser) {
        if (ftell(temp) > 0) {  
            fprintf(temp, "\n\n");  
        }

        fprintf(temp, "User %d\n", userIndex + 1);
        fprintf(temp, "                        Transaction Summary\n");
        fprintf(temp, "================================================================\n");
        fprintf(temp, "Transaction #       Transaction Type       Transaction Amount\n");
        
        for (int i = 0; i < user[userIndex].transactionCount; i++) {
            fprintf(temp, "%-15d%-30s%-20.2f\n", i + 1, user[userIndex].transactionType[i], user[userIndex].transactionAmount[i]);
        }
    }

    fclose(fp);
    fclose(temp);

    // temp file move to atm.txt
    remove("atm.txt");
    rename("temp.txt", "atm.txt");
}

void loadTransactions(USER user[], int userIndex) {
    FILE *fp = fopen("atm.txt", "r");
    if (fp == NULL) {
        return;
    }

    char line[256];
    int currentUser = -1;
    int transCount = 0;
    float amount;
    char transType[30];
    
    // correct user section 
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "User %d", &currentUser) == 1) {
            if (currentUser == userIndex + 1) {
                
                fgets(line, sizeof(line), fp); // trans line
                fgets(line, sizeof(line), fp); // the equal border
                fgets(line, sizeof(line), fp); // header

                break;
            }
        }
    }

    // trans read
    user[userIndex].transactionCount = 0;
    user[userIndex].balance = 0;
    
    while (fgets(line, sizeof(line), fp) && line[0] != '\n') {
        if (sscanf(line, "%*d%29s%f", transType, &amount) == 2) {
            
            // trailing spaces (stackoverflow "c trailing space removal")
            char *start = transType;
            while (*start == ' ') start++;
            char *end = start + strlen(start) - 1;
            while (end > start && *end == ' ') end--;
            *(end + 1) = '\0';
            
            strcpy(user[userIndex].transactionType[transCount], start);
            user[userIndex].transactionAmount[transCount] = amount;
            
            // update based on trans type
            if (strcmp(start, "DEPOSIT") == 0) {
                user[userIndex].balance += amount;
            } else if (strcmp(start, "WITHDRAW") == 0) {
                user[userIndex].balance -= amount;
            }
            
            transCount++;
        }
    }
    
    user[userIndex].transactionCount = transCount;
    fclose(fp);
}