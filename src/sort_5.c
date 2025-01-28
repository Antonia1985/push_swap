/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:41:26 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 19:41:31 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	first_case(t_stack_array *a, t_stack_array *b)
{
	if (b->arr[0] < a->arr[0])
		pa_2(a, b);
	else if (b->arr[0] < a->arr[1])
	{
		pa(a, b);
		sa(a);
		pa(a, b);
	}
	else if (b->arr[0] < a->arr[2])
	{
		rra(a);
		pa(a, b);
		ra_2(a);
		pa(a, b);
	}
	else if (b->arr[0] > a->arr[2])
	{
		pa(a, b);
		ra(a);
		pa(a, b);
	}
}

void	second_case(t_stack_array *a, t_stack_array *b)
{
	if (b->arr[0] < a->arr[1])
	{
		pa(a, b);
		sa(a);
		pa(a, b);
		sa(a);
	}
	else if (b->arr[0] < a->arr[2])
	{
		rra(a);
		pa(a, b);
		ra_2(a);
		pa(a, b);
		sa(a);
	}
	else if (b->arr[0] > a->arr[2])
	{
		pa(a, b);
		ra(a);
		pa(a, b);
		sa(a);
	}
}

void	third_case(t_stack_array *a, t_stack_array *b)
{
	if (b->arr[0] < a->arr[2])
	{
		rra(a);
		pa_2(a, b);
		rra_2(a);
	}
	else if (b->arr[0] > a->arr[2])
	{
		pa(a, b);
		ra_3(a);
		pa(a, b);
		rra_2(a);
	}
}

void	sort_5(t_stack_array *a, t_stack_array *b)
{
	if (a->arr[2] < a->arr[1] || a->arr[3] < a->arr[2] || a->arr[4] < a->arr[3])
	{
		pb_2(b, a);
		sort_3(a);
		if (b->arr[0] < b->arr[1])
			sb(b);
		if (b->arr[1] < a->arr[0])
			first_case(a, b);
		else if (b->arr[1] < a->arr[1])
			second_case(a, b);
		else if (b->arr[1] < a->arr[2])
			third_case(a, b);
		else if (b->arr[1] > a->arr[2])
		{
			pa_2(a, b);
			ra_2(a);
		}
	}
	else if (a->arr[1] < a->arr[0] && !(a->arr[2] < a->arr[1]
			|| a->arr[3] < a->arr[2] || a->arr[4] < a->arr[3]))
		sa(a);
}
