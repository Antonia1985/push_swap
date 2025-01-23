#include "push_swap_initial.h"

t_node *bottom_node(t_stack_list *stack)
{   
    t_node *current = stack->top;
    while(current->next != NULL)
    {
        current = current->next;
    }
    return current;
}

void list_sort_big(t_stack_list *a, t_stack_list *b)
{
    lpb(b, a);
    lpb(b, a);

    ///checks?
    if (!b || !b->top) {
        printf("Error: Stack b is empty or uninitialized.\n");
        return;
    }
    if (!a->top) {
    printf("Stack a is empty. Exiting loop.\n");
    }
    ////

    if(b->top->value < b->top->next->value)
    {
        lsb(b);
    }
    
    t_node *current = a->top;
    t_node *bottom_b = bottom_node(b);
    t_node *bottom_a = bottom_node(a);

    int i =0;
    int sorted_num_counter = 0;
    //less than 3 operations loop
    while ((current && current->next && b->top)&& i < a-> size) 
    {
        ft_printf("entered in BIG LOOP\n");
        bottom_b = bottom_node(b); // Ensure bottom_b is updated at the start of each iteration
        bottom_a = bottom_node(a);

        if (current->value > b->top->value)
        {
            ft_printf("entered in 1st case\n");
            ft_printf(" a: %i > b: %i\n", current->value, b->top->value);
            lpb(b, a);
            current = a->top;
            sorted_num_counter++;
        }    
        else if (current->value < bottom_b->value)
        {
            ft_printf("entered in 2nd case\n");
            ft_printf(" a: %i < b: %i\n", current->value, bottom_b->value);
            lpb(b, a);
            lrb(b);
            bottom_b = bottom_node(b); // Update bottom after modifying b
            current = a->top;  
            sorted_num_counter++;
        }        
        else if(current->value > b->top->next->value)
        {
            ft_printf("entered in 3rd case\n");
            lpb(b, a);            
            lsb(b);
            current = a->top;  
            sorted_num_counter++;
        }
        else if(bottom_a->value > b->top->value)
        {
            ft_printf("entered in 4th case\n");
            lrra(a);
            lpb(b, a);
            bottom_a = bottom_node(a);
            sorted_num_counter++;
        }
        else if(bottom_a->value < bottom_b->value)
        {   
            ft_printf("entered in 5th case\n");
            lrra(a);
            lpb(b, a);
            lrb(b);
            bottom_a = bottom_node(a);
            bottom_b = bottom_node(b);
            sorted_num_counter++;
        }
        else if(current->next->value > b->top->next->value)
        {
            ft_printf("entered in 6th case\n");
            lsa(a);
            lpb(b, a);
            lsb(b);
            current = a->top;
            sorted_num_counter++;
        }
        i++;
        /*if (!current) break; // Exit if a is empty
        if(current)
            current = current->next;
        else
            current = NULL;
            */
        
    }
    /*
    current = a->top;
    bottom_a = bottom_node(a);
    bottom_b = bottom_node(b);
    i=0;
    while ((current && current->next && b->top)&& i < a-> size) 
    {
        int b_size = b->size;
        
        
        i++;         
    }
   
   if (a->size - sorted_num_counter == 3)
    {
        sort_3(a);
    }*/
}
