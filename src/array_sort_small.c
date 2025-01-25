/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:24:52 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 13:24:55 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_2(t_stack_array *a)
{
	if (a->arr[1] < a->arr[0])
	{
		sa(a);
	}
}

void	sort_3(t_stack_array *a)
{
	if (a->arr[1] > a->arr[0])
	{
		if (a->arr[2] > a->arr[0] && a->arr[1] > a->arr[2])
		{
			rra(a);
			sa(a);
		}
		if (a->arr[2] < a->arr[0])
		{
			rra(a);
		}
	}
	else
	{
		if (a->arr[2] > a->arr[0])
			sa(a);
		else if (a->arr[2] < a->arr[1])
		{
			sa(a);
			rra(a);
		}
		else if (a->arr[2] > a->arr[1] && a->arr[2] < a->arr[0])
			ra(a);
	}
}

void	sort_3_desc(t_stack_array *a)
{
	if (a->arr[1] > a->arr[0])
	{
		sa(a);
	}
	if (a->arr[2] > a->arr[0])
	{
		rra(a);
	}
	else if (a->arr[2] > a->arr[1])
	{
		rra(a);
		sa(a);
	}
}

void	sort_4(t_stack_array *a, t_stack_array *b)
{
	if (a->arr[1] < a->arr[0])
		sa(a);
	if (a->arr[2] < a->arr[1])
	{
		pb_3(b, a);
		if (b->arr[0] < b->arr[2])
			rb(b);
		else
			sb(b);
		pa_3(a, b);
	}
	if (a->arr[3] < a->arr[0])
		rra(a);
	if (a->arr[3] < a->arr[1])
	{
		rra(a);
		sa(a);
	}
	if (a->arr[3] < a->arr[2])
	{
		pb_2(b, a);
		sa(a);
		pa_2(a, b);
	}
}
