ccred="\033[0;31m"
ccyellow="\033[0;33m"
ccend="\033[0m"
ccgreen= "\033[0;32m"


# Compiler

CC = gcc

FLAGS = -Wall -Wextra -Werror

# Libraries

NAME = libftprintf.a

LIBFT = libft

# Directories

DIR_S = sources

DIR_O = temporary

DIR_H = includes

# Files

SOURCES = arguments.c \
		  parse_arguments.c	 \
		  floats.c \
		  hand_base.c \
		  hand_string.c \
		  useful_functions.c \
		  useful_functions_2.c \
		  ft_printf.c \
		  hand_di.c \
		  indentation.c \
		  bonus.c \
		  buff.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

# Utils

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)
	@:

$(NAME): $(OBJS) lib
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

lib:
	@printf $(ccgreen)"\t[OK]\n"$(ccend)
	@printf $(ccyellow)"%-20s"$(ccred) $(LIBFT)
	@make -C $(LIBFT)
	@printf $(ccgreen)"\t[OK]\n"$(ccend)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@echo -n '#'
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(DIR_H) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all re
