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
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			x * game->tile_size, y * game->tile_size);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
			x * game->tile_size, y * game->tile_size);
	if (game->map[y][x] == 'C')
	{
		if ((game->global_frame / 30) % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->item_img_1,
				x * game->tile_size, y * game->tile_size);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->item_img_2,
				x * game->tile_size, y * game->tile_size);
	}
	if (game->map[y][x] == 'E')
	{
		if (game->count_c == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->exit_open_img,
				x * game->tile_size, y * game->tile_size);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->exit_closed_img,
				x * game->tile_size, y * game->tile_size);
	}
}

static void	render_entities(t_game *game)
{
	int		i;
	void	*enemy_img;
	void	*player_img;

	i = 0;
	while (i < game->enemy_count)
	{
		if ((game->global_frame / 30) % 2 == 0)
			enemy_img = game->enemy_move_1;
		else
			enemy_img = game->enemy_move_2;
		mlx_put_image_to_window(game->mlx, game->win, enemy_img,
			game->enemies[i].x * game->tile_size,
			game->enemies[i].y * game->tile_size);
		i++;
	}
	if (game->win_flag == 1)
		player_img = game->player_win;
	else if (game->win_flag == 2)
		player_img = game->player_dead;
	else
	{
		if ((game->global_frame / 30) % 2 == 0)
			player_img = game->player_idle_1;
		else
			player_img = game->player_idle_2;
	}
	mlx_put_image_to_window(game->mlx, game->win, player_img,
		game->player_x * game->tile_size,
		game->player_y * game->tile_size);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

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
	render_entities(game);
	render_move_count(game);
}
