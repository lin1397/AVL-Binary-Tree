#include <stdio.h>
#include <stdlib.h>

typedef struct _BSTNode
{
    int data;
    int height;
    struct _BSTNode *left;
    struct _BSTNode *right;
} BSTNode;

void insert(int data, BSTNode **root); // insert data into binary tree

void preorder_traversal(BSTNode *root); // print pre-order traversal

void inorder_traversal(BSTNode *root); // print in-order traversal

void postorder_traversal(BSTNode *root); // print post-order traversal

void destroy_tree(BSTNode **root); // free b-tree

void rotate_counterclockwise(BSTNode **root); // rotate counterclockwise

void rotate_clockwise(BSTNode **root); // rotate clockwise

void update_height(BSTNode *root); // update height of node

void balance_after_insert_in_left(int data, BSTNode **root); // balance tree after left node insertion

void balance_after_insert_in_right(int data, BSTNode **root); // balance tree after right node insertion

int get_height(BSTNode const *root); // return the height of the current node

int get_balance_score(BSTNode const *root); // determine if the tree is unbalanced
