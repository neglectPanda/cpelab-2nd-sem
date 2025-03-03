#include <stdio.h>
#include "../tree.h"

void breadthFirst(TREENODE *root) {
    if(root == NULL) {
        printf("tree is empty!\n\n");
        return;
    }

    //new queue
    QUEUE *q = createQueue();
    if (q == NULL) {
        red();
        printf("ERROR: failed to create queue!\n\n");
        reset();
        return;
    }

    enqueue(q, root);

    while(!isQueueEmpty(q)) {
        TREENODE *current = dequeue(q);
        if (current == NULL) {
            continue; // Skip NULL nodes
        }
        
        printf("%d ", current->value);

        //enqueue left
        if(current->left != NULL) {
            enqueue(q, current->left);
        }

        //enqueue right
        if(current->right != NULL) {
            enqueue(q, current->right);
        }
    }

    freeQueue(q);
    printf("\n");

    return;
}