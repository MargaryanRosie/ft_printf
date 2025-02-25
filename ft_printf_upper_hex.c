#include "ft_printf.h"
#include <stdio.h>

static int	hex_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}


int	ft_printf_upper_hex(unsigned int n)
{
	char	hex_digits[9] = {0};
	int		temp;
	int		i;
	int		count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	count = hex_count(n);
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			hex_digits[i] = temp + '0';
		else
			hex_digits[i] = temp + 55;
		n = n / 16;
		i++;
	}
	while (i > 0)
		write(1, &hex_digits[--i], 1);
	return (count);
}
