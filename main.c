#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_grid(int grid[4][4]);
void	fill_zero(int grid[4][4]);

int		ft_cpystr(char *str, int *userin);
int		solve(int grid[4][4], int *userin, int row, int col);
int		is_valid(int grid[4][4], int row, int col, int num);
int		check_all(int grid[4][4], int *userin);
int		check_coldown(int grid[4][4], int *userin);
int		check_colup(int grid[4][4], int *userin);
int		check_rowleft(int grid[4][4], int *userin);
int		check_rowright(int grid[4][4], int *userin);
int		count_visible(int *line);

void	fill_zero(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	userin[16];
	int	grid[4][4];

	fill_zero(grid);
	if (argc != 2 || !ft_cpystr (argv[1], userin))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (solve(grid, userin, 0, 0))
		print_grid(grid);
	else
	{
		ft_putstr("Error\n");
		return (1);
	}	
	return (0);
}
