#include "binary_trees.h"
/**
 * sorted_array_to_avl - Function that builds an AVL tree from an array
 * @array: Address to Array
 * @size: Size of the Array
 * Return: Address to main node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *main = NULL;

	if (array == NULL)
		return (NULL);

	if (allocateAvlNode(array, 0, (int)size - 1, &main) == NULL)
		return (NULL);
	return (main);
}

/**
 * allocateAvlNode - Allocate New AVL Node
 * @array: Address to Array
 * @init: Start position
 * @end: End Position
 * @main: Address to AVL Main node
 * Return: Main
 */
avl_t *allocateAvlNode(int *array, int init, int end, avl_t **main)
{
	avl_t *allocatedNode = NULL;
	avl_t *left = NULL;
	avl_t *right = NULL;
	int halfArray;

	if (init > end)
		return (NULL);

	halfArray = (end + init) / 2;

	allocateAvlNode(array, init, halfArray - 1, &left);
	allocateAvlNode(array, halfArray + 1, end, &right);

	allocatedNode = malloc(sizeof(avl_t));
	if (allocatedNode == NULL)
		return (NULL);

	allocatedNode->n = array[halfArray];
	allocatedNode->parent = NULL;
	allocatedNode->left = left;
	allocatedNode->right = right;

	if (left != NULL)
		left->parent = allocatedNode;

	if (right != NULL)
		right->parent = allocatedNode;

	*main = allocatedNode;
	return (allocatedNode);
}
