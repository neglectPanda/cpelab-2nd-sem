#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

void freeQueue(QUEUE *q) {
    QUEUENODE *current = q->front;
    QUEUENODE *next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(q);
}
