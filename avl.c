#include "btree.h"

void update_height(BSTNode *root)
{
    int height_of_left = get_height(root->left);                                              // get height from left branch
    int height_of_right = get_height(root->right);                                            // get height from right branch
    root->height = 1 + (height_of_left > height_of_right ? height_of_left : height_of_right); // update the current node height
}

int get_height(BSTNode const *root)
{
    return root == NULL ? -1 : root->height; // return the height of the current node
}

int get_balance_score(BSTNode const *root)
{
    return get_height(root->left) - get_height(root->right); // determine if the tree is unbalance
}

void rotate_counterclockwise(BSTNode **root)
{
    BSTNode *old_root = *root; // set the new root as the first node in the right branch
    BSTNode *new_root = old_root->right;
    old_root->right = new_root->left;
    new_root->left = old_root;
    *root = new_root;
    update_height(old_root);
    update_height(new_root);
}

void rotate_clockwise(BSTNode **root)
{
    BSTNode *old_root = *root; // set the new root as the first node in the left branch
    BSTNode *new_root = old_root->left;
    old_root->left = new_root->right;
    new_root->right = old_root;
    *root = new_root;
    update_height(old_root);
    update_height(new_root);
}

void balance_after_insert_in_left(int data, BSTNode **root)
{
    if (get_balance_score(*root) == 2)
    {
        if (data < (*root)->left->data)
        {
            // Single rotation -- after insert in root -> left -> left
            rotate_clockwise(root);
        }
        else
        {
            // Double rotation -- after insert in root -> left -> right
            rotate_counterclockwise(&((*root)->left));
            rotate_clockwise(root);
        }
    }
}

void balance_after_insert_in_right(int data, BSTNode **root)
{
    if (get_balance_score(*root) == -2)
    {
        if (data > (*root)->right->data)
        {
            // Single rotation -- after insert in root -> right -> right
            rotate_counterclockwise(root);
        }
        else
        {
            // Double rotation -- after insert in root -> right -> left
            rotate_clockwise(&((*root)->right));
            rotate_counterclockwise(root);
        }
    }
}
