/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:25:20 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 13:25:23 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_integer_limits(char *num)
{
	long	number;

	number = ft_atol(num);
	if (number < INT_MIN || number > INT_MAX)
	{
		return (0);
	}
	return (1);
}

int	check_if_non_digit(char *num)
{
	size_t	i;

	if (!num || *num == '\0')
		return (0);
	i = 0;
	if ((num[0] == '+' || num[0] == '-') && num[1] != '\0')
		i++;
	while (num[i])
	{
		if ((num[i] < '0') || (num[i] > '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_duplicate(char *num, char **numbers, size_t num_index)
{
	size_t	i;

	i = 0;
	while (i < num_index)
	{
		if (num[0] == '+')
			num = num + 1;
		if (numbers[i][0] == '+')
			numbers[i] = numbers[i] + 1;
		if (ft_strcmp(num, numbers[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_arguments(char **arg_array)
{
	size_t	i;

	i = 0;
	while (arg_array[i] != NULL)
	{
		if (check_if_non_digit(arg_array[i]) != 1)
			return (0);
		if (check_integer_limits(arg_array[i]) != 1)
			return (0);
		if (check_duplicate(arg_array[i], arg_array, i) != 1)
			return (0);
		i++;
	}
	return (1);
}
