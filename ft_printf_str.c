#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}