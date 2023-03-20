/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriver <mosriver@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:13:14 by mosriver          #+#    #+#             */
/*   Updated: 2023/03/19 20:18:46 by mosriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "head.h"

void	swap(int *p1, int *p2)
{
	int	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int	*copy_array_section(int *arr, int start, int end)
{
	int	*result;
	int	i;

	i = 0;
	result = malloc(4 * (end + 1 - start));
	while (start <= end)
		result[i++] = arr[start++];
	return (result);
}

int	compare(int *arr, int *perm, int clue)
{
	int	i;
	int	j;
	int	count;
	int	*cpy;

	count = 0;
	cpy = copy_array_section(arr, 1, arr[0]);
	i = 0;
	j = 1;
	while (i < arr[0])
	{
		if (cpy[i] == 0)
			cpy[i] = perm[j++];
		i++;
	}
	count = count_view(cpy, arr[0]);
	free(cpy);
	return (count == clue);
}

int	validate_permutations(int *arr, int *perm, int clue, int k)
{
	int	i;

	if (k == 2)
		return (compare(arr, perm, clue));
	else
	{
		if (validate_permutations(arr, perm, clue, k - 1))
			return (1);
		i = 0;
		while (i < k - 1)
		{
			if (k % 2 == 0)
			{
				swap(&(perm[i + 1]), &(perm[k - 1]));
			}
			else
			{
				swap(&(perm[1]), &(perm[k - 1]));
			}
			if (validate_permutations(arr, perm, clue, k - 1))
				return (1);
			i++;
		}
		return (0);
	}
}

int	*get_missing_numbers(int *row, int size)
{
	int	nums[10];
	int	*result;
	int	i;
	int	j;

	i = size;
	while (i--)
		nums[i] = 1;
	while (i < size)
	{
		if (row[i] != 0)
			nums[row[i]] = 0;
		i++;
	}
	i = 0;
	j = 1;
	result = malloc(4 * (size + 1));
	result[i++] = size;
	while (i < size)
	{
		if (nums[i] == 1)
			result[j++] = i;
		i++;
	}
	return (result);
}
