#include "sandpiles.h"


/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: First grid
 * @grid2: Second grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;
	int haltVariable = 0;

	int IndexPlace[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];

	while (1)
	{
		haltVariable = 0;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					IndexPlace[i][j] = 1;
					haltVariable = 1;
				}
				else
				{
					IndexPlace[i][j] = 0;
				}
			}
		}

		if (haltVariable == 0)
			return;

		NewPrintGrid(grid1);
		GridTopple(grid1, IndexPlace);
	}
}

/**
 * GridTopple - Manage the toppling of the Grid
 * @grid: The grid for toppling.
 * @IndexPlace: Indicates toppling
 */

void GridTopple(int grid[3][3], int IndexPlace[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (IndexPlace[i][j] == 1)
			{
				grid[i][j] = grid[i][j] - 4;
				if (i > 0)
					grid[i - 1][j] = grid[i - 1][j] + 1;
				if (i < 2)
					grid[i + 1][j] = grid[i + 1][j] + 1;
				if (j > 0)
					grid[i][j - 1] = grid[i][j - 1] + 1;
				if (j < 2)
					grid[i][j + 1] = grid[i][j + 1] + 1;
			}
		}
	}
}

/**
 * NewPrintGrid - Prints the grid
 * @grid: Grid to print
 */

void NewPrintGrid(int grid[3][3])
{
	int i = 0;
	int j = 0;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);

			if (j < 2)
				putchar(' ');
		}
		putchar('\n');
	}
}
