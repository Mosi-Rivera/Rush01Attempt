#include <stdlib.h>

int *get_empty_position(int *matrix, int size)
{
	int	x;
	int	y;
	int	*result;

	result = malloc(4 * 3);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (matrix[y * size + x] == 0)
			{
				result[0] = x;
				result[1] = y;
				return result;
			}
			x++;
		}
		y++;
	}
	result[0] = -1;
	return result;
}

int *copy_column(int *matrix, int size, int x)
{
	int *column;
	int y;

	column = malloc(size * 4);
	y = 0;
	while (y < size)
	{
		column[y] = matrix[y * size + x];
		y++;
	}
	return column;
}

int *copy_row(int *matrix, int size, int y)
{
	int *row;
	int x;

	row = malloc(size * 4);
	x = 0;
	while (x < size)
	{
		row[x] = matrix[y * size + x];
		x++;
	}
	return row;
}



void reverse_arr(int *arr, int size)
{
	int i;
	int limit;
	int tmp;

	i = 0;
	limit = size / 2;
	while (i < limit)
	{
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
		i++;
	}
}


int	count_view(int *arr, int size)
{
	int max;
	int count;
	int i;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			count++;
			max = arr[i];
		}
		i++;
	}
	return count;
}


