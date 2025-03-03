#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25

typedef struct treeNode {
    int value;
    struct treeNode *left;
    struct treeNode *right;
} TREENODE;

typedef struct queueNode {
    TREENODE *data;
    struct queueNode *next;
} QUEUENODE;

typedef struct queue {
    QUEUENODE *front;
    QUEUENODE *rear;
} QUEUE;


//other functions
void displayMainMenu();
void clearInputBuffer();
int calculateTreeHeight(TREENODE *root);
TREENODE *findMin(TREENODE *node);

//node module functions
void addNodeModule(TREENODE **root);
void deleteNodeModule(TREENODE **root);
void searchNodeModule(TREENODE **root);
void editNodeModule(TREENODE **root);
void traverseTreeModule(TREENODE **root);

//node function
TREENODE *createNode(int value);
TREENODE *insertNode(TREENODE *root, int value);
TREENODE *deleteNode(TREENODE *root, int value);
TREENODE *searchNode(TREENODE *root, int value);
TREENODE *editNode(TREENODE *root, int oldVal, int newVal);

void printTree(TREENODE *root, char *buffer[], int height, int level, int col, int row);
void printBuffers(char *buffer[], int height);
void displayTree(TREENODE *root);

// tree traversal
void breadthFirst(TREENODE *root);
void inOrderTraversal(TREENODE *root);
void preOrderTraversal(TREENODE *root);
void postOrderTraversal(TREENODE *root);

//queue functions
QUEUE *createQueue();
void enqueue(QUEUE *q, TREENODE *node);
TREENODE *dequeue(QUEUE *q);
bool isQueueEmpty(QUEUE *q);
void freeQueue(QUEUE *q);

//the colors
void red();
void green();
void reset();

#endif