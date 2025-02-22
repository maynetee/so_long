/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:53:09 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 20:15:43 by mteichma         ###   ########.fr       */
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

void	collect_item(t_game *game, int nx, int ny)
{
	if (game->map[ny][nx] == 'C')
	{
		game->count_c--;
		game->map[ny][nx] = '0';
		system("afplay assets/item.wav &");
	}
}

void	check_victory(t_game *game, int nx, int ny)
{
	if (game->map[ny][nx] == 'E' && game->count_c == 0)
	{
		system("afplay assets/victory.wav &");
		display_message(game, "You Win!");
		ft_printf("You Win!\n");
		game->win_flag = 1;
		game->win_start_frame = game->global_frame;
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (can_move_to(game, new_x, new_y))
	{
		game->move_count++;
		ft_printf("Mouvements : %d\n", game->move_count);
		collect_item(game, new_x, new_y);
		check_victory(game, new_x, new_y);
		game->player_x = new_x;
		game->player_y = new_y;
		mlx_clear_window(game->mlx, game->win);
		mlx_do_sync(game->mlx);
		render_map(game);
	}
}
