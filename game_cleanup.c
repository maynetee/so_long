/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:58:43 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 15:40:32 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_img(void *mlx, void **img)
{
	if (mlx && *img)
	{
		mlx_destroy_image(mlx, *img);
		*img = NULL;
	}
}

void	free_images(t_game *game)
{
	destroy_img(game->mlx, &game->assets.wall);
	destroy_img(game->mlx, &game->assets.floor);
	destroy_img(game->mlx, &game->assets.exit_closed);
	destroy_img(game->mlx, &game->assets.exit_open);
	destroy_img(game->mlx, &game->assets.item_1);
	destroy_img(game->mlx, &game->assets.item_2);
	destroy_img(game->mlx, &game->assets.player_idle_1);
	destroy_img(game->mlx, &game->assets.player_idle_2);
	destroy_img(game->mlx, &game->assets.player_move_1);
	destroy_img(game->mlx, &game->assets.player_move_2);
	destroy_img(game->mlx, &game->assets.player_win);
	destroy_img(game->mlx, &game->assets.player_dead);
	destroy_img(game->mlx, &game->assets.enemy_move_1);
	destroy_img(game->mlx, &game->assets.enemy_move_2);
	destroy_img(game->mlx, &game->assets.move_bg);
	if (game->buffer)
	{
		mlx_destroy_image(game->mlx, game->buffer);
		game->buffer = NULL;
	}
}

void	free_window_and_display(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	free_map_and_exit(t_game *game)
{
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
	exit(0);
}

void	close_game(t_game *game)
{
	free_images(game);
	free_window_and_display(game);
	free_map_and_exit(game);
}
