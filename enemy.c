/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:00:22 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/24 19:01:51 by mteichma         ###   ########.fr       */
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
		game->enemies[i].dir_x *= -1;
		game->enemies[i].dir_y *= -1;
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
	if (game->win_flag)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->end_screen, 0, 0);
		if (game->global_frame - game->win_start_frame > 240)
			close_game(game);
		return (0);
	}
	if (game->enemy_count > 0 && (game->global_frame % 30 == 0))
		move_enemies(game);
	if (game->enemy_count > 0 && check_enemy_collision(game))
	{
		game->end_screen = mlx_xpm_file_to_image(game->mlx,
				"assets/player_dead.xpm", &game->win_w, &game->win_h);
		game->win_flag = 1;
		game->win_start_frame = game->global_frame;
	}
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}
