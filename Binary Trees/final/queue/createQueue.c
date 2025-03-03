#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

QUEUE *createQueue() {
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));

    if(q == NULL) {
        red();
        printf("ERROR: malloc failed!\n\n");
        exit(1);
    }

    q->front = NULL;
    q->rear = NULL;
    return q;
}