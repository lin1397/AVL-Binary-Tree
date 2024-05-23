#include "btree.h"

void insert(int data, BSTNode **root)
{
    if (*root == NULL) // create a new node
    {
        *root = malloc(sizeof **root);
        **root = (BSTNode){.data = data, .height = 0, .left = NULL, .right = NULL};
    }
    else if (data < (*root)->data) // recursively insert the data value correctly
    {
        insert(data, &(*root)->left);
        update_height(*root);                     // update the tree height
        balance_after_insert_in_left(data, root); // balance the tree
    }
    else if (data > (*root)->data) // recursively insert the data value correctly
    {
        insert(data, &((*root)->right));
        update_height(*root);                      // update the tree height
        balance_after_insert_in_right(data, root); // balance the tree
    }
}
