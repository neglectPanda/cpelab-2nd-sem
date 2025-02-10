#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

// the functions
int appendRecord(RECORD **head, char product[50], float price, int quantity);
void browseRecord(RECORD *head);
int changeRecord(RECORD *head, char product[], float price, int quantity);
int deleteRecord(RECORD **head, char product[]);

// function modules
void appendModule(RECORD **head);
void changeModule(RECORD *head);
void deleteModule(RECORD **head);

int main() {
    RECORD *head = NULL;
    char choice;

    while(1) {
        displayMenu();
        printf("Choice? ");
        scanf(" %c", &choice);
        clearInputBuffer();

        switch(tolower(choice)) {
            case 'a':
                appendModule(&head);
                break;
            case 'b':
                browseRecord(head);
                break;
            case 'c':
                changeModule(head);
                break;
            case 'd':
                deleteModule(&head);
                break;
            case 'e':
                printf("Exiting...\n\n");
                return 0;
            default:
                printf("Invalid choice!\n\n");
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
}

int findProduct(RECORD *head, char product[]) {
    while(head) {
        if(strcmp(head->product, product) == 0) {
            return 1; //found
        } 
        head = head->next;
    }

    return 0; // not found
}

void appendModule(RECORD **head) {
    char product[50], ch;
    int quantity;
    float price;

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
        printf("SUCCESS: record saved!\n\n");
    } else {
        printf("ERROR: record not saved!\n\n");
    }

    return;
}

int appendRecord(RECORD **head, char product[50], float price, int quantity) {
    RECORD *newRecord = (RECORD *)malloc(sizeof(RECORD));

    if(newRecord == NULL) {
        return 0; //failed
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

        // traverse
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newRecord;
        newRecord->prev = temp;
    }

    return 1; //success
}

void browseRecord(RECORD *head) {
    float total = 0.0;

    if(head == NULL) {
        printf("List is empty!\n\n");
        return;
    }

    printf("==========================================================================\n");
    printf("%-15s %-15s %-15s %-15s\n", "Product", "Price", "Quantity", "Total Price");
    printf("--------------------------------------------------------------------------\n");

    while(head) {
        printf("%-15s %-15.2f %-15d %-15.2f\n", head->product, head->price, head->quantity, head->totalPrice);
        total += head->totalPrice;
        head = head->next;
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Total: %.2f\n", total);
    printf("==========================================================================\n");
    
    return;
}

void changeModule(RECORD *head) {
    char product[50], ch;
    float newPrice;
    int newQuantity;

    while(1) {
        printf("Enter product name: ");
        fgets(product, sizeof(product), stdin);
        product[strcspn(product, "\n")] = '\0';

        if(findProduct(head, product)) {

            while(1) {
                printf("Enter new price: ");
                if((scanf("%f%c", &newPrice, &ch)) == 2 && ch == '\n') {
                    break;
                } else {
                    printf("ERROR: new price is of type int!\n\n");
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
                printf("SUCCESS: record successfully updated!\n\n");
            } else {
                printf("ERROR: record not updated!\n\n");
            }

            break;

        } else {
            printf("ERROR: product not found!\n\n");
            return;
        }
    }

    printf("\n");
    return;
}

int changeRecord(RECORD *head, char product[], float price, int quantity) {
    while(head) {
        if(strcmp(head->product, product) == 0) {
            head->price = price;
            head->quantity = quantity;
            head->totalPrice = price * quantity;
            return 1; //success
        }
        head = head->next;
    }

    return 0; // failed
}

void deleteModule(RECORD **head) {
    char product[50];

    printf("Enter product name: ");
    fgets(product, sizeof(product), stdin);
    product[strcspn(product, "\n")] = '\0';

    if(deleteRecord(head, product)) {
        printf("SUCCESS: record successfully deleted!\n\n");
    } else {
        printf("ERROR: record product not found!\n\n");
    }

    return;
}

int deleteRecord(RECORD **head, char product[]) {
    RECORD *temp = *head, *prev = NULL;

    while(temp) {
        if(strcmp(temp->product, product) == 0) {
            if(prev) {
                prev->next = temp;
            } else {
                *head = temp->next;
            }

            free(temp);
            return 1; // success
        }

        prev = temp;
        temp = temp->next;
    }

    return 0; // error
}