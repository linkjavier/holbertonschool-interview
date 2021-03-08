#include "menger.h"
/**
 * menger - Function that draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */

void menger(int level)
{
	int i;
	int j;
	int width;
	int height;
	int squareSize;

	squareSize = pow(3, level);
	for (i = 0; i < squareSize; i++)
	{
		for (j = 0; j < squareSize; j++)
		{
			height = i, width = j;
			while (1)
			{
				if (height % 3 == 1 && width % 3 == 1)
				{
					printf(" ");
					break;
				}
				if (height == 0 || width == 0)
				{
					printf("#");
					break;
				}
				height = height / 3;
				width = width / 3;
			}
		}
		printf("\n");
	}
}
