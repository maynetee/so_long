/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:12:08 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/21 01:12:10 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119)
		move_player(game, x, y - 1);
	else if (keycode == 97)
		move_player(game, x - 1, y);
	else if (keycode == 115)
		move_player(game, x, y + 1);
	else if (keycode == 100)
		move_player(game, x + 1, y);
	return (0);
}

void	close_game(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->item_img)
		mlx_destroy_image(game->mlx, game->item_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
	exit(0);
}

int	close_game_wrapper(t_game *game)
{
	close_game(game);
	return (0);
}
