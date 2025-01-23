#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_array {
    int *arr;
    int size;
    int capacity;
} t_stack_array;

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack_list {
    t_node *top;
    t_node *bottom;
    int size;
} t_stack_list;

int     main(int argc, char **argv);
int     ft_printf(const char *format, ...);
int     ft_atoi(const char *nptr);
long    ft_atol(const char *nptr);
char    **ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

void    print_error();
void    print_sorted(t_stack_array *a);
void    l_print_sorted(t_stack_list *a);
void    print_current (t_stack_array *a, t_stack_array *b);

int     check_integer_limits(char *num);
int     check_if_non_digit(char *num);
int     check_duplicate(char *num, char **numbers, size_t num_index);
int     is_argument_an_array(char * argument_str);

int     numb_stack_size(char **numbers);

void    *initiallize_stack(int size, int is_array);
void    push(void *stack, int value, int is_array);
int     pop(void *stack, int is_array);
void    fill_stack_from_args(void *stack, int nums_size, char **numbers, int is_array);

void    start_sorting(void *stack_a, void *stack_b, int nums_size);
void    sa(t_stack_array * stack);
void    sb(t_stack_array * stack);
void    ss(t_stack_array * stack_a, t_stack_array * stack_b);
void    pa(t_stack_array * stack_to_push, t_stack_array * stack_to_pop);
void    pb(t_stack_array * stack_to_push, t_stack_array * stack_to_pop);
void    ra(t_stack_array * stack);
void    rb(t_stack_array * stack);
void    rr(t_stack_array * stack_a, t_stack_array * stack_b);
void    rra(t_stack_array * stack);
void    rrb(t_stack_array * stack);
void    rrr(t_stack_array * stack_a, t_stack_array * stack_b);

/*void    lsa(t_stack_list * stack);
void    lsb(t_stack_list * stack);
void    lss(t_stack_list * stack_a, t_stack_list * stack_b);
void    lpa(t_stack_list * stack_to_push, t_stack_list * stack_to_pop);
void    lpb(t_stack_list * stack_to_push, t_stack_list * stack_to_pop);
void    lra(t_stack_list * stack);
void    lrb(t_stack_list * stack);
void    lrr(t_stack_list * stack_a, t_stack_list * stack_b);
void    lrra(t_stack_list * stack);
void    lrrb(t_stack_list * stack);
void    lrrr(t_stack_list * stack_a, t_stack_list * stack_b);*/

void    sort_2(t_stack_array *a);
void    sort_3(t_stack_array *a);
void    sort_3_desc(t_stack_array *a);
void    sort_4(t_stack_array *a, t_stack_array *b);
void    sort_5(t_stack_array *a, t_stack_array *b);

void array_sort_big(t_stack_array *a, t_stack_array *b);
//void    array_insertion_sort(t_stack_array *a, t_stack_array *b);
//void    list_insertion_sort(t_stack_list *a, t_stack_list *b, int nums_size);
//void    list_sort_big(t_stack_list *a, t_stack_list *b);

int     get_operation_count();
int     l_get_operation_count();

/*void    push_and_rotate_stack_b(t_stack_array *b, t_stack_array *a);
void    rotate_to_top_stack_a(int position, t_stack_array *a);
void    reverse_rotate_to_top_stack_a(int position, t_stack_array *a);
int     position_rotated_to_top_of_stack_a(int min_position, int max_position, t_stack_array *a);
int     position_reverse_rot_to_top_of_stack_a(int min_position, int max_position, t_stack_array *a);*/

#endif