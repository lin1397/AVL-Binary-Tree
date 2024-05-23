#include "btree.h"

void destroy_tree(BSTNode **root)
{
    if (*root != NULL)
    {
        destroy_tree(&((*root)->left));
        destroy_tree(&((*root)->right));

        free(*root);  // deallocate
        *root = NULL; // set to NULL to indicate that it is empty
    }
}
