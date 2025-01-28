/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:24:33 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 13:24:40 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	count_elements_in_range(t_stack_array *a, int min_val, int max_val)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] >= min_val && a->arr[i] <= max_val)
			count++;
		i++;
	}
	return (count);
}

void	create_chunks(t_stack_array *a, int num_chunks, int *chunk_bounds)
{
	int	i;
	int	*sorted_arr;

	i = 0;
	sorted_arr = malloc(sizeof(int) * a->size);
	if (!sorted_arr)
		exit(EXIT_FAILURE);
	while (i < a->size)
	{
		sorted_arr[i] = a->arr[i];
		i++;
	}
	sort_array(sorted_arr, a->size);
	i = 0;
	while (i < num_chunks)
	{
		chunk_bounds[2 * i] = sorted_arr[i * (a->size / num_chunks)];
		if (i == num_chunks - 1)
			chunk_bounds[2 * i + 1] = sorted_arr[a->size - 1];
		else
			chunk_bounds[2 * i + 1] = sorted_arr[(i + 1) * (a->size
					/ num_chunks) - 1];
		i++;
	}
	free(sorted_arr);
}

void	push_values_of_each_chunk(t_stack_array *a, t_stack_array *b, int min,
		int max, char **print_list)
{
	int	pushed;
	int	to_push;

	pushed = 0;
	to_push = count_elements_in_range(a, min, max);
	while (pushed < to_push && a->size > 0)
	{
		if (a->arr[0] >= min && a->arr[0] <= max)
		{
			pb(b, a, print_list);
			if (b->arr[0] < (min + max) / 2 && b->size > 1)
				rb(b, print_list);
			pushed++;
		}
		else if (a->arr[a->size - 1] >= min && a->arr[a->size - 1] <= max)
		{
			rra(a, print_list);
			pb(b, a, print_list);
			if (b->arr[0] < (min + max) / 2 && b->size > 1)
				rb(b, print_list);
			pushed++;
		}
		else
			ra(a, print_list);
	}
}

void	sort_stack_b_descending_and_push(t_stack_array *b, t_stack_array *a, char **print_list)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = find_max_pos(b);
		move_max_to_top(b, max_pos, print_list);
		pa(a, b, print_list);
	}
}

void	array_sort_big(t_stack_array *a, t_stack_array *b, char **print_list)
{
	int	num_chunks;
	int	*chunk_bounds;
	int	i;
	int	min_val;
	int	max_val;

	if (a->size >=100 && a->size <= 200)
	num_chunks = 5;
	else
	num_chunks =  9;

	chunk_bounds = malloc(sizeof(int) * 2 * num_chunks);
	if (!chunk_bounds)
		exit(EXIT_FAILURE);
	create_chunks(a, num_chunks, chunk_bounds);
	i = 0;
	while (i < num_chunks)
	{
		min_val = chunk_bounds[i * 2];
		max_val = chunk_bounds[(i * 2) + 1];
		push_values_of_each_chunk(a, b, min_val, max_val, print_list);
		i++;
	}
	sort_stack_b_descending_and_push(b, a, print_list);
	free(chunk_bounds);
}
