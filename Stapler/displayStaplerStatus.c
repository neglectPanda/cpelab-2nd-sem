#include <stdio.h>
#include "stapler.h"

void displayStaplerStatus(STAPLER *stapler) {
    int i;

    printf("Magazines loaded: %d/%d\n", stapler->top + 1, MAX_MAG);
    for(i = 0; i <= stapler->top; i++) {
        printf("Magazine %d: %.1f cm, staples left %d/%d\n", i+1, stapler->magazine[i].size, stapler->magazine[i].staples, MAX_STAPLES);
    }
}