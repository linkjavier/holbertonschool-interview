#include<stdio.h>
#include<stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Function that creates a binary tree node
 * @parent: Address to parent node of the node to create
 * @value: Value to put in the new node
 * Return: A pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/*Allocate memory for new node*/
	binary_tree_t *BinaryTreeNode = malloc(sizeof(binary_tree_t));

	if (BinaryTreeNode == NULL)
		return (NULL);

	/*Assign value to this node n field*/
	BinaryTreeNode->n = value;

	/*Initialize left and right children as NULL*/
	BinaryTreeNode->parent = parent;
	BinaryTreeNode->left = NULL;
	BinaryTreeNode->right = NULL;

	return (BinaryTreeNode);
}
