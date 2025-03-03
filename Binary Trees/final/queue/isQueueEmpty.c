#include <stdio.h>
#include <stdbool.h>
#include "../tree.h"

bool isQueueEmpty(QUEUE *q) {
    return q->front == NULL;
}