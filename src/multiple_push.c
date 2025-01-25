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

void	pb_2(t_stack_array *b, t_stack_array *a)
{
	pb(b, a);
	pb(b, a);
}

void	pa_2(t_stack_array *a, t_stack_array *b)
{
	pa(a, b);
	pa(a, b);
}

void	pb_3(t_stack_array *b, t_stack_array *a)
{
	pb(b, a);
	pb(b, a);
	pb(b, a);
}

void	pa_3(t_stack_array *a, t_stack_array *b)
{
	pa(a, b);
	pa(a, b);
	pa(a, b);
}
