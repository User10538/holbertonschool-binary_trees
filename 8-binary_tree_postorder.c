#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * binary_tree_postorder - function that
 * goes through a binary tree using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func:  a pointer to a function to call for each node
 *
 * Return: 1 if node is a root, otherwise 0
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{

	/*Left -> Right-> Root*/

	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

