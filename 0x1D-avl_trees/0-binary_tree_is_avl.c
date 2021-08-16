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
}#include "binary_trees.h"

/**
 * bst_h - checks if valid BST
 * @tree: pointer to root node being checked
 * @min: integer
 * @max: integer
 *
 * Return: 1 if valid BST, 0 on failure
 */
int bst_h(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_h(tree->left, min, tree->n - 1) &&
		bst_h(tree->right, tree->n + 1, max));
}

/**
 * bst - checks if valid BST
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if valid BST, 0 on failure
 */
int bst(const binary_tree_t *tree)
{
	return (bst_h(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_is_avl - Determine if binary tree is an AVL or not
 * @tree: Pointer to root node of binary tree
 *
 * Return: 1 if tree is an AVL, 0 on failure
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;
	size_t diff;

	if (!tree)
		return (0);

	if (!bst(tree))
		return (0);

	height_left = tree->left ? binary_tree_height(tree->left) : 0;
	height_right = tree->right ? binary_tree_height(tree->right) : 0;

	if (height_left > height_right)
		diff = height_left - height_right;
	else
		diff = height_right - height_left;

	if (diff > 1)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}