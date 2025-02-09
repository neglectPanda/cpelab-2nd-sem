#include <stdio.h>
#include <string.h>

#include "phonebook.h"

void appendRecord(NODE **head) {
    char inputName[20], ch; 
    int inputMobile;

    printf("Input name: ");
    fgets(inputName, sizeof(inputName), stdin);
    inputName[strcspn(inputName, "\n")] = '\0';

    printf("\nAppending to records...\n");

    while(1) {
        printf("Input mobile number: ");
        if((scanf("%d%c", &inputMobile, &ch)) == 2 && ch == '\n') {

            if(inputMobile < 0 || inputMobile > 99999) {
                printf("ERROR: mobile number should only be 5 digits!\n\n");
                continue;
            }

            NODE *newNode = createNode(inputName, inputMobile);

            if(newNode == NULL) {
                return;
            }

            // if there is no list, then the first one will be the head node
            if(*head == NULL) {
                *head = newNode;
                return;
            }
            
            NODE *temp = *head;
            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            printf("SUCCESS: record appended!\n\n");
            break;
        } else {
            printf("ERROR: mobile is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}