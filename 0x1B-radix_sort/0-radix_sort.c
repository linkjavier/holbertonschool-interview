#include "sort.h"

/**
 * decimalSort - Function to handle digits
 * @array: Address to array for radix sorting
 * @size: Size of array
 * @exponent: Exponent int
 */
void decimalSort(int *array, size_t size, int exponent)
{
	int tenArray[10] = {0}, j;
	int *sorted = NULL;
	size_t i;

	sorted = malloc(sizeof(int) * size);

	if (!sorted)
		return;

	for (i = 0; i < size; i++)
		tenArray[(array[i] / exponent) % 10]++;

	for (i = 1; i < 10; i++)
		tenArray[i] += tenArray[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		sorted[tenArray[(array[j] / exponent) % 10] - 1] = array[j];
		tenArray[(array[j] / exponent) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	print_array(array, size);
	free(sorted);
}

/**
 * radix_sort - Radix sorting
 * @array: Address to array for radix sorting
 * @size: Size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t index = 1;
	int biggest = 0, power = 1;

	if (!array || size < 2)
		return;

	biggest = array[0];

	while (index < size)
	{
		if (array[index] > biggest)
			biggest = array[index];
		index++;
	}

	while (biggest)
	{
		decimalSort(array, size, power);
		power *= 10;
		biggest /= 10;
	}
}
