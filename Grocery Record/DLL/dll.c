#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct record {
    char product[50];
    float price;
    int quantity;
    float totalPrice;
    struct record *next, *prev;
} RECORD;

void clearInputBuffer();
void displayMenu();
int findProduct(RECORD *head, char product[]);

void appendModule(RECORD **head);
int appendRecord(RECORD **head, char product[], float price, int quantity);
void browseRecord(RECORD *head);
void changeModule(RECORD *head);
int changeRecord(RECORD *head, char product[], float newPrice, int newQuantity);
void deleteModule(RECORD **head);
int deleteRecord(RECORD **head, char product[]);

int main() {
    RECORD *head = NULL;
    char choice;

    while(1) {
        displayMenu();
        printf("Enter choice: ");
        scanf("%c", &choice);
        clearInputBuffer();

        switch(choice) {
            case 'a':
            case 'A':
                appendModule(&head);
                break;
            case 'b':
            case 'B':
                browseRecord(head);
                break;
            case 'c':
            case 'C':
                changeModule(head);
                break;
            case 'd':
            case 'D':
                deleteModule(&head);
                break;
            case 'e':
            case 'E':
                printf("Exiting...\n");

                while(head != NULL) {
                    RECORD *temp = head;
                    head = head->next;
                    free(temp);
                }

                return 0;
            default:
                printf("Invalid option!\n\n");
        }
    }

    return 0;
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

void displayMenu() {
    printf("========== Grocery Record ==========\n");
    printf("[A] Append Record\n");
    printf("[B] Browse Record\n");
    printf("[C] Change Record\n");
    printf("[D] Delete Record\n");
    printf("[E] Exit\n");

    return;
}

int findProduct(RECORD *head, char product[]) {
    while(head) {
        if(strcmp(head->product, product) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

void appendModule(RECORD **head) {
    char product[50], ch;
    float price;
    int quantity;

    printf("Enter product: ");
    fgets(product, sizeof(product), stdin);
    product[strcspn(product, "\n")] = '\0';

    while(1) {
        printf("Enter price: ");
        if((scanf("%f%c", &price, &ch)) == 2 && ch == '\n') {
            break;
        } else {
            printf("ERROR: price is of type float!\n\n");
            clearInputBuffer();
        }
    }

    while(1) {
        printf("Enter quantity: ");
        if((scanf("%d%c", &quantity, &ch)) == 2 && ch == '\n') {

            if(quantity <= 0) {
                printf("ERROR: quantity must be greater than 0!\n\n");
            }

            break;

        } else {
            printf("ERROR: quantity is of type int!\n\n");
            clearInputBuffer();
        }
    }

    if(appendRecord(head, product, price, quantity)) {
        printf("SUCCESS: record added!\n\n");
    } else {
        printf("ERROR: record not added!\n\n");
    }

    return;
}

int appendRecord(RECORD **head, char product[], float price, int quantity) {
    RECORD *newRecord = (RECORD *)malloc(sizeof(RECORD));

    if(!newRecord) {
        return 0;
    }

    strcpy(newRecord->product, product);
    newRecord->price = price;
    newRecord->quantity = quantity;
    newRecord->totalPrice = price * quantity;
    newRecord->next = NULL;
    newRecord->prev = NULL;

    if(*head == NULL) {
        *head = newRecord;
    } else {
        RECORD *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRecord;
        newRecord->prev = temp;
    }

    return 1;
}

void changeModule(RECORD *head) {
    char product[50], ch;
    float newPrice;
    int newQuantity;

    printf("Enter product to update: ");
    fgets(product, sizeof(product), stdin);
    product[strcspn(product, "\n")] = '\0';

    //check if product exists
    if(!findProduct(head, product)) {
        printf("ERROR: product not found!\n\n");
        return;
    }

    printf("SUCCESS: product found!\n\n");

    while(1) {
        printf("Enter new price: ");
        if((scanf("%f%c", &newPrice, &ch)) == 2 && ch == '\n') {
            break;
        } else {
            printf("ERROR: new price is of type float!\n\n");
            clearInputBuffer();
        }
    }

    while(1) {
        printf("Enter new quantity: ");
        if((scanf("%d%c", &newQuantity, &ch)) == 2 && ch == '\n') {

            if(newQuantity <= 0) {
                printf("ERROR: new quantity must be greater than 0!\n\n");
            }

            break;

        } else {
            printf("ERROR: new quantity is of type int!\n\n");
            clearInputBuffer();
        }
    }

    if(changeRecord(head, product, newPrice, newQuantity)) {
        printf("SUCCESS: record updated!\n\n");
    } else {
        printf("ERROR: product not found!\n\n");
    }

    return;
}

void deleteModule(RECORD **head) {
    char product[50];

    printf("Enter product: ");
    fgets(product, sizeof(product), stdin);
    product[strcspn(product, "\n")] = '\0';

    if(deleteRecord(head, product)) {
        printf("SUCCESS: record deleted!\n\n");
    } else {
        printf("ERROR: product not found!\n\n");
    }
}

void browseRecord(RECORD *head) {
    float total = 0.0;

    if(!head) {
        printf("Record is empty!\n\n");
        return;
    }

    printf("===========================================================\n");
    printf("%-15s %-15s %-15s %-15s\n", "Product", "Price", "Quantity", "Total Price");
    printf("-----------------------------------------------------------\n");

    while(head) {
        printf("%-15s %-15.2f %-15d %-15.2f\n", head->product, head->price, head->quantity, head->totalPrice);
        total += head->totalPrice;
        head = head->next;
    }

    printf("-----------------------------------------------------------\n");
    printf("Total: %.2f\n", total);
    printf("===========================================================\n");

    printf("\n\n");

    return;
}

int changeRecord(RECORD *head, char product[], float newPrice, int newQuantity) {
    while(head) {
        if(strcmp(head->product, product) == 0) {
            head->price = newPrice;
            head->quantity = newQuantity;
            head->totalPrice = newPrice * newQuantity;
            return 1; // success
        }
        head = head->next;
    }

    return 0;
}

int deleteRecord(RECORD **head, char product[]) {
    RECORD *temp = *head, *prev = NULL;

    while(temp) {
        if(strcmp(temp->product, product) == 0) {
            if(prev) {
                prev->next = temp->next;
            } else {
                *head = temp->next;
            }

            free(temp);
            return 1; //success
        }
        prev = temp;
        temp = temp->next;
    }

    return 0;
}