#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

 /**
  * insert_node - function in C that inserts a number
  * @head: Address to a array of adrreses.
  * @number: Number to insert.
  * Return: the address of the new node, or NULL if it failed.
  */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *pointerNode;

	pointerNode = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL || head == NULL)
		return (NULL);

	newNode->n = number;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (*head);
	}
	else
	{
		if (pointerNode->n > newNode->n)
		{
			newNode->next = pointerNode;
			*head = newNode;
			return (*head);
		}
		else
		{
			while (pointerNode->next != NULL && pointerNode->next->n < newNode->n)
			{
				pointerNode = pointerNode->next;
			}
			newNode->next = pointerNode->next;
			pointerNode->next = newNode;
			return (newNode);
		}
	}
}
