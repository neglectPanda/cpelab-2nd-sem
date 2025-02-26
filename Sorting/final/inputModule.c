#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdlib.h>

#include "sorting.h"

Input inputModule() {
    char inpArr[100], order;
    int *nums = NULL, numIndex = 0;
    Input input;

    printf("Enter array of numbers:\n");
    while(1) {
        fgets(inpArr, sizeof(inpArr), stdin);
        inpArr[strcspn(inpArr, "\n")] = '\0';

        // loops through the string and converts the nonspace as integers
        for(int i = 0; inpArr[i] != '\0'; i++) {
            if(isdigit(inpArr[i])) { 
                int num = 0;
                
                // handles multi-digit numbers
                while (isdigit(inpArr[i])) {
                    num = num * 10 + (inpArr[i] - '0'); // conversion 
                    i++;
                }
                i--; // after the multi-digit, it will go back to original count

                int *temp = realloc(nums, (numIndex + 1) * sizeof(int));

                // if malloc fails
                if(!temp) {
                    printf("ERROR: memory reallocation failed!\n\n");
                    input.arr = NULL;
                    input.size = 0;
                    free(temp);
                    return input;
                }

                nums = temp;
                nums[numIndex++] = num; 
            }
        }

        if(strchr(inpArr, '!')) {
            break;
        }
    }

    printf("Sort in?\n[A]scending or [D]escending: ");
    scanf(" %c", &order);

    input.arr= nums;
    input.size = numIndex;
    input.order = order;

    return input;
}