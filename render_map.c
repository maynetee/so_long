/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:22 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/24 18:35:44 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * game->tile_size;
	pos_y = y * game->tile_size;
	mlx_put_image_to_window(game->mlx, game->win, game->assets.floor, pos_x,
		pos_y);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->assets.wall, pos_x,
			pos_y);
	else if (game->map[y][x] == 'C')
	{
		if ((game->global_frame / 30) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->assets.item_1,
				pos_x, pos_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->assets.item_2,
				pos_x, pos_y);
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->count_c == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->assets.exit_open, pos_x, pos_y);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->assets.exit_closed, pos_x, pos_y);
	}
}

static void	render_player(t_game *game)
{
	void	*player_img;
	int		pos_x;
	int		pos_y;

	pos_x = game->player.x * game->tile_size;
	pos_y = game->player.y * game->tile_size;
	if (game->win_status == 1)
		player_img = game->assets.player_win;
	else if (game->win_status == 2)
		player_img = game->assets.player_dead;
	else
	{
		if ((game->global_frame / 30) % 2 == 0)
			player_img = game->assets.player_idle_1;
		else
			player_img = game->assets.player_idle_2;
	}
	if (player_img)
		mlx_put_image_to_window(game->mlx, game->win, player_img, pos_x, pos_y);
}

static void	render_enemies(t_game *game)
{
	int		i;
	void	*enemy_img;
	int		pos_x;
	int		pos_y;

	i = 0;
	while (i < game->enemy_count)
	{
		pos_x = game->enemies[i].x * game->tile_size;
		pos_y = game->enemies[i].y * game->tile_size;
		if ((game->global_frame / 30) % 2 == 0)
			enemy_img = game->assets.enemy_move_1;
		else
			enemy_img = game->assets.enemy_move_2;
		if (enemy_img)
			mlx_put_image_to_window(game->mlx, game->win, enemy_img, pos_x,
				pos_y);
		i++;
	}
}

void	render_map(t_game *game)
{
	int x;
	int y;

	mlx_clear_window(game->mlx, game->win);

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}

	render_enemies(game);
	render_player(game);
	render_move_count(game);

	mlx_do_sync(game->mlx);
}