#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct record {
    char product[50];
    float price;
    int quantity;
    float totalPrice;
    struct record *next;
} RECORD;

void displayMenu();
void clearInputBuffer();

int push(RECORD **top, RECORD newRecord);
RECORD pop(RECORD **top);
void pushModule(RECORD **top);
void popModule(RECORD **top);
void show(RECORD *top);

int main() {
    RECORD *top = NULL;
    int choice;
    char ch;

    while (1) {
        displayMenu();
        printf("Enter choice: ");
        if ((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
            switch (choice) {
                case 1:
                    pushModule(&top);
                    break;
                case 2:
                    popModule(&top);
                    break;
                case 3:
                    show(top);
                    break;
                case 4:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("Invalid option!\n\n");
            }
        } else {
            printf("ERROR: choice is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return 0;
}

void displayMenu() {
    printf("========== Grocery Record ==========\n");
    printf("[1] - Push\n");
    printf("[2] - Pop\n");
    printf("[3] - Show\n");
    printf("[4] - Exit\n");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void pushModule(RECORD **top) {
    RECORD newRecord;
    char ch;

    printf("Enter product: ");
    fgets(newRecord.product, sizeof(newRecord.product), stdin);
    newRecord.product[strcspn(newRecord.product, "\n")] = '\0';

    while (1) {
        printf("Enter price: ");
        if ((scanf("%f%c", &newRecord.price, &ch)) == 2 && ch == '\n') {
            break;
        } else {
            printf("ERROR: price should be of type float!\n\n");
            clearInputBuffer();
        }
    }

    while (1) {
        printf("Enter quantity: ");
        if ((scanf("%d%c", &newRecord.quantity, &ch)) == 2 && ch == '\n') {
            if (newRecord.quantity <= 0) {
                printf("ERROR: quantity should be greater than 0!\n\n");
                continue;
            }
            break;
        } else {
            printf("ERROR: quantity is of type int!\n\n");
            clearInputBuffer();
        }
    }

    newRecord.totalPrice = newRecord.price * newRecord.quantity;
    newRecord.next = NULL;

    if (push(top, newRecord)) {
        printf("SUCCESS: record added!\n\n");
    } else {
        printf("ERROR: malloc failed!\n\n");
    }
}

void popModule(RECORD **top) {
    RECORD poppedRecord = pop(top);

    if (poppedRecord.quantity == 0) {
        printf("Stack is empty!\n\n");
    } else {
        printf("SUCCESS: %s record popped!\n\n", poppedRecord.product);
    }
}

int push(RECORD **top, RECORD newRecord) {
    RECORD *newNode = (RECORD *)malloc(sizeof(RECORD));

    if (!newNode) {
        return 0; // failed malloc
    }

    *newNode = newRecord;
    newNode->next = *top;
    *top = newNode;
    return 1; // successful
}

RECORD pop(RECORD **top) {
    RECORD empty = {"", 0, 0, 0, NULL}; // empty record to return just in case

    if (!*top) {
        return empty;
    }

    RECORD poppedRecord = **top;
    RECORD *temp = *top;
    *top = (*top)->next;
    free(temp);

    return poppedRecord;
}

void show(RECORD *top) {
    float total = 0.0;

    if (!top) {
        printf("Stack is empty!\n\n");
        return;
    }

    printf("==============================================================\n");
    printf("%-15s %-15s %-15s %-15s\n", "Product", "Price", "Quantity", "Total Price");
    printf("--------------------------------------------------------------\n");

    RECORD *current = top;
    while (current) {
        printf("%-15s %-15.2f %-15d %-15.2f\n", current->product, current->price, current->quantity, current->totalPrice);
        total += current->totalPrice;
        current = current->next;
    }

    printf("--------------------------------------------------------------\n");
    printf("Total: %.2f\n", total);
    printf("==============================================================\n\n");
}
