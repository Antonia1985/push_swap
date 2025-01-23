#include "push_swap_initial.h"

int find_min(t_stack_array *a, int nums_size) 
{
    int min = a->arr[0];
    int min_position = 0;
    int i = 1;

    while (i < nums_size) 
    {
        if (a->arr[i] < min) {
            min = a->arr[i];
            min_position = i;
        }
        i++;
    }
   
    return min_position;
}

void    array_insertion_sort(t_stack_array *a, t_stack_array *b)
{
    int half_size;
    int min_position;    
    int i;

    while (a->size > 0)
    {
        min_position = find_min(a, a->size);
        half_size = a->size / 2;

        if(min_position <= half_size)
        {
            i = 0;
            while(i < min_position)
            {   
                ra(a);
                i++;
            }           
        }
        else
        {
            i = a->size;
            while( i > min_position)
            {   
                rra(a);
                i--;
            }
        }
        pb(b, a);
    }
    while (b->size > 0)
    {
        pa(a, b);
    }
}