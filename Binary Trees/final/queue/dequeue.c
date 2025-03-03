#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

TREENODE* dequeue(QUEUE* q) {
    // queue empty
    if (q->front == NULL) {
        return NULL;
    }
    
    // get front node
    QUEUENODE* temp = q->front;
    TREENODE* data = temp->data;
    
    // front update
    q->front = q->front->next;
    
    // if front null, update rear
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}