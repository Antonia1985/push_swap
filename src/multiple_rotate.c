/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:42:03 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 19:42:06 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ra_2(t_stack_array *a, char **print_list)
{
	ra(a, print_list);
	ra(a, print_list);
}

void	ra_3(t_stack_array *a, char **print_list)
{
	ra(a, print_list);
	ra(a, print_list);
	ra(a, print_list);
}

void	rb_2(t_stack_array *b, char **print_list)
{
	rb(b, print_list);
	rb(b, print_list);
}

void	rb_3(t_stack_array *b, char **print_list)
{
	rb(b, print_list);
	rb(b, print_list);
	rb(b, print_list);
}
