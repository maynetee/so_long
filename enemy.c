/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:00:22 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 21:33:23 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_enemy(t_game *game, int i)
{
	int	nx;
	int	ny;

	nx = game->enemies[i].x + game->enemies[i].dir_x;
	ny = game->enemies[i].y + game->enemies[i].dir_y;
	if (nx < 0 || nx >= game->width || ny < 0 || ny >= game->height
		|| game->map[ny][nx] == '1')
	{
		game->enemies[i].dir_x = -game->enemies[i].dir_x;
		game->enemies[i].dir_y = -game->enemies[i].dir_y;
	}
	else
	{
		game->enemies[i].x = nx;
		game->enemies[i].y = ny;
	}
}

void	move_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		move_enemy(game, i);
		i++;
	}
}

static int	check_enemy_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].x == game->player_x
			&& game->enemies[i].y == game->player_y)
			return (1);
		i++;
	}
	return (0);
}
	
int	update_game(t_game *game)
{
	game->global_frame++;
	if (game->win_flag == 1 || game->win_flag == 2)
	{
		if (game->global_frame - game->win_start_frame > 60)
			close_game(game);
		return (0);
	}
	if (game->enemy_count > 0 && (game->global_frame % 30 == 0))
		move_enemies(game);
	if (game->enemy_count > 0 && check_enemy_collision(game))
	{
		ft_printf("Game Over\n");
		display_message(game, "You Lost!");
		game->win_flag = 2;
		game->win_start_frame = game->global_frame;
	}
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}
