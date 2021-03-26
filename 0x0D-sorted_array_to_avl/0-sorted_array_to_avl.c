#include "binary_trees.h"

/**
 * newNode - Creates a allocated binary tree node
 * @parent: Main node
 * @value: Value of New Node
 * Return: New node
 */

binary_tree_t *newNode(binary_tree_t *parent, int value)
{
	binary_tree_t *allocatedNode;

	allocatedNode = malloc(sizeof(binary_tree_t));
	if (allocatedNode == NULL)
		return (NULL);

	allocatedNode->left = NULL;
	allocatedNode->right = NULL;
	allocatedNode->n = value;
	allocatedNode->parent = parent;

	return (allocatedNode);
}

/**
 * arrayToAvl - builds an AVL tree from an array
 * @array: Given Array
 * @init: Start of array
 * @final: End of array
 * @parent: Main node
 * Return: Pointer to Main node
 */

avl_t *arrayToAvl(int *array, size_t init, size_t final, avl_t *parent)
{
	avl_t *main;
	size_t half;

	half = (init + final) / 2;
	main = newNode(parent, array[half]);

	if (main == NULL)
		return (NULL);

	if (init > final)
		return (NULL);

	if (half != init)
		main->left = arrayToAvl(array, init, half - 1, main);

	if (half != final)
		main->right = arrayToAvl(array, half + 1, final, main);

	return (main);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: array to be converted
 * @size: number of elements in the array
 * Return: main node
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *main;

	if (array == NULL || size == 0)
		return (NULL);

	main = arrayToAvl(array, 0, size - 1, NULL);

	return (main);
}
