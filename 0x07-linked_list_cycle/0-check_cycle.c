#include "lists.h"

/**
 * check_cycle - Function that checks if a singly linked list
 * has a cycle in it.
 * @list: Address to a listint_t.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	listint_t *FordwardFork, *LastNode;

	FordwardFork = list;
	LastNode = list;

	while (list && FordwardFork && FordwardFork->next)
	{
		list = list->next;
		FordwardFork = FordwardFork->next->next;
		if (list == FordwardFork)
		{
			list = LastNode;
			LastNode =  FordwardFork;
			while (1)
			{
				FordwardFork = LastNode;
				while (FordwardFork->next != list && FordwardFork->next != LastNode)
				{
					FordwardFork = FordwardFork->next;
				}
				if (FordwardFork->next == list)
					break;

				list = list->next;
			}
			return (1);
		}
	}

	return (0);
}
