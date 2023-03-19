#include "head.h"

int	main(int argc, char **argv)
{
	int	size = 4;
	int	*clues;
	int	*matrix;

	if (argc != 2 || !validate_params(argv[1], size))
	{
		put_error();
		return (1);
	}
	clues = parse_params(argv[1], size);
	matrix = generate_matrix(size);
	fill_matrix(matrix, size, 0);
	solve(matrix, size, clues);
	return (0);
}
