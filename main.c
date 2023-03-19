#include <stdio.h>
#include <stdlib.h>

void	put_error()
{
	printf("Error");
}

void	ft_putchar(char c)
{
	printf("%c", c);
}

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
	int limit;
	int *params;
	int count;

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
	return params;
}

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
			return 0;
	}
	return 1;
}

int 	validate_column(int *matrix, int size, int *data)
{
	int	x;
	int	y;
	int	value;

	x = data[0];
	y = 0;
	value = data[2];
	while (y < size)
	{
		if (matrix[y++ * size + x] == value)
			return 0;
	}
	return 1;
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

int 	validate_view_clue(int *arr, int size, int clue)
{
	return (count_view(arr, size) <= clue);
}

int	validate_top_clue(int *matrix, int size, int clue, int *data)
{
	int	*column;
	int	result;
	column = copy_column(matrix, size, data[0]);
	result = validate_view_clue(column, size, clue);	
	free(column);
	return (result);
}

int	validate_bottom_clue(int *matrix, int size, int clue, int *data)
{
	int	*column;
	int	result;

	column = copy_column(matrix, size, data[0]);
	reverse_arr(column, size);
	result = validate_view_clue(column, size, clue);
	free(column);
	return (result);
}

int	validate_left_clue(int *matrix, int size, int clue, int *data)
{
	int	*row;
	int	result;

	row = copy_row(matrix, size, data[1]);
	result = validate_view_clue(row, size, clue);
	free(row);
	return (result);
}

int	validate_right_clue(int *matrix, int size, int clue, int *data)
{
	int	*row;
	int	result;

	row = copy_row(matrix, size, data[1]);
	reverse_arr(row, size);
	result = validate_view_clue(row, size, clue);
	free(row);
	return result;
}

int	validate_placement(int *matrix, int size, int *clues, int *data)
{
	if (!validate_row(matrix, size, data) || !validate_column(matrix, size, data))
		return 0;
	if (!validate_top_clue(matrix, size, clues[data[0]], data))
		return 0;
	if (!validate_bottom_clue(matrix, size, clues[size + data[0]], data))
		return 0;
	if (!validate_left_clue(matrix, size, clues[(size * 2) + data[1]], data))
		return 0;
	if (!validate_right_clue(matrix, size, clues[(size * 3) + data[1]], data))
		return 0;
	
	return 1;
}

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

void	rush(int *matrix, int size, int *clues)
{
	prefill(matrix, size, clues);
	if (!recursive_solve(matrix, size, clues))
	{
		put_error();
		return ;
	}
	print_matrix(matrix, size);
	free(matrix);
	free(clues);
}

int	main(int argc, char **argv)
{
	int size = 4;
	int *clues;
	int *matrix;
	if (argc != 2 || !validate_params(argv[1], size))
	{
		put_error();
		return (1);
	}
	clues = parse_params(argv[1], size);
	matrix = generate_matrix(size);
	fill_matrix(matrix, size, 0);
	rush(matrix, size, clues);
	return (0);
}
