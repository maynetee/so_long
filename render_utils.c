/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:00 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 20:36:41 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * game->tile_size, y
		* game->tile_size);
}

void	render_player(t_game *game, int x, int y)
{
	if (game->count_c == 0 && game->map[y][x] == 'E')
	{
		put_image(game, game->player_win, x, y);
		return ;
	}
	if (game->player_x != x || game->player_y != y)
	{
		if (game->frame_count < 10)
			put_image(game, game->player_move_1, x, y);
		else
			put_image(game, game->player_move_2, x, y);
	}
	else
	{
		if (game->frame_count < 10)
			put_image(game, game->player_idle_1, x, y);
		else
			put_image(game, game->player_idle_2, x, y);
	}
	game->frame_count++;
	if (game->frame_count > 20)
		game->frame_count = 0;
}

void	render_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] != '1')
		put_image(game, game->floor_img, x, y);
	if (game->map[y][x] == '1')
		put_image(game, game->wall_img, x, y);
	if (game->map[y][x] == 'C')
	{
		if (game->frame_count < 10)
			put_image(game, game->item_img_1, x, y);
		else
			put_image(game, game->item_img_2, x, y);
	}
	if (game->map[y][x] == 'E')
	{
		if (game->count_c == 0)
			put_image(game, game->exit_open_img, x, y);
		else
			put_image(game, game->exit_closed_img, x, y);
	}
	if (game->player_x == x && game->player_y == y)
		render_player(game, x, y);
}

static void	draw_rectangle(t_game *game, t_draw d)
{
	int	i;
	int	j;
	int	x_end;
	int	y_end;

	x_end = d.x + d.w;
	y_end = d.y + d.h;
	j = d.y;
	while (j < y_end)
	{
		i = d.x;
		while (i < x_end)
		{
			mlx_pixel_put(game->mlx, game->win, i, j, d.color);
			i++;
		}
		j++;
	}
}

void	render_move_count_bg(t_game *game, int x, int y)
{
	t_draw	d;

	d.x = x;
	d.y = y;
	d.w = 200;
	d.h = 40;
	d.color = 0xF5DEB3;
	draw_rectangle(game, d);
}
