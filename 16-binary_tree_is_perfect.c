#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * *binary_tree_sibling - function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: no sibling, return NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    const binary_tree_t *temp;
    int depth = 0, level = 0;
    const binary_tree_t *stack[1024];
    int top = -1;
    const binary_tree_t *node;
    int levels[1024];

    if (tree == NULL)
        return (0);

    /* Calculate depth (leftmost path) */
    temp = tree;
    while (temp)
    {
        depth++;
        temp = temp->left;
    }

    /* Iterative DFS to check perfectness */
    stack[++top] = tree;
    levels[top] = 0;

    while (top >= 0)
    {
        node = stack[top];
        level = levels[top--];

        if (!node->left && !node->right)
        {
            if (level + 1 != depth)
                return (0);
        }
        else if (!node->left || !node->right)
        {
            return (0);
        }
        else
        {
            stack[++top] = node->right;
            levels[top] = level + 1;

            stack[++top] = node->left;
            levels[top] = level + 1;
        }
    }

    return (1);
}

