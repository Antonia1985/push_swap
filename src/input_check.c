#include "push_swap.h"

int check_integer_limits(char *num)
{
    long number = ft_atol(num);
    
    if (number < INT_MIN  || number > INT_MAX)
    {
        return 0;
    }
    return 1;
}

int check_if_non_digit(char *num)
{
    if (!num || *num == '\0') // Null or empty string
        return 0;

    size_t i = 0;
    if(num[0] == '+' || num[0] == '-')
        i++;

    while (num[i])
    { 
        if ((num[i] < '0') || (num[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (diff);
}

int check_duplicate(char *num, char **numbers, size_t num_index)
{ 
    size_t i = 0;
    while (i < num_index)
    {
        if (ft_strcmp(num, numbers[i]) == 0)
        {
            return (0);
        }
        i++;
    }
    return 1;
}

int is_argument_an_array(char * argument_str)
{
    if (!argument_str)
        return 0;

    while (*argument_str)
    {
        if (*argument_str == ' ')
            return 1;
        argument_str++;
    }
    return 0;
}
