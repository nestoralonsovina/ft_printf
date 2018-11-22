
SRCS = main.c

SRCS += ft_printf.c 

FILES = handle_parameter.c useful_functions.c handle_arguments.c

HANDLERS =	char.c	\
			ptr.c	\
			str.c	\
			long.c	\
			int.c	\
			float.c	\
			octal.c	\
			dec.c	\
			hexa.c

#USEFUL_FUNC = fstrjoin.c	\

#SRCS += $(addprefix srcs/handlers/handle_, $(HANDLERS))
SRCS += $(addprefix srcs/, $(FILES))

all:
	@make -C libft/
	@gcc -o printf -g $(SRCS) libft/libft.a -I libft/ -I.
	@echo "\033[0;32mPrintf compiled\033[0m"