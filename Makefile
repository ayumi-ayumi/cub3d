# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asato <asato@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 15:06:45 by chagen            #+#    #+#              #
#    Updated: 2026/05/11 16:22:46 by asato            ###   ########.fr        #
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
# Linker directives lmlx is the lmx library on the school compputer
LDLIBS		=	$(LIBFT_A) -lmlx -lX11 -lXext -lm
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c


INC			=	-I$(INC_DIR) -I$(LIBFT_DIR)

SRC			=	main.c

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ			=	$(SRC:.c=.o)
OBSJ		=	$(addprefix $(OBJ_DIR)/, $(OBJ))
GNL_OBJS = $(GNL_SRCS:./get_next_line/%.c=$(OBJDIR)/get_next_line/%.o)

MAKEFLAGS += --no-print-directory

all:	$(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(GNL_OBJS) $(OBJS)
	@$(CC) $(CFLAGS) $(GNL_OBJS) $(OBJS) $(LDLIBS) -o $(NAME)

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
