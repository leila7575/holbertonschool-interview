#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_before_toppling - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_before_toppling(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable;
	int temp[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (1)
	{
		stable = 1;
		for (i = 0; i < 3 && stable; i++)
			for (j = 0; j < 3 && stable; j++)
				if (grid1[i][j] > 3)
					stable = 0;

		if (stable)
			return;

		printf("=\n");
		print_before_toppling(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				temp[i][j] = grid1[i][j];

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (temp[i][j] > 3)
				{
					grid1[i][j] -= 4;
					if (i + 1 < 3)
						grid1[i + 1][j] += 1;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (j + 1 < 3)
						grid1[i][j + 1] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
				}
	}
}
