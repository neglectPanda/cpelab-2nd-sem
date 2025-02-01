#include <stdio.h>
#include "phonebook.h"

void browseRecord(NODE *head) {
    NODE *temp = head;

    if(head == NULL) {
        printf("List is empty!\n\n");
        return;
    }

    printf("=============== RECORDS ===============\n");
    printf("Name:\t\tMobile No.:\n");
    while(temp != NULL) {
        printf("%s\t\t%d\n", temp->name, temp->mobile);
        temp = temp->next;
    }
    
    return;
}