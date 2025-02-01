#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "phonebook.h"

void changeRecord(NODE *head) {
    NODE *temp = head;
    int mobile, choice;
    char ch;

    if(head == NULL) {
        printf("List is empty!\n\n");
        return;
    }

    printf("Changing record...\n");

    while(1) {
        printf("Input mobile number: ");
        if((scanf("%d%c", &mobile, &ch)) == 2 && ch == '\n') {
            
            while(temp != NULL) {
                if(temp->mobile == mobile) {
                    printf("SUCCESS: record found!\n");
                    printf("    Name:%s\tMobile No.:%d\n", temp->name, temp->mobile);

                    while(1) {
                        displayChangeMenu();
                        printf("Enter Choice: ");
                        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
                            switch(choice) {
                                case 1:
                                    printf("\nEnter new name: ");
                                    fgets(temp->name, sizeof(temp->name), stdin);
                                    temp->name[strcspn(temp->name, "\n")] = '\0';
                                    printf("SUCCESS: name was successfully updated!\n\n");
                                    break;
                                case 2:
                                    while(1) {
                                        printf("Enter new mobile number: ");
                                        if((scanf("%d%c", &temp->mobile, &ch)) == 2 && ch == '\n') {
                                            printf("SUCCESS: mobile number was successfully updated!\n\n");    
                                            break;
                                        } else {
                                            printf("ERROR: mobile is of type int!\n\n");
                                            clearInputBuffer();
                                        }
                                    }
                                    break;
                                case 3:
                                    printf("Quitting program...\n");
                                    return;
                                default:
                                    printf("Invalid option!\n\n");
                            }
                        } else {
                            printf("ERROR: invalid option!\n\n");
                            clearInputBuffer();
                        }
                    }

                    return;
                }

                temp = temp->next;

            }

            printf("ERROR: record not found!\n\n");
            return;
        } else {
            printf("ERROR: mobile is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}