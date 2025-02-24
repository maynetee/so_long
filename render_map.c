/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:22 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 21:48:50 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x
		* game->tile_size, y * game->tile_size);
}

static void	render_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x
		* game->tile_size, y * game->tile_size);
}

static void	render_exit(t_game *game, int x, int y)
{
	if (game->count_c == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_open_img, x
			* game->tile_size, y * game->tile_size);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->exit_closed_img, x
			* game->tile_size, y * game->tile_size);
}

static void	render_item(t_game *game, int x, int y)
{
	void	*item_img;

	if ((game->global_frame / 30) % 2 == 0)
		item_img = game->item_img_1;
	else
		item_img = game->item_img_2;
	mlx_put_image_to_window(game->mlx, game->win, item_img, x * game->tile_size,
		y * game->tile_size);
}

/* Retrait de static ici */
void	render_enemies(t_game *game)
{
	void	*enemy_img;
	int		i;

	i = 0;
	while (i < game->enemy_count)
	{
		if ((game->global_frame / 30) % 2 == 0)
			enemy_img = game->enemy_move_1;
		else
			enemy_img = game->enemy_move_2;
		mlx_put_image_to_window(game->mlx, game->win, enemy_img,
			game->enemies[i].x * game->tile_size, game->enemies[i].y
			* game->tile_size);
		i++;
	}
}

void	render_player(t_game *game)
{
	void	*player_img;

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
	mlx_put_image_to_window(game->mlx, game->win, player_img, game->player_x
		* game->tile_size, game->player_y * game->tile_size);
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
			if (game->map[y][x] == '1')
				render_wall(game, x, y);
			else
				render_floor(game, x, y);
			if (game->map[y][x] == 'C')
				render_item(game, x, y);
			if (game->map[y][x] == 'E')
				render_exit(game, x, y);
			x++;
		}
		y++;
	}
	render_enemies(game);
	render_player(game);
	render_move_count(game);
}
