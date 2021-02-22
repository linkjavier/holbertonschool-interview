#include "slide_line.h"

/**
 * slide_line - Function that slides and merges an array of integers.
 * @line: Points to an array of integers containing size elements.
 * @size: Number of elements.
 * @direction: SLIDE_LEFT/SLIDE_RIGHT.
 * Return: 1 upon success, or 0 upon failure.
 */

int slide_line(int *line, size_t size, int direction)
{
	int IndexA = 0;
	int IndexB = 1;
	int Fordward = 1;

	if (!line || size < 1 || (direction != 0 && direction != 1))
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		IndexA = size - 1;
		IndexB = size - 2;
		Fordward = -1;
	}
	while (direction == 0 ? IndexB < (int) size : IndexB >= 0)
	{
		if (line[IndexA] == 0 || line[IndexA] == line[IndexB])
		{
			line[IndexA] += line[IndexB];

			if (line[IndexA] != line[IndexB])
				IndexA += Fordward;

			line[IndexB] = 0;
			IndexB += Fordward;
		}
		else if (line[IndexB] != 0)
		{
			IndexA += Fordward;

			if (IndexA == IndexB)
				IndexB += Fordward;
		}
		else
			IndexB += Fordward;
	}
	return (1);
}
