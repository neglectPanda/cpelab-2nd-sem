#include <stdio.h>
#include "stapler.h"

int loadMag(STAPLER *stapler, float size) {
    if(stapler->top >= MAX_MAG - 1) {
        return 0;
    }

    stapler->top++;
    stapler->magazine[stapler->top].size = size;
    stapler->magazine[stapler->top].staples = MAX_STAPLES;
    return 1; //success
}