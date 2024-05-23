#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main(int argc, char *argv[])
{
    BSTNode *root = NULL;
    insert(9, &root);
    insert(8, &root);
    insert(10, &root);
    insert(11, &root);
    insert(2, &root);
    insert(1, &root);
    insert(4, &root);
    insert(13, &root);
    insert(12, &root);
    insert(15, &root);

    inorder_traversal(root);
    destroy_tree(&root);

    return (0);
}
