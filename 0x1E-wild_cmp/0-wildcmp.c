#include "holberton.h"

/**
* wildcmp - function that compares two strings and returns 1
* if the strings can be considered identical, otherwise return 0..
* @s1: Address to string to compare
* @s2: Address to string to compare
* Return: 1 for match, 0 otherwise
*/

int wildcmp(char *s1, char *s2)
{
	int firstElement, secondElement;

	if (!*s1)
	{
		if (*s2 == '*')
		{
			firstElement = wildcmp(s1, s2 + 1);
			return (firstElement);
		}

		secondElement = (*s2 == '\0') ? 1 : 0;

		return (secondElement);
	}

	if (*s2 == '*')
	{
		firstElement = wildcmp(s1, s2 + 1);
		secondElement = wildcmp(s1 + 1, s2);
		return (firstElement || secondElement);
	}

	if (*s1 == *s2)
	{
		firstElement = wildcmp(s1 + 1, s2 + 1);
		return (firstElement);
	}
	return (0);
}
