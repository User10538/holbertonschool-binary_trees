#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: 1 if node is a root, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

	/*height of left and right*/
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* calculate the max height, compare left and right to find the max*/
	return (1 + (left_height > right_height ? left_height : right_height));
}
