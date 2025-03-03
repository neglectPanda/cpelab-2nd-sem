#include <stdio.h>
#include "../tree.h"

TREENODE *insertNode(TREENODE *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // If both left and right children are NULL, randomly choose one to insert
    if (root->left == NULL && root->right == NULL) {
        // For simplicity, let's alternate between left and right
        static int toggle = 0; // Static variable to alternate
        if (toggle == 0) {
            root->left = createNode(value);
            toggle = 1;
        } else {
            root->right = createNode(value);
            toggle = 0;
        }

        if (root->left == NULL && root->right == NULL) {
            red();
            printf("ERROR: failed to create new node!\n\n");
            reset();
            return NULL;
        }
    }
    // If only the left child is NULL, insert there
    else if (root->left == NULL) {
        root->left = createNode(value);
        if (root->left == NULL) {
            red();
            printf("ERROR: failed to create new node!\n\n");
            reset();
            return NULL;
        }
    }
    // If only the right child is NULL, insert there
    else if (root->right == NULL) {
        root->right = createNode(value);
        if (root->right == NULL) {
            red();
            printf("ERROR: failed to create new node!\n\n");
            reset();
            return NULL;
        }
    }
    // If both children are occupied, recursively insert into the left or right subtree
    else {
        // Alternate between left and right subtrees for insertion
        static int toggle = 0; // Static variable to alternate
        if (toggle == 0) {
            root->left = insertNode(root->left, value);
            toggle = 1;
        } else {
            root->right = insertNode(root->right, value);
            toggle = 0;
        }
    }

    return root;
}