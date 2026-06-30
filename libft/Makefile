NAME = libft.a
AR = ar rcs
OBJ_DIR = obj
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c\
		ft_atoi_zero.c ft_strcmp.c ft_free_arr.c ft_strjoinjoin.c \
		ft_swap.c ft_is_all_digit.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

CC = cc
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

#compile .c to objectfiles (.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAG) -c $< -o $@

#compile bonus
bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS) $(OBJS)

#remove object files
clean:
	@rm -rf $(OBJ_DIR)

#Remove object filtes and the library
fclean: clean
	@rm -f $(NAME)

#Rebuild. first remove and then build again
re: fclean all

#tell whitch are not files but commands
.PHONY: clean fclean re
