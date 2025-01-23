#include "push_swap.h"
#include <stdio.h>

// Static variable to hold the count of operations
static int operation_count = 0;
// Function to increment the counter
void increment_operation_count() {
    operation_count++;
}
int get_operation_count() {
    return operation_count;
}

static void swap(t_stack_array * stack)
{
    if (stack->size > 1)
    {
        int swap = stack->arr[0];
        stack->arr[0] = stack->arr[1];
        stack->arr[1] = swap;
    }
    else
    {
        printf("cannot swap, stack->size < 1 \n");
    }
}

void sa(t_stack_array * stack)
{  
    swap(stack);
    increment_operation_count();
    ft_printf("sa\n");
}

void sb(t_stack_array * stack)
{
    swap(stack);
    increment_operation_count();
    ft_printf("sb\n");
}

void ss(t_stack_array * stack_a, t_stack_array * stack_b)
{    
    swap(stack_a);
    swap(stack_b);
    increment_operation_count();
    ft_printf("ss\n");   
}

static void pop_push(t_stack_array * stack_to_push_in, t_stack_array * stack_to_pop)
{
    //printf("entered pop_push()\n");
    //printf("a->size = %i\n", stack_to_pop->size);
    if (stack_to_pop->size > 0)
    {
        
        int value = pop(stack_to_pop, 1);        
        push(stack_to_push_in, value, 1);
    }
    else
    {
        printf("cannot pop_push, stack_to_pop->size <= 0 \n");
    }
}

void pa(t_stack_array * stack_to_push_in, t_stack_array * stack_to_pop)
{    
    pop_push(stack_to_push_in, stack_to_pop);
    increment_operation_count();
    ft_printf("pa\n");   
}

void pb(t_stack_array * stack_to_push_in, t_stack_array * stack_to_pop)
{    
    pop_push(stack_to_push_in, stack_to_pop);
    increment_operation_count();
    ft_printf("pb\n");    
}

static void rotate(t_stack_array * stack)
{
    if (stack->size > 1)
    {
        int i;
        int swap = stack->arr[0];
        i = 0;
        while( i < stack->size)
        {
            stack->arr[i] = stack->arr[i+1];
            i++;
        }
        stack->arr[stack->size - 1] = swap;       
    }
    else
    {
        printf("cannot rotate, stack->size <= 1 \n");
    }
    
}

void ra(t_stack_array * stack)
{  
    rotate(stack);
    increment_operation_count();
    ft_printf("ra\n");
   
}

void rb(t_stack_array * stack)
{  
    rotate(stack);
    increment_operation_count();
    ft_printf("rb\n");
}

void rr(t_stack_array * stack_a, t_stack_array * stack_b)
{  
    rotate(stack_a);
    rotate(stack_b);
    increment_operation_count();
    ft_printf("rr\n");
  
}

static void reverse_rotate(t_stack_array * stack)
{  
    if (stack->size > 1)
    {
        int i;
        int swap = stack->arr[stack->size - 1];
        i = stack->size - 1;
        while( i > 0)
        {
            stack->arr[i] = stack->arr[i-1];
            i--;
        }
        stack->arr[0] = swap;        
    }
    else
    {
        printf("cannot reverse_rotate, stack->size <= 1 \n");
    }
}

void rra(t_stack_array * stack)
{  
    reverse_rotate(stack);
    increment_operation_count();
    ft_printf("rra\n");
}

void rrb(t_stack_array * stack)
{  
    reverse_rotate(stack);
    increment_operation_count();
    ft_printf("rrb\n");
}

void rrr(t_stack_array * stack_a, t_stack_array * stack_b)
{  
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    increment_operation_count();
    ft_printf("rrr\n");
}
