#include <unistd.h>

int	str_size(char *str)
{
	int	size;

	size = 0;
	while (str[size])
	{
		size++;
	}
	return (size);
}

int	ft_cpystr(char *str, int *userin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str_size (str) != 31)
		return (0);
	while (str[j] && i < 16)
	{
		if (str[j] >= '1' && str[j] <= '4')
		{
			userin[i] = str[j] - '0';
			i++;
			j++;
		}
		else if (str[j] == ' ')
		{
			if (str[j - 1] == ' ')
				return (0);
			j++;
		}
		else
			return (0);
	}
	return (i == 16);
}
