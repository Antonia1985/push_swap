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

void	sort_2(t_stack_array *a, char **print_list)
{
	if (a->arr[1] < a->arr[0])
	{
		sa(a, print_list);
	}
}

void	sort_3(t_stack_array *a, char **print_list)
{
	if (a->arr[1] > a->arr[0])
	{
		if (a->arr[2] > a->arr[0] && a->arr[1] > a->arr[2])
		{
			rra(a, print_list);
			sa(a, print_list);
		}
		if (a->arr[2] < a->arr[0])
		{
			rra(a, print_list);
		}
	}
	else
	{
		if (a->arr[2] > a->arr[0])
			sa(a, print_list);
		else if (a->arr[2] < a->arr[1])
		{
			sa(a, print_list);
			rra(a, print_list);
		}
		else if (a->arr[2] > a->arr[1] && a->arr[2] < a->arr[0])
			ra(a, print_list);
	}
}

void	sort_3_desc(t_stack_array *a, char **print_list)
{
	if (a->arr[1] > a->arr[0])
	{
		sa(a, print_list);
	}
	if (a->arr[2] > a->arr[0])
	{
		rra(a, print_list);
	}
	else if (a->arr[2] > a->arr[1])
	{
		rra(a, print_list);
		sa(a, print_list);
	}
}

void	sort_4(t_stack_array *a, t_stack_array *b, char **print_list)
{
	if (a->arr[1] < a->arr[0])
		sa(a, print_list);
	if (a->arr[2] < a->arr[1])
	{
		pb_3(b, a, print_list);
		if (b->arr[0] < b->arr[2])
			rb(b, print_list);
		else
			sb(b, print_list);
		pa_3(a, b, print_list);
	}
	if (a->arr[3] < a->arr[0])
		rra(a, print_list);
	if (a->arr[3] < a->arr[1])
	{
		rra(a, print_list);
		sa(a, print_list);
	}
	if (a->arr[3] < a->arr[2])
	{
		pb_2(b, a, print_list);
		sa(a, print_list);
		pa_2(a, b, print_list);
	}
}
