#include "push_swap_initial.h"

int find_min_pos(t_stack_array *a, int nums_size) 
{
    int min = a->arr[0];
    int min_position = 0;
    int i = 1;  

    while (i < nums_size) 
    {        
        if (a->arr[i] < min) 
        {
            min = a->arr[i];
            min_position = i;
        }        
        i++;
    }   
    return min_position;
}

int find_max_pos(t_stack_array *a, int nums_size) 
{
    int max = a->arr[0];
    int max_position = 0;
    int i = 1;

    while (i < nums_size) 
    {        
        if (a->arr[i] > max) 
        {
            max = a->arr[i];
            max_position = i;
        }        
        i++;
    }   
    return max_position;
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

int find_max(t_stack_array *a, int nums_size) 
{
    int max = a->arr[0];    
    int i = 1;

    while (i < nums_size) 
    {
        if (a->arr[i] > max) 
        {
            max = a->arr[i];
        }
        i++;
    }   
    return max;
}


void    array_insertion_sort(t_stack_array *a, t_stack_array *b)
{
    int half_size;
    int min_position, min;
    int max_position, max;        
    int i, c, case1, case2, case3, case3a;//, j;
    case1 = 0;
    case2 = 0;
    case3 = 0;
    case3a =0;
   c = 0;
    while (a->size > 1)
    {
        min_position = find_min_pos(a, a->size);
        max_position = find_max_pos(a, a->size);
        min = find_min(a, a->size);
        max = find_max(a, a->size);

        half_size = a->size / 2;
    //1st case: min and max found on the first half
        if(min_position <= half_size && max_position <= half_size)
        {
            case1++;
            ft_printf("ITERATION: %i - 1st case: min and max found on the first half\n", c+1);
            ft_printf("a->SIZE = %i\n min = %i, position = %i \n max = %i position = %i\n", a->size, min, min_position, max, max_position);
            
            //rotaste until min or max go to top
            i = position_rotated_to_top_of_stack_a(min_position, max_position, a);
            // 1st case, max found first
            if(i == max_position)
            {
                //push and rotate
                push_and_rotate_stack_b(b, a);
               
                //find min
                min_position = find_min_pos(a, a->size);
                rotate_to_top_stack_a(min_position, a);
                pb(b, a);
            }
            // 2nd case, min found first
            else if (i == min_position)
            {
                //just push the minimum
                pb(b, a);
                //find max
                max_position = find_max_pos(a, a->size);
                rotate_to_top_stack_a(max_position, a);
                push_and_rotate_stack_b(b, a);
            }

        }
    //2nd case: min and max found on the second half
        else if(min_position > half_size && max_position > half_size)
        {
            case2++;
            ft_printf("ITERATION: %i - 2nd case: min and max found on the second half\n", c+1);
            ft_printf("a->SIZE = %i\n min = %i, position = %i \n max = %i position = %i\n", a->size, min, min_position, max, max_position);
            
            i = position_reverse_rot_to_top_of_stack_a( min_position, max_position, a);
            // 1st case, max found first
            if(i == max_position)
            {
                //push max and rotate b
                push_and_rotate_stack_b(b,a);
                
                //find min
                min_position = find_min_pos(a, a->size);                
                reverse_rotate_to_top_stack_a(min_position, a);
                pb(b, a);

            }
            // 2nd case, min found first
            else if (i == min_position)
            {
                // push the minimum
                pb(b, a);
                //find max
                max_position = find_max_pos(a, a->size);
                reverse_rotate_to_top_stack_a(max_position, a);
                push_and_rotate_stack_b(b, a);                
            }
        }
    //3rd case: min and max found on different halfs
        else
        {   
            case3++;
            
            ft_printf("ITERATION: %i - 3rd case: min and max found on different halfs\n", c+1);
            ft_printf("a->SIZE = %i\n min = %i, position = %i \n max = %i position = %i\n", a->size, min, min_position, max, max_position);
            i = position_rotated_to_top_of_stack_a(min_position, max_position, a);
            //min found first - so in first half
            if (i == min_position)
            {
                pb(b, a);

                // find the new max position
                max_position = find_max_pos(a, a->size);
                ft_printf("new max_pos = %i\n", max_position);

                //if new max position is in first half now
                if (max_position >= a->size/2)
                {
                    case3a++;
                    rotate_to_top_stack_a(max_position, a);
                    push_and_rotate_stack_b(b, a);
                }
                else // if is still at the second half
                {
                    reverse_rotate_to_top_stack_a(max_position, a);
                    push_and_rotate_stack_b(b,a);                    
                }
                
            }
            //max found first - so in first half
            else //if (i == max_position)
            {
                push_and_rotate_stack_b(b, a);

                min_position = find_min_pos(a, a->size);
                ft_printf("new min_pos = %i\n", min_position);

                // calculate if the new min position is in first half or second half                
                if (min_position <= a->size/2) //min position is in first half now
                {
                    case3a++;
                    rotate_to_top_stack_a(min_position, a);
                    pb(b, a);
                }
                else //min_position is still in the second half
                {
                    reverse_rotate_to_top_stack_a(min_position, a);                  
                    pb(b,a);
                }
            }
            ft_printf("the stacks after operations in 3rd CASE\n");
            
        }
        c++;
        print_current(a, b);
    }

    while (b->size > 0)
    {
        pa(a, b);
    }

    min_position = find_min_pos(a, a->size);
    rotate_to_top_stack_a(min_position, a);

   ft_printf("1st case= %i \n2nd case= %i \n3rd case= %i \n3a case= %i \n ", case1, case2, case3, case3a);    
    
}
