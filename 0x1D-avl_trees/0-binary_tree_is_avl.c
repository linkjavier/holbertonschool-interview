#include "binary_trees.h"

/**
 * _abs - get the absolute value of a given number
 * @x: value to get the absolute value
 * Return: the absolute value of a given number
 */
int _abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

/**
 * is_valid_avl_tree - check if a binary tree is a valid avl tree using
 * recursion
 * @tree: head node of the tree to check
 * @min_tree_v: minimun value of a subtree
 * @max_tree_v: maximun value of a subtree
 * @height: height of the tree
 * Return: 1 if the tree is a valid avl tree, 0 otherwise
 */

int is_valid_avl_tree(const binary_tree_t *tree, int min_tree_v,
		int max_tree_v, int *height)
{
	int height1 = 0, height2 = 0;

	if (tree == NULL)
		return (1);

	if (tree->n <= min_tree_v || tree->n >= max_tree_v)
		return (0);

	if (is_valid_avl_tree(tree->left, min_tree_v, tree->n, &height1) == 0 ||
			is_valid_avl_tree(tree->right, tree->n, max_tree_v, &height2) == 0)
		return (0);

	*height = ((height1 > height2) ? height1 : height2) + 1;

	if (_abs(height1 - height2) > 1)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - check if a given tree is a valid AVL tree
 * @tree: head node of a tree
 * Return: 1 if a given tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_valid_avl_tree(tree, INT_MIN, INT_MAX, &height));