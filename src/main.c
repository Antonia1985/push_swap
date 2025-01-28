/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:26:07 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 13:26:29 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_if_sorted(t_stack_array *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			i++;
		else
			break ;
	}
	if (i == a->size - 1)
		return (1);
	else
		return (0);
}

static char	**parse_arguments(int argc, char **argv)
{
	char	**arg_array;

	if (argc == 1)
		return (NULL);
	arg_array = &argv[1];
	if (is_argument_an_array(argv[1]))
	{
		arg_array = ft_split(argv[1], ' ');
		if (!arg_array)
			return (NULL);
	}
	return (arg_array);
}

static void	handle_sorting(char **arg_array, char **print_list)
{
	t_stack_array	*stack_a;
	t_stack_array	*stack_b;
	int				nums_size;

	nums_size = stack_array_size(arg_array);
	if (nums_size <= 1)
		return ;
	stack_a = initiallize_stack(nums_size);
	if (!stack_a)
		return (print_error());
	stack_b = initiallize_stack(nums_size);
	if (!stack_b)
	{
		free_stacks(stack_a, NULL);
		return (print_error());
	}
	fill_stack_from_args(stack_a, nums_size, arg_array);
	if (check_if_sorted(stack_a) == 0)
		start_sorting(stack_a, stack_b, nums_size, print_list);
	free_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**arg_array;
	
	arg_array = parse_arguments(argc, argv);
	if (!arg_array)
		return (0);
	if (!validate_arguments(arg_array))
		return (print_error(), 1);

	char	**print_list; 
	int nums_size = stack_array_size(arg_array);    
	print_list = (char **)malloc(sizeof(char*) * nums_size * 100);
	print_list[0] = NULL;
	if (!print_list)
		return (print_error(), 1);

	handle_sorting(arg_array, print_list);
	print_the_list(print_list);

	if (is_argument_an_array(argv[1]))
		free(arg_array);
	return (0);
}

/*int	main(int argc, char **argv)
{
	char			**arg_array;
	int				nums_size;
	t_stack_array	*stack_a;
	t_stack_array	*stack_b;

	arg_array = &argv[1];
	if (argc == 1)
		return (0);
	if (is_argument_an_array(argv[1]))
	{
		arg_array = ft_split(argv[1], ' ');
		if (!arg_array)
			return (print_error(), 1);
	}
	if (!validate_arguments(arg_array))
		return (print_error(), 1);
	nums_size = stack_array_size(arg_array);
	if (nums_size > 1)
	{
		stack_a = initiallize_stack(nums_size);
		if (!stack_a)
			return (print_error(), 1);
		stack_b = initiallize_stack(nums_size);
		if (!stack_b)
			return (print_error(), 1);
		fill_stack_from_args(stack_a, nums_size, arg_array);
		if (check_if_sorted(stack_a) == 0)
			start_sorting(stack_a, stack_b, nums_size);
		free_stacks(stack_a, stack_b);
	}
	return (0);
}*/