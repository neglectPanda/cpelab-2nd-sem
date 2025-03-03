#include <stdio.h>
#include "tree.h"

void clearInputBuffer() {
    while(getchar() != '\n');
}

int calculateTreeHeight(TREENODE *root) {
    if(root == NULL) {
        return 0;
    } else {
        int leftTreeHeight = calculateTreeHeight(root->left);
        int rightTreeHeight = calculateTreeHeight(root->right);

        return (leftTreeHeight > rightTreeHeight) ? (leftTreeHeight + 1) : (rightTreeHeight + 1);
    }
}

TREENODE *findMin(TREENODE *node) {
    if (node == NULL) {
        return NULL;
    }
    
    TREENODE *current = node;

    //find leftmost
    while(current && current->left != NULL) {
        current = current->left;
    }

    return current;
}