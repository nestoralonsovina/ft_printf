
#SRCS = main.c


#all:
#	@make -C libft/
#	@gcc -o printf -g $(SRCS) libft/libft.a -I libft/ -I.
#	@echo "\033[0;32mPrintf compiled\033[0m"
	
# Name of the library
NAME = libprintf.a

SRCS += ft_printf.c 

SRCS  += handle_parameter.c useful_functions.c handle_arguments.c handle_conversions.c

#USEFUL_FUNC = fstrjoin.c	\

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
all: $(NAME)

# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RLIB) $(NAME)
	@echo "\033[0;32mlbprintf compiled\033[0m"

# This won't run if the source files don't exit or are not modified
$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "\033[0;32mObject files compiled\033[0m"

# Removes all the object files and directory
clean:
	@rm -f $(OBJS)

# Removes everything that has been created by the makefile
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re