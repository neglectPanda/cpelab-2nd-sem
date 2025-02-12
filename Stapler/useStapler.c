#include <stdio.h>
#include "stapler.h"

void useStapler(STAPLER *stapler) {
    if(stapler->top == -1) {
        printf("ERROR: no magazines loaded!\n\n");
        return;
    }

    STAPLEMAG *topMag = &stapler->magazine[stapler->top];

    printf("Using magazine with %.1f cm\n", topMag->size);
    topMag->staples--;

    if(topMag->staples == 0) {
        unloadMag(stapler);
        printf("SUCCESS: unloaded!\n\n");
    }

    return;

}