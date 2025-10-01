# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 13:12:25 by maria-j2          #+#    #+#              #
#    Updated: 2025/08/31 19:36:57 by maria-j2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library file
NAME = libft.a 

# Compiler and compilation flags
CC = cc -c
CFLAGS = -Wall -Werror -Wextra -g

# Create library and delete files
AR = ar rcs 
RM = rm -f

# Source files and object files
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_printf.c ft_putchar_pf.c ft_putnbr_pf.c ft_putptr_pf.c ft_putstr_pf.c \
ft_putunbr_pf.c get_next_line_utils.c get_next_line.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))

# Header file
INCLUDE = libft.h

# Indicates that everything to the right are commands and not files
.PHONY: all clean fclean re bonus

# Default rule that compiles everything
# target : dependencies
#  commands
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $@ $^

# Rule to create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile .c files to .o files
$(OBJ_DIR)/%.o: %.c $(INCLUDE) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Rule to delete all created object files
clean:
	$(RM) $(OBJ_DIR)/*.o

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME)

re: fclean all