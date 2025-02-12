#include <stdio.h>
#include "stapler.h"

void unloadModule(STAPLER *stapler) {
    if(unloadMag(stapler)) {
        printf("SUCCESS: unloaded!\n\n");
    } else {
        printf("ERROR: no magazines to unload!\n\n");
    }

    return;
}