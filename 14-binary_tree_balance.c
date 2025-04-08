#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * binary_tree_balance - function that measures the balance factor of a binary tree
 * @tree:  pointer to the root node of the tree to measure the balance factor
 *
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (((int)binary_tree_height(tree->left) - (int)binary_tree_height(tree->right)));

}
