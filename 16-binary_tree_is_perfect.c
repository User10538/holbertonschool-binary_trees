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

	return (check_perfect(tree, level, depth));
}

/**
 * check_perfect - Recursively checks if the binary tree is perfect.
 * @tree: A pointer to the current node.
 * @level: The current level of the node.
 * @depth: The depth of the leftmost leaf node.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int check_perfect(const binary_tree_t *tree, size_t level, size_t depth)
{
	if (tree == NULL)
		return (1);

	/* If the node is a leaf, it should be at the correct depth */
	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	/* If the node has one child, it's not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_perfect(tree->left, level + 1, depth)
			&& check_perfect(tree->right, level + 1, depth));
}
