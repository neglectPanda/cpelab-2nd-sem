#include <stdio.h>
#include "../tree.h"

TREENODE *editNode(TREENODE *root, int oldVal, int newVal) {
    TREENODE *foundNode = searchNode(root, oldVal);

    if(foundNode == NULL) {
        red();
        printf("ERROR: node does not exist!\n\n");
        return root; //unchanged
    }

    // Update the value
    foundNode->value = newVal;

    return root;
}