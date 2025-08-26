#include <unistd.h>

int		is_valid(int grid[4][4], int row, int col, int num);
int		check_all(int grid[4][4], int *userin);

int	solve(int grid[4][4], int *userin, int row, int col)
{
	int	num;

	if (row == 4)
		return (check_all (grid, userin));
	else if (col == 4)
		return (solve(grid, userin, row + 1, 0));
	else if (grid[row][col] != 0)
		return (solve(grid, userin, row, col +1));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, userin, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
