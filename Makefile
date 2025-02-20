NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx_linux
MLX_NAME = libmlx.a
MLX_LIB = $(MLX_PATH)/$(MLX_NAME)

LIBFT_PATH = Libft
LIBFT_NAME = libft.a
LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT_NAME)

SRCS = main.c \
       file_checks.c \
       map_checks.c \
       map_utils.c \
       map_reader.c \
       map_parser.c \
       map_validator.c \
       path_check.c


OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(LIBFT_PATH)/includes -I$(MLX_PATH)

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_PATH)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
