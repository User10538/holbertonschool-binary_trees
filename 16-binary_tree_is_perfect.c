#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    const binary_tree_t *temp = tree;
    int d = 0;

    if (tree == NULL)
        return (0);

    /* Find depth of the leftmost leaf */
    while (temp)
    {
        d++;
        temp = temp->left;
    }

    /* Inline helper function using a lambda-style static definition */
    int is_perfect(const binary_tree_t *node, int depth, int level)
    {
        if (node == NULL)
            return (1);

        if (!node->left && !node->right)
            return (depth == level + 1);

        if (!node->left || !node->right)
            return (0);

        return (is_perfect(node->left, depth, level + 1) &&
                is_perfect(node->right, depth, level + 1));
    }

    return (is_perfect(tree, d, 0));
}

