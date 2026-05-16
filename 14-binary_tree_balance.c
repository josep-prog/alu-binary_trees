#include "binary_trees.h"

/**
 * tree_height - measures height of a binary tree
 * @tree: pointer to root node
 * Return: height, 0 if tree is NULL
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);

	h_left = tree->left ? 1 + tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + tree_height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor
 *         0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (!tree)
		return (0);

	h_left = tree->left ? (int)tree_height(tree->left) : -1;
	h_right = tree->right ? (int)tree_height(tree->right) : -1;

	return (h_left - h_right);
}
