#include "push_swap.h"

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putstr(char *s, int *counter)
{
	int	len;

	if (s)
	{
		len = 0;
		while (s[len])
			len++;
		write(1, s, len);
		*counter += len;
	}
	else
	{
		write(1, "(null)", 6);
		*counter += 6;
		return ;
	}
}

void	ft_dec_to_hex(unsigned long n, const char *base, int *counter)
{
	if ((n / 16) != 0)
		ft_dec_to_hex(n / 16, base, counter);
	ft_putchar(base[n % 16], counter);
}

void	ft_print_nbr(int n, int *counter)
{
	char	c;

	if (n == -2147483648)
		ft_putstr("-2147483648", counter);
	else if (n == 0)
		ft_putchar('0', counter);
	else
	{
		c = '\0';
		if (n < 0)
		{
			ft_putchar('-', counter);
			n = -n;
		}
		if ((n / 10) != 0)
			ft_print_nbr(n / 10, counter);
		c = '0' + (n % 10);
		ft_putchar(c, counter);
	}
}

void	ft_print_ptr(unsigned long n, const char *base, int *counter)
{
	if (!n)
	{
		ft_putstr("(nil)", counter);
	}
	else
	{
		ft_putstr("0x", counter);
		ft_dec_to_hex(n, base, counter);
	}
}

void	ft_print_unsigned_dec(unsigned int n, int *counter)
{
	char			c;
	unsigned int	max;

	max = 4294967295;
	if (n == max)
		ft_putstr("4294967295", counter);
	else if (n == 0)
		ft_putchar('0', counter);
	else
	{
		c = '\0';
		if ((n / 10) != 0)
			ft_print_unsigned_dec(n / 10, counter);
		c = '0' + (n % 10);
		ft_putchar(c, counter);
	}
}

static void	conversion_cases(char conversion_char, va_list args, int *counter)
{
	const char	base_low[16] = "0123456789abcdef";
	const char	base_up[16] = "0123456789ABCDEF";

	if (conversion_char == 'c')
		ft_putchar((char)va_arg(args, int), counter);
	else if (conversion_char == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (conversion_char == 'p')
		ft_print_ptr(va_arg(args, unsigned long), base_low, counter);
	else if (conversion_char == 'd' || conversion_char == 'i')
		ft_print_nbr(va_arg(args, int), counter);
	else if (conversion_char == 'u')
		ft_print_unsigned_dec(va_arg(args, unsigned int), counter);
	else if (conversion_char == 'x')
		ft_dec_to_hex((unsigned long)va_arg(args, unsigned int), base_low,
			counter);
	else if (conversion_char == 'X')
		ft_dec_to_hex((unsigned long)va_arg(args, unsigned int), base_up,
			counter);
	else if (conversion_char == '%')
		ft_putchar('%', counter);
	else
		ft_putchar(conversion_char, counter);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	args;

	va_start(args, format);
	counter = 0;
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			conversion_cases(*format, args, &counter);
		}
		else
			ft_putchar((char)*format, &counter);
		format++;
	}
	va_end(args);
	return (counter);
}