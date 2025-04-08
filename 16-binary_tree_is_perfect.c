#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth, level = 0;
	const binary_tree_t *temp;

	if (tree == NULL)
		return (0);

	/* Find the depth of the leftmost leaf node */
	temp = tree;

	while (temp != NULL)
	{
		depth++;
		temp = temp->left;
	}

	/* If the node is a leaf, it should be at the correct depth */
	if (tree->left == NULL && tree->right == NULL)
		return (depth == 1);

	/* If the node has one child, it's not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	
	/* Recursively check if both subtrees are perfect */
	left_perfect = binary_tree_is_perfect(tree->left);
	right_perfect = binary_tree_is_perfect(tree->right);

	return (left_perfect && right_perfect);
}
