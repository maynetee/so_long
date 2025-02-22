/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:15:31 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 20:15:33 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
