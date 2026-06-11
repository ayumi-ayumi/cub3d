# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asato <asato@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 15:06:45 by chagen            #+#    #+#              #
#    Updated: 2026/06/07 15:17:05 by asato            ###   ########.fr        #
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
				1_parsing/1_load_map_and_config.c \
				1_parsing/2_parse_file.c \
				1_parsing/3_validate_elements.c \
				1_parsing/4_extract_elements.c \
				1_parsing/5_extract_map.c \
				1_parsing/6_validate_map.c \
				1_parsing/7_validate_start_pos.c \
				1_parsing/8_check_walls.c \
				1_parsing/cleanup.c \
				1_parsing/error.c \
				1_parsing/get_next_line.c \
				2_exec/1_exec.c \
				2_exec/2_init_play.c \
				2_exec/3_start_graphics.c \
				2_exec/4_move.c \
				3_mlx/1_init_mlx.c \
				3_mlx/2_mlx_cleanup.c \
				4_raycast/1_raycast.c \
				4_raycast/2_start_values.c \
				4_raycast/3_time.c \
				5_render/1_draw.c\
				5_render/2_put_pixel.c\
				5_render/3_put_wall.c \

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
