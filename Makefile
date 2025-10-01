# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 18:20:13 by maria-j2          #+#    #+#              #
#    Updated: 2025/10/01 17:27:21 by maria-j2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the file
NAME = minitalk

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)

# Tools
AR = ar rcs
RM = rm -f

# Directories
SRCS_DIR = src
OBJ_DIR = obj

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRC_FILES = \
	client.c \
	server.c

# Add paths
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Header file
INCLUDE = minitalk.h

# Default rule
all: server client

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build client
client: client.c libft/libft.a
	$(CC) $(CFLAGS) client.c libft/libft.a -o client
	
# Build server
server: server.c libft/libft.a
	$(CC) $(CFLAGS) server.c libft/libft.a -o server
	
# Ensure object dir exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile .c into .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Cleaning rules
clean:
	rm -f server client
	$(MAKE) -C libft clean

fclean: clean
	rm -f libft/libft/a

re: fclean all

.PHONY: all clean fclean re