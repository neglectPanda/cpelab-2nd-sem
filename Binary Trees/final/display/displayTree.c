#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../tree.h"

void displayTree(TREENODE *root) {
    if(root == NULL) {
        printf("Tree empty!\n\n");
        return;
    }

    int height = calculateTreeHeight(root);
    int bufferHeight = height * 2 - 1; //branch lines;

    if(bufferHeight > CONSOLE_HEIGHT - 5) {
        bufferHeight = CONSOLE_HEIGHT - 5; //room for menu and the prompts
    }
    
    // ensure at least one line for display
    if (bufferHeight < 1) {
        bufferHeight = 1;
    }

    char *buffer[bufferHeight];
    for(int i = 0; i < bufferHeight; i++) {
        buffer[i] = (char*)malloc(sizeof(char) * (CONSOLE_WIDTH + 1));
        if (buffer[i] == NULL) {
            red();
            printf("ERROR: Memory allocation failed for display buffer!\n\n");
            reset();
            
            // Free previously allocated buffers
            for (int j = 0; j < i; j++) {
                free(buffer[j]);
            }
            return;
        }
        
        memset(buffer[i], ' ', CONSOLE_WIDTH);
        buffer[i][CONSOLE_WIDTH] = '\0';
    }

    //tree to buffer
    printTree(root, buffer, height, 0, CONSOLE_WIDTH / 2, CONSOLE_WIDTH / 2);

    //buffer to console
    printBuffers(buffer, bufferHeight);

    //free
    for(int i = 0; i < bufferHeight; i++) {
        free(buffer[i]);
    }

    return;
}