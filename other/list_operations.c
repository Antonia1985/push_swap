#include "push_swap_initial.h"

// Static variable to hold the count of operations
static int l_operation_count = 0;
// Function to increment the counter
void l_increment_operation_count() {
    l_operation_count++;
}
int l_get_operation_count() {
    return l_operation_count;
}

static void swap(t_stack_list * stack)
{
    if (stack->size > 1)
    {
        t_node *first = stack->top;
        t_node *second = first->next;

        first->next = second->next;
        first->prev = first;

        second->next = first;
        second->prev = NULL;

        stack->top = second;
    }
    else
    {
        printf("cannot swap, stack->size < 2\n");
    }
}

void lsa(t_stack_list * stack)
{  
    swap(stack);
    l_increment_operation_count();
    ft_printf("sa\n");
}

void lsb(t_stack_list * stack)
{
    swap(stack);
    l_increment_operation_count();
    ft_printf("sb\n");
}

void lss(t_stack_list * stack_a, t_stack_list * stack_b)
{    
    swap(stack_a);
    swap(stack_b);
    l_increment_operation_count();
    ft_printf("ss\n");   
}

static void pop_push(t_stack_list * stack_to_push_in, t_stack_list * stack_to_pop)
{
    if (stack_to_pop->size > 0)
    {        
        int value = pop(stack_to_pop, 0);        
        push(stack_to_push_in, value, 0);
    }
    else
    {
        printf("cannot pop_push, stack_to_pop->size <= 0 \n");
    }
}

void lpa(t_stack_list * stack_to_push_in, t_stack_list * stack_to_pop)
{    
    pop_push(stack_to_push_in, stack_to_pop);
    l_increment_operation_count();
    ft_printf("pa\n");   
}

void lpb(t_stack_list * stack_to_push_in, t_stack_list * stack_to_pop)
{    
    pop_push(stack_to_push_in, stack_to_pop);
    l_increment_operation_count();
    ft_printf("pb\n");    
}

static void rotate(t_stack_list * stack)
{
    if (stack->size > 1)
    {
        t_node *old_top  = stack->top;
        stack->top = old_top->next;
        stack->top->prev = NULL;

        old_top->prev = stack->bottom;
        old_top-> next = NULL;

        stack->bottom->next = old_top;
        stack->bottom = old_top;
    }
    else
    {
        printf("cannot rotate, stack->size <= 1 \n");
    }
    
}

void lra(t_stack_list * stack)
{  
    rotate(stack);
    l_increment_operation_count();
    ft_printf("ra\n");   
}

void lrb(t_stack_list * stack)
{  
    rotate(stack);
    l_increment_operation_count();
    ft_printf("rb\n");
}

void lrr(t_stack_list * stack_a, t_stack_list * stack_b)
{  
    rotate(stack_a);
    rotate(stack_b);
    l_increment_operation_count();
    ft_printf("rr\n");
  
}

static void reverse_rotate(t_stack_list * stack)
{  
    if (stack->size > 1)
    {
        t_node *old_bottom = stack->bottom;

        stack->bottom = stack->bottom->prev;
        stack->bottom->next = NULL;

        stack->top->prev = old_bottom;

        old_bottom->prev = NULL;
        old_bottom->next = stack->top;

        stack->top = old_bottom;
    }
    else
    {
        printf("cannot reverse_rotate, stack->size <= 1 \n");
    }
}

void lrra(t_stack_list * stack)
{  
    reverse_rotate(stack);
    l_increment_operation_count();
    ft_printf("rra\n");
}

void lrrb(t_stack_list * stack)
{  
    reverse_rotate(stack);
    l_increment_operation_count();
    ft_printf("rrb\n");
}

void lrrr(t_stack_list * stack_a, t_stack_list * stack_b)
{  
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    l_increment_operation_count();
    ft_printf("rrr\n");
}
