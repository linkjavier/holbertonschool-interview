#include "lists.h"

/**
 * is_palindrome - Function in C that checks if a singly
 * linked list is a palindrome.
 * @head: Address / Pointer to a single linked list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	listint_t *FirstFork;
	listint_t *SecondFork;
	listint_t *PreviousNode;
	listint_t *NextNode;

	if (!head || !*head)
		return (1);
	FirstFork = *head;
	SecondFork = *head;
	while (SecondFork && SecondFork->next)
	{
		FirstFork = FirstFork->next;
		SecondFork = SecondFork->next->next;
	}
	PreviousNode = NULL;
	SecondFork = *head;
	while (FirstFork)
	{
		NextNode = FirstFork->next;
		FirstFork->next = PreviousNode;
		PreviousNode = FirstFork;
		if (!NextNode)
			break;
		FirstFork = NextNode;
	}
	while (FirstFork)
	{
		if (FirstFork->n != SecondFork->n)
			return (0);
		FirstFork = FirstFork->next;
		SecondFork = SecondFork->next;
	}
	return (1);
}
