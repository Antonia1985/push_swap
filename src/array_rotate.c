/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:23:40 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 18:23:43 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rotate(t_stack_array *stack)
{
	int	i;
	int	swap;

	if (stack->size > 1)
	{
		swap = stack->arr[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
		stack->arr[stack->size - 1] = swap;
	}
}

void	ra(t_stack_array *stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_stack_array *stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_stack_array *stack_a, t_stack_array *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
