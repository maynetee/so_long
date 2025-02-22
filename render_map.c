/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:22 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 20:37:18 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_move_count(t_game *game)
{
	char	*move_str;
	int		color_text;
	int		x;
	int		y;

	move_str = ft_itoa(game->move_count);
	color_text = 0x8B0000;
	x = (game->width * game->tile_size) / 2 - 100;
	y = 10;
	render_move_count_bg(game, x, y);
	mlx_string_put(game->mlx, game->win, x + 30, y + 15, color_text, "Moves: ");
	mlx_string_put(game->mlx, game->win, x + 130, y + 15, color_text, move_str);
	free(move_str);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

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
	render_move_count(game);
	game->frame_count++;
	if (game->frame_count > 20)
		game->frame_count = 0;
}
