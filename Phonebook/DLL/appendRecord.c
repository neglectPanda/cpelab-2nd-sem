#include <stdio.h>
#include <string.h>

#include "phonebook.h"

void appendRecord(NODE **head) {
    char inputName[20], ch; 
    char inputMobile[20];

    printf("\nAppending to records...\n");
    
    printf("Input name: ");
    fgets(inputName, sizeof(inputName), stdin);
    inputName[strcspn(inputName, "\n")] = '\0';

    printf("Input mobile: ");
    fgets(inputMobile, sizeof(inputMobile), stdin);
    inputMobile[strcspn(inputMobile, "\n")] = '\0';

    NODE *newNode = createNode(inputName, inputMobile);
    if(newNode == NULL) {
        return;
    }

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    NODE *temp = *head;
    // list traversal
    while(temp->next != NULL) {
        temp->next = newNode;
        newNode->prev = temp;
    }

    //append
    temp->next = newNode;
    newNode->prev = temp;
    printf("SUCCESS: record appended!\n\n");

    return;
}