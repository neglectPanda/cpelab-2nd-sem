#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "phonebook.h"

void changeRecord(NODE *head)
{
    NODE *temp = head, *check = head;
    int choice, mobileExists = 0;
    char ch, mobile[20];
    char newName[20], newMobile[20];

    if (head == NULL)
    {
        printf("List is empty!\n\n");
        return;
    }

    printf("Changing record...\n");

    printf("Input mobile: ");
    fgets(mobile, sizeof(mobile), stdin);
    mobile[strcspn(mobile, "\n")] = '\0';

    while (temp != NULL)
    {
        if (strcmp(mobile, temp->mobile) == 0)
        {
            printf("SUCCESS: record found!\n");
            printf(" Name: %s\tMobile:%s\n", temp->name, temp->mobile);

            while (1)
            {
                displayChangeMenu();
                printf("Enter choice: ");
                if ((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n')
                {

                    switch (choice)
                    {
                    case 1:
                        printf("Enter new name: ");
                        fgets(newName, sizeof(newName), stdin);
                        newName[strcspn(newName, "\n")] = '\0';
                        strcpy(temp->name, newName);
                        printf("SUCCESS: name has been successfully updated!\n\n");
                        break;
                    case 2:
                        printf("Enter new mobile: ");
                        fgets(newMobile, sizeof(newMobile), stdin);
                        newMobile[strcspn(newMobile, "\n")] = '\0';

                        while(check != NULL) {
                            if(strcmp(newMobile, check->mobile) == 0) {
                                mobileExists = 1;
                                break;
                            }

                            check = check->next;
                        }

                        if(mobileExists) {
                            printf("ERROR: number already exists!\n\n");
                        } else {
                            strcpy(temp->mobile, newMobile);
                            printf("SUCCESS: mobile number has been successfully updated!\n\n");
                        }

                        break;
                    case 3:
                        printf("Quitting program...\n");
                        return;
                    default:
                        printf("Invalid option!\n\n");
                    }
                }
                else
                {
                    printf("ERROR: choice is of type int!\n\n");
                    clearInputBuffer();
                }
                return;
            }
        }

        temp = temp->next;
    }
    
    printf("ERROR: mobile number not found!\n\n");

    return;
}