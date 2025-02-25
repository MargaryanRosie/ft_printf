CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_char.c ft_printf_str.c ft_printf_lower_hex.c ft_printf_upper_hex.c ft_printf_nbr.c ft_printf_ptr.c ft_printf.c ft_printf_uint.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h
NAME = libftprintf.a
LIB_PATH = ./libft 
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp	$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)
	
$(LIBFT):
	make -C $(LIB_PATH) all 

%.o: %.c  $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)	

clean:
	make -C $(LIB_PATH) clean
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re
