# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chagen <chagen@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 15:06:45 by chagen            #+#    #+#              #
#    Updated: 2026/05/06 15:06:47 by chagen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanatizer=leak
SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	includes
LIBFT_DIR	=	libft
MLX_DIR		=	minilibx-linux
LIBFT_A		=	$(LIBFT_DIR)/libft.a
MLX_A		=	$(MLX_DIR)/libmlx.a
LDLIBS		=	$(LIBFT_A) $(MLX_A) -lX11 -lXext -lm

INC			=	-I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC			=	main.c

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ			=	$(SRC:.c=.o)
OBSJ		=	$(addprefix $(OBJ_DIR)/, $(OBJ))

all:	$(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#compile .o and create their dir if they dont exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean


re: fclean all

.PHONY: all clean fclean re

