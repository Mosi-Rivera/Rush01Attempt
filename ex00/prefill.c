/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriver <mosriver@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:01:27 by mosriver          #+#    #+#             */
/*   Updated: 2023/03/19 14:12:52 by mosriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	prefill_top(int *matrix, int size, int *clues)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (clues[i] == 1)
		{
			matrix[0 * size + i] = size;
			if (clues[size + i] == 2)
				matrix[(size - 1) * size + i] = size - 1;
		}
		else if (clues[i] == size)
		{
			j = -1;
			while (++j < size)
				matrix[j * size + i] = j + 1;
		}
		else if (clues[i] < clues[size + i])
			matrix[(clues[i] - 1) * size + i] = size;
		i++;
	}
}

void	prefill_bottom(int *matrix, int size, int *clues)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (clues[size + i] == 1)
		{
			matrix[(size - 1) * size + i] = size;
			if (clues[i] == 2)
				matrix[0 * size + i] = size - 1;
		}
		else if (clues[size + i] == size)
		{
			j = -1;
			while (++j < size)
				matrix[j * size + i] = size - j;
		}
		else if (clues[size + i] < clues[i])
			matrix[(size - clues[size + i]) * size + i] = size;
		i++;
	}
}

void	prefill_left(int *matrix, int size, int *clues)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (clues[size * 2 + i] == 1)
		{
			matrix[i * size + 0] = size;
			if (clues[size * 3 + i] == 2)
				matrix[i * size + size - 1] = size - 1;
		}
		else if (clues[size * 2 + i] == size)
		{
			j = -1;
			while (++j < size)
				matrix[i * size + j] = j + 1;
		}
		else if (clues[size * 2 + i] < clues[size * 3 + i])
			matrix[i * size + clues[size * 2 + i] - 1] = size;
		i++;
	}
}

void	prefill_right(int *matrix, int size, int *clues)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (clues[size * 3 + i] == 1)
		{
			matrix[i * size + (size - 1)] = size;
			if (clues[size * 2 + i] == 2)
				matrix[i * size + 0] = size - 1;
		}
		else if (clues[size * 3 + i] == size)
		{
			j = -1;
			while (++j < size)
				matrix[i * size + j] = size - j;
		}
		else if (clues[size * 3 + i] < clues[size * 2 + i])
			matrix[i * size + size - clues[size * 3 + i]] = size;
		i++;
	}
}

void	prefill(int *matrix, int size, int *clues)
{
	prefill_top(matrix, size, clues);
	prefill_bottom(matrix, size, clues);
	prefill_left(matrix, size, clues);
	prefill_right(matrix, size, clues);
}
