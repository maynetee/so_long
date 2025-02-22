/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:11:27 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 20:39:39 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_images_part1(t_game *game)
{
	int	w;
	int	h;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w,
			&h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w,
			&h);
	game->exit_closed_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit_closed.xpm", &w, &h);
	game->exit_open_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit_open.xpm", &w, &h);
	game->item_img_1 = mlx_xpm_file_to_image(game->mlx, "assets/item_1.xpm", &w,
			&h);
}

static void	load_images_part2(t_game *game)
{
	int	w;
	int	h;

	game->item_img_2 = mlx_xpm_file_to_image(game->mlx, "assets/item_2.xpm", &w,
			&h);
	game->player_idle_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_idle_1.xpm", &w, &h);
	game->player_idle_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_idle_2.xpm", &w, &h);
	game->player_move_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_move_1.xpm", &w, &h);
	game->player_move_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_move_2.xpm", &w, &h);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	load_images_part1(game);
	load_images_part2(game);
	game->player_win = mlx_xpm_file_to_image(game->mlx, "assets/player_win.xpm",
			&w, &h);
	if (!game->wall_img || !game->floor_img || !game->item_img_1
		|| !game->item_img_2 || !game->player_idle_1 || !game->player_idle_2
		|| !game->player_move_1 || !game->player_move_2 || !game->player_win
		|| !game->exit_closed_img || !game->exit_open_img)
	{
		ft_printf("Error\nFailed to load images\n");
		close_game(game);
	}
}

void	setup_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to init MiniLibX\n");
		close_game(game);
	}
	game->win = mlx_new_window(game->mlx, 1280, 704, "So_Long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		close_game(game);
	}
	game->scale_x = 1280 / game->width;
	game->scale_y = 720 / game->height;
	if (game->scale_x < game->scale_y)
		game->tile_size = game->scale_x;
	else
		game->tile_size = game->scale_y;
}

void	init_window(t_game *game)
{
	setup_window(game);
	load_images(game);
	render_map(game);
	mlx_hook(game->win, 17, 0, close_game_wrapper, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_loop(game->mlx);
}
