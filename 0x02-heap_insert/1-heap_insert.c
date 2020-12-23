#include "binary_trees.h"
/**
 *heap_insert - Function that inserts nodes in a Max heap
 *@root: Double pointer to the root node of the Heap
 *@value: Value store in the node to be inserted
 *Return: Pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	int NumberOfNodes;
	int HeapIndex;
	heap_t *HeapNode;
	heap_t *PointerHeapNode;

	if (*root == NULL)
	{
		HeapNode = binary_tree_node(*root, value);

		if (HeapNode == NULL)
			return (NULL);
		*root = HeapNode;
		return (*root);
	}
	NumberOfNodes = BinaryTreeSize(*root) + 1;
	HeapIndex = NumberOfNodes / 2;
	PointerHeapNode = FindHeapNode(root, HeapIndex);
	HeapNode = binary_tree_node(PointerHeapNode, value);

	if (HeapNode == NULL)
		return (NULL);
	if (HeapIndex * 2 == NumberOfNodes)
		PointerHeapNode->left = HeapNode;
	else
		PointerHeapNode->right = HeapNode;
	if (NumberOfNodes >= 2)
	{
		while (HeapNode->parent != NULL &&
				HeapNode->n > HeapNode->parent->n)
		{
			HeapNode->n = HeapNode->parent->n;
			HeapNode->parent->n = value;
			HeapNode = HeapNode->parent;
		}
	}
	return (HeapNode);
}

/**
 * BinaryTreeSize - Function to get the number of nodes
 * @bynaryTree: address to the root of a tree
 * Return: Number of nodes (Size of Tree)
 */

size_t BinaryTreeSize(const binary_tree_t *bynaryTree)
{
	size_t NumberOfNodes;

	NumberOfNodes = 0;
	if (bynaryTree != NULL)
	{
		NumberOfNodes = 1 +  BinaryTreeSize(bynaryTree->left) +
			BinaryTreeSize(bynaryTree->right);
	}
	return (NumberOfNodes);
}

/**
 *FindHeapNode - Function to get the node to appenning
 *@root: Address to root node
 *@index: Index to find and get route to node
 *Return: Node for added new one
 */

heap_t *FindHeapNode(heap_t **root, int index)
{
	int Counter;
	int Temporal;
	heap_t *PointerHeapNode;

	Counter = 0;
	PointerHeapNode = *root;
	while (1)
	{
		if ((1 << (Counter + 1)) > index)
			break;
		Counter++;
	}
	Counter--;
	while (Counter >= 0)
	{
		Temporal = (1 << Counter);
		if (index & Temporal)
			PointerHeapNode = PointerHeapNode->right;
		else
			PointerHeapNode = PointerHeapNode->left;
		Counter--;
	}
	return (PointerHeapNode);
}
