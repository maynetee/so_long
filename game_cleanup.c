/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:58:43 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 20:15:03 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->assets.wall)
		mlx_destroy_image(game->mlx, game->assets.wall);
	if (game->assets.floor)
		mlx_destroy_image(game->mlx, game->assets.floor);
	if (game->assets.exit_closed)
		mlx_destroy_image(game->mlx, game->assets.exit_closed);
	if (game->assets.exit_open)
		mlx_destroy_image(game->mlx, game->assets.exit_open);
	if (game->assets.item_1)
		mlx_destroy_image(game->mlx, game->assets.item_1);
	if (game->assets.item_2)
		mlx_destroy_image(game->mlx, game->assets.item_2);
	if (game->assets.player_idle_1)
		mlx_destroy_image(game->mlx, game->assets.player_idle_1);
	if (game->assets.player_idle_2)
		mlx_destroy_image(game->mlx, game->assets.player_idle_2);
	if (game->assets.player_move_1)
		mlx_destroy_image(game->mlx, game->assets.player_move_1);
	if (game->assets.player_move_2)
		mlx_destroy_image(game->mlx, game->assets.player_move_2);
	if (game->assets.player_win)
		mlx_destroy_image(game->mlx, game->assets.player_win);
	if (game->assets.player_dead)
		mlx_destroy_image(game->mlx, game->assets.player_dead);
	if (game->assets.enemy_move_1)
		mlx_destroy_image(game->mlx, game->assets.enemy_move_1);
	if (game->assets.enemy_move_2)
		mlx_destroy_image(game->mlx, game->assets.enemy_move_2);
	if (game->assets.move_bg)
		mlx_destroy_image(game->mlx, game->assets.move_bg);
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