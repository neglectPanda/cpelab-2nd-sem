#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

void deleteRecord(NODE **head)
{
    NODE *temp = *head, *prev = NULL;
    char ch;
    char inputMobile[20];

    if (*head == NULL)
    {
        printf("List is empty!\n\n");
        return;
    }

    printf("=============== Delete a record ===============\n");

    printf("Input mobile number: ");
    fgets(inputMobile, sizeof(inputMobile), stdin);
    inputMobile[strcspn(inputMobile, "\n")] = '\0';

    if (temp != NULL && (strcmp(temp->mobile, inputMobile) == 0))
    {
        *head = temp->next;
        if(*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("SUCCESS: record deleted!\n\n");
        return;
    }

    //search
    while (temp != NULL && (strcmp(temp->mobile, inputMobile) != 0))
    {
        temp = temp->next;
    }

    //if wala
    if (temp == NULL)
    {
        printf("ERROR: record not found!\n\n");
        return;
    }

    //prev uodate
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    //next update
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("SUCCESS: record deleted!\n\n");
    return;

    return;
}