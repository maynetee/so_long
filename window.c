/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:11:27 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 19:56:52 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &width,
			&height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&width, &height);
	game->exit_closed_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit_closed.xpm", &width, &height);
	game->exit_open_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit_open.xpm", &width, &height);
	game->item_img_1 = mlx_xpm_file_to_image(game->mlx, "assets/item_1.xpm",
			&width, &height);
	game->item_img_2 = mlx_xpm_file_to_image(game->mlx, "assets/item_2.xpm",
			&width, &height);
	game->player_idle_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_idle_1.xpm", &width, &height);
	game->player_idle_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_idle_2.xpm", &width, &height);
	game->player_move_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_move_1.xpm", &width, &height);
	game->player_move_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/player_move_2.xpm", &width, &height);
	game->player_win = mlx_xpm_file_to_image(game->mlx, "assets/player_win.xpm",
			&width, &height);
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
		ft_printf("Error\nFailed to initialize MiniLibX\n");
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

void	display_message(t_game *game, char *message)
{
	mlx_string_put(game->mlx, game->win, game->width * 32 - 100, 10, 0xFF0000,
		message);
	mlx_do_sync(game->mlx);
}

int	update_game(t_game *game)
{
	render_map(game);
	game->global_frame++;
	if (game->win_flag == 1)
	{
		if ((game->global_frame - game->win_start_frame) > 60)
			close_game(game);
	}
	return (0);
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
