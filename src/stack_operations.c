/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:26:56 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 13:26:58 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	*initiallize_stack(int capacity)
{
	t_stack_array	*stack;

	stack = malloc(sizeof(t_stack_array));
	if (!stack)
		return (NULL);
	stack->arr = malloc(capacity * sizeof(int));
	if (!stack->arr)
		return (free(stack), NULL);
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	fill_stack_from_args(void *stack, int nums_size, char **numbers)
{
	int				i;
	t_stack_array	*stack_array;
	int				value;

	i = 0;
	stack_array = (t_stack_array *)stack;
	if (numbers[i] == NULL)
		print_error();
	while (i < nums_size)
	{
		value = atoi(numbers[i]);
		stack_array->arr[i] = value;
		stack_array->size++;
		i++;
	}
}

void	free_stacks(t_stack_array *stack_a, t_stack_array *stack_b)
{
	free(stack_a->arr);
	free(stack_a);
	free(stack_b->arr);
	free(stack_b);
}
