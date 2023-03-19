/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriver <mosriver@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:02:39 by mosriver          #+#    #+#             */
/*   Updated: 2023/03/19 14:09:04 by mosriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	validate_row(int *matrix, int size, int *data)
{
	int	x;
	int	y;
	int	value;

	x = 0;
	y = data[1];
	value = data[2];
	while (x < size)
	{
		if (matrix[y * size + x++] == value)
			return (0);
	}
	return (1);
}

int	validate_column(int *matrix, int size, int *data)
{
	int	x;
	int	y;
	int	value;

	x = data[0];
	y = 0;
	value = data[2];
	while (y < size)
	{
		if (matrix[y * size + x] == value)
			return (0);
		y++;
	}
	return (1);
}

int	validate_placement(int *matrix, int size, int *clues, int *data)
{
	if (!validate_row(matrix, size, data))
		return (0);
	if (!validate_column(matrix, size, data))
		return (0);
	if (!validate_top_clue(matrix, size, clues[data[0]], data))
		return (0);
	if (!validate_bottom_clue(matrix, size, clues[size + data[0]], data))
		return (0);
	if (!validate_left_clue(matrix, size, clues[(size * 2) + data[1]], data))
		return (0);
	if (!validate_right_clue(matrix, size, clues[(size * 3) + data[1]], data))
		return (0);
	return (1);
}
