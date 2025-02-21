/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:58:43 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/21 20:59:28 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->wall_img)
	{
		mlx_destroy_image(game->mlx, game->wall_img);
		game->wall_img = NULL;
	}
	if (game->floor_img)
	{
		mlx_destroy_image(game->mlx, game->floor_img);
		game->floor_img = NULL;
	}
	if (game->item_img_1)
	{
		mlx_destroy_image(game->mlx, game->item_img_1);
		game->item_img_1 = NULL;
	}
	if (game->item_img_2)
	{
		mlx_destroy_image(game->mlx, game->item_img_2);
		game->item_img_2 = NULL;
	}
	if (game->player_idle_1)
	{
		mlx_destroy_image(game->mlx, game->player_idle_1);
		game->player_idle_1 = NULL;
	}
	if (game->player_idle_2)
	{
		mlx_destroy_image(game->mlx, game->player_idle_2);
		game->player_idle_2 = NULL;
	}
	if (game->player_move_1)
	{
		mlx_destroy_image(game->mlx, game->player_move_1);
		game->player_move_1 = NULL;
	}
	if (game->player_move_2)
	{
		mlx_destroy_image(game->mlx, game->player_move_2);
		game->player_move_2 = NULL;
	}
	if (game->player_win)
	{
		mlx_destroy_image(game->mlx, game->player_win);
		game->player_win = NULL;
	}
	if (game->exit_closed_img)
	{
		mlx_destroy_image(game->mlx, game->exit_closed_img);
		game->exit_closed_img = NULL;
	}
	if (game->exit_open_img)
	{
		mlx_destroy_image(game->mlx, game->exit_open_img);
		game->exit_open_img = NULL;
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
	exit(0);
}

void	close_game(t_game *game)
{
	free_images(game);
	free_window_and_display(game);
	free_map_and_exit(game);
}
