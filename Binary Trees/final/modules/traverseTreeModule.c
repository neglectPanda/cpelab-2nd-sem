#include <stdio.h>
#include "../tree.h"

void traverseTreeModule(TREENODE **root) {
    printf("\n=== TRAVERSE TREE ===\n");

    printf("Breadth-first                : ");
    breadthFirst(*root);

    printf("\n");

    printf("Depth-First Inorder          : ");
    inOrderTraversal(*root);

    printf("\n");

    printf("Depth-First Preorder         : ");
    preOrderTraversal(*root);

    printf("\n");

    printf("Depth-First PostOrder        : ");
    postOrderTraversal(*root);

    printf("\n");
}