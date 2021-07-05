#include "list.h"

/**
* create_node - Creates a new node
* @str: Adress to new node
* Return: Address of the new node, or NULL on failure
*/
List *create_node(char *str)
{
	List *newNode;

	newNode = malloc(sizeof(*newNode));

	if (!newNode)
		return (NULL);

	newNode->str = strdup(str);

	if (!newNode->str)
	{
		free(newNode->str);
		return (NULL);
	}

	newNode->next = newNode->prev = NULL;

	return (newNode);
}

/**
* add_node_end - Add a new node to the end of a double circular linked list
* @list: Address to list
* @str: Address to new data
* Return: Address of the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
	List *last, *node;

	if (!list || !str)
		return (NULL);

	node = create_node(str);

	if (!node)
		return (NULL);

	if (*list)
	{
		last = (*list)->prev;
		last->next = node;
		node->prev = last;
		node->next = *list;
		(*list)->prev = node;
	}
	else
	{
		*list = node;
		node->prev = node->next = node;
	}

	return (node);
}

/**
* add_node_begin - Add a new node to the beginning of a DCLL
* @list: Address to list
* @str: Address to new data
* Return: Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
	return (add_node_end(list, str) ? *list = (*list)->prev : NULL);
}
