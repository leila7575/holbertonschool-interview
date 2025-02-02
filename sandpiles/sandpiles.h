#ifndef SANDPILES_H
#define SANDPILES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void print_grid_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_before_toppling(int grid[3][3]);

#endif /* SANDPILES_H */