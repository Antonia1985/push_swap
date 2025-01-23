#include "push_swap.h"

static int	ft_isspace(char c)
{
	size_t	i;
	char	*space_char;

	i = 0;
	space_char = " \t\n\v\f\r";
	while (i < 6)
	{
		if (c == space_char[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	size_t	i;
	long		signd;
	long		sign;
	long		num;

	if (!nptr)
        return 0;
		
	i = 0;
	signd = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (signd == 0 && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		signd = 1;
		i++;
	}
	if ((signd == 1) && (nptr[i] == '+' || nptr[i] == '-'))
		return (num);
	while ((nptr[i] != '\0') && (nptr[i] >= 48) && (nptr[i] <= 57))
		num = (num * 10) + (nptr[i++] - '0');
	num = num * sign;
	return (num);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	// size_t i = 0;

	if (argc < 2)
	{
		printf("Please provide at least one argument.\n");
		return (1);
	}

	printf("Argument : %s\n", argv[1]);
	printf("ft_atoi : %d\n", ft_atoi(argv[1]));
	printf("atoi : %d\n", atoi(argv[1]));
	return (0);
}*/