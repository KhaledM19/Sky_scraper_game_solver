int	count_visible(int *line);

int	check_colup(int grid[4][4], int *userin)
{
	int	line[4];
	int	i;
	int	col;

	col = 0;
	while (col < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = grid[i][col];
			i++;
		}
		if (count_visible(line) != userin[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_coldown(int grid[4][4], int *userin)
{
	int	col;
	int	line[4];
	int	i;

	col = 0;
	while (col < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = grid[3 - i][col];
			i++;
		}
		if (count_visible(line) != userin[4 + col])
			return (0);
		col++;
	}
	return (1);
}

int	check_rowleft(int grid[4][4], int *userin)
{
	int	row;
	int	i;
	int	line[4];

	row = 0;
	while (row < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = grid[row][i];
			i++;
		}
		if (count_visible(line) != userin[8 + row])
			return (0);
		row++;
	}
	return (1);
}

int	check_rowright(int grid[4][4], int *userin)
{
	int	row;
	int	i;
	int	line[4];

	row = 0;
	while (row < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = grid[row][3 - i];
			i++;
		}
		if (count_visible(line) != userin[12 + row])
			return (0);
		row++;
	}
	return (1);
}

int	check_all(int grid[4][4], int *userin)
{
	if (!check_colup(grid, userin))
		return (0);
	else if (!check_coldown(grid, userin))
		return (0);
	else if (!check_rowleft(grid, userin))
		return (0);
	else if (!check_rowright(grid, userin))
		return (0);
	else
		return (1);
}
