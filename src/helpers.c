/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:00:00 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 20:00:03 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	stack_array_size(char **numbers)
{
	size_t	length;

	length = 0;
	while (numbers[length] != NULL)
	{
		length++;
	}
	return (length);
}

int	is_argument_an_array(char *argument_str)
{
	if (!argument_str)
		return (0);
	while (*argument_str)
	{
		if (*argument_str == ' ')
			return (1);
		argument_str++;
	}
	return (0);
}

void	sort_array(int *arr, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_max_pos(t_stack_array *b)
{
	int	max;
	int	max_position;
	int	i;

	if (b->size == 0)
		return (0);
	max = b->arr[0];
	max_position = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->arr[i] > max)
		{
			max = b->arr[i];
			max_position = i;
		}
		i++;
	}
	return (max_position);
}

void	move_max_to_top(t_stack_array *b, int max_pos)
{
	int	i;

	if (max_pos <= b->size / 2)
	{
		i = 0;
		while (i < max_pos)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		i = b->size;
		while (i > max_pos)
		{
			rrb(b);
			i--;
		}
	}
}
