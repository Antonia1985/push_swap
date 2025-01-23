#include "push_swap.h"

void print_error()
{
    ft_printf("Error\n");    
}

void print_sorted(t_stack_array *a)
{
    int i = 0;

    while(i < a->size)
    {
        ft_printf("%i\n", a->arr[i]);
        i++;
    }
}

void print_current (t_stack_array *a, t_stack_array *b)
{
    int i = 0;
    ft_printf("->A   ");
    while(i < a->size)
    {
        ft_printf("%i ", a->arr[i]);
        i++;
    }
    ft_printf("\n");
    ft_printf("->B   ");
    i = 0;
    while(i < b->size)
    {
        ft_printf("%i ", b->arr[i]);
        i++;
    }
     ft_printf("\n");
    
}

void l_print_sorted(t_stack_list *a)
{
    if (!a || !a->top) // Check if the stack or top node is NULL
    {
        ft_printf("Stack is empty or uninitialized.\n");
        return;
    }
    t_node *current =  a->top;
    while(current != NULL)
    {
        ft_printf("%i\n", current->value);
        //if(current->next == NULL)
            //break;
        current = current->next;
    }
}