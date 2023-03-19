/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriver <mosriver@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:01:16 by mosriver          #+#    #+#             */
/*   Updated: 2023/03/19 14:13:24 by mosriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	main(int argc, char **argv)
{
	int	size;
	int	*clues;
	int	*matrix;

	size = 4;
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
