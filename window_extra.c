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

void	create_move_count_bg_image(t_game *game)
{
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		sl;
	int		endian;
	int		x;
	int		y;

	width = 100;
	height = 40;
	game->move_bg_img = mlx_new_image(game->mlx, width, height);
	if (!game->move_bg_img)
		return ;
	addr = mlx_get_data_addr(game->move_bg_img, &bpp, &sl, &endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			*(unsigned int *)(addr + (y * sl + x * (bpp / 8))) = 0x000000;
			x++;
		}
		y++;
	}
}

void	display_message(t_game *game, char *message)
{
	int	color;

	color = 0xFFFFFF;
	mlx_string_put(game->mlx, game->win, 10, 60, color, message);
}
