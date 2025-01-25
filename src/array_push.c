/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:23:11 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 18:23:13 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push(void *stack, int value)
{
	t_stack_array	*array_stack;
	int				i;

	array_stack = (t_stack_array *)stack;
	i = array_stack->size;
	if (array_stack->size == array_stack->capacity)
	{
		return ;
	}
	while (i > 0)
	{
		array_stack->arr[i] = array_stack->arr[i - 1];
		i--;
	}
	array_stack->arr[0] = value;
	array_stack->size++;
}

int	pop(void *stack)
{
	int				i;
	t_stack_array	*array_stack;
	int				top_value;

	i = 0;
	array_stack = (t_stack_array *)stack;
	if (array_stack->size == 0)
	{
		return (-1);
	}
	top_value = array_stack->arr[0];
	while (i < array_stack->size)
	{
		array_stack->arr[i] = array_stack->arr[i + 1];
		i++;
	}
	array_stack->size--;
	return (top_value);
}

static void	pop_push(t_stack_array *stack_to_push_in,
		t_stack_array *stack_to_pop)
{
	int	value;

	if (stack_to_pop->size > 0)
	{
		value = pop(stack_to_pop);
		push(stack_to_push_in, value);
	}
}

void	pa(t_stack_array *stack_to_push_in, t_stack_array *stack_to_pop)
{
	pop_push(stack_to_push_in, stack_to_pop);
	ft_printf("pa\n");
}

void	pb(t_stack_array *stack_to_push_in, t_stack_array *stack_to_pop)
{
	pop_push(stack_to_push_in, stack_to_pop);
	ft_printf("pb\n");
}
