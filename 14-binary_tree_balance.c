#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left = tree_height(tree->left);
	int right = tree_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = tree->left ? tree_height(tree->left) : 0;
	int right_height = tree->right ? tree_height(tree->right) : 0;

	return (left_height - right_height);
}

