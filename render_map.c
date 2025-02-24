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

void	blit_img(t_game *game, void *src_img, int dest_x, int dest_y)
{
	int			x;
	int			y;
	int			src_sl;
	int			src_bpp;
	char		*src;

	src = mlx_get_data_addr(src_img, &src_bpp, &src_sl, &(int){0});
	y = 0;
	while (y < game->tile_size)
	{
		x = 0;
		while (x < game->tile_size)
		{
			{
				unsigned int	*dest;
				unsigned int	*src_pixel;

				dest = (unsigned int *)(game->buffer_addr +
					((dest_y + y) * game->buffer_size_line +
					(dest_x + x) * (game->buffer_bpp / 8)));
				src_pixel = (unsigned int *)(src +
					(y * src_sl + x * (src_bpp / 8)));
				*dest = *src_pixel;
			}
			x++;
		}
		y++;
	}
}

static void	render_tile_buffer(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * game->tile_size;
	pos_y = y * game->tile_size;
	blit_img(game, game->assets.floor, pos_x, pos_y);
	if (game->map[y][x] == '1')
		blit_img(game, game->assets.wall, pos_x, pos_y);
	else if (game->map[y][x] == 'C')
	{
		if ((game->global_frame / 30) % 2 == 0)
			blit_img(game, game->assets.item_1, pos_x, pos_y);
		else
			blit_img(game, game->assets.item_2, pos_x, pos_y);
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->count_c == 0)
			blit_img(game, game->assets.exit_open, pos_x, pos_y);
		else
			blit_img(game, game->assets.exit_closed, pos_x, pos_y);
	}
}

static void	render_player_buffer(t_game *game)
{
	int		pos_x;
	int		pos_y;
	void	*player_img;

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
		blit_img(game, player_img, pos_x, pos_y);
}

static void	render_enemies_buffer(t_game *game)
{
	int		i;
	int		pos_x;
	int		pos_y;
	void	*enemy_img;

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
			blit_img(game, enemy_img, pos_x, pos_y);
		i++;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	win_height;

	win_height = game->tile_size * game->height;
	ft_bzero(game->buffer_addr,
		game->buffer_size_line * win_height);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile_buffer(game, x, y);
			x++;
		}
		y++;
	}
	render_enemies_buffer(game);
	render_player_buffer(game);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer, 0, 0);
	render_move_count(game);
	mlx_do_sync(game->mlx);
}
