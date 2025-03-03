#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

TREENODE *deleteNode(TREENODE *root, int value) {
    if(root == NULL) {
        return root;
    }

    // If the node to be deleted is found
    if(root->value == value) {
        // Node with only one child or no child
        if(root->left == NULL) {
            TREENODE *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            TREENODE *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TREENODE *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    } else {
        // Recursively delete in the left and right subtrees
        root->left = deleteNode(root->left, value);
        root->right = deleteNode(root->right, value);
    }

    return root;
}