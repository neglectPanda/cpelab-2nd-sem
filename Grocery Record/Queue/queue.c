#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for a record
typedef struct record {
    char product[50];
    float price;
    int quantity;
    float totalPrice;
    struct record *next;
} RECORD;

// Structure for a queue
typedef struct queue {
    RECORD *front, *back;
} QUEUE;

// Function prototypes
void clearInputBuffer();
void displayMenuOptions();

int enqueue(QUEUE *q, RECORD item);
void enqueueModule(QUEUE *q);
RECORD dequeue(QUEUE *q);
void dequeueModule(QUEUE *q);
void show(QUEUE *q);

int main() {
    int choice;
    char ch;
    QUEUE q = {NULL, NULL}; // Initialize an empty queue

    while (1) {
        displayMenuOptions();
        printf("Enter choice: ");
        if ((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {

            switch (choice) {
                case 1:
                    enqueueModule(&q);
                    break;
                case 2:
                    dequeueModule(&q);
                    break;
                case 3:
                    show(&q);
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

void clearInputBuffer() {
    while (getchar() != '\n');
}

void displayMenuOptions() {
    printf("============ Grocery Record ============\n");
    printf("[1] - Enqueue\n");
    printf("[2] - Dequeue\n");
    printf("[3] - Show\n");
    printf("[4] - Exit\n");
}

void enqueueModule(QUEUE *q) {
    RECORD item;
    char ch;

    printf("Enter product: ");
    fgets(item.product, sizeof(item.product), stdin);
    item.product[strcspn(item.product, "\n")] = '\0';

    while (1) {
        printf("Enter price: ");
        if ((scanf("%f%c", &item.price, &ch)) == 2 && ch == '\n') {
            break;
        } else {
            printf("ERROR: price is of type float!\n\n");
            clearInputBuffer();
        }
    }

    while (1) {
        printf("Enter quantity: ");
        if ((scanf("%d%c", &item.quantity, &ch)) == 2 && ch == '\n') {
            if (item.quantity <= 0) {
                printf("ERROR: Quantity should be greater than 0!\n\n");
                continue;
            }
            break;
        } else {
            printf("ERROR: Quantity is of type int!\n\n");
            clearInputBuffer();
        }
    }

    item.totalPrice = item.price * item.quantity;

    if (enqueue(q, item)) {
        printf("SUCCESS: Record added!\n\n");
    } else {
        printf("ERROR: Memory allocation failed!\n\n");
    }
}

void dequeueModule(QUEUE *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n\n");
        return;
    }

    RECORD item = dequeue(q);
    printf("SUCCESS: %s removed!\n\n", item.product);
}

int enqueue(QUEUE *q, RECORD item) {
    RECORD *newRecord = (RECORD *)malloc(sizeof(RECORD));
    if (newRecord == NULL) {
        return 0; // Memory allocation failed
    }

    *newRecord = item;
    newRecord->next = NULL;

    if (q->back == NULL) {
        q->front = newRecord;
        q->back = newRecord;
    } else {
        q->back->next = newRecord;
        q->back = newRecord;
    }

    return 1; // Success
}

RECORD dequeue(QUEUE *q) {
    RECORD item = {"", 0, 0, 0, NULL}; // Default empty record

    if (q->front == NULL) {
        return item;
    }

    RECORD *temp = q->front;
    item = *temp;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->back = NULL;
    }

    free(temp);
    return item;
}

void show(QUEUE *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n\n");
        return;
    }

    float total = 0.0;
    RECORD *current = q->front;

    printf("\n======================================================================\n");
    printf("%-15s %-15s %-15s %-15s\n", "Product", "Price", "Quantity", "Total Price");
    printf("----------------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%-15s %-15.2f %-15d %-15.2f\n", current->product, current->price, current->quantity, current->totalPrice);
        total += current->totalPrice;
        current = current->next;
    }

    printf("----------------------------------------------------------------------\n");
    printf("Total: %.2f\n", total);
    printf("======================================================================\n\n");
}
