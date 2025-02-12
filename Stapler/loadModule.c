#include <stdio.h>
#include "stapler.h"

void loadModule(STAPLER *stapler) {
    float size;
    char ch;

    if(stapler->top >= MAX_MAG - 1) {
        printf("ERROR: stapler mags full!\n\n");
        return;
    }

    while(1) {
        printf("Enter size: ");
        if((scanf("%f%c", &size, &ch)) == 2 && ch == '\n') {

            if(size != 1.0 && size != 1.5 && size != 2.0) {
                printf("ERROR: invalid size!\n\n");
                return;
            }

            if(loadMag(stapler, size)) {
                printf("SUCCESS: %.1f cm loaded!\n\n", size);
            } else {
                printf("ERROR: mag not loaded!\n\n");
            }

            break;

        } else {
            printf("ERROR: size is of type float!\n\n");
            clearInputBuffer();
        }
    }

    return;
}
