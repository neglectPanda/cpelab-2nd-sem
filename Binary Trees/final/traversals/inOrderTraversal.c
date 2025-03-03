#include <stdio.h>
#include "../tree.h"

//lvr
void inOrderTraversal(TREENODE *root) {
    if(root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right); 
    }
} 