/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:23:23 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 18:23:31 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	reverse_rotate(t_stack_array *stack)
{
	int	i;
	int	swap;

	if (stack->size > 1)
	{
		swap = stack->arr[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
		stack->arr[0] = swap;
	}
}

void	rra(t_stack_array *stack, char **print_list)
{
	reverse_rotate(stack);
	fill_print_list(print_list, "rra\n");
	//ft_printf("rra\n");
}

void	rrb(t_stack_array *stack, char **print_list)
{
	reverse_rotate(stack);
	fill_print_list(print_list, "rrb\n");
	//ft_printf("rrb\n");
}

void	rrr(t_stack_array *stack_a, t_stack_array *stack_b, char **print_list)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	fill_print_list(print_list, "rrr\n");
	//ft_printf("rrr\n");
}
