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

void	first_case(t_stack_array *a, t_stack_array *b, char **print_list)
{
	if (b->arr[0] < a->arr[0])
		pa_2(a, b, print_list);
	else if (b->arr[0] < a->arr[1])
	{
		pa(a, b, print_list);
		sa(a, print_list);
		pa(a, b, print_list);
	}
	else if (b->arr[0] < a->arr[2])
	{
		rra(a, print_list);
		pa(a, b, print_list);
		ra_2(a, print_list);
		pa(a, b, print_list);
	}
	else if (b->arr[0] > a->arr[2])
	{
		pa(a, b, print_list);
		ra(a, print_list);
		pa(a, b, print_list);
	}
}

void	second_case(t_stack_array *a, t_stack_array *b, char **print_list)
{
	if (b->arr[0] < a->arr[1])
	{
		pa(a, b, print_list);
		sa(a, print_list);
		pa(a, b, print_list);
		sa(a, print_list);
	}
	else if (b->arr[0] < a->arr[2])
	{
		rra(a, print_list);
		pa(a, b, print_list);
		ra_2(a, print_list);
		pa(a, b, print_list);
		sa(a, print_list);
	}
	else if (b->arr[0] > a->arr[2])
	{
		pa(a, b, print_list);
		ra(a, print_list);
		pa(a, b, print_list);
		sa(a, print_list);
	}
}

void	third_case(t_stack_array *a, t_stack_array *b, char **print_list)
{
	if (b->arr[0] < a->arr[2])
	{
		rra(a, print_list);
		pa_2(a, b, print_list);
		rra_2(a, print_list);
	}
	else if (b->arr[0] > a->arr[2])
	{
		pa(a, b, print_list);
		ra_3(a, print_list);
		pa(a, b, print_list);
		rra_2(a, print_list);
	}
}

void	sort_5(t_stack_array *a, t_stack_array *b, char **print_list)
{
	if (a->arr[2] < a->arr[1] || a->arr[3] < a->arr[2] || a->arr[4] < a->arr[3])
	{
		pb_2(b, a, print_list);
		sort_3(a, print_list);
		if (b->arr[0] < b->arr[1])
			sb(b, print_list);
		if (b->arr[1] < a->arr[0])
			first_case(a, b, print_list);
		else if (b->arr[1] < a->arr[1])
			second_case(a, b, print_list);
		else if (b->arr[1] < a->arr[2])
			third_case(a, b, print_list);
		else if (b->arr[1] > a->arr[2])
		{
			pa_2(a, b, print_list);
			ra_2(a, print_list);
		}
	}
	else if (a->arr[1] < a->arr[0] && !(a->arr[2] < a->arr[1]
			|| a->arr[3] < a->arr[2] || a->arr[4] < a->arr[3]))
		sa(a, print_list);
}
