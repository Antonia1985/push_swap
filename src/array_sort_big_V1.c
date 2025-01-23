#include "push_swap.h"

void    sort_array(int *arr, int size)
{
    int temp;
    int i;
    int j;

    i = 0;
    while (i < size-1)
    {
        j = 0;
        while(j < size - i - 1)
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void create_chunks(t_stack_array *a, int num_chunks, int *chunk_bounds) 
{
    int i;
    
    i = 0;
    int *sorted_arr = malloc(sizeof(int) * a->size);
    if (!sorted_arr) 
    {
        ft_printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }    
    while (i < a->size) 
    {
        sorted_arr[i] = a->arr[i];
        i++;
    }

    sort_array(sorted_arr, a->size);
    
    i = 0;
    int chunk_size = a->size / num_chunks;

    while  (i < num_chunks)
    {
        chunk_bounds[2 * i] = sorted_arr[i * chunk_size];

        if (i == num_chunks - 1)
        {
            chunk_bounds[2 * i + 1] = sorted_arr[a->size - 1];  
        }
        else 
        {
            chunk_bounds[2 * i + 1] = sorted_arr[(i + 1) * chunk_size - 1];
        }
        i++;
    }
    free(sorted_arr);
}


/*int define_chunk_size(const int init_array_size, int num_chunks, int current_chunk)
{
    int chunk_size = init_array_size / num_chunks;
    int remaining = init_array_size % num_chunks;
    if (current_chunk == num_chunks - 1)
    {
        chunk_size = chunk_size + remaining;
    }
    return chunk_size;
}*/

static int count_elements_in_range(t_stack_array *a, int min_val, int max_val)
{
    int i;
    int count = 0;

    i = 0;
    while (i < a->size)
    {
        if (a->arr[i] >= min_val && a->arr[i] <= max_val)
            count++;
        i++;
    }
    return (count);
}

//current best version 
void push_values_of_each_chunk(t_stack_array *a, t_stack_array *b, int min_val, int max_val) 
{
    int rr_counter = 0;
    int pushed = 0;

    int to_push = count_elements_in_range(a, min_val, max_val);    
    while (pushed < to_push && a->size > 0)
    {
        if (a->arr[0] >= min_val && a->arr[0] <= max_val)
        {
            pb(b, a);

            if (b->arr[0] < (min_val + max_val) / 2 && b->size > 1)
            rb(b);
          
            pushed++;
        } 
        else if (a->arr[a->size - 1] >= min_val && a->arr[a->size - 1] <= max_val)
        {
            rra(a);  // Rotate in reverse to bring back to the front
            pb(b, a);
            if (b->arr[0] < (min_val + max_val) / 2 && b->size > 1)
            rb(b);

            pushed++;
        }
        else
        {
            ra(a);
        }               
    }
    ft_printf("rr_counter : %i\n",  rr_counter);
}

int find_max_pos(t_stack_array *b) 
{
    int max = b->arr[0];
    int max_position = 0;
    int i = 1;
    if (b->size == 0)
        return (0);
    while (i < b->size) 
    {        
        if (b->arr[i] > max) 
        {
            max = b->arr[i];
            max_position = i;
        }        
        i++;
    }   
    return max_position;
}

void sort_stack_b_descending_and_push(t_stack_array *b, t_stack_array *a)
{
    int i;
    int max_pos;
    int half_size;

    while (b->size > 0)
    {
        
        if (b->size == 3)
        {
            sort_3_desc(b);
            while (b->size)
            pa(a,b);

            break;
        }
        max_pos = find_max_pos(b);
        half_size = b->size / 2;

        if(max_pos <= half_size )
        {
            i = 0;            
            while(i < max_pos)
            {  
                rb(b);
                i++;
            }
        }
        else
        {
            i = b->size;           
            while(i > max_pos)
            {   
                rrb(b);
                i--;
            }
             
        }        
        pa(a, b);                    
    }
}

void array_sort_big(t_stack_array *a, t_stack_array *b) 
{
    int i = 0;
    int num_chunks = 11;
    int *chunk_bounds = malloc(sizeof(int) * 2 * num_chunks);
   // const int init_array_size = a->size;
    if (!chunk_bounds) 
    {
        ft_printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    create_chunks(a, num_chunks, chunk_bounds);

    while (i < num_chunks)
    {
        ft_printf("Entered in -- while (i < num_chunks)-- i: %i \n", i);
        int min_val = chunk_bounds[i*2];
        int max_val = chunk_bounds[(i*2) +1];       
       
        push_values_of_each_chunk(a,b, min_val, max_val);
       
        i++;
    }
    sort_stack_b_descending_and_push(b,a);
    free(chunk_bounds);
}