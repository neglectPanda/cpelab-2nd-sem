#include <stdio.h>
#include <string.h>
#include "phonebook.h"

void saveToFile(NODE *head) {
    FILE *file = fopen("records.txt", "w");
    if(file == NULL) {
        printf("ERROR: could not open file!\n\n");
        return;
    }

    NODE *current = head;
    while(current != NULL) {
        fprintf(file, "%s,%s\n", current->name, current->mobile);
        current = current->next;
    }

    fclose(file);

    return;
}

void loadFromFile(NODE **head) {
    FILE *file = fopen("records.txt", "r");
    if(file == NULL) {
        printf("ERROR: records.txt does not exist!\n\n");
        return;
    }

    char line[100];
    char name[20];
    char mobile[20];

    while(fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        if(sscanf(line, "%[^,],%[^\n]", name, &mobile) == 2) {
            NODE *newNode = createNode(name, mobile);
            if(newNode != NULL) {

                if(*head == NULL) {
                    *head = newNode;
                } else {
                    NODE *temp = *head;
                    while(temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                    newNode->prev = temp;
                }

            }
        }
    }

    fclose(file);
    return;
}