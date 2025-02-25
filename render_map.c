/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:22 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 16:38:40 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	blit_img(t_game *game, void *src_img, int dest_x, int dest_y)
{
	int			x;
	int			y;
	t_blit_data	data;

	data.src = mlx_get_data_addr(src_img, &data.src_bpp, &data.src_sl,
			&(int){0});
	y = 0;
	while (y < game->tile_size)
	{
		x = 0;
		while (x < game->tile_size)
		{
			data.dest = (unsigned int *)(game->buffer_addr + ((dest_y + y)
						* game->buffer_size_line + (dest_x + x)
						* (game->buffer_bpp / 8)));
			data.src_pixel = (unsigned int *)(data.src + (y * data.src_sl + x
						* (data.src_bpp / 8)));
			*data.dest = *data.src_pixel;
			x++;
		}
		y++;
	}
}

void	render_tile_buffer(t_game *game, int x, int y)
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

void	render_map(t_game *game)
{
	prepare_buffer(game);
	render_enemies_buffer(game);
	render_player_buffer(game);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer, 0, 0);
	render_move_count(game);
	mlx_do_sync(game->mlx);
}
