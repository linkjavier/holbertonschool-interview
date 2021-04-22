#include "sort.h"

/**
 * swap - Function that swaps values.
 * @a: Address to a
 * @b: Address to b
 * @array: The array - Needed to print it
 * @n: Length of the array
 */
void swap(int *a, int *b, int *array, size_t n)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, n);
}

/**
 * heapify - Function that swaps values.
 * @array: The array
 * @n: Input length of the array
 * @i: Index
 * @size: Original length of the array
 */
void heapify(int array[], int n, int i, size_t size)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	/* left child is greater than root */
	if (l < n && array[l] > array[largest])
	{
		largest = l;
	}

	/* right child is greater than root */
	if (r < n && array[r] > array[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(&array[i], &array[largest], array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - Function that sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: The array
 * @size: Original length of the array
 */
void heap_sort(int *array, size_t size)
{
	/* build the heap */
	int i;

	if (!array)
		return;

	for (i = size / 2 ; i > 0; i--)
	{
		heapify(array, size, i - 1, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heapify(array, i, 0, size);
	}
}
