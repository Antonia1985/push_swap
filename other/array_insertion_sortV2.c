#include "push_swap_initial.h"

int find_min_position(t_stack_array *a, int nums_size) 
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

int find_min(t_stack_array *a, int nums_size) 
{
    int min = a->arr[0];    
    int i = 1;

    while (i < nums_size) 
    {
        if (a->arr[i] < min) 
        {
            min = a->arr[i];          
        }
        i++;
    }   
    return min;
}

void  populate_chunks_s(int *chunk_sizes[divisions], int nums_size, int divisions)
{
    if (nums_size > 50 && nums_size < 100)
    {          
        int i = 0;
        chunk_sizes[0] = divisions + (nums_size % divisions);
        while (divisions > i )
        {
            chunk_sizes[i] = nums_size / divisions;
            i++;
        }
    }
}

void  populate_the_chunk(int * chunk1[size], t_stack_array *a)
{
    while (i < size)
    {
        chunk1[size] = find_min(a, a->size);
        i++;
    }
}

void    array_insertion_sort(t_stack_array *a, t_stack_array *b)
{
    int half_size;
    int min;    
    int i,k, divisions;
    int divisions = 3;
    int how_many_numbers_in_chunk = a->size / divisions;
    k =0;
    
    while (k < divisions)
    {
        while (chunk_sizes[k] > 0)
        {    
            //1st time  
            
            min_chunk = find_min(a, a->size);
            max_chunk = min + how_many_numbers_in_chunk; // + a->size % divisions

            int positions[]
            
            half_size = a->size / 2;
            int * chunk_sizes = 
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
        k++;
    }
    
    while (b->size > 0)
    {
        pa(a, b);
    }
}