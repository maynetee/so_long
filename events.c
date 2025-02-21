/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:12:08 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/21 01:58:59 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119)
		move_player(game, x, y - 1);
	else if (keycode == 97)
		move_player(game, x - 1, y);
	else if (keycode == 115)
		move_player(game, x, y + 1);
	else if (keycode == 100)
		move_player(game, x + 1, y);
	return (0);
}

int	close_game_wrapper(t_game *game)
{
	close_game(game);
	return (0);
}
