# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asato <asato@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 15:06:45 by chagen            #+#    #+#              #
#    Updated: 2026/05/13 20:00:41 by asato            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=leak
SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	includes
LIBFT_DIR	=	libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a
# Linker directives lmlx is the lmx library on the school compputer
LDLIBS		=	$(LIBFT_A) -lmlx -lX11 -lXext -lm

INC			=	-I$(INC_DIR) -I$(LIBFT_DIR)
SRC			=	main.c \
				parsing/get_next_line.c \
				parsing/cleanup.c \
				parsing/create_map.c \
				parsing/init_map.c \
				parsing/validate_map_helper.c \
				parsing/utils.c \
				parsing/error.c \
				parsing/flood_fill.c \
				parsing/flood_fill_helper.c

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ))

#suppress the "Entering directory" and "Leaving directory" messages
MAKEFLAGS += --no-print-directory

all:	$(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#compile .o and create their dir if they dont exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re
