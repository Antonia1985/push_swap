#include "push_swap.h"

int validate_arguments(char **arg_array) 
{
    size_t i = 0;
    while (arg_array[i] != NULL) 
    {
        if (check_if_non_digit(arg_array[i]) != 1)
        {
            ft_printf("non digit\n");
            return 0;
        }
        if (check_integer_limits(arg_array[i]) != 1)
        {
            ft_printf("out of int limits\n");
            return 0;
        }
        if (check_duplicate(arg_array[i], arg_array, i) != 1)
        {
            ft_printf("duplicate\n");
            return 0;
        }
        // Argument passed all checks
        //ft_printf("Valid integer\n");
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    char **arg_array = &argv[1];
    if (argc == 1)
    return 0;

    if (is_argument_an_array(argv[1]))
    {
        arg_array = ft_split(argv[1], ' ');
        if (!arg_array)
        return(print_error(), 1);
    }
    
    if (!validate_arguments(arg_array)) 
    return(print_error(), 1);

    int nums_size;
    nums_size = numb_stack_size(arg_array);
    
    if (nums_size > 0)// && nums_size <= 100)
    {
        t_stack_array *stack_a;
        stack_a = initiallize_stack(nums_size, 1);        
        if (!stack_a)
        return (print_error(), 1);
        
        fill_stack_from_args(stack_a, nums_size, arg_array, 1);

        t_stack_array *stack_b;
        stack_b = initiallize_stack(nums_size, 1);
        if (!stack_b)
        return (print_error(), 1);

        if(nums_size >= 2)
        start_sorting(stack_a, stack_b, nums_size);
        
        print_sorted(stack_a); 
        printf("Total operations: %d\n", get_operation_count());

        free(stack_a->arr);
        free(stack_a);
        free(stack_b->arr);
        free(stack_b);
    }
    /*else
    {        
        t_stack_list    *stack_a;
        stack_a = initiallize_stack(nums_size, 0);
        if (!stack_a)
            return (print_error(), 1);
        fill_stack_from_args(stack_a, nums_size, arg_array, 0);
        
        t_stack_list    *stack_b;
        stack_b = initiallize_stack(nums_size, 0);
        if (!stack_b)
            return (print_error(), 1);

        //logic
        start_sorting(stack_a, stack_b, nums_size);
        //list_sort_big(stack_a, stack_b, nums_size);

        printf("stack A\n");
        l_print_sorted(stack_a);
        printf("stack B\n");
        l_print_sorted(stack_b);

        printf("Total operations: %d\n", l_get_operation_count());

        free(stack_a);
    }*/
    
    return (0);
}