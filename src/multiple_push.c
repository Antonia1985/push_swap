/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:42:39 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 19:42:41 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pb_2(t_stack_array *b, t_stack_array *a, char **print_list)
{
	pb(b, a, print_list);
	pb(b, a, print_list);
}

void	pa_2(t_stack_array *a, t_stack_array *b, char **print_list)
{
	pa(a, b, print_list);
	pa(a, b, print_list);
}

void	pb_3(t_stack_array *b, t_stack_array *a, char **print_list)
{
	pb(b, a, print_list);
	pb(b, a, print_list);
	pb(b, a, print_list);
}

void	pa_3(t_stack_array *a, t_stack_array *b, char **print_list)
{
	pa(a, b, print_list);
	pa(a, b, print_list);
	pa(a, b, print_list);
}
