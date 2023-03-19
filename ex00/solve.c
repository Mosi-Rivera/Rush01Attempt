/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriver <mosriver@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:01:59 by mosriver          #+#    #+#             */
/*   Updated: 2023/03/19 14:22:30 by mosriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdlib.h>

int	free_and_return(int *mem, int value)
{
	free(mem);
	return (value);
}

int	recursive_solve(int *matrix, int size, int *clues)
{
	int	*data;
	int	i;

	data = get_empty_position(matrix, size);
	if (data[0] == -1)
		return (free_and_return(data, 1));
	i = size;
	while (i > 0)
	{
		data[2] = i--;
		if (validate_placement(matrix, size, clues, data))
		{
			matrix[data[1] * size + data[0]] = data[2];
			if (recursive_solve(matrix, size, clues))
				return (free_and_return(data, 1));
			else
				matrix[data[1] * size + data[0]] = 0;
		}
	}
	return (free_and_return(data, 0));
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
