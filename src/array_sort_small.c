#include "push_swap.h"

void    sort_2(t_stack_array *a)
{    
    if (a->arr[1] < a->arr[0])
    {
        sa(a);
    }    
}

void    sort_2_desc(t_stack_array *a)
{    
    if (a->arr[1] > a->arr[0])
    {
        sa(a);
    }    
}

void    sort_3(t_stack_array *a)
{
    
    if (a->arr[1] < a->arr[0])
    {
        sa(a);
    }

    if (a->arr[1] > a->arr[2])
    {
        if(a->arr[2] > a->arr[0])
        {
            rra(a);
            sa(a);
        }
        else
        {
            rra(a);
        }
    }  
}

void    sort_3_desc(t_stack_array *a)
{
    if (a->arr[1] > a->arr[0])
    {
        sa(a);
    }
    if (a->arr[2] > a->arr[0])
    {
       rra(a);
    }
    else if(a->arr[2] > a->arr[1])
    {
        rra(a);
        sa(a);
    }
}

void    sort_4(t_stack_array *a, t_stack_array *b)
{  
    if (a->arr[1] < a->arr[0])
    {
        sa(a);
    }
    if (a->arr[2] < a->arr[1])
    {
        pb(b, a);
        pb(b, a);
        pb(b, a); 

        if(b->arr[0] < b->arr[2])
        {
            rb(b);
        }
        else 
        {
            sb(b);
        }
        pa(a, b);
        pa(a, b);
        pa(a, b);  
    }
    if(a->arr[3] < a->arr[0])
    {
        rra(a);
    }
    if(a->arr[3] < a->arr[1])
    {
        rra(a);
        sa(a);
    }
    if(a->arr[3] < a->arr[2])
    {
        pb(b, a);
        pb(b, a);
        sa(a);
        pa(a, b);
        pa(a, b);
    }
}

void    sort_5(t_stack_array *a, t_stack_array *b)
{
    if (a->arr[2] < a->arr[1] || a->arr[3] < a->arr[2] || a->arr[4] < a->arr[3])
    {          
        pb(b, a);
        pb(b, a);
        
        sort_3(a);
       
        if(b->arr[1] < a->arr[0])//ordinary case 1
        {
            if(b->arr[0] < a->arr[0]) //best case 1
            {
                pa(a, b);
                pa(a, b);
            }
            else if(b->arr[0] < a->arr[1])
            {
                pa(a, b);
                sa(a);
                pa(a, b);
            }
            else if(b->arr[0] < a->arr[2])
            {
                rra(a);
                pa(a, b);
                ra(a);
                ra(a);
                pa(a, b);
            }
            else if(b->arr[0] > a->arr[2])
            {
                pa(a, b);
                ra(a);
                pa(a, b);
            }            
        }
        else if(b->arr[1]< a->arr[1])//ordinary case 2
        {
            if(b->arr[0] < a->arr[1])
            {
                pa(a, b);
                sa(a);
                pa(a, b);
                sa(a);
            }
            else if(b->arr[0] < a->arr[2])
            {
                rra(a);
                pa(a, b);
                ra(a);
                ra(a);
                pa(a, b);
                sa(a);
            }
            else if(b->arr[0] > a->arr[2])
            {
                pa(a, b);
                ra(a);
                pa(a, b);
                sa(a);
            }
        }
        else if(b->arr[1] < a->arr[2]) //ordinary case 3
        {
            if(b->arr[0] < a->arr[2])
            {
                rra(a);
                pa(a, b);
                pa(a, b);
                rra(a);
                rra(a);
            }
            else if(b->arr[0] > a->arr[2])
            {
                pa(a, b);
                ra(a);                    
                ra(a);
                ra(a);
                pa(a, b);
                rra(a);
                rra(a);
            }

        }
        else if(b->arr[1] > a->arr[2])
        {
            pa(a, b);
            pa(a, b);
            ra(a);
            ra(a);
        }           
    }
    else if(a->arr[1] < a->arr[0] && !( a->arr[2] < a->arr[1] || a->arr[3] < a->arr[2] || a->arr[4] < a->arr[3]))
    {
        sa(a); 
    }
}