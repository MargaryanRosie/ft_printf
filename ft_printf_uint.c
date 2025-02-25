#include "ft_printf.h"

int	ft_printf_uint(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count = count + ft_printf_uint(n / 10);
	count = count + ft_printf_char((n % 10) + '0');
	return (count);
}
