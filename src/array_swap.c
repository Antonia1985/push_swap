/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:30:55 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 18:24:05 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

static void	swap(t_stack_array *stack)
{
	int	swap;

	if (stack->size > 1)
	{
		swap = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = swap;
	}
}

void	sa(t_stack_array *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack_array *stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stack_array *stack_a, t_stack_array *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
