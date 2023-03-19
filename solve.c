#include "head.h"
#include <stdlib.h>

int	recursive_solve(int *matrix, int size, int *clues)
{
	int 	*data;
	int	i;

	data = get_empty_position(matrix, size);
	if (data[0] == -1)
	{
		free(data);
		return 1;
	}
	i = 1;
	while (i <= size)
	{
		data[2] = i;
		if (validate_placement(matrix, size, clues, data))
		{
			matrix[data[1] * size + data[0]] = data[2];
			if (recursive_solve(matrix, size, clues))
			{
				free(data);
				return 1;
			}
			else
				matrix[data[1] * size + data[0]] = 0;
		}
		i++;
	}
	free(data);
	return 0;
}

void	solve(int *matrix, int size, int *clues)
{
	prefill(matrix, size, clues);
	if (!recursive_solve(matrix, size, clues))
	{
		put_error();
		free(matrix);
		free(clues);
		return ;
	}
	print_matrix(matrix, size);
	free(matrix);
	free(clues);
}
