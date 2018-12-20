
#				LIBC FUNCTIONS
LIBFT += ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_isspace.c

#					ADDITIONAL FUNCTIONS
LIBFT += ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_strclr.c		\
		ft_putchar.c	\
		ft_putchar_fd.c	\
		ft_putstr.c		\
		ft_putstr_fd.c	\
		ft_putnbr.c		\
		ft_putnbr_fd.c	\
		ft_putendl.c	\
		ft_putendl_fd.c

#					CHAINED LIST FUNCTIONS
LIBFT += ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c

LIBFTSRCS = $(addprefix libft/, $(LIBFT))
LIBFTOBJS = $(LIBFT:.c=.o)

# Name of the library
NAME = libftprintf.a

SRCS += ft_printf.c \
		useful_functions.c arguments.c \
		conversions.c indentation.c floats.c


#USEFUL_FUNC = fstrjoin.c

#SRCS += $(addprefix srcs/handlers/handle_, $(HANDLERS))

OBJS = $(SRCS:%.c=%.o)

#SRCS += $(addprefix srcs/, $(FILES))

# Define all the compiling flags
CFLAGS += -Wall -Werror -Wextra
CC := gcc

# Define all library flags
LFLAGS += -I.
AR = ar rcs
RLIB := ranlib

# Name of the directories
OBJ_DIR := objs/

# Files
HEAD = ft_printf.h

# Path to the directories
# SRCS := $(wildcard $(*.c)
# OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compile and create everything.
all: $(NAME) clean

# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJS) $(LIBFTOBJS)
	@$(AR) $(NAME) *.o
	@$(RLIB) $(NAME)
	@echo "\033[0;32mlibprintf compiled\033[0m"

# This won't run if the source files don't exit or are not modified
$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "\033[0;32mObject files compiled\033[0m"

$(LIBFTOBJS): $(LIBFTSRCS)
	@$(CC) $(CFLAGS) -c $(LIBFTSRCS)
	@echo "\033[0;32mObject files compiled\033[0m"

# Removes all the object files and directory
clean:
	@rm -f *.o

# Removes everything that has been created by the makefile
fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@make
	@echo "libfprintf.a compiled"
	@gcc -g -o printf my_main/main.c libftprintf.a
	@echo "./printf executable compiled"
	@echo "executing ./printf..."
	@echo ""
	@./printf

leaks:
	make
	gcc -g -o printf my_main/main.c libftprintf.a
	valgrind --leak-check=full ./printf
.PHONY: clean fclean all re
