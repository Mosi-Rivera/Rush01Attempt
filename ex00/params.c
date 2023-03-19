#include <stdlib.h>

int	validate_params(char *str, int size)
{
	int	space_flag;
	int	count;

	count = 0;
	space_flag = 1;
	while (*str)
	{
		if (*str == ' ')
		{
			if (space_flag)
				return (0);
			space_flag = 1;
		}
		else
		{
			if (!space_flag || (*str < '1' || *str > '0' + size))
				return (0);
			space_flag = 0;
			count++;
		}
		str++;
	}
	return (*(str - 1) != ' ' && count == size * size);
}

int	*parse_params(char *str, int size)
{
	int	limit;
	int	*params;
	int	count;

	params = malloc(4 * size * 4);
	limit = size * size;
	count = 0;
	while (count < limit)
	{
		if (*str != ' ')
		{
			params[count] = *str - '0';
			count++;
		}
		str++;
	}
	return (params);
}


