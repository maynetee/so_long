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

static void	free_wall_and_floor(t_game *game)
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
}

static void	free_item_images(t_game *game)
{
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
}

static void	free_player_images(t_game *game)
{
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
}

static void	free_exit_images(t_game *game)
{
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

void	free_images(t_game *game)
{
	free_wall_and_floor(game);
	free_item_images(game);
	free_player_images(game);
	free_exit_images(game);
}
