#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    int mobile;
    struct node *next;
} NODE;

void displayMenu();
void displayChangeMenu();
void clearInputBuffer();
void appendRecord(NODE **head);
void browseRecord(NODE *head);
void changeRecord(NODE *head);
void deleteRecord(NODE **head);

NODE *createNode(char name[20], int mobile);

int main() {
    char choice;
    NODE *head = NULL;

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
                printf("Exiting Program...\n");
                return 0;
            default:
                printf("ERROR: invalid choice!\n\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=============== Phonebook ===============\n");
    printf("[A] - Append Record\n");
    printf("[B] - Browse Record\n");
    printf("[C] - Change Record\n");
    printf("[D] - Delete Record\n");
    printf("[E] - Exit\n");
}

void displayChangeMenu() {
    char menuOptions[3][20] = {
        "Name",
        "Mobile No.",
        "Quit program"
    };
    int menuSize = sizeof(menuOptions)/sizeof(menuOptions[0]);
    int i;

    printf("\n");
    printf("What would you like to change?\n");
    for(i = 0; i < menuSize; i++) {
        printf("[%d] - %s\n", i+1, menuOptions[i]);
    }

    return;
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

NODE *createNode(char name[20], int mobile) {
    NODE *newNode = (NODE *) malloc(sizeof(NODE));

    if(newNode == NULL) {
        printf("ERROR: memory allocation failed!\n\n");
        return NULL;
    }

    strcpy(newNode->name, name); // no direct assignments for strings
    newNode->mobile = mobile;
    newNode->next = NULL;

    return newNode;
}

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