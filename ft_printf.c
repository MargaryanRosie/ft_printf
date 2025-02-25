#include "ft_printf.h"

static int	ft_printf_format(const char *input, int i, va_list *args)
{
	unsigned int	count;

	count = 0;
	if (input[i] == 'c')
		count += ft_printf_char(va_arg(*args, int));
	else if (input[i] == 's')
		count += ft_printf_str(va_arg(*args, char *));
	else if (input[i] == 'p')
		count += ft_printf_ptr(va_arg(*args, void *));
	else if (input[i] == 'd' || input[i] == 'i')
		count += ft_printf_nbr(va_arg(*args, int));
	else if (input[i] == 'x')
		count += ft_printf_lower_hex(va_arg(*args, int));
	else if (input[i] == 'X')
		count += ft_printf_upper_hex(va_arg(*args, int));
	else if (input[i] == 'u')
		count += ft_printf_uint(va_arg(*args, int));
	else if (input[i] == '%')
	{
		ft_printf_char('%');
		return (1);
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			count += ft_printf_format(input, i, &args);
			i++;
		}
		else
		{
			count += ft_printf_char(input[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}