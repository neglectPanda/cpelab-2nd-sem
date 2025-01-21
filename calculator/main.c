#include <stdio.h>
#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"

void displayMenu(char options[][30], int size);
void clearInputBuffer(int input);

int main(void) {
    // var declarations
    char menuOptions[5][30] = {
        "Add",
        "Subtract",
        "Multiply",
        "Divide",
        "Exit"
    };
    int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]);
    int sum, difference, product;
    int num1, num2;
    int choice;
    char ch;
    float quotient;
    
    while(1) {
        while(1) {
            displayMenu(menuOptions, menuSize);
            printf("Enter choice: ");
            if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
                break;
            } else {
                printf("INPUT ERROR: Must be a valid integer.\n\n");
                clearInputBuffer(choice);
            }
        }

    // GET INPUTS
        if(choice == 5) {
            printf("Exiting...\n");
            return 0;
        } else {
            while(1) {
                printf("Enter num1: ");
                if((scanf("%d%c", &num1, &ch)) == 2 && ch == '\n') {
                    break;
                } else {
                    printf("INPUT ERROR: Must be a valid integer.\n\n");
                    clearInputBuffer(num1);
                }
            }

            while(1) {
                printf("Enter num2: ");
                if((scanf("%d%c", &num2, &ch)) == 2 && ch == '\n') {
                    break;
                } else {
                    printf("INPUT ERROR: Must be a valid integer.\n\n");
                    clearInputBuffer(num2);
                }
            }
        }
    
        switch(choice) {
            case 1:
                sum = add(num1, num2);
                printf("Sum : %d\n\n", sum);
                break;
            case 2:
                difference = subtract(num1, num2);
                printf("Difference : %d\n\n", difference);
                break;
            case 3:
                product = multiply(num1, num2);
                printf("Product : %d\n\n", product);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Cannot divide by zero.\n\n");
                } else {
                    quotient = divide(num1, num2);
                    printf("Quotient: %.2f\n\n", quotient);
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Option.\n\n");
            }
    }

    return 0;
}

void displayMenu(char options[][30], int size) {
    for(int i = 0; i < size; i++) {
        printf("[%d] - %s\n", i+1, options[i]);
    }

    return;
}

void clearInputBuffer(int input) {
    while((input = getchar()) != '\n');
    return;
}