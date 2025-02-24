/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:11:27 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/24 18:35:59 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_image(void **img, void *mlx, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	return (*img != NULL);
}

static int	load_all_images(t_game *game)
{
	return (load_image(&game->assets.wall, game->mlx, "assets/wall.xpm")
		&& load_image(&game->assets.floor, game->mlx, "assets/floor.xpm")
		&& load_image(&game->assets.exit_closed, game->mlx,
			"assets/exit_closed.xpm")
		&& load_image(&game->assets.exit_open, game->mlx,
			"assets/exit_open.xpm")
		&& load_image(&game->assets.item_1, game->mlx, "assets/item_1.xpm")
		&& load_image(&game->assets.item_2, game->mlx, "assets/item_2.xpm")
		&& load_image(&game->assets.player_idle_1, game->mlx,
			"assets/player_idle_1.xpm")
		&& load_image(&game->assets.player_idle_2, game->mlx,
			"assets/player_idle_2.xpm")
		&& load_image(&game->assets.player_move_1, game->mlx,
			"assets/player_move_1.xpm")
		&& load_image(&game->assets.player_move_2, game->mlx,
			"assets/player_move_2.xpm")
		&& load_image(&game->assets.player_win, game->mlx,
			"assets/player_win.xpm")
		&& load_image(&game->assets.player_dead, game->mlx,
			"assets/player_dead.xpm")
		&& load_image(&game->assets.enemy_move_1, game->mlx,
			"assets/enemy_move_1.xpm")
		&& load_image(&game->assets.enemy_move_2, game->mlx,
			"assets/enemy_move_2.xpm"));
}

static void	calc_window_size(t_game *game, int *width, int *height)
{
	*width = game->width * 64;
	*height = game->height * 64;
	if (*width > 1280)
		*width = 1280;
	if (*height > 720)
		*height = 720;
	game->tile_size = *width / game->width;
	if (game->tile_size > *height / game->height)
		game->tile_size = *height / game->height;
	*width = game->tile_size * game->width;
	*height = game->tile_size * game->height;
}

void	setup_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to init MiniLibX\n");
		close_game(game);
	}
	calc_window_size(game, &width, &height);
	game->win = mlx_new_window(game->mlx, width, height, "So_Long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		close_game(game);
	}
	game->buffer = mlx_new_image(game->mlx, width, height);
	if (!game->buffer)
	{
		ft_printf("Error\nFailed to create buffer image\n");
		close_game(game);
	}
	game->buffer_addr = mlx_get_data_addr(game->buffer,
		&game->buffer_bpp, &game->buffer_size_line,
		&game->buffer_endian);
	if (!game->buffer_addr)
	{
		ft_printf("Error\nFailed to get buffer image address\n");
		close_game(game);
	}
}

void	init_window(t_game *game)
{
	setup_window(game);
	if (!load_all_images(game))
	{
		ft_printf("Error\nFailed to load images\n");
		close_game(game);
	}
	create_move_count_bg_image(game);
	render_map(game);
	mlx_hook(game->win, 17, 0, close_game_wrapper, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_loop(game->mlx);
}
