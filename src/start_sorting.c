/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:27:07 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 13:27:09 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	start_sorting(void *stack_a, void *stack_b, int nums_size)
{
	t_stack_array	*a;
	t_stack_array	*b;

	a = (t_stack_array *)stack_a;
	b = (t_stack_array *)stack_b;
	if (nums_size == 2)
	{
		sort_2(a);
	}
	else if (nums_size == 3)
	{
		sort_3(a);
	}
	else if (nums_size == 4)
	{
		sort_4(a, b);
	}
	else if (nums_size == 5)
	{
		sort_5(a, b);
	}
	else if (nums_size > 5)
	{
		array_sort_big(a, b);
	}
}
