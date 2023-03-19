#include "head.h"
#include <stdlib.h>

int	validate_view_clue(int *arr, int size, int clue, int default_result)
{
	default_result = count_view(arr, size) <= clue;
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
