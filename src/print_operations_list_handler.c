#include "libft.h"
#include "push_swap.h"  

void	fill_print_list(char **print_list, char *operation_name)
{
	if (!operation_name)
		return;

    int i = 0;
    while (print_list[i] != NULL)
        i++;   
    print_list[i] = ft_strdup(operation_name);
    if (print_list[i] == NULL) 
    {
        perror("Failed to allocate memory for string");
        exit(EXIT_FAILURE);
    }
    print_list[i + 1] = NULL;
}

void    the_list_after_single_change(char **print_list, char *replacement_str, int *i, int *j)
{
    print_list[*i] = ft_strdup(replacement_str);
    (*i)++;
    *j = *i;
    while(print_list[(*j)+1] != NULL)
    {
        print_list[*j] = print_list[(*j)+1];
        (*j)++;
    }
    print_list[*j] = NULL;
}

void    print_final_list(char **print_list)
{
    int i;

    i = 0;
    while(print_list[i] != NULL)
    {
        ft_printf("%s", print_list[i]);
        i++;
    }
    ft_printf(" operations= %i", i);
}

void print_the_list(char **print_list)
{
    int i;
    int j;

    i =0;
    j = 0;
    if (!print_list || !print_list[0] || !print_list[1])
        return;
    while(print_list[i+1] != NULL)
    {
        if ((ft_strncmp(print_list[i], "rra\n", 4) == 0 && ft_strncmp(print_list[i+1], "rrb\n",4) == 0) ||
                        (ft_strncmp(print_list[i], "rrb\n", 4) == 0 && ft_strncmp(print_list[i+1], "rra\n",4) == 0))
        the_list_after_single_change(print_list, "rrr\n", &i, &j);
        else if ((ft_strncmp(print_list[i], "ra\n", 3) == 0 && ft_strncmp(print_list[i+1], "rb\n", 3) == 0) ||
                        (ft_strncmp(print_list[i], "rb\n", 3) == 0 && ft_strncmp(print_list[i+1], "ra\n", 3) == 0))
        the_list_after_single_change(print_list, "rr\n", &i, &j);
        else if ((ft_strncmp(print_list[i], "sa\n", 3) == 0 && ft_strncmp(print_list[i+1], "sb\n", 3) == 0) ||
                        (ft_strncmp(print_list[i], "sb\n", 3) == 0 && ft_strncmp(print_list[i+1], "sa\n", 3) == 0))
        the_list_after_single_change(print_list, "ss\n", &i, &j);      
        i++;
    }
    print_final_list(print_list);
}