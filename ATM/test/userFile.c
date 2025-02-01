#include <stdio.h>
#include "user.h"

void initializeUserFile() {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        fp = fopen("users.txt", "w");
        if (fp == NULL) {
            printf("Error creating users file!\n");
            return;
        }
        
        // the default init
        fprintf(fp, "User 1\n");
        fprintf(fp, "    passcode = 1234\n");
        fprintf(fp, "    balance = 0.00\n");
        fprintf(fp, "User 2\n");
        fprintf(fp, "    passcode = 5678\n");
        fprintf(fp, "    balance = 0.00\n");
        fprintf(fp, "User 3\n");
        fprintf(fp, "    passcode = 1011\n");
        fprintf(fp, "    balance = 0.00\n");
        
        fclose(fp);
    } else {
        fclose(fp);
    }
}

void loadUsersFromFile(USER user[]) {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error opening users file!\n");
        return;
    }

    char line[256];
    int userIndex = -1;
    
    while (fgets(line, sizeof(line), fp)) {
        int tempUserNum;
        int tempPasscode;
        float tempBalance;
        
        if (sscanf(line, "User %d", &tempUserNum) == 1) {
            userIndex = tempUserNum - 1;
        } else if (sscanf(line, "    passcode = %d", &tempPasscode) == 1) {
            if (userIndex >= 0) {
                user[userIndex].passcode = tempPasscode;
            }
        } else if (sscanf(line, "    balance = %f", &tempBalance) == 1) {
            if (userIndex >= 0) {
                user[userIndex].balance = tempBalance;
            }
        }
    }
    
    fclose(fp);
}

void updateUserFile(USER user[], int userIndex) {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error opening users file!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    char line[256];
    int currentUser = -1;
    
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "User %d", &currentUser) == 1) {
            fprintf(temp, "%s", line);
            if (currentUser == userIndex + 1) {
                fprintf(temp, "    passcode = %d\n", user[userIndex].passcode);
                fprintf(temp, "    balance = %.2f\n", user[userIndex].balance);
                
                // two line skip of file
                fgets(line, sizeof(line), fp);
                fgets(line, sizeof(line), fp);
            } else {
                // the next 2 lines should be copied
                if (fgets(line, sizeof(line), fp)) fprintf(temp, "%s", line);
                if (fgets(line, sizeof(line), fp)) fprintf(temp, "%s", line);
            }
        }
    }

    fclose(fp);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");
}