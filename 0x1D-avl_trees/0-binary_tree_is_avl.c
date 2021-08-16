#include "binary_trees.h"
#include <limits.h>
/**
 * tree_max_height - measures the max height of a binary tree
 * @node: pointer to the root node of the tree to measure the height.
 * Return: return the max height
 **/
size_t tree_max_height(const binary_tree_t *node)
{
	size_t l = 0, r = 0;

	if (node->left)
		l = tree_max_height(node->left);
	if (node->right)
		r = tree_max_height(node->right);
	return (1 + MAX(l, r));
}

/**
 * inOrder_checkBST - Checks if the tree is a Binary Search Tree
 * @tree: Tree to check
 * @dir: Which direction to check, left or right ?
 * @max: Used to compare value max value with current node value
 * @count: Used in case if the tree is not a valid BST
 **/
void inOrder_checkBST(binary_tree_t *tree, int dir, int max, int *count)
{
	if (tree == NULL)
		return;

	inOrder_checkBST(tree->left, dir, max, count);
	inOrder_checkBST(tree->right, dir, max, count);
	if (tree->left && tree->right && tree->left->n > tree->right->n)
		*count -= 1;
	if (dir == 0 && tree->n >= max)
		*count -= 1;
	if (dir == 1 && tree->n <= max)
		*count -= 1;
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Tree to check
 * Return: 1 if tree is a valid AVL Tree otherwise 0
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int leftHeight, rightHeight, count;

	if (tree == NULL)
		return (0);

	leftHeight = 0, rightHeight = 0, count = 0;
	if (tree->left)
		leftHeight = tree_max_height((binary_tree_t *)tree->left) - 1;
	if (tree->right)
		rightHeight = tree_max_height((binary_tree_t *)tree->right) - 1;
	if (leftHeight + rightHeight == 1)
		return (1);
	if (leftHeight - rightHeight >= 1 || leftHeight - rightHeight < 0)
		return (0);
	inOrder_checkBST((binary_tree_t *)tree->left, 0, tree->n, &count);
	if (count < 0)
		return (0);
	inOrder_checkBST((binary_tree_t *)tree->right, 1, tree->n, &count);
	if (count < 0)
		return (0);
	return (1);
}