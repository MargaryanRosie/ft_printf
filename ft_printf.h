#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printf_upper_hex(unsigned int n);
int	ft_printf_lower_hex(unsigned int n);
int	ft_printf_nbr(int n);
int	ft_printf_ptr(void *ptr);
int	ft_printf_uint(unsigned int n);


#endif