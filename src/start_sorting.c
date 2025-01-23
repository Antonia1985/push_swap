#include "push_swap.h"

void    start_sorting(void *stack_a, void *stack_b, int nums_size)
{   
    //if(nums_size >= 2)// && nums_size <= 100)
    //{
        t_stack_array *a = (t_stack_array *)stack_a;
        t_stack_array *b = (t_stack_array *)stack_b;

        if (nums_size == 2)
        {
            sort_2(a); 
        }
        else if (nums_size == 3)
        {
            sort_3(a);
        }
        else if (nums_size == 4)
        {
            sort_4(a, b);        
        }
        else if (nums_size == 5)
        {
            sort_5(a, b);        
        }
        else if (nums_size > 5)// && nums_size <= 100)
        {
            array_sort_big(a, b);            
        }
    //}    
    /*else 
    {      
        t_stack_list *a = (t_stack_list *)stack_a;
        t_stack_list *b = (t_stack_list *)stack_b;
        if (nums_size > 5 && nums_size <= 100)
        {   
            list_sort_big(a, b);
        }
        else
        {
            ft_printf("Not implemented yet for more than 100 numbers");
            //list_radix_sort(a, b, nums_size);
        }
    }*/ 
}
