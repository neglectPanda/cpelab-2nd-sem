#include <stdio.h>
#include "../tree.h"

TREENODE *searchNode(TREENODE *root, int value) {
    if(root == NULL || root->value == value) {
        return root;
    }

    // Search in the left subtree
    TREENODE *leftResult = searchNode(root->left, value);
    if(leftResult != NULL) {
        return leftResult;
    }

    // Search in the right subtree
    return searchNode(root->right, value);
}