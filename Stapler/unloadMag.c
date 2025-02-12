#include <stdio.h>
#include "stapler.h"

int unloadMag(STAPLER *stapler) {
    if(stapler->top == -1) {
        return 0; //stack empty
    }

    stapler->top--;
    return 1;
}