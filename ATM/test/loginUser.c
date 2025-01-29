#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "utility.h"

#define MAX_ATTEMPTS 3
#define USER_NUM 50

int loginUser(USER user[]) {
    int inputPasscode, i, attempts = 0;
    char ch;

    while(1) {
        printf("INPUT ACCESS CODE: ");
        if((scanf("%d%c", &inputPasscode, &ch)) == 2 && ch == '\n') {
            for(i = 0; i < USER_NUM; i++) {
                if(user[i].passcode == inputPasscode) {
                    printf("SUCCESS: access code granted!\n\n");
                    return i;
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
    exit(0);
}