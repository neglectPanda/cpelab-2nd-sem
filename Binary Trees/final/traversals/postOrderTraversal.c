#include <stdio.h>
#include "../tree.h"

//lrv
void postOrderTraversal(TREENODE *root) {
    if(root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->value);
    }
}