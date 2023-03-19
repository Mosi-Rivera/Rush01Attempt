/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriver <mosriver@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:02:16 by mosriver          #+#    #+#             */
/*   Updated: 2023/03/19 14:28:29 by mosriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

void	put_error(void);
void	ft_putchar(char c);
int		validate_params(char *str, int size);
int		*parse_params(char *str, int size);
int		*generate_matrix(int size);
void	fill_matrix(int *matrix, int size, int value);
int		*copy_matrix(int *matrix, int size);
void	print_matrix(int *matrix, int size);
int		*get_empty_position(int *matrix, int size);
int		validate_row(int *matrix, int size, int *data);
int		validate_column(int *matrix, int size, int *data);
int		*copy_column(int *matrix, int size, int x);
int		*copy_row(int *matrix, int size, int y);
void	reverse_arr(int *arr, int size);
int		count_view(int *arr, int size);
int		validate_view_clue(int *arr, int size, int clue, int default_result);
int		validate_top_clue(int *matrix, int size, int clue, int *data);
int		validate_bottom_clue(int *matrix, int size, int clue, int *data);
int		validate_left_clue(int *matrix, int size, int clue, int *data);
int		validate_right_clue(int *matrix, int size, int clue, int *data);
int		validate_placement(int *matrix, int size, int *clues, int *data);
int		recursive_solve(int *matrix, int size, int *clues);
void	prefill_top(int *matrix, int size, int *clues);
void	prefill_bottom(int *matrix, int size, int *clues);
void	prefill_left(int *matrix, int size, int *clues);
void	prefill_right(int *matrix, int size, int *clues);
void	prefill(int *matrix, int size, int *clues);
void	solve(int *matrix, int size, int *clues);

#endif
