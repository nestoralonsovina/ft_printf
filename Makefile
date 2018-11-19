
SRCS = main.c


SRCS += ft_printf.c

SRCS += srcs/handlers/handle_char.c		\
		srcs/handlers/handle_ptr.c		\
		srcs/handlers/handle_str.c


all:
	make -C libft/
	gcc -o printf $(SRCS) libft/libft.a -I libft/ -I.
