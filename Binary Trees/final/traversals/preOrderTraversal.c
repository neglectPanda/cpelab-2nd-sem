#include <stdio.h>
#include "../tree.h"

//vlr
void preOrderTraversal(TREENODE *root) {
    if(root != NULL) {
        printf("%d ", root->value);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}