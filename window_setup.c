/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:53:59 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 16:39:39 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_window(t_game *game, int width, int height)
{
	game->win = mlx_new_window(game->mlx, width, height, "So_Long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		return (0);
	}
	return (1);
}

int	create_buffer(t_game *game, int width, int height)
{
	game->buffer = mlx_new_image(game->mlx, width, height);
	if (!game->buffer)
	{
		ft_printf("Error\nFailed to create buffer image\n");
		return (0);
	}
	game->buffer_addr = mlx_get_data_addr(game->buffer,
			&game->buffer_bpp, &game->buffer_size_line,
			&game->buffer_endian);
	if (!game->buffer_addr)
	{
		mlx_destroy_image(game->mlx, game->buffer);
		game->buffer = NULL;
		ft_printf("Error\nFailed to get buffer image address\n");
		return (0);
	}
	return (1);
}

int	setup_window(t_game *game)
{
	int	width;
	int	height;

	initialize_mlx(game);
	calc_window_size(game, &width, &height);
	if (!create_window(game, width, height))
		return (0);
	if (!create_buffer(game, width, height))
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		return (0);
	}
	return (1);
}
