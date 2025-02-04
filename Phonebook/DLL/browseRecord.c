#include <stdio.h>
#include "phonebook.h"

void browseRecord(NODE *head) {
    NODE *temp = head;

    if(head == NULL) {
        printf("List is empty!\n\n");
        return;
    }

    printf("=============== RECORDS ===============\n");
    printf("%-20s %10s\n", "Name", "Mobile No.");
    while(temp != NULL) {
        printf("%-20s %10s\n", temp->name, temp->mobile);
        temp = temp->next;
    }
    
    return;
}