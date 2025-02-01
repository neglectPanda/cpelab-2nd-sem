#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"

void deleteRecord(NODE **head) {
    NODE *temp = *head, *prev = NULL;
    char ch;
    int inputMobile;

    if(*head == NULL) {
        printf("List is empty!\n\n");
        return;
    }

    printf("=============== Delete a record ===============\n");

    while(1) {
        printf("Input mobile number: ");
        if((scanf("%d%c", &inputMobile, &ch)) == 2 && ch == '\n') {

            if(temp != NULL && temp->mobile == inputMobile) {
                *head = temp->next;
                free(temp);
                printf("SUCCESS: record deleted!\n\n");
                return;
            }

            while(temp != NULL && temp->mobile != inputMobile) {
                prev = temp;
                temp = temp->next;
            }

            if(temp == NULL) {
                printf("ERROR: record not found!\n\n");
                return;
            }

            //unlink node 
            prev->next = temp->next;
            free(temp);
            printf("SUCCESS: record deleted!\n\n");
            return;

        } else {
            printf("ERROR: mobile is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}