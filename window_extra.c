/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:52 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 21:52:33 by mteichma         ###   ########.fr       */
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

	game->move_bg_img = mlx_new_image(game->mlx, 100, 40);
	if (!game->move_bg_img)
		return ;
	addr = mlx_get_data_addr(game->move_bg_img, &bpp, &sl, &endian);
	row = 0;
	while (row < 40)
	{
		draw_bg_row(addr, row, sl, bpp);
		row++;
	}
}

void	display_message(t_game *game, char *message)
{
	mlx_string_put(game->mlx, game->win, 10, 60, 0xFFFFFF, message);
}
