# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asato <asato@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 15:06:45 by chagen            #+#    #+#              #
#    Updated: 2026/06/04 16:12:09 by asato            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
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
				parsing/1_load_map_and_config.c \
				parsing/2_parse_file.c \
				parsing/3_validate_elements.c \
				parsing/4_extract_elements.c \
				parsing/5_extract_map.c \
				parsing/6_validate_map.c \
				parsing/7_validate_start_pos.c \
				parsing/8_check_walls.c \
				parsing/cleanup.c \
				parsing/error.c \
				20exec/200exec.c \
				21mlx/210init_mlx.c \
				21mlx/211mlx_cleanup.c \
				parsing/get_next_line.c \

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
