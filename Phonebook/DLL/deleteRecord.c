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

    if (temp != NULL && (strcmp(temp->mobile, inputMobile) == 0))
    {
        *head = temp->next;
        free(temp);
        printf("SUCCESS: record deleted!\n\n");
        return;
    }

    while (temp != NULL && (strcmp(temp->mobile, inputMobile) != 0))
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("ERROR: record not found!\n\n");
        return;
    }

    // unlink node
    prev->next = temp->next;
    free(temp);
    printf("SUCCESS: record deleted!\n\n");
    return;

    return;
}