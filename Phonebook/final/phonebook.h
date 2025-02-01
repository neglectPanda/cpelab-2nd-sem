#ifndef PHONEBOOK_H
#define PHONEBOOK_H

typedef struct node {
    char name[20];
    int mobile;
    struct node *next;
} NODE;

void appendRecord(NODE **head);
void browseRecord(NODE *head);
void changeRecord(NODE *head);
void deleteRecord(NODE **head);

void saveToFile(NODE *head);
void loadFromFile(NODE **head);
void displayMenu();
void displayChangeMenu();
void clearInputBuffer();
NODE *createNode(char name[20], int mobile);

#endif