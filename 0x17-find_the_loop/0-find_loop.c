#include "lists.h"

/**
 * loopFinder - Find the loop between nodes.
 * @head_p: pointer to start node
 * @nextNode: pointer to end node
 * Return: Detected loop node
 */

listint_t *loopFinder(listint_t *head_p, listint_t *nextNode)
{
	while (head_p != nextNode)
	{
		head_p = head_p->next;
		nextNode = nextNode->next;
	}
	return (head_p);
}

/**
 * find_listint_loop - Function that finds the loop in a linked list.
 * @head: Address to first node (index 0)
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *forkedNode, *nextNode;

	if (!head)
		return (NULL);

	forkedNode = head->next;
	nextNode = head->next->next;

	while (forkedNode && nextNode && nextNode->next)
	{
		forkedNode = forkedNode->next;
		nextNode = nextNode->next->next;
		if (forkedNode == nextNode)
			return (loopFinder(head, nextNode));
	}
	return (NULL);
}
