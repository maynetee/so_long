/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:53:09 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/21 00:53:21 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move_to(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'E' && game->count_c > 0)
		return (0);
	return (1);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (can_move_to(game, new_x, new_y))
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->count_c--;
			game->map[new_y][new_x] = '0';
		}
		if (game->map[new_y][new_x] == 'E' && game->count_c == 0)
		{
			ft_printf("You Win!\n");
			close_game(game);
		}
		game->player_x = new_x;
		game->player_y = new_y;
		mlx_clear_window(game->mlx, game->win);
		render_map(game);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall_img, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->item_img, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit_img, x * 64, y * 64);
			else if (game->player_x == x && game->player_y == y)
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
