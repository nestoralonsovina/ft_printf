
SRCS = main.c

SRCS += ft_printf.c

HANDLERS =	char.c	\
			ptr.c	\
			str.c	\
			long.c	\
			int.c	\
			float.c	\
			octal.c	\
			dec.c	\
			hexa.c

SRCS += $(addprefix srcs/handlers/handle_, $(HANDLERS))

all:
	@make -C libft/
	@gcc -o printf $(SRCS) libft/libft.a -I libft/ -I.
	@echo "\033[0;32mPrintf compiled\033[0m"