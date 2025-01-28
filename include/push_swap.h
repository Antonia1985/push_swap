/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:22:36 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/25 13:22:51 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_array
{
	int	*arr;
	int	size;
	int	capacity;
}		t_stack_array;

int		main(int argc, char **argv);

void	print_error(void);
void	fill_print_list(char **print_list, char *operation_name);
void	print_the_list(char **print_list);

int		check_integer_limits(char *num);
int		check_if_non_digit(char *num);
int		check_duplicate(char *num, char **numbers, size_t num_index);
int		validate_arguments(char **arg_array);

int		is_argument_an_array(char *argument_str);
int		stack_array_size(char **numbers);
int		find_max_pos(t_stack_array *b);
void	sort_array(int *arr, int size);
void	move_max_to_top(t_stack_array *b, int max_pos, char **print_list);

void	*initiallize_stack(int size);
void	fill_stack_from_args(void *stack, int nums_size, char **numbers);
void	free_stacks(t_stack_array *stack_a, t_stack_array *stack_b);

void	start_sorting(void *stack_a, void *stack_b, int nums_size, char **print_list);
void	sa(t_stack_array *stack, char **print_list);
void	sb(t_stack_array *stack, char **print_list);
void	ss(t_stack_array *stack_a, t_stack_array *stack_b, char **print_list);
void	push(void *stack, int value);
int		pop(void *stack);
void	pa(t_stack_array *stack_to_push, t_stack_array *stack_to_pop, char **print_list);
void	pb(t_stack_array *stack_to_push, t_stack_array *stack_to_pop, char **print_list);
void	ra(t_stack_array *stack, char **print_list);
void	rb(t_stack_array *stack, char **print_list);
void	rr(t_stack_array *stack_a, t_stack_array *stack_b, char **print_list);
void	rra(t_stack_array *stack, char **print_list);
void	rrb(t_stack_array *stack, char **print_list);
void	rrr(t_stack_array *stack_a, t_stack_array *stack_b, char **print_list);

void	rra_2(t_stack_array *a, char **print_list);
void	pb_2(t_stack_array *b, t_stack_array *a, char **print_list);
void	pa_2(t_stack_array *a, t_stack_array *b, char **print_list);
void	pb_3(t_stack_array *b, t_stack_array *a, char **print_list);
void	pa_3(t_stack_array *a, t_stack_array *b, char **print_list);
void	ra_2(t_stack_array *a, char **print_list);
void	ra_3(t_stack_array *a, char **print_list);
void	rb_2(t_stack_array *b, char **print_list);
void	rb_3(t_stack_array *b, char **print_list);

void	sort_2(t_stack_array *a, char **print_list);
void	sort_3(t_stack_array *a, char **print_list);
void	sort_3_desc(t_stack_array *a, char **print_list);
void	sort_4(t_stack_array *a, t_stack_array *b, char **print_list);
void	sort_5(t_stack_array *a, t_stack_array *b, char **print_list);
void	array_sort_big(t_stack_array *a, t_stack_array *b, char **print_list);

#endif
