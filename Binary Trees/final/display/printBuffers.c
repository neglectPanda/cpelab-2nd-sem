#include <stdio.h>

void printBuffers(char *buffer[], int height) {
    for(int i = 0; i < height; i++) {
        printf("%s\n", buffer[i]);
    }
}