/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:11:27 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/21 01:55:17 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &width, &height);
	game->item_img = mlx_xpm_file_to_image(game->mlx,
			"assets/item.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &width, &height);
	if (!game->wall_img || !game->item_img
		|| !game->exit_img || !game->player_img)
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
	game->win = mlx_new_window(game->mlx,
			game->width * 64, game->height * 64,
			"So_Long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		close_game(game);
	}
}

void	init_window(t_game *game)
{
	setup_window(game);
	load_images(game);
	render_map(game);
	mlx_hook(game->win, 17, 0, close_game_wrapper, game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_loop(game->mlx);
}
