NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./Libft
MLX_PATH = ./mlx_linux

MLX_LIB = $(MLX_PATH)/libmlx.a
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBRARIES = -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx \
			-L/usr/lib -lXext -lX11 -lm -lz

SRCS = main.c \
       file_checks.c \
       map_checks.c \
       map_utils.c \
       map_reader.c \
       map_parser.c \
       map_validator.c \
       path_check.c \
       events.c \
       game_cleanup.c \
       close_helpers.c \
       player_movement.c \
       render_utils.c \
       render_map.c \
       window.c \
       window_extra.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(LIBFT_PATH) -I$(MLX_PATH)

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
