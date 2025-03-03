#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

void enqueue(QUEUE *q, TREENODE *node) {
    QUEUENODE *newNode = (QUEUENODE *)malloc(sizeof(QUEUENODE));
    if(newNode == NULL) {
        red();
        printf("ERROR: malloc failed1\n\n");
        exit(1);
    }

    newNode->data = node;
    newNode->next = NULL;

    //if q empty
    if(q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    //add and update
    q->rear->next = newNode;
    q->rear = newNode;
}