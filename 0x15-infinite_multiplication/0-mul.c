#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * isArgZero - Zero value identifier
 * @argv: Arguments.
 *
 * Return: None.
 */

void isArgZero(char *argv[])
{
	int i, isZeroArg1 = 1, isZeroArg2 = 1;

	for (i = 0; argv[1][i]; i++)
		if (argv[1][i] != '0')
		{
			isZeroArg1 = 0;
			break;
		}

	for (i = 0; argv[2][i]; i++)
		if (argv[2][i] != '0')
		{
			isZeroArg2 = 0;
			break;
		}

	if (isZeroArg1 == 1 || isZeroArg2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * NewZeroArray - Set a new array with zeros
 * @array: Pointer to char array.
 * @length: length of the char array.
 *
 * Return: Pointer to array.
 */

char *NewZeroArray(char *array, int length)
{
	int i = 0;

	for (i = 0; i < length; i++)
		array[i] = '0';
	array[length] = '\0';
	return (array);
}

/**
 * ArgLenght - Verify that the argument is a valid number
 * and return the lenght.
 * @argv: The arguments.
 * @n: Index of the argument.
 *
 * Return: The length of the number.
 */

int ArgLenght(char *argv[], int n)
{
	int lenght;

	for (lenght = 0; argv[n][lenght]; lenght++)
		if (!isdigit(argv[n][lenght]))
		{
			printf("Error\n");
			exit(98);
		}

	return (lenght);
}

/**
 * main - Main function that multiplies two positive numbers.
 * factor1 > fc1
 * factor2 > fc2
 * ProductSize > ps
 * product > prd
 * @argc: Number of argumnets.
 * @argv: The arguments.
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	int factor1, factor2, ps, add, addl, i, j, k, ca;
	char *prd;

	if (argc != 3)
		printf("Error\n"), exit(98);
	factor1 = ArgLenght(argv, 1), factor2 = ArgLenght(argv, 2);
	isArgZero(argv), ps = factor1 + factor2, prd = malloc(ps + 1);
	if (prd == NULL)
		printf("Error\n"), exit(98);
	prd = NewZeroArray(prd, ps);
	k = ps - 1, i = factor1 - 1, j = factor2 - 1, ca = addl = 0;
	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (addl > 0)
			{
				add = (prd[k] - '0') + addl;
				if (add > 9)
					prd[k - 1] = (add / 10) + '0';
				prd[k] = (add % 10) + '0';
			}
			i = factor1 - 1, j--, addl = 0, ca++, k = ps - (1 + ca);
		}
		if (j < 0)
		{
			if (prd[0] != '0')
				break;
			ps--;
			free(prd), prd = malloc(ps + 1), prd = NewZeroArray(prd, ps);
			k = ps - 1, i = factor1 - 1, j = factor2 - 1, ca = addl = 0;
		}
		if (j >= 0)
		{
			add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (prd[k] - '0') + addl;
			addl = add / 10, prd[k] = (add % 10) + '0';
		}
	}
	printf("%s\n", prd);
	return (0);
}
