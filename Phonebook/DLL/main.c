#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook.h"

int main() {
    char choice;
    NODE *head = NULL;
    loadFromFile(&head);

    while(1) {
        displayMenu();
        printf("Choice? ");
        scanf(" %c", &choice);
        clearInputBuffer();
        printf("\n");

        switch(choice) {
            case 'A':
            case 'a':
                appendRecord(&head);
                break;
            case 'B':
            case 'b':
                browseRecord(head);
                break;
            case 'C':
            case 'c':
                changeRecord(head);
                break;
            case 'D':
            case 'd':
                deleteRecord(&head);
                break;
            case 'E':
            case 'e':
                saveToFile(head);
                printf("Exiting Program...\n");
                return 0;
            default:
                printf("ERROR: invalid choice!\n\n");
        }
    }

    return 0;
}