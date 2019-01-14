
# Compiler

CC = gcc

FLAGS = -Wall -Wextra -Werror

# Libraries

NAME = libftprintf.a

LIBFT = libft

# Directories

DIR_S = sources

DIR_O = temporary

DIR_H = include

# Files

SOURCES = arguments.c \
		  parse_arguments.c \
		  floats.c \
		  hand_base.c \
		  hand_string.c \
		  useful_functions.c \
		  ft_printf.c \
		  hand_di.c \
		  indentation.c \
		  bonus.c \
		  buff.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

# Utils

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
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

leaks:
	make
	gcc -o printf my_main/main.c libftprintf.a -g
	valgrind --leak-check=full ./printf

test:
	make re
	gcc -g -o printf my_main/main.c libftprintf.a -I includes/f
	./printf

.PHONY: clean fclean all re
