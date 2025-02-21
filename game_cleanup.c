/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:58:43 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/21 01:59:09 by mteichma         ###   ########.fr       */
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
	if (game->item_img)
	{
		mlx_destroy_image(game->mlx, game->item_img);
		game->item_img = NULL;
	}
	if (game->exit_img)
	{
		mlx_destroy_image(game->mlx, game->exit_img);
		game->exit_img = NULL;
	}
	if (game->player_img)
	{
		mlx_destroy_image(game->mlx, game->player_img);
		game->player_img = NULL;
	}
	if (game->floor_img)
	{
		mlx_destroy_image(game->mlx, game->floor_img);
		game->floor_img = NULL;
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
