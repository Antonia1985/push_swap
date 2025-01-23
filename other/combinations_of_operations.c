#include "push_swap_initial.h"

void push_and_rotate_stack_b(t_stack_array *b, t_stack_array *a)
{
    pb(b, a);
    rb(b);
}

void    rotate_to_top_stack_a(int position, t_stack_array *a)
{
    int i = 0;
    while(i < position)
    {   
        ra(a);
        i++;
    }
}

void    reverse_rotate_to_top_stack_a(int position, t_stack_array *a)
{
    int i = a->size;
    while(i > position)
    {   
        rra(a);
        i--;
    }
}

int    position_rotated_to_top_of_stack_a(int min_position, int max_position, t_stack_array *a)
{
    int i = 0;
    while(i < min_position && i < max_position)
    {   
        ra(a);
        i++;
    }

    return i;
}

int     position_reverse_rot_to_top_of_stack_a(int min_position, int max_position, t_stack_array *a)
{
    int i = a->size;

    while(i > min_position && i > max_position)
    {   
        rra(a);
        i--;
    }
    i++;

    return i;
}
