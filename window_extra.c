/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:52 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 20:37:26 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_message(t_game *game, char *message)
{
	int	x;

	x = game->width * 32 - 100;
	mlx_string_put(game->mlx, game->win, x, 10, 0xFF0000, message);
	mlx_do_sync(game->mlx);
}

int	update_game(t_game *game)
{
	render_map(game);
	game->global_frame++;
	if (game->win_flag == 1)
	{
		if ((game->global_frame - game->win_start_frame) > 60)
			close_game(game);
	}
	return (0);
}
