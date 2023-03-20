/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clue_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriver <mosriver@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:01:38 by mosriver          #+#    #+#             */
/*   Updated: 2023/03/19 20:12:39 by mosriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdlib.h>

int	validate_view_clue(int *arr, int size, int clue, int default_result)
{
	int	*missing_numbers;
	int	*size_arr;
	int	i;

	i = 0;
	size_arr = malloc(4 * (size + 1));
	size_arr[0] = size;
	while (i < size)
	{
		size_arr[i + 1] = arr[i];
		i++;
	}
	missing_numbers = get_missing_numbers(arr, size);
	default_result = validate_permutations(
			size_arr, missing_numbers, clue, size + 1);
	free(size_arr);
	return (default_result);
}

int	validate_top_clue(int *matrix, int size, int clue, int *data)
{
	int	*column;
	int	result;

	column = copy_column(matrix, size, data[0]);
	result = validate_view_clue(column, size, clue, 0);
	free(column);
	return (result);
}

int	validate_bottom_clue(int *matrix, int size, int clue, int *data)
{
	int	*column;
	int	result;

	column = copy_column(matrix, size, data[0]);
	reverse_arr(column, size);
	result = validate_view_clue(column, size, clue, 0);
	free(column);
	return (result);
}

int	validate_left_clue(int *matrix, int size, int clue, int *data)
{
	int	*row;
	int	result;

	row = copy_row(matrix, size, data[1]);
	result = validate_view_clue(row, size, clue, 0);
	free(row);
	return (result);
}

int	validate_right_clue(int *matrix, int size, int clue, int *data)
{
	int	*row;
	int	result;

	row = copy_row(matrix, size, data[1]);
	reverse_arr(row, size);
	result = validate_view_clue(row, size, clue, 0);
	free(row);
	return (result);
}
