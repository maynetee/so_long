/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:52 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 16:39:26 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_bg_row(char *addr, int row, int sl, int bpp)
{
	int	x;

	x = 0;
	while (x < 100)
	{
		*(unsigned int *)(addr + (row * sl + x * (bpp / 8))) = 0x000000;
		x++;
	}
}

void	create_move_count_bg_image(t_game *game)
{
	int		row;
	int		bpp;
	int		sl;
	int		endian;
	char	*addr;

	game->assets.move_bg = mlx_new_image(game->mlx, 100, 25);
	if (!game->assets.move_bg)
	{
		close_game(game);
		return ;
	}
	addr = mlx_get_data_addr(game->assets.move_bg, &bpp, &sl, &endian);
	if (!addr)
	{
		close_game(game);
		return ;
	}
	row = 0;
	while (row < 20)
	{
		draw_bg_row(addr, row, sl, bpp);
		row++;
	}
}

void	calc_window_size(t_game *game, int *width, int *height)
{
	*width = game->width * 64;
	*height = game->height * 64;
	if (*width > 1280)
		*width = 1280;
	if (*height > 720)
		*height = 720;
	game->tile_size = *width / game->width;
	if (game->tile_size > *height / game->height)
		game->tile_size = *height / game->height;
	*width = game->tile_size * game->width;
	*height = game->tile_size * game->height;
}

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to init MiniLibX\n");
		exit(EXIT_FAILURE);
	}
}
