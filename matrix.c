#include <stdlib.h>
#include "head.h"

int 	*generate_matrix(int size)
{
	int limit;
	int *matrix;

	limit = size * size;
	matrix = malloc(4 * limit);
	if (matrix == 0)
		return (0);
	return matrix;
}

void	fill_matrix(int *matrix, int size, int value)
{
	size = size * size;
	while (size--)
	{
		matrix[size] = value;
	}
}

int	*copy_matrix(int *matrix, int size)
{
	int *cpy;

	cpy = generate_matrix(size);
	size = size * size;
	while (size--)
	{
		cpy[size] = matrix[size];
	}
	return cpy;
}

void	print_matrix(int *matrix, int size)
{
	int i;
	int width;

	i = 0;
	width = size;
	size = size * size;
	while (i < size)
	{
		ft_putchar(matrix[i] + '0');
		ft_putchar(' ');
		if (i % width == width - 1)
			ft_putchar('\n');
		i++;
	}
}


