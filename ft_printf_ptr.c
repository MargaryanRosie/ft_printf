#include "ft_printf.h"


static int	hex_count(unsigned long n)
{
	int	count;

	if (n == 0)
	{
		return (1);
	}
	count = 0;
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static int	ptr_hex(unsigned long n)
{
	char	hex_digits[17] = {0};
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
			hex_digits[i] = temp + 87;
		n = n / 16;
		i++;
	}
	while (i > 0)
		write(1, &hex_digits[--i], 1);
	return (count);
}

int	ft_printf_ptr(void *ptr)
{
	int	count;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = (ptr_hex((unsigned long)ptr));
	return (count + 2);
}

